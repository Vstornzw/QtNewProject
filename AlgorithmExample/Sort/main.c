#include <stdio.h>

#define SIZE 10

//任务：
// https://blog.csdn.net/m0_53036448/article/details/131638220

void Print_(int *arr, int len, char *str)
{
    printf("============ %s ============", str);
    printf("\n");
    for(int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("============ %s ============", str);
}

void BubbleSort(int *arr, int len, char *str)
{
    /*
    原则就是：最外层循环 每执行一次；从最右侧值开始排序好一位
    */
    int temp = 0;
    for(int i = 0; i < len - 1; ++i)
    {
        for(int j = 0; j < len - i - 1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    Print_(arr, len, str);

}

void InsertSort(int *arr, int len, char *str)
{
    // https://blog.csdn.net/ThinkWon/article/details/101537804
    int insertNum = 0;
    for(int i = 1; i < len; ++i)
    {
        insertNum = arr[i];
        //已经排序好的元素个数
        int j = i - 1;
        while(j >= 0 && arr[j] > insertNum)
        {
            //从后到前循环，将大于insetNum的数向后移动一格
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = insertNum;//将需要插入的数放在要插入的位置
    }
    Print_(arr, len, str);
}


void SelectSort(int *arr, int len, char *str)
{
    //https://blog.csdn.net/ThinkWon/article/details/101534721
    for(int i = 0; i < len - 1; ++i)
    {
        int minIndex = i;
        for(int j =  i + 1; j < len; ++j)
        {
             if(arr[j] < arr[minIndex])
             {
                 minIndex = j;
             }
        }
        //交换元素位置
        if (i != minIndex)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
    Print_(arr, len, str);
}

void QuickSort1(int *arr, int begin, int end)
{
    //https://blog.csdn.net/gjyfe5f13/article/details/126815419
    if(begin > end)
    {
        return;
    }
    int temp = arr[begin];
    int left = begin;
    int right = end;
    while(left != right)
    {
        while(arr[right] >= temp && right > left)//哨兵从右往左找
        {
            right--;
        }
        while(arr[left] <= temp && right > left)//哨兵从左往右找
        {
            left++;
        }
        if(right > left)//交换数值
        {
            int temp1 = arr[left];
            arr[left] = arr[right];
            arr[right] = temp1;
        }
    }
    arr[begin] = arr[left];
    arr[left] = temp;
    QuickSort1(arr, begin, left - 1);
    QuickSort1(arr, left + 1, end);
}

void QuickSort(int *arr, int len, char *str)
{
    QuickSort1(arr, 0, len - 1);
    Print_(arr, len, str);
}


int main()
{
    int arr[SIZE] = {12, 43, 9, 13, 67, 98, 101, 89, 3, 35};

    //BubbleSort(arr, sizeof(arr) / sizeof(int), "BubbleSort");
    //InsertSort(arr, sizeof(arr) / sizeof(int), "InsertSort");
    //SelectSort(arr, sizeof(arr) / sizeof(int), "SelectSort");
    //QuickSort(arr, sizeof(arr) / sizeof(int), "QuickSort");

    return 0;
}
