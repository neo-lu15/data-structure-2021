#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#define num 10

using namespace std;
// C++ program for implementation of Heap Sort




// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int  largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

int main() {

	srand(time(NULL));
	double start,end;
	for(int j=10 ; j< 31;++j){
		cout << endl <<endl<<j<<endl<<endl;
		int n=10;
		while(n>0){
                        int *arr;
                        arr = (int *)malloc( pow(2,j) * sizeof(int));

                        if( arr == NULL ) {
                                // 無法取得記憶體空間
                                fprintf(stderr, "Error: unable to allocate required memory\n");
                                return 1;
                        }
                        for(int i = 0 ; i < pow(2,j);++i){
                                arr[i] = (rand()%1000)+1;
                        }
                        start = clock();
                        heapSort(arr,pow(2,j)-1);
                        free(arr);
                        end = clock();


                        cout << (double)(end-start)/CLOCKS_PER_SEC<<endl;

                        --n;


                }
	}
	return 0;
}
