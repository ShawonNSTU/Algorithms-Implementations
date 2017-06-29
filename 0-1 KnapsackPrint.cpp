#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
int val[MAX],w[MAX],dp[MAX][MAX];
int knapsack(int n,int W)
{
   for(int i=0;i<=n;i++){
       for(int j=0;j<=W;j++){
           if(i==0||j==0) dp[i][j] = 0;
           else if(w[i-1]>j) dp[i][j] = dp[i-1][j];
           else dp[i][j] = max(val[i-1] + dp[i-1][j-w[i-1]],  dp[i-1][j]);
       }
   }
   return dp[n][W];
}
void KnapsackPrint(int i,int j)
{
    if(i==0 or j==0) return;
    if(dp[i][j]==dp[i-1][j]) KnapsackPrint(i-1,j);
    else{
        printf("%d %d\n",val[i-1],w[i-1]);
        KnapsackPrint(i-1,j-w[i-1]);
    }
}
int main()
{
    int n,W;
    scanf("%d %d",&n,&W);
    for(int i=0;i<n;i++) scanf("%d",val+i);
    for(int i=0;i<n;i++) scanf("%d",w+i);
    printf("%d\n",knapsack(n,W));
    KnapsackPrint(n,W);
    return 0;
}
