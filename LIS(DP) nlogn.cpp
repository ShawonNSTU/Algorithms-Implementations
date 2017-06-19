#include <bits/stdc++.h>
#define LL long long
#define INF 10000000000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, length=0;
    cin>>n;
    LL dp[n+1], arr[n];
    dp[0] = -INF;
    for(int i=0; i<n; i++){
        scanf("%lld",&arr[i]);
        dp[i+1]=INF;
    }
    for(int i=0; i<n; i++){
       int j = upper_bound(dp, dp+n+1, arr[i]) - dp;
       if(dp[j-1] < arr[i] && arr[i] < dp[j]){
            dp[j] = arr[i];
            length = max(length,j);
        }
    }
    cout<<length<<"\n";
    return 0;
}
