#include <bits/stdc++.h>
using namespace std;
int knapsack(int val[],int w[],int n,int W)
{
   int dp[n+1][W+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=W;j++){
           if(i==0||j==0) dp[i][j] = 0;
           else if(w[i-1]>j) dp[i][j] = dp[i-1][j];
           else dp[i][j] = max(val[i-1] + dp[i-1][j-w[i-1]],  dp[i-1][j]);
       }
   }
   return dp[n][W];
}
int main()
{
    int n,W;
    scanf("%d %d",&n,&W);
    int val[n],w[n];
    for(int i=0;i<n;i++) scanf("%d",val+i);
    for(int i=0;i<n;i++) scanf("%d",w+i);
    printf("%d\n",knapsack(val,w,n,W));
    return 0;
}
