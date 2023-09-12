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
void Quicksort(int arr[],int l,int h)
{
    if (l<h)
    {
        int index = patrition(arr,l,h);
        Quicksort(arr,l,index-1);
        Quicksort(arr,index,h);
    }
}
void Selection_Sort(int a[],int n)
{
    int minf;
    for (int i=0;i<n-1;i++)
    {
        minf=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[minf]) minf=j;
        }
        swap(a[i],a[minf]);
    }
}
void Insertion_Sort(int a[],int n)
{
    for (int i=1;i<n;i++)
    {
        int j=i;
        while (j>0 && a[j-1]>a[j])
        {
            swap(a[j],a[j-1]);
            j--;
        }
    }
}
void Bubble_Sort(int a[],int n)
{
    bool swapf = true;
    while (swapf)
    {
        swapf = false;
        for (int i=0;i<n-1;i++)
        {
            if (a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                swapf = true;
            }
        }
    }
}
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void Merge_Sort(int a[],int l,int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        Merge_Sort(a, l, m);
        Merge_Sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
