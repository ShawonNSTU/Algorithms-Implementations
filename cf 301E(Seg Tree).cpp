#include <bits/stdc++.h>
#define mx 1000001
using namespace std;
string str;
struct info{
    int u_open,u_close,ans;
};
info tree[mx*4];
void build(int node,int a,int b)
{
    if(a==b){
        if(str[a]=='('){
            tree[node].u_open=1;
            tree[node].u_close=0;
        }
        else{
            tree[node].u_open=0;
            tree[node].u_close=1;
        }
        tree[node].ans=0;
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    build(left,a,mid);
    build(right,mid+1,b);
    tree[node].ans=tree[left].ans+tree[right].ans;
    int x=min(tree[left].u_open,tree[right].u_close);
    tree[node].ans+=x;
    tree[node].u_open=tree[right].u_open+(tree[left].u_open-x);
    tree[node].u_close=tree[left].u_close+(tree[right].u_close-x);
}
pair<int,pair<int,int> > query(int node,int a,int b,int i,int j)
{
    if(i>b||j<a) return make_pair(0,make_pair(0,0));
    if(a>=i and b<=j){
        return make_pair(tree[node].u_open,make_pair(tree[node].u_close,tree[node].ans));
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    pair<int,pair<int,int> > q1=query(left,a,mid,i,j);
    pair<int,pair<int,int> > q2=query(right,mid+1,b,i,j);
    int Ans=q1.second.second+q2.second.second;
    int X=min(q1.first,q2.second.first);
    Ans+=X;
    int U_open=q2.first+(q1.first-X);
    int U_close=q1.second.first+(q2.second.first-X);
    return make_pair(U_open,make_pair(U_close,Ans));
}
int main()
{
    ios_base::sync_with_stdio(true);

    int m,n,a,b;
    cin>>str;
    n=str.size();
    build(1,0,n-1);
    cin>>m;
    while(m--){
        cin>>a>>b;
        --a,--b;
        pair<int,pair<int,int> > p=query(1,0,n-1,a,b);
        cout<<p.second.second*2<<"\n";
    }
    return 0;
}
