#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
int p[MAX];
void makeset(int n)
{
    p[n]=n;
}
int Find(int r)
{
    if(p[r]==r) return r;
    else return p[r]=Find(p[r]);
}
void Union(int a,int b)
{
    int u=Find(a);
    int v=Find(b);
    if(u!=v) p[u]=v;
}
int main()
{
    int N,u,v;
    map<int,int>mymap;
    set<int>myset;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>u>>v;
        if(mymap.find(u)==mymap.end()){
            myset.insert(u);
            makeset(u);
            mymap[u]=1;
        }
        if(mymap.find(v)==mymap.end()){
            myset.insert(v);
            makeset(v);
            mymap[v]=1;
        }
        Union(u,v);
        for(set<int>::iterator it=myset.begin();it!=myset.end();++it){
        if(p[*it] == *it) cout<< *it<<endl;
    }
    }
    return 0;
}
