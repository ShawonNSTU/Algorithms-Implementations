#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int BIT[MAX], arr[MAX], n, q, l, r;
void update(int x, int delta)
{
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
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
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
        update(i+1,arr[i]);
     }
    scanf("%d",&q);
    for(int i = 1; i <= q; i++){
        scanf("%d %d",&l,&r);
        printf("%d\n",query(r)-query(l-1));
    }
    return 0;
}
