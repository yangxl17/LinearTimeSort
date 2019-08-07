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
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

void CountingSort(const std::vector<int>& A, std::vector<int>& B, int k)
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
	for (int j = A.size() - 1; j >= 0; j--)
	{
		B[C[A[j]]-1] = A[j];
		C[A[j]]--;
	}
}

int main()
{
	int A1[10] = { 2,1,5,10,4,0,11,9,20,7 };
	int B1[10];
	vector<int> A2{ 2,1,5,10,4,0,11,9,20,7 };
	vector<int> B2(10, 0);
	CountingSort(A1, B1, 10, 20);
	CountingSort(A2, B2, 20);
	for each (int num in B2)
	{
		cout << num << " ";
	}
	cout << endl;
	auto begin = B2.begin();
	auto end = B2.end();
	for (; begin != end; begin++)
	{
		cout << *begin << " ";
	}
	return 0;
}
