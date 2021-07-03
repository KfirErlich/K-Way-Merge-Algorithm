#include "mainFunctions.h"

int main() {
	string N, K, inputFileName, outputFileName;
	cin >> N;	
	cin >> K;
	cin >> inputFileName;
	cin >> outputFileName;

	int* arr = nullptr;
	int nVal = atoi(N.data()), kVal = atoi(K.data());

	if (isNumber(N) && isNumber(K))
	{
		loadToArray(nVal,arr,inputFileName);
		if (true)//check it
		{
			kWayMerge(arr, kVal, 0, nVal - 1);
			arrayToFile(nVal, arr, outputFileName);
		}
	}
	else
	{
		cout << "wrong input";
		exit(1);
	}
	
	delete arr;

	return 0;
}

void loadToArray(int n, int* arr, string inputFileName)
{
	arr = new int[n];
	string temp;
	ifstream infile;
	infile.open(inputFileName);

	for (int i = 0; i < n; i++) //Enter values to dynamic array and validate them 
	{
		infile >> temp;
		if (!isNumber(temp))
		{
			cout << "wrong input";
			delete arr;
			exit(1);
		}
		else
			arr[i] = atoi(temp.data());
	}
	infile.close();
}

void arrayToFile(int n, int* arr, string outputFileName)
{
	ofstream outfile;
	outfile.open(outputFileName);
	for (int i = 0; i < n; i++) //Enter values to output file
	{
		outfile << to_string(arr[i]) + "\n";
	}
	outfile.close();
}


bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}

void kWayMerge(int A[], int k, int left, int right) {
	if ((right - left) < k) {
		quickSort(A, left, right);
	}
	else {
		int lenArr = right - left + 1;
		int length = (lenArr % k == 0) ? (lenArr / k) : ((lenArr / k) + 1);
		int currRight = length - 1, currLeft = 0;

		Heap** heaps = new Heap * [k];

		for (int i = 0; i < k; i++)
		{
			kWayMerge(A + currLeft, k, 0, length - 1);
			heaps[i] = new Heap(length);
			for (int j = currLeft; j < currRight + 1; j++)
				heaps[i]->Insert(A[j]);
			currLeft += length;

			if (right - currRight < length) {
				length = (right - currRight);
				currRight += (right - currRight);
			}
			else
				currRight += length;
		}

		int i = 0;
		while (i != right - left + 1) {
			int minHeap = skipEmptyHeaps(heaps, k);
			int minNum = heaps[minHeap]->Min();

			for (int j = 0; j < k; j++) {
				if (heaps[j]->getHeapSize() != 0) {
					int curr = heaps[j]->Min();
					if (minNum > curr) {
						minNum = curr;
						minHeap = j;
					}
				}

			}
			A[i] = heaps[minHeap]->DeleteMin();
			i++;
		}
		freeHeaps(heaps, k);
	}

}
int skipEmptyHeaps(Heap** heaps, int length) {
	for (int i = 0; i < length; i++)
	{
		int heapSize = heaps[i]->getHeapSize();
		if (heapSize != 0)
			return i;
	}
}
void freeHeaps(Heap** heaps, int length) {
	for (int i = 0; i < length; i++)
	{
		delete heaps[i];
	}
	delete heaps;
}