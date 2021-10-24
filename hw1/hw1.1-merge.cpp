#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>



using namespace  std;
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
	*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
	     indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	free(leftArray);
	free(rightArray);
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

int main(){

	int n=10;
	srand(time(NULL));
	double start, end;
	for(int num = 10 ; num < 31 ; ++num){
		n = 10;
		cout << endl << endl << num << endl << endl;
		while( n > 0 ){
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
			mergeSort(arr,0,pow(2,num)-1);


			free(arr);
			end = clock();

			cout << (double)(end-start)/CLOCKS_PER_SEC<<endl;

			--n;


		}
	}

	return 0;
}
