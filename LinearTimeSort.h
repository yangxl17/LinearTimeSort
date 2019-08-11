// LinearTimeSort.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <vector>
// TODO: 在此处引用程序需要的其他标头。

//Counting Sort Function
void CountingSort(int A[], int B[], int length, int k);
void CountingSort(const std::vector<int>& A, std::vector<int>& B, int k);

//Radix Sort
void RadixSort(const std::vector <std::vector<int>>& A, std::vector<std::vector<int>>& B, int k);