#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n,s;
        int mn=1000000000;
        scanf("%d %d",&n,&s);
        int arr[n+1];
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        int j=1,cnt=0;
        for(int i=1;;){
            if(cnt<s){
                if(i>n) break;
                cnt+=arr[i];
                ++i;
            }
            else{
                mn=min(mn,i-j);
                cnt-=arr[j];
                ++j;
            }
        }
    if(mn==1000000000) mn=-1;
    printf("Case %d: %d\n",t,mn);
    }
    return 0;
}
