#include <bits/stdc++.h>
using namespace std;
int arr[1000];
// The value of dp[i][j] will be true if there is a
// subset of set[0..i-1] with sum equal to j
bool SubsetSUM(int n,int SUM)
{
    bool dp[n+1][SUM+1];
    for(int i=0;i<=n;i++) dp[i][0] = true; // As sum = 0, the answer is true
    for(int i=1;i<=SUM;i++) dp[0][i] = false; // // As sum is not equal to 0 and set is empty, then answer is false
    for(int i=1;i<=n;i++){
        for(int j=1;j<=SUM;j++){
            if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][SUM];
}
int main()
{
    int n,SUM;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    scanf("%d",&SUM);
    if(SubsetSUM(n,SUM)==true)
        printf("Found\n");
    else printf("Not Found\n");
    return 0;
}
