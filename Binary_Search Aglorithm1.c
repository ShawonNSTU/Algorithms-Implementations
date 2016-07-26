#include <stdio.h>
int BinarySearch(int ara[],int first,int last,int search)
{
    while(first<=last){
        int middle=(first+last)/2;
    if(ara[middle]==search) return 0;
    else if(ara[middle]<search) first=middle+1;
    else last=middle-1;
    }
    return -1;
}
int main()
{
    int ara[1000],arr[1000],i,j,k,max,size,search,result;
    while(scanf("%d",&size)!=EOF){
        max=0,k=0;
        memset(arr,0,sizeof(arr));
        for(i=0;i<size;i++){
            scanf("%d",&ara[i]);
            if(ara[i]>max) max=ara[i];
            arr[ara[i]]++;
        }
        for(i=0;i<=max;i++){
            if(arr[i]!=0){
                for(j=1;j<=arr[i];j++){
                    ara[k]=i;
                    k++;
                }
            }
        }
        scanf("%d",&search);
        result=BinarySearch(ara,0,size-1,search);
        if(result!=-1) printf("%d found in the array.\n",search);
        else printf("%d not found in the array.\n",search);
    }
    return 0;
}
