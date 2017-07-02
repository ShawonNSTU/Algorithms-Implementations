/// Each of the numbers can exist in 2^(n-1) different subsets.
/// So, let's define sum = 2^(n-1)
/// Then sum*1 + sum*2 + .... + sum*n = 2^(n-1) * (sum of all elements)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,n;
    scanf("%d",&n);
    long long sum=0,ans=1;
    for(int i=0;i<n-1;i++) ans<<=1;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        sum+=a;
    }
    printf("%lld\n",sum*ans);
    return 0;
}
