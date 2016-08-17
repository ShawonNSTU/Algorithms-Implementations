#include <stdio.h>
int main()
{
    int t,ara[10000],number,i,j,carry,digit_counter,mul;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&number);
        ara[0]=1; //initializes array with only 1 digit, the digit 1.
        digit_counter=1;
        carry=0;
        for(i=1;i<=number;i++){
            for(j=0;j<digit_counter;j++){
                mul=ara[j]*i+carry; // this variable contains the digit by digit product
                ara[j]=mul%10; // contains the digit to store in position j
                carry=mul/10;
            }
            while(carry>0){ // while loop that will store the carry value on array
                ara[digit_counter]=carry%10;
                carry/=10;
                digit_counter++; // increments digit counter
            }
        }
        for(i=digit_counter-1;i>=0;i--) //printing answer
            printf("%d",ara[i]);
        printf("\n");
    }
    return 0;
}
