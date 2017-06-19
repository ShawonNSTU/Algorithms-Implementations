#include <bits/stdc++.h>
using namespace std;
int lcs(int X[],int Y[],int m,int n)
{
   int L[m+1][n+1];
   for(int i=0;i<=m;i++){
     for(int j=0;j<=n;j++){
       if(i == 0 || j == 0)
         L[i][j] = 0;
       else if(X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
   }
   return L[m][n];
}
int main()
{
    int n,m,t=0;
    while(scanf("%d %d",&n,&m)){
        int tower1[n],tower2[m];
        if(!n&&!m) break;
        ++t;
        for(int i=0;i<n;i++) scanf("%d",tower1+i);
        for(int i=0;i<m;i++) scanf("%d",tower2+i);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",t,lcs(tower1,tower2,n,m));
    }
}
