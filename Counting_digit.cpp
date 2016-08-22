#include <bits/stdc++.h>
using namespace std;
int main()
{
    double number,digit;
    cin>>number;
/*
    Here,

        log10(1) = 0 because 10^0 = 1, log10(10)=1 because 10^1 = 10, log10(100)=2 because 10^2 = 100. . .
        log10() works with the power of 10. . .
*/
    digit=log10(number);
    cout<<ceil(digit)<<endl;
    return 0;
}
