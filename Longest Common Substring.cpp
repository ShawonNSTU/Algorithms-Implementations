#include <bits/stdc++.h>
#define N 1005
using namespace std;
int length,DP[N][N];
string X,Y,S;
vector<string>v;
int LCS(string X,string Y,int m,int n)
{
    int mx=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0) DP[i][j]=0;
            else if(X[i-1]==Y[j-1]) DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=0;
            mx=max(mx,DP[i][j]);
        }
    }
    return mx;
}
string PrintLCS(int i,int j)
{
    if(i==0 or j== 0 or !DP[i][j]){
        S="";
        return S;
    }
    PrintLCS(i-1,j-1);
    S.push_back(X[i-1]);
    return S;
}
void Backtrack(string X,string Y,int m,int n)
{
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(DP[i][j]==length){
                string ans= PrintLCS(i,j);
                v.push_back(ans);
            }
        }
    }
}
int main()
{
    cin>>X>>Y;
    int m=X.length();
    int n=Y.length();
    length=LCS(X,Y,m,n);
    printf("%d\n",length);
    Backtrack(X,Y,m,n);
    for(auto it : v) cout<<it<<"\n";
    return 0;
}
