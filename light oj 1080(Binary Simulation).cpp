#include <bits/stdc++.h>
#define mx 100005
using namespace std;
string s;
int n,q,mx_node,mx_carry;
struct info {
    int invert;
    vector<int>v;
};
info tree[mx*3];
void Clear()
{
    for(int i=1;i<=mx_node;i++){
        tree[i].invert=0;
        tree[i].v.clear();
    }
}
void build(int node, int a, int b)
{
    if (a == b){
        tree[node].v.push_back(s[a]-48);
        mx_node=max(mx_node,node);
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid + 1, b);
    copy(tree[Left].v.begin(),tree[Left].v.end(),back_inserter(tree[node].v));
    copy(tree[Right].v.begin(),tree[Right].v.end(),back_inserter(tree[node].v));
}
void update(int node, int a, int b, int i, int j)
{
    if (i > b || j < a)
        return;
    if (a >= i && b <= j){
        tree[node].invert+=1;
        return;
    }
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;
    update(Left, a, mid, i, j);
    update(Right, mid + 1, b, i, j);
}
void query(int node, int a, int b, int i, int carry=0)
{
    if(node>mx_node)
        return;
    if (i >= a and i <= b){
        carry+=tree[node].invert;
        if(carry>mx_carry)
            mx_carry=carry;
    }
    else
        return;

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;
    query(Left, a, mid, i, carry);
    query(Right, mid + 1, b, i, carry);
}
int main()
{
   int t,p,Q;
   char ch;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
    printf("Case %d:\n",tt);
    cin>>s;
    scanf("%d",&Q);
    int len=s.size();
    mx_node=1;
    build(1,0,len-1);
    for(int i=1;i<=Q;i++){
        scanf(" %c",&ch);
        if(ch=='I'){
            scanf("%d %d",&p,&q);
            --p,--q;
            update(1,0,len-1,p,q);
        }
        else{
            scanf("%d",&p);
            --p;
            mx_carry=0;
            query(1,0,len-1,p);
            int div=mx_carry/2;
            if(div*2==mx_carry)
                printf("%c\n",s[p]);
            else{
                if(s[p]=='0') printf("1\n");
                else printf("0\n");
            }
        }
    }
    Clear();
   }
   return 0;
}
