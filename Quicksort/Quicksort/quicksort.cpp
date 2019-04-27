#include <iostream>
using namespace std;

class QuickSort{
public:
    void quickSort(int *arr[],int startIndex,int endIndex);
private:
    int partition(int *arr[],int startIndex,int endIndex);
};
 void QuickSort::quickSort(int* arr[],int startIndex,int endIndex){
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


