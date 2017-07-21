#include <bits/stdc++.h>
using namespace std;
#define MAX_NODE 100005
int tree[MAX_NODE][11];
int root,nnode;
bool end_of_word[MAX_NODE],check;

void build_root()
{
    root = 0;
    nnode = 0;
    for(int i=0; i<11; i++) tree[root][i] = -1;
    for(int i=0; i<MAX_NODE; i++) end_of_word[i]=0;
}
void Insert(string S)
{
    int len = S.size();
    int now = root;
    for(int i=0; i<len; i++){
        if(tree[now][S[i]-48] == -1) tree[now][S[i]-48] = ++nnode;
        for(int j=0; j<11; j++) tree[nnode][j] = -1;
        now = tree[now][S[i]-48];
        if(end_of_word[now] == 1) check = true;
    }
    end_of_word[now] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        vector<pair<int,string> >v;
        int n;
        build_root();
        check=false;
        cin>>n;
        cout<<"Case "<<t<<": ";
        for(int i=1; i<=n; i++){
            string S;
            cin>>S;
            v.push_back(make_pair(S.length(),S));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            Insert(v[i].second);
        }
        if(check) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
