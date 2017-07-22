/// Time Complexity: O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int Merge(int arr[],int temp[],int left,int mid,int right)
{
    int i = left,j = mid,k = left;
    while((i <= mid-1) and (j <= right)){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid-1) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];
    for(i=left; i<=right; i++) arr[i] = temp[i];
}
int MergeSort(int arr[],int temp[],int left,int right)
{
    int mid;
    if(right > left){
        mid = (right+left) >> 1;
        MergeSort(arr,temp,left,mid);
        MergeSort(arr,temp,mid+1,right);
        Merge(arr,temp,left,mid+1,right);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n], temp[n];
    for(int i=0; i<n; i++) scanf("%d",arr+i);
    MergeSort(arr,temp,0,n-1);
    for(int i=0; i<n; i++) printf("%d ",arr[i]);
    return 0;
}
