#include "stdio.h"

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int deQuy(int a[], int low, int high)
{
    int pivot = a[high];
    int left = low;
    int right = high - 1;

    while (true)
    {
        while(left <= right && a[left] < pivot){
            left++;
        }
        while(left >= right && a[right] > pivot){
            right--;
        }
        if (left >= right)
        {
            break;
            swap(a[left], a[right]);
            left++;
            right--;
        }
        
    }
    swap(a[left],a[right]);
        return left;
}
void quickSort(int a[], int low , int high)
{
    if(low < high)
    {
        int pi = deQuy(a,low,high);
        quickSort(a,low, pi - 1);
        quickSort(a,low + 1, high);
    }
}
// Độ phức tạp của QuickSort
// + Trường hợp tốt O(nlog(n))
// + Trường hợp xấu O(n^2)
// + Trường hợp trung bình: O(nlog(n))

void merge(int a, int l, int m ,int r)
{
    int i,j,k;
    int n1 = m -l +1;
    int n2 = r -m ;
    int L[n1],R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[i+1];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = l[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
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
void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int m = l +(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+l,r);
        merge(a,l,m,r);
    }
}
// Độ phức tạp của thuật toán
//  Trường hợp tốt: O(nlog(n))
//  Trường hợp xấu: O(nlog(n))
//  Trường hợp trung bình: O(nlog(n))