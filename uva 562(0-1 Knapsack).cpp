#include <bits/stdc++.h>
using namespace std;
int coin[100];
int knapsack(int n,int W)
{
   int dp[n+1][W+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=W;j++){
           if(i==0||j==0) dp[i][j] = 0;
           else if(coin[i-1]>j) dp[i][j] = dp[i-1][j];
           else dp[i][j] = max(coin[i-1] + dp[i-1][j-coin[i-1]], dp[i-1][j]);
       }
   }
   return dp[n][W];
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int m,cnt=0;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",coin+i);
            cnt+=coin[i];
        }
    printf("%d\n",cnt-(knapsack(m,cnt/2)*2));
    }
    return 0;
}
