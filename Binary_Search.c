#include <stdio.h>
int BinarySearch(int ara[],int first,int last,int search)
{
    while(first<=last){
        int middle=(first+last)/2;
    if(ara[middle]==search) return middle+1;
    else if(ara[middle]<search) first=middle+1;
    else last=middle-1;
    }
    return -1;
}
int main()
{
    int ara[1000],i,size,search,result;
    while(1){
    printf("Enter The Size Of The Array...");
    scanf("%d",&size);
    if(!size) break;
    printf("Enter %d Elements...\n",size);
        for(i=0;i<size;i++)
            scanf("%d",&ara[i]);
        printf("Enter The Key Element to Search...");
        scanf("%d",&search);
        result=BinarySearch(ara,0,size-1,search);
        if(result!=-1) printf("%d found in the array at location %d.\n\n",search,result);
        else printf("%d not found in the array.\n\n",search);
    }
    return 0;
}
