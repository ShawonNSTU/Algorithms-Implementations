#include <bits/stdc++.h>
int phi(int n)
{
    int result=n; // Initialize result as n

/*  Procedure: The idea is to count all prime factors and
    their multiples and subtract this count from n to get the value
    of Totient Function.(Prime factors and multiples of prime factors won't
    have GCD as 1).
    Suppose, n=10 then the prime factor of 10 is 2,5
    then multiples of are 2 are 2,4,6,8,10 so,
    GCD(2,10),GCD(4,10),GCD(6,10),GCD(8,10),GCD(10,10) > 1.
    so, we can subtract this count (n/p) from n.
    After this procedure  if n > 1 then we can assume that n is a prime or,
    n has a prime factor greater than sqrt(n).
    then we have to subtract the multiples of this prime.
    Suppose, above example 10-10/2 = 5 now, 5 is a prime number. or, the prime factor
    of 10 is 2,5. The sqrt of 10 is 3.16 so, we can see that one prime factor is greater than sqrt(n).
*/
    for(int p=2;p*p<=n;p++){
            // Check if p is a prime factor.
        if(n%p==0){
            // If yes, then update n and result.
            while(n%p==0){
                n/=p;
            }
            result-=result/p;
        }
    }
    // if n has a prime factor greater than sqrt(n) or,
    // if n is a prime number then,
    // there can be at-most one such prime factor.
    if(n>1)
        result-=result/n;
    return result;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("phi(%d) = %d\n",n,phi(n));
    return 0;
}
