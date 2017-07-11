#include <bits/stdc++.h>
#define N 305
using namespace std;
int length,DP[N][N];
string X,Y,S;
set<string>v;
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
                v.insert(ans);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int T=0;
    while(cin>>X>>Y){
        int m=X.length();
        int n=Y.length();
        ++T;
        if(T>1) cout<<"\n";
        length=LCS(X,Y,m,n);
        if(!length){ cout<<"No common sequence."<<"\n"; continue; }
        Backtrack(X,Y,m,n);
        for(auto it : v) cout<<it<<"\n";
        v.clear();
    }
    return 0;
}
