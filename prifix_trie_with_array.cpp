#include<bits/stdc++.h>
using namespace std;
#define MAX_NODE 1000000
int node[MAX_NODE][130];
int root,nnode;
bool isword[MAX_NODE];
void initialize()
{
    root = 0;
    nnode = 0;
    for(int i=45;i<130;i++) node[root][i] = -1;
}
void insert()
{
    string S;
    cin>>S;
    int len = S.size();
    int now = 0;
    for(int i=0;i<len;i++){
        if(node[now][S[i]]==-1) node[now][S[i]]=++nnode;
        for(int j=45;j<130;j++) node[nnode][j] = -1;
        now = node[now][S[i]];
    }
    isword[now]=1;
}
bool search(string S)
{
    int len = S.size();
    int now = 0;
    bool flag=0;
    for(int i=0;i<len;i++){
        if(node[now][S[i]]!=-1){
            now=node[now][S[i]];
        }
        else{
            flag=1;
            break;
        }
    }
    if(!flag&&isword[now]==1) return true;
    return false;
}
int main()
{
    int word;
    printf("Number of word: ");
    scanf("%d ",&word);
    initialize();
    for(int i=1;i<=word;i++) insert();
    int query;
    printf("Number of Query: ");
    scanf("%d ",&query);
    for(int i=1;i<=query;i++){
        string S;
        cin>>S;
        if(search(S)==true) printf("FOUND\n");
        else printf("NOT FOUND\n");
    }
    return 0;
}
