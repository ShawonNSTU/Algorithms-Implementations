#include <bits/stdc++.h>
#define MAX 10000000
char prime[MAX];
void seive()
{
    int i,j,x;
    x=sqrt(MAX);
    prime[0]=prime[1]=1;
    for(i=4;i<=MAX;i+=2) prime[i]=1;
    for(i=3;i<=x;i+=2){
        for(j=i*i;j<=MAX;j+=i)
            prime[j]=1;
    }
}
int get_power(int i,int n)
{
    int power=0;
    while(n>1){
        power+=n/i;
        n/=i;
    }
    return power;
}
int main()
{
    seive();
    int n,power;
    scanf("%d",&n);
    power=get_power(2,n);
    if(power>0) printf("%d^%d ",2,power);
    for(int i=3;i<=n;i+=2){
        if(prime[i]!=1){
            power=get_power(i,n);
            if(power>0) printf("%d^%d ",i,power);
        }
    }
    return 0;
}
