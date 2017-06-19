#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
int parent[MAX];
int Size[MAX];
void makeset(int x)
{
    parent[x]=x; //initially all node are own's representative.
    Size[x]=1; // initially all node are own's representative and all representative's are 1.
}
int Find(int x)
{
    while(x!=parent[x])
        x = parent[x];
    return x; // return representative.
}
void Union_by_size(int x,int y)
{
    int r = Find(x); // to return u's representative.
    int s = Find(y); // to return v's representative.
    if(r==s) return;
    else if(Size[r]>Size[s]){
        parent[s] = r; // if representative of u contains more node than v's representative than ultimate parent[s] = r; and Size[r]+=Size[s];
        Size[r]+=Size[s];
    }
    else{
        parent[r] = s; // if representative of v contains more node than u's representative or equal than ultimate parent[r] = s; and Size[s]+=Size[r];
        Size[s]+= Size[r];
    }
}
int main()
{
    int n,u,v;
    cin>>n;
    for(int i=1;i<=n;i++) makeset(i);
    for(int i=1;i<=n;i++){
        cin>>u>>v;
        Union_by_size(u,v);
    }
    for(int i=1;i<=n;i++){
        int rep=Find(i);
        cout<<Size[rep]<<endl;
    }
    return 0;
}
