#include <bits/stdc++.h>
#define mx 10005
#define pii pair<int,int>

using namespace std;

int arr[mx];

struct info{
    int mx_elmnt;
    int mx_idx;
};

info tree[mx*4];

void build(int node,int a,int b)
{
    if(a==b){
        tree[node].mx_elmnt=arr[a];
        tree[node].mx_idx=a;
        return;
    }

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;

    build(Left,a,mid);
    build(Right,mid+1,b);

    tree[node].mx_elmnt=max(tree[Left].mx_elmnt,tree[Right].mx_elmnt);

    if(tree[node].mx_elmnt==tree[Left].mx_elmnt)
        tree[node].mx_idx=tree[Left].mx_idx;
    else tree[node].mx_idx=tree[Right].mx_idx;
}
pii query(int node,int a,int b,int i,int j)
{
    if(i>b||j<a) return pii(0,0);

    if(a>=i&&b<=j) return pii(tree[node].mx_elmnt,tree[node].mx_idx);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (a + b) >> 1;

    pii q1=query(Left,a,mid,i,j);
    pii q2=query(Right,mid+1,b,i,j);

    int m=max(q1.first,q2.first);

    if(m==q1.first) return q1;
    else return q2;
}
bool prime_check(int num)
{
    int i=2;
    bool is_prime=true;

    while(i<=sqrt(num)){
        if(num%i==0){
            is_prime=false;
            break;
        }
        ++i;
    }

    return is_prime;
}
int main()
{
    ios_base::sync_with_stdio(true);

    int n,T;
    cin>>T;
    for(int t=1;t<=T;t++){
        printf("Game %d:\n",t);
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

        build(1,1,n);

        int p=1,q=n,cnt=0;
        long long s=0,r=0;

        while(true){
            pii x=query(1,1,n,p,q);
            ++cnt;
            if(cnt&1) s+=x.second;
            else r+=x.second;
            if(x.second==1) break;
            else{p=1;q=x.second-1;}
        }
        bool is_prime;
        if(abs(s-r)==1){is_prime=false;goto print;}
        is_prime=prime_check(abs(s-r));

        print:
        if(is_prime==true){
            printf("Rafi=%lld Shafi=%lld\nRafi win\n",r,s);
        }
        else printf("Shafi=%lld Rafi=%lld\nShafi win\n",s,r);
    }
    return 0;
}
