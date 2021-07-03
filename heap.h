#pragma once
namespace DS
{

	class Heap {
	private:
		int* data;
		int maxSize; //Max size of heap
		int heapSize; //Current size of heap
		int allocated;
		static int Left(int node);
		static int Right(int node);
		static int Parent(int node);
		void FixHeap(int node);
	public:
		Heap(int A[], int n);
		Heap(int max);//allocate memory
		~Heap();
		int Min();
		int DeleteMin();
		void Insert(int item);
		void swap(int* a, int* b);
		int getHeapSize();
	};
}