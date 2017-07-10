#include <bits/stdc++.h>
using namespace std;
void read(int &x)
{
    char k;
    for(k=getchar();k<=32;k=getchar());
    for(x=0;'0'<=k;k=getchar()) x=x*10+k-'0';
}
int main()
{
    int T;
    read(T);
    for(int t=1;t<=T;t++){
        int n,mx=0,mn=30005;
        read(n);
        int arr[n];
        vector<int>v;
        for(int i=0;i<n;i++){
            read(arr[i]);
            mn=min(mn,arr[i]);
        }
        for(int i=0;i<n;i++){
            if(!i or arr[v[v.size()-1]]<=arr[i]){
                v.push_back(i);
                mx=max(mx,arr[i]);
                continue;
            }
            else{
                while(true){
                    if(v.size()==0) break;
                    int m=arr[v[v.size()-1]];
                    if(m<=arr[i]) break;
                    v.pop_back();
                    if(v.size()==0) mx=max(mx,m*i);
                    else mx=max(mx,m*(i-v[v.size()-1]-1));
                }
                v.push_back(i);
            }
        }
        int i=v.size();
        while(v.size()>0){
            int m=arr[v[v.size()-1]];
            v.pop_back();
            if(v.size()==0) mx=max(mx,m*i);
            else mx=max(mx,m*(i-v[v.size()-1]-1));
        }
    printf("Case %d: %d\n",t,max(mx,mn*n));
    }
    return 0;
}
