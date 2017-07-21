#include <bits/stdc++.h>
#define MAX_NODE 1000005
using namespace std;
int tree[MAX_NODE][26],outside[MAX_NODE];
int root,nnode,mx;
string ans;
map<string,int>mp;
void build_root()
{
    root = 0;
    nnode = 0;
    for(int i=0; i<26; i++) tree[root][i] = -1;
    ans.clear();
    mp.clear();
    for(int i=0; i<MAX_NODE; i++) outside[i] = 0;
}
void Insert(string S)
{
    int len = S.size();
    int now = root;
    string str;
    for(int i=0; i<len; i++){
        if(tree[now][S[i]-'A'] == -1){
            tree[now][S[i]-'A'] = ++nnode;
            outside[now] = 1;
        }
        for(int j=0; j<26; j++) tree[nnode][j] = -1;
        now = tree[now][S[i]-'A'];
        str.push_back(S[i]);
        if(outside[now] == 1){
            int str_len = str.size();
            if(mx<str_len){
                mx = str_len;
                ans = str;
                mp[str]++;
            }
        else if(mx == str_len){
                if(str<ans) ans = str;
                mp[str]++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        build_root();
        string S;
        cin>>S;
        int idx = 0;
        mx = 0;
        int len = S.size();
        while(idx != len){
            string s;
            for(int i=idx; i<len; i++){
                s.push_back(S[i]);
            }
            ++idx;
            Insert(s);
        }
        if(ans.size() !=0 ){
            cout<<ans<<" "<<mp[ans] + 1<<endl;
        }
        else cout<<"No repetitions found!\n";
    }
    return 0;
}
