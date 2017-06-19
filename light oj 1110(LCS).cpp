#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
string str[105][105];
void LCS(const string &X,const string &Y,int m,int n)
{
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
                str[i][j]="";
            }
            else if(X[i-1]==Y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                str[i][j]=str[i-1][j-1]+X[i-1];
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    str[i][j]=str[i-1][j];
                }
                else if(dp[i-1][j]<dp[i][j-1]){
                    dp[i][j]=dp[i][j-1];
                    str[i][j]=str[i][j-1];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    str[i][j]=min(str[i-1][j],str[i][j-1]);
                }
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        string X,Y;
        cin>>X>>Y;
        int m=X.length();
        int n=Y.length();
        LCS(X,Y,m,n);
        printf("Case %d: ",t);
        if(dp[m][n]) cout<<str[X.length()][Y.length()]<<"\n";
        else cout<<":("<<endl;
    }
    return 0;
}
