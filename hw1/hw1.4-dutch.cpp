#include <iostream>
#include <time.h>
#include <math.h>
#include <cstdlib>
#define num 20

using namespace std;

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition(int a[], int l, int r, int& i, int& j)
{
	i = l - 1, j = r;
	int p = l - 1, q = r;
	int v = a[r];

	while (true) {
		// From left, find the first element greater than
		// or equal to v. This loop will definitely
		// terminate as v is last element
		while (a[++i] < v)
			;

		// From right, find the first element smaller than
		// or equal to v
		while (v < a[--j])
			if (j == l)
				break;

		// If i and j cross, then we are done
		if (i >= j)
			break;

		// Swap, so that smaller goes on left greater goes
		// on right
		swap(a[i], a[j]);

		// Move all same left occurrence of pivot to
		// beginning of array and keep count using p
		if (a[i] == v) {
			p++;
			swap(a[p], a[i]);
		}

		// Move all same right occurrence of pivot to end of
		// array and keep count using q
		if (a[j] == v) {
			q--;
			swap(a[j], a[q]);
		}
	}

	// Move pivot element to its correct index
	swap(a[i], a[r]);

	// Move all left same occurrences from beginning
	// to adjacent to arr[i]
	j = i - 1;
	for (int k = l; k < p; k++, j--)
		swap(a[k], a[j]);

	// Move all right same occurrences from end
	// to adjacent to arr[i]
	i = i + 1;
	for (int k = r - 1; k > q; k--, i++)
		swap(a[i], a[k]);
}

// 3-way partition based quick sort
void quicksort(int a[], int l, int r)
{
	if (r <= l)
		return;

	int i, j;

	// Note that i and j are passed as reference
	partition(a, l, r, i, j);

	// Recur
	quicksort(a, l, j);
	quicksort(a, i, r);
}
int main(){
	int n=10;
	srand(time(NULL));
	double start,end;
	for(int j=10;j<31;++j){
	cout << endl <<endl<<j<<endl<<endl;
		n=10;
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
		quicksort(arr,0,pow(2,j)-1);
		free(arr);
		end = clock();


		cout << (double)(end-start)/CLOCKS_PER_SEC<<endl;

		--n;


	}

	}
	return 0;
} 
