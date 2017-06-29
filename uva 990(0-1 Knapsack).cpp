#include <bits/stdc++.h>
using namespace std;
int w,gold[30],depth[30],dp[31][1001];
vector<pair<int,int> > ans;
int knapsack(int n,int W)
{
   for(int i=0;i<=n;i++){
       for(int j=0;j<=W;j++){
           if(i==0||j==0) dp[i][j] = 0;
           else if(depth[i-1]>j) dp[i][j] = dp[i-1][j];
           else dp[i][j] = max(gold[i-1] + dp[i-1][j-depth[i-1]], dp[i-1][j]);
       }
   }
   return dp[n][W];
}
void KnapsackPrint(int i,int j)
{
    if(i==0 or j==0) return;
    if(dp[i][j]==dp[i-1][j]) KnapsackPrint(i-1,j);
    else{
        ans.push_back({depth[i-1]/(w*3),gold[i-1]});
        KnapsackPrint(i-1,j-depth[i-1]);
    }
}
int main()
{
    int t,T=0;
    while(scanf("%d %d",&t,&w)==2){
        int n;
        if(T) printf("\n");
        ++T;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",depth+i,gold+i);
            depth[i]*=3*w;
        }
        printf("%d\n",knapsack(n,t));
        ans.clear();
        KnapsackPrint(n,t);
        printf("%d\n",ans.size());
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return 0;
}
