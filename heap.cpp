#include "heap.h"
namespace DS
{
	Heap::Heap(int max)
	{
		this->data = new int[max];
		this->maxSize = max;
		this->heapSize = 0;
		this->allocated = 1;
	}
	Heap::~Heap()
	{
		if (this->allocated)
			delete[] this->data;
		this->data = nullptr;
	}
	int Heap::Parent(int node)
	{
		return (node - 1) / 2;
	}
	int Heap::Left(int node)
	{
		return (2 * node + 1);
	}
	int Heap::Right(int node)
	{
		return (2 * node + 2);
	}

	void Heap::swap(int* a, int* b)
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
	void Heap::FixHeap(int node)
	{
		int min;
		int left = Left(node);
		int right = Right(node);

		if ((left < this->heapSize) && (this->data[left] < this->data[node]))
			min = left;
		else min = node;
		if ((right < this->heapSize) && (this->data[right] < this->data[min]))
			min = right;

		if (min != node)
		{
			swap(this->data + node, this->data + min);
			FixHeap(min);
		}
	}
	int Heap::DeleteMin()
	{
		if (this->heapSize >= 1)
		{
			int min = this->data[0];
			this->heapSize--;
			this->data[0] = this->data[this->heapSize];
			this->FixHeap(0);
			return min;
		}
	}
	void Heap::Insert(int item)
	{
		if (this->heapSize < this->maxSize)
		{
			int i = this->heapSize;
			this->heapSize++;
			while ((i > 0) && (this->data[Parent(i)]) > item)
			{
				this->data[i] = this->data[Parent(i)];
				i = Parent(i);
			}
			this->data[i] = item;
		}
	}

	Heap::Heap(int A[], int n)
	{
		this->heapSize = this->maxSize = n;

		this->data = A;
		this->allocated = 0;

		for (int i = (n / 2) - 1; i >= 0; i--)
			this->FixHeap(i);
	}

	int Heap::Min()
	{
		return this->data[0];
	}
	int Heap::getHeapSize()
	{
		return this->heapSize;
	}

}