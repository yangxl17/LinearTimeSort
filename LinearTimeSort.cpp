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
	delete[] C;
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

void RadixSort(const std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, int k)
{
	auto D = A;
	for (int i = D[0].size() - 1; i >= 0; i--)
	{
		std::vector<int> C(k + 1, 0);
		for (auto d : D)
		{
			C[d[i]]++;
		}
		for (int j = 1; j <= k; j++)
		{
			C[j] = C[j] + C[j - 1];
		}
		auto begin = D.begin();
		auto end = D.end();
		while (begin != end)
		{
			end--;
			B[C[(*end)[i]]-1] = *end;
			C[(*end)[i]]--;
		}
		D = B;
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
	cout << endl;
	vector<vector<int>> A3{ {1,3,5},{1,2,6},{2,1,9},{0,4,8} };
	vector<vector<int>> B3(4, { 0,0,0 });
	RadixSort(A3, B3, 9);
	for (auto b3 : B3)
	{
		for (auto bb3 : b3)
		{
			cout << bb3 << " ";
		}
		cout << endl;
	}
	return 0;
}
