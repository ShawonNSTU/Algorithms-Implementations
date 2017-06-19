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
    ios_base::sync_with_stdio(true);
    int n,x;
    cin>>n;
    int correct_rank[n+1],stdnt_rank[n+1];
    for(int i=1;i<=n;i++){
        cin>>x;
        correct_rank[x]=i;
    }
    while(cin>>x){
    stdnt_rank[x]=1;
    for(int i=2;i<=n;i++){
        cin>>x;
        stdnt_rank[x]=i;
    }
        cout<<lcs(correct_rank,stdnt_rank,n+1,n+1)<<"\n";
    }
    return 0;
}
