#include <bits/stdc++.h>
// A function to print all prime factors of a given number.
void PrimeFactors(int n)
{
    int i;
    // Print the number of 2s that divide n.
    while(n%2==0){
        printf("%d ",2);
        n/=2;
    }
    // n must be odd at this point.
    for(i=3;i<=sqrt(n);i+=2){
        // while i divides n, print i and divide n.
        while(n%i==0){
            printf("%d ",i);
            n/=i;
        }
    }
    // this condition is to handle the case when n is a prime number
    // greater than 2
    if(n>2)
        printf("%d ",n);
}
int main()
{
    int n;
    scanf("%d",&n);
    PrimeFactors(n);
    return 0;
}
