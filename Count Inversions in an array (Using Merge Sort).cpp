/// Time Complexity: O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int Merge(int arr[],int temp[],int left,int mid,int right)
{
    int i=left,j=mid,k=left;
    int inv_count=0;
    while((i<=mid-1)&&(j<=right)){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv_count+=(mid-i);
        }
    }
    while(i<=mid-1) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];
    for(i=left;i<=right;i++) arr[i]=temp[i];
    return inv_count;
}
int MergeSort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count=0;
    if(right>left){
        mid=(right+left)>>1;
        inv_count=MergeSort(arr,temp,left,mid);
        inv_count+=MergeSort(arr,temp,mid+1,right);
        inv_count+=Merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],temp[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    printf("%d\n",MergeSort(arr,temp,0,n-1));
    return 0;
}
