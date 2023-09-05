#include <iostream>
using namespace std;
void swap (int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int patrition(int arr[], int low,int high)
{
    int left = low;
    int right = high;
    int pivot = arr[(low+high)/2];
    while (left<=right)
    {
        while (arr[left]<pivot) left++;
        while (arr[right]>pivot) right--;
        if (left <= right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    return left;
}
void quicksort(int arr[],int l,int h)
{
    if (l<h)
    {
        int index = patrition(arr,l,h);
        quicksort(arr,l,index-1);
        quicksort(arr,index,h);
    }
}
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i=0;i<n;i++) cin >> a[i];
    quicksort(a,0,n-1);
    for (int i=0;i<n;i++) cout << a[i] <<" ";
    return 0;
}
