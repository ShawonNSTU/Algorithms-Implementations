/*
    Email: shuvroshawon9@gmail.com
*/

#include <bits/stdc++.h>
int phi(int n)
{
    int p;
    float result=n; // Initialize result as n
    // Consider all prime factors of n
    // Formula: n*(1-1/p)...here p is the prime factor
    for(p=2;p*p<=n;p++){
        // Check if p is a prime factor.
        if(n%p==0){
            // if yes, divide all occurrences of p in n.
            while(n%p==0){
                n/=p;
            }
            result*=(1.0-(1.0/(float)p));
        }
    }
    // if n has a prime factor greater than sqrt(n) or,
    // if n is a prime number then, there can be at-most one such prime factor
    if(n>1)
        result*=(1.0-(1.0/(float)n));
    return (int)result;

}
int main()
{
    int n;
    scanf("%d",&n);
    printf("phi(%d) = %d\n",n,phi(n));
    return 0;
}
