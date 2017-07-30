#include <bits/stdc++.h>
#define MAX 10000000000
#define Max 100000
using namespace std;
long long m,arr[50],Copy1[50],Copy2[50];
int n;
map<long long,bool>sub;
void subsetSums(long long arr[], int n)
{
    long long total = 1<<n;
    for(long long i=0; i<total; i++){
        long long sum = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j))
                sum += arr[j];
        }
        sub[sum] = 1;
    }
    return ;
}
bool subsetSumsAgain(long long arr[], int n)
{
    long long total = 1<<n;
    for(long long i=0; i<total; i++){
        long long sum = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j))
                sum += arr[j];
        }
        if(sub[m-sum]==1) return true;
    }
    return false;
}
void getvalue()
{
    arr[0] = 2;
    arr[1] = 7;
    int i = 3;
    while(true){
        if(i%2!=0){
            long long curr = arr[i-2] + (3 * arr[i-3]);
            if(curr >= MAX) break;
            else arr[i-1] = curr;
        }
        else{
            long long curr = arr[i-1] = arr[i-2] + 7;
            if(curr >= MAX) break;
            else arr[i-1] = curr;
        }
        ++i;
    }
    n = i-1;
    int j = 0;
    for(int i=0; i<n/2; i++){
        Copy2[j] = arr[i];
        ++j;
    }
    j = 0;
    for(int i=n/2; i<n; i++){
        Copy1[j] = arr[i];
        ++j;
    }
    return ;
}
int main()
{
    int T;
    scanf("%d",&T);
    getvalue();
    subsetSums(Copy2,16);
    while(T--){
        scanf("%lld",&m);
        if(m > Max){
            if(subsetSumsAgain(Copy1,16))
                printf("YES\n");
            else printf("NO\n");
        }
        else{
            if(sub[m]){
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
    return 0;
}
