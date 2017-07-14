#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
int BIT[MAX], n, q, l, r, idx, len;
void update(int x, int delta)
{
      for(; x <= len; x += x&-x)
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
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++){
        string S;
        cin>>S;
        len = S.length();
        for(int i=0 ;i<=len; i++) BIT[i]=0;
        printf("Case %d:\n",t);
        scanf("%d",&q);
        for(int i=1; i<=q; i++){
            char ch;
            scanf(" %c",&ch);
            if(ch=='I'){
                scanf("%d %d",&l,&r);
                update(l,1);
                update(r+1,-1);
            }
            else{
                scanf("%d",&idx);
                if(!(query(idx) & 1)) printf("%c\n",S[idx-1]);
                else{
                    if(S[idx-1]=='0') printf("1\n");
                    else printf("0\n");
                }
            }
        }
    }
    return 0;
}
