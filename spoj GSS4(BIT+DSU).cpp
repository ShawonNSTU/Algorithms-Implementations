#include <bits/stdc++.h>
#define LL long long
#define MAX 100001
using namespace std;
LL BIT[MAX], arr[MAX], parent[MAX], n, l, r;
void update(LL x, LL delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
LL query(LL x)
{
     LL sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
void makeset(LL num)
{
    for(LL i=0;i<=num;i++)
        parent[i]=i;
    return ;
}
LL Find(LL r)
{
    if(parent[r]==r) return r;
    else return parent[r]=Find(parent[r]);
}
void update2(LL l1, LL r1)
{
    LL idx;
    while(true){
        idx=Find(l1);
        if(idx>r1) break;
        else{
            if(arr[idx]!=1){
                update(idx+1,-arr[idx]);
                arr[idx]=(long long)floor(sqrt((double)arr[idx]));
                update(idx+1,arr[idx]);
                if(arr[idx]==1){
                    parent[idx]=idx+1;
                }
            }
            l1=idx+1;
        }
    }
}
int main()
{
    int T=0;
    while(scanf("%lld",&n)!=EOF){
        ++T;
        memset(BIT,0,sizeof(BIT));
        for(LL i=0;i<n;i++){
            scanf("%lld",arr+i);
            update(i+1,arr[i]);
        }
        makeset(n);
        LL m;
        scanf("%lld",&m);
        if(T>=1) printf("Case #%d:\n",T);
        for(LL i=1;i<=m;i++){
            LL ch;
            scanf("%lld %lld %lld",&ch,&l,&r);
            if(l>r) swap(l,r);
            if(ch==1){
                printf("%lld\n",query(r)-query(l-1));
            }
            else{
                update2(--l,--r);
            }
        }
        printf("\n");
    }
    return 0;
}
