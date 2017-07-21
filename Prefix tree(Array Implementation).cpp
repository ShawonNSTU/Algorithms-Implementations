#include <bits/stdc++.h>
using namespace std;
#define MAX_NODE 1000005
int tree[MAX_NODE][130];
int root,nnode;
bool end_of_word[MAX_NODE];
void build_root()
{
    root = 0;
    nnode = 0;
    for(int i=45; i<130; i++) tree[root][i] = -1;
}
void Insert()
{
    string S;
    cin>>S;
    int len = S.size();
    int now = root;
    for(int i=0; i<len; i++){
        if(tree[now][S[i]] == -1) tree[now][S[i]] = ++nnode;
        for(int j=45; j<130; j++) tree[nnode][j] = -1;
        now = tree[now][S[i]];
    }
    end_of_word[now] = 1;
}
bool Search(string S)
{
    int len = S.size();
    int now = root;
    bool flag = true;
    for(int i=0; i<len; i++){
        if(tree[now][S[i]] != -1){
            now = tree[now][S[i]];
        }
        else{
            flag = false;
            break;
        }
    }
    if(flag && end_of_word[now] == 1) return true;
    return false;
}
int main()
{
    int word;
    cin>>word;
    build_root();
    for(int i=1; i<=word; i++) Insert();
    int query;
    cin>>query;
    for(int i=1; i<=query; i++){
        string S;
        cin>>S;
        if(Search(S)) cout<<"FOUND\n";
        else cout<<"NOT FOUND\n";
    }
    return 0;
}
