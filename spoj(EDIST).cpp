#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int EditDist(string str1,string str2,int m,int n)
{
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            // If first string is empty, only option is to
            // insert all characters of second string
            if(i == 0) dp[i][j] = j;  // Min. operations = j

            // If second string is empty, only option is to
            // remove all characters of second string
            else if(j == 0) dp[i][j] = i; // Min. operations = i

            // If last characters are same, ignore last char
            // and recur for remaining string
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }

    return dp[m][n];
}

// Driver program
int main()
{
    ios_base::sync_with_stdio(true);
    int t;
    cin>>t;
    while(t--){
        string str1,str2;
        cin>>str1>>str2;
        for(int i=0;i<=2004;i++){
            for(int j=0;j<=2004;j++) dp[i][j]=0;
        }
        cout <<EditDist(str1,str2,str1.length(),str2.length())<<"\n";
    }
    return 0;
}
