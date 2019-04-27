#include <iostream>
//#include "quicksort.cpp"
using namespace std;
#define ArrayLength 7

 int partition(int arr[],int startIndex,int endIndex){
    //first element as pivot
    int privotIndex = arr[startIndex];
    int left = startIndex;
    int right = endIndex;

    int Index = startIndex;

    while(left<=right)
    {
        //scan array from right to left
        while(privotIndex<arr[right])
            right--;

            Index = right;
            arr[left] = arr[right];
            left++;
            if(left>=right)break;
        //scan array from left to right
        while(privotIndex>arr[left])
            left++;

            Index = left;
            arr[right] = arr[left];
            right--;
            if(left>=right)break;
    }
    arr[Index] = privotIndex;
    for(int i=0;i<ArrayLength;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return Index;

}

 void quickSort(int arr[],int startIndex,int endIndex){
    //�ݹ��������,����ָ����ڵ�����ָ��
    if(startIndex>=endIndex){
        return;
    }
    //�õ���׼Ԫ�ص�λ��
    int pivotIndex = partition(arr,startIndex,endIndex);
    //�÷��η��ݹ���Ҫ�����������
    quickSort(arr,startIndex,pivotIndex-1);
    quickSort(arr,pivotIndex+1,endIndex);
  }

int main()
{
    int arr2[ArrayLength] = {1,2,3,4,5,6,7};
    int arr[ArrayLength] = {2,4,1,5,3,7,9};
    quickSort(arr,0,ArrayLength-1);
    quickSort(arr2,0,ArrayLength-1);
    return 0;
}
