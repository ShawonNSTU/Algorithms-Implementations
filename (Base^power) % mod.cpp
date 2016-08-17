// Calculate value of (Base ^ Power) % Mod
#include <bits/stdc++.h>
long long int BIG_MOD(long long base,int power,int mod);
int main()
{
    long long base;
    int power,mod;
    printf("Enter Base: ");
    scanf("%lld",&base);
    printf("Enter Power: ");
    scanf("%d",&power);
    printf("Enter Mod: ");
    scanf("%d",&mod);
    printf("%d\n",BIG_MOD(base,power,mod)); // Function Calling. . .
    return 0;
}
// BIG MOD FUNCTION
long long int BIG_MOD(long long base,int power,int mod)
{
    if(!power) return 1; // If power is 0, then Base ^ 0 = 1 for any value of a, so return 1
    if(power%2) return ((base%mod)*BIG_MOD(base,power-1,mod))%mod; // If power is odd, split it : Base ^ 5 = ( Base )*(Base ^ 4) --> left and right child respectively
    else{
        long long c=BIG_MOD(base,power/2,mod); // If power is even then split it equally and return the result...
        return ((c%mod)*(c%mod))%mod;
    }
}
