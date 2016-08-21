#include <bits/stdc++.h>
using namespace std;
void base_conversion(char str[50],int base1,int base2)
{
    int i,r,digit,n=0,b=1,count=0;
    for(i=strlen(str)-1;i>=0;i--){
        if(str[i]>='A'&&str[i]<='Z') digit=str[i]-'0'-7;
        else digit=str[i]-'0';
        n=digit*b+n;
        b=b*base1;
    }
    while(n!=0){
        r=n%base2;
        digit='0'+r;
        if(digit>'9') digit+=7;
        str[count++]=digit;
        n/=base2;
    }
    for(i=count-1;i>=0;i--) printf("%c",str[i]);
}
int main()
{
    char str[50];
    int base1,base2;
    printf("Enter the number: ");
    cin>>str;
    printf("Enter the base: ");
    scanf("%d",&base1);
    printf("Enter the base to be converted: ");
    scanf("%d",&base2);
    base_conversion(str,base1,base2);
    return 0;
}
