#include <iostream>
using namespace std;

class QuickSort{
public:
    void quickSort(int *arr[],int startIndex,int endIndex);
private:
    int partition(int *arr[],int startIndex,int endIndex);
};
 void QuickSort::quickSort(int* arr[],int startIndex,int endIndex){
    //递归结束条件,当左指针大于等于右指针
    if(startIndex>=endIndex){
        return;
    }
    //得到基准元素的位置
    int pivotIndex = partition(arr,startIndex,endIndex);
    //用分治法递归需要排序的两部分
    quickSort(arr,startIndex,pivotIndex-1);
    quickSort(arr,pivotIndex+1,endIndex);
  }


 int QuickSort::partition(int *arr[],int startIndex,int endIndex){
    //first element as pivot
    int privotIndex = arr[startIndex];
    int left = startIndex;
    int right = endIndex;

    int Index = startIndex;

    while(left>=right)
    {
        while(privotIndex<=arr[right])
            right--;
        //
            Index = right;
            arr[left] = arr[right];
            left++;

        while(privotIndex>=arr[left])
            left++;

            Index = left;
            arr[right] = arr[left];
            right++;
    }
    arr[left] = Index;
    return Index;
}


