#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#define num 10


using namespace  std;

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main(){
	int n=10;
	srand(time(NULL));
	double start,end;
	
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


		}

	
	return 0;
}

