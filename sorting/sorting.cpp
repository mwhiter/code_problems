#include <iostream>
#include <stdlib.h>
#include <time.h>

/** Sorter class with various sorts. */

template <class T>
class Sorter {
public:
	static void qsort(T arr[], int start, int end);
private:
	static int qsort_partition(T arr[], int start, int end);
};

template <class T>
/** Implements a recursive quick sort (with partition at the end)
	Best case run time: O(n lg n)
	Average case run time: O(n lg n)
	Worst case run time: O(n^2)
*/
void Sorter<T>::qsort(T arr[], int start, int end) {
	if(start < end) {
		int part = qsort_partition(arr, start, end);
		qsort(arr, start, part-1);
		qsort(arr, part+1, end);
	}
}

template <class T>
int Sorter<T>::qsort_partition(T arr[], int start, int end) {
	T x = arr[end];
	int i = start-1;
	for(int j = start; j < end; j++) {
		if(arr[j] <= x) {
			i++;
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	} 
	T temp = arr[i+1];
	arr[i+1] = arr[end];
	arr[end] = temp;
	return i+1;
}

int main() {
	srand(time(NULL));
	
	const int size = 10000;
	int arr1[size];
	for(int i=0; i < size; i++) {
		arr1[i] = rand() % 1000;
	}
	
	Sorter<int>::qsort(arr1, 0, size-1);
	std::cout << "QSort: ";
	for(int i=0; i < size; i++) {
		std::cout << arr1[i] << (i == size-1 ? "" : " ");
	}
	std::cout << std::endl;
	return 0;
}