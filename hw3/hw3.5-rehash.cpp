#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <math.h>

using namespace std;

class Hash
{
public:
    Hash(int);
    void insert(int, int);
    void search(int);
    long long int hashfunc(int, int);
    long long int prime(int);
    void deletehash();
    void rehash();
    void displayHash();

private:
    long long int primenum[21] = {1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869,
                                  3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};
    int bucket;
    int r[4];
    list<int> *table;
};

long long int Hash::hashfunc(int key, int b)
{

    int byte[4];
    byte[0] = (key >> 24) & 0b11111111;
    byte[1] = (key >> 16) & 0b11111111;
    byte[2] = (key >> 8) & 0b11111111;
    byte[3] = (key >> 0) & 0b11111111;

    return (byte[0] * r[0] + byte[1] * r[1] + byte[2] * r[2] + byte[3] * r[3]) % bucket;
}

long long int Hash::prime(int n)
{
    for (int i = 0; i < 30; ++i)
    {
        if (primenum[i] > n)
            return primenum[i];
    }
}

Hash::Hash(int b)
{
    srand(time(NULL));
    this->bucket = prime(b);
    table = new list<int>[bucket];

    for (int i = 0; i < 4; ++i)
    {
        r[i] = rand() % bucket;
    }
}

void Hash::insert(int key, int j)
{
    if (bucket < j)
        rehash();
    int index = hashfunc(key, bucket);

    table[index].push_back(key);
}

void Hash::search(int key)
{
    int index = hashfunc(key, bucket);

    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }
}
void Hash::deletehash()
{
    delete[] table;
}
void Hash::displayHash()
{
    for (int i = 0; i < bucket; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
void Hash::rehash()
{
    int j = 0;
    int oldbucket = this->bucket;
    int tmp[bucket];
    for (int i = 0; i < oldbucket; i++)
    {
        for (auto x : table[i])
        {
            tmp[j++] = (x);
            if (j >= oldbucket)
                cout << j << endl;
        }
    }
    deletehash();

    this->bucket = prime(2 * oldbucket);
    table = new list<int>[bucket];

    for (int i = 0; i < oldbucket; ++i)
    {
        int index = hashfunc(tmp[i], bucket);
        table[index].push_back(tmp[i]);
    }
    for (int i = 0; i < 4; ++i)
    {
        r[i] = rand() % bucket;
    }
}

int main()
{
    cout << "Hash\n";
    for (int i = 22; i < 31; i++)
    {

        clock_t st, en;
        Hash h(200);
        cout << i << endl;
        st = clock();
        int *arr = new int[(int)pow(2, i)];
        for (int j = 0; j < (int)pow(2, i); ++j)
        {
            arr[j] = ((rand() % (int)pow(2, 30)) + 1);

            h.insert(arr[j], j);
        }
        en = clock();
        cout << "insert" << ((double)(en - st) / CLOCKS_PER_SEC) << "\n";
        // h.displayHash();
        st = clock();
        for (int j = 0; j < 100000; ++j)
        {
            h.search((rand() % (int)pow(2, 30)) + 1);
        }
        en = clock();

        cout << "search" << ((double)(en - st) / CLOCKS_PER_SEC) << "\n";

        h.deletehash();

        cout << endl;
    }
    cout << endl;
    return 0;
}
