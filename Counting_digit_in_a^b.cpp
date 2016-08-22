/*
    Email: shuvroshawon9@gmail.com
*/

#include <bits/stdc++.h>
int main()
{
    int a,b;
    double digit=0;
    scanf("%d %d",&a,&b);
/*
    Here,

        log10(1) = 0 because 10^0 = 1, log10(10)=1 because 10^1 = 10, log(100)=2 because 10^2 = 100. . .
        log10() works with the power of 10. . .

    Formula: 4^5 = log10(4)+log10(4)+log10(4)+log10(4)+log10(4)
*/
    for(int i=1;i<=b;i++)
        digit+=log10(a);
    printf("%.0lf\n",ceil(digit));
    return 0;
}
