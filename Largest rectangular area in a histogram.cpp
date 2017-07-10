#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,mx=0,mn=100005;
    scanf("%d",&n);
    int arr[n];
    vector<int>v;
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
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
    printf("%d\n",max(mx,mn*n));
    return 0;
}
