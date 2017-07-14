#include <bits/stdc++.h>
using namespace std;
const int MAX = 200001;
int BIT[MAX], qsum[MAX],n, q, l, r, k;
void update(int x, int add)
{
      for(; x < MAX; x += x&-x)
        BIT[x] += add;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
int main()
{
    scanf("%d %d %d",&n,&k,&q);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&l,&r);
        update(l,1);
        update(r+1,-1);
    }
    for(int i=1;i<MAX;i++){
        qsum[i]=qsum[i-1];
        int add=query(i);
        if(add>=k) qsum[i]++;
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",qsum[r]-qsum[l-1]);
    }
    return 0;
}
