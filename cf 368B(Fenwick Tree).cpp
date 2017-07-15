#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int BIT[MAX], arr[MAX], n, q, idx;
bool visited[MAX];
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
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        if(!visited[arr[i]]){
            update(i+1,1);
            visited[arr[i]]=1;
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d",&idx);
        printf("%d\n",query(n-idx+1));
    }
    return 0;
}
