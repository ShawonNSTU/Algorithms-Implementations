#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi ts,AdjList[1005],RevList[1005],Component[1005];
bool visited[1005];
void dfs(int u)
{
    visited[u]=1;
    for(int i : AdjList[u]){
        if(!visited[i]) dfs(i);
    }
    ts.push_back(u);
}
void findSCC(int u,int mark)
{
    Component[mark].push_back(u);
    visited[u]=1;
    for(int i : RevList[u]){
        if(!visited[i]) findSCC(i,mark);
    }
}
Clear(int n)
{
    for(int i=1;i<=n;i++){
        AdjList[i].clear();
        RevList[i].clear();
        Component[i].clear();
    }
    ts.clear();
}
int main()
{
    int n,e,t=0;
    while(cin>>n>>e){
        map<string,int>mp;
        vector<string>str;
        if(!n&&!e) break;
        ++t;
        if(t>1) cout<<"\n";
        string u,v;
        int mark=0,cnt=1;
        for(int i=1;i<=e;i++){
            cin>>u>>v;
            if(mp.find(u)==mp.end()){
                mp[u]=cnt++;
                str.push_back(u);
            }
            if(mp.find(v)==mp.end()){
                mp[v]=cnt++;
                str.push_back(v);
            }
            AdjList[mp[u]].push_back(mp[v]);
            RevList[mp[v]].push_back(mp[u]);
        }
        /** Topological Sort **/
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++){
            if(!visited[i]) dfs(i);
        }
        memset(visited,0,sizeof(visited));
        reverse(ts.begin(),ts.end());
        /** SCC **/
        for(int i : ts){
            if(!visited[i]){
                ++mark;
                findSCC(i,mark);
            }
        }
        cout<<"Calling circles for data set "<<t<<":\n";
        for(int i=1;i<=mark;i++){
            int Size=Component[i].size();
            for(int j=0;j<Size;j++){
                cout<<str[Component[i][j]-1];
                if(j+1!=Size){
                    cout<<", ";
                }
            }
            cout<<"\n";
        }
        Clear(n);
    }
    return 0;
}
