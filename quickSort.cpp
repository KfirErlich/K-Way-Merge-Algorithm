#include "QuickSort.h"
namespace DS
{
	void swap(int* a, int* b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
	int partition(int* arr, int left, int right)
	{
		double pivot = arr[left];

		while (left != right)
		{
			if (arr[left] == pivot)
			{
				if (pivot > arr[right])
				{
					swap(&arr[left], &arr[right]);
					left++;
				}
				else
					right--;
			}
			else
			{
				if (pivot > arr[left])
					left++;
				else {
					swap(&arr[right], &arr[left]);
					right--;
				}
			}
		}
		return left;//left and right are both the center
	}

	void quickSort(int A[], int left, int right)
	{
		int pivot;

		if (left < right)
		{
			pivot = partition(A, left, right);
			quickSort(A, left, pivot - 1);
			quickSort(A, pivot + 1, right);
		}

	}

}