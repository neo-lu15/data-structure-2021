#include <iostream>
#include <time.h>
#include <math.h>


using namespace std;
/* This function takes first element as pivot, and places
   all the elements smaller than the pivot on the left side
   and all the elements greater than the pivot on
   the right side. It returns the index of the last element
   on the smaller side*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
 
int main(){
        int n=10;
        srand(time(NULL));
        double start,end;
	for(int num=10;num<31;++num){
                cout << endl<<endl<<num<<endl<<endl;
		n=10;
		while(n>0){
                        int *arr;
                        arr = (int *)malloc( pow(2,num) * sizeof(int));

                        if( arr == NULL ) {
                                // 無法取得記憶體空間
                                fprintf(stderr, "Error: unable to allocate required memory\n");
                                return 1;
                        }
                        for(int i = 0 ; i < pow(2,num);++i){
                                arr[i] = (rand()%1000)+1;
                        }
                        start = clock();
                        quickSort(arr,0,pow(2,num)-1);
                        free(arr);
                        end = clock();


                        cout << (double)(end-start)/CLOCKS_PER_SEC<<endl;

                        --n;


		}               }


        return 0;
}
