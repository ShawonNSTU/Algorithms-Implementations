/*
    Email: shuvroshawon9@gmail.com
*/

#include <bits/stdc++.h>
int main()
{
    double digit=0.0;
    int number;
    scanf("%d",&number);
/*
    Here,

        log10(1) = 0 because 10^0 = 1, log10(10)=1 because 10^1 = 10, log10(100)=2 because 10^2 = 100. . .
        log10() works with the power of 10. . .

    Formula: 6! = log10(1) + log10(2) + log10(3) + log10(4) + log10(5) + log10(6)
*/
    for(int i=1;i<=number;i++)
        digit+=log10(i);
    printf("%.0lf\n",ceil(digit));
    return 0;
}
