#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    double digit=0;
    cin>>a>>b;
    for(int i=1;i<=b;i++)
        digit+=log10(a);
    cout<<ceil(digit)<<endl;
    return 0;
}
