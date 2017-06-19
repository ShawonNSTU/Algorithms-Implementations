#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi AdjList[20005];
bool dfs_num[20005],check,flag[20005];
map<string,int>mp;
void dfs2(int u)
{
    dfs_num[u]=1;
    flag[u]=1;
    for(int j=0;j<AdjList[u].size();j++){
        int v=AdjList[u][j];
        if(flag[v]==1) check=true;
        else if(dfs_num[v]==0) dfs2(v);
    }
}
int main()
{
    string s1,s2;
    int T,m;
    cin>>T;
    for(int j=1;j<=T;j++){
        cin>>m;
        int cnt=0;
    for(int i=1;i<=m;i++){
        cin>>s1>>s2;
        if(mp[s1]==0){ ++cnt; mp[s1]=cnt;}
        if(mp[s2]==0){ ++cnt; mp[s2]=cnt;}
        AdjList[mp[s1]].push_back(mp[s2]);
    }
    memset(dfs_num,0,sizeof(dfs_num));
    for(int i=1;i<=cnt;i++){
        check=false;
        memset(flag,0,sizeof(flag));
        if(dfs_num[i]==0) dfs2(i);
        if(check==true) break;
    }
        printf("Case %d: ",j);
        if(check==true) printf("No\n");
        else printf("Yes\n");
        mp.clear();
        for(int i=1;i<=cnt;i++) AdjList[i].clear();
    }
    return 0;
}
