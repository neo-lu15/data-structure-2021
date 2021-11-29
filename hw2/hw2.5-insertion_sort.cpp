// C++ program for insertion sort
#include <bits/stdc++.h>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
//no need
// A utility function to print an array of size n
/*void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}*/
// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

/* Driver code */
int main()
{
	// Seed random number generator
	srand(time(NULL));
	cout <<"insertion\n";	

	// create SkipList object with MAXLVL and P

	for( int i = 10 ; i < 31 ; i++){
		int *arr = new int[(int) pow(2,i)];
		clock_t st,en;
		st = clock();
		for(int j = 0 ; j < pow(2,i) ; ++j)
			arr[j] = (rand()%(int)pow(2,30))+1;
		insertionSort(arr, (int)pow(2,i));
		en = clock();
		cout <<"insert"<< ((double)(en - st) / CLOCKS_PER_SEC) << "\n";
		st = clock();
		for(int j =0 ; j< 100000;++j)
			binarySearch(arr, 0, (int)pow(2,i) - 1,(rand()%(int)pow(2,30))+1 );
		en = clock();
		delete arr;
		cout<<"search" << ((double)(en - st) / CLOCKS_PER_SEC) << "\n";
		cout << endl;
	}

	cout<<endl;



	return 0;
}


