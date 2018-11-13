#pragma once
#include <vector>

void generateRandomVector(std::vector<int>&changingVector)
{
	int loop = 30;

	do
	{
		changingVector.push_back(rand() % 500);
		loop--;
	} while (loop > 0);

}


//code taken from https://stackoverflow.com/questions/22504837/how-to-implement-quick-sort-algorithm-in-c

int partition(std::vector<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j < q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}

	}

	int temp = A[i];
	A[i] = A[p];
	A[p] = temp;
	return i;
}

void quickSort(std::vector<int>& A, int p, int q)
{
	int r;
	if (p < q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}

//end of borrowed code


void comparisonSort(std::vector<int>&sortingSet)
{
	bool sorted = false;
	do {
		sorted = true;
		for (int i = 0; i < sortingSet.size() - 1; i++)
		{
			if (sortingSet[i] > sortingSet[i + 1])
			{
				sorted = false;
				int temp = sortingSet[i];
				sortingSet[i] = sortingSet[i + 1];
				sortingSet[i + 1] = temp;
			} 
		}


	} while (!sorted);
}


//code taken from https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(std::vector<int>&A, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = A[i];
		j = i - 1;

		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}
//end borrowed code

//borrowed code from https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/
void bubbleSort(std::vector<int> arr, int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}
//end of borrowed code

//borrowed code from https://www.geeksforgeeks.org/heap-sort/
void heapify(std::vector<int>arr, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(std::vector<int> arr, int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}
//end borrowed code