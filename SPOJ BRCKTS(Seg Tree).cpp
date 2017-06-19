#include <bits/stdc++.h>
#define mx 30005
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
pair<int,pair<int,int> > update(int node,int a,int b,int i)
{
    if(i>b||i<a) return make_pair(tree[node].u_open,make_pair(tree[node].u_close,tree[node].ans));
    if(a==b){
        if(tree[node].u_close==1){
            tree[node].u_open=1;
            tree[node].u_close=0;
           }
        else{
            tree[node].u_open=0;
            tree[node].u_close=1;
        }
        return make_pair(tree[node].u_open,make_pair(tree[node].u_close,tree[node].ans));
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(a+b)>>1;
    pair<int,pair<int,int> > q1=update(left,a,mid,i);
    pair<int,pair<int,int> > q2=update(right,mid+1,b,i);
    int Ans=q1.second.second+q2.second.second;
    int X=min(q1.first,q2.second.first);
    Ans+=X;
    int U_open=q2.first+(q1.first-X);
    int U_close=q1.second.first+(q2.second.first-X);
    tree[node].u_open=U_open;
    tree[node].u_close=U_close;
    tree[node].ans=Ans;
    return make_pair(U_open,make_pair(U_close,Ans));
}
int main()
{
    ios_base::sync_with_stdio(true);
    int n,m,q,t=0;
    while(scanf("%d",&n)!=EOF){
        cin>>str;
        build(1,0,n-1);
        cin>>m;
        printf("Test %d:\n",++t);
        for(int i=0;i<m;i++){
            cin>>q;
            if(!q){
                if(tree[1].ans*2==n) cout<<"YES\n";
                else cout<<"NO\n";
            }
            else update(1,0,n-1,--q);
        }
    }
    return 0;
}
