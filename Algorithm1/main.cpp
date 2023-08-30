#include <iostream>

using namespace std;
#include "Sort.h"
#include "Hanoi.h"
#include "LeeCode.h"

#define SIZE 10




int main()
{

    {
        int arr[SIZE] = {12, 43, 9, 13, 67, 98, 101, 89, 3, 35};

        //BubbleSort(arr, sizeof(arr) / sizeof(int), "BubbleSort");
        //InsertSort(arr, sizeof(arr) / sizeof(int), "InsertSort");
        //SelectSort(arr, sizeof(arr) / sizeof(int), "SelectSort");
        //QuickSort(arr, sizeof(arr) / sizeof(int), "QuickSort");

    }// 排序


    {
        //hanoi(5, 'A', 'B', 'C');
    } //汉诺塔问题


    {
        LeeCode();
    }

    return 0;
}
