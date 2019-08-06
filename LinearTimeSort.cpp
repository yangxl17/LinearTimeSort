// LinearTimeSort.cpp: 定义应用程序的入口点。
//

#include "LinearTimeSort.h"

using namespace std;

//Counting Sort Function
void CountingSort(int A[], int B[], int length, int k)
{
	int* C= new int[k+1]();
	for (int i = 0; i < length; i++)
	{
		C[A[i]]++;
	}
	for (int j = 1; j <= k; j++)
	{
		C[j] = C[j] + C[j - 1];
	}
	for (int i = length-1; i >= 0 ; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

void CountingSort(std::vector<int> A, std::vector<int> B, int k)
{
	std::vector<int> C(k + 1, 0);
	for each (int num in A)
	{
		C[num]++;
	}
	for (int i = 1; i <= k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	for (int j = A.size - 1; j >= 0; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
}

int main()
{
	cout << "Hello CMake。" << endl;
	return 0;
}
