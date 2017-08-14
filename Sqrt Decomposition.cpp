#include <bits/stdc++.h>
#define MAXN 100005
#define SQRSIZE 500
using namespace std;

int arr[MAXN];               // original array
int block[SQRSIZE];          // decomposed array
int blk_sz;                  // block size

// Time Complexity : O(1)

void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

// Time Complexity : O(sqrt(n))

int query(int l, int r)
{
    int sum = 0;
    while(l<r and l%blk_sz!=0 and l!=0){
        // traversing first block in range
        sum += arr[l];
        l++;
    }
    while(l + blk_sz <= r){
        // traversing completely overlapped blocks in range
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while(l <= r){
        // traversing last block in range
        sum += arr[l];
        l++;
    }
    return sum;
}

// Building the blocks

void preprocess(int input[], int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array
    for(int i=0; i<n; i++){
        arr[i] = input[i];
        if (i%blk_sz == 0){
            // entering next block
            // incrementing block pointer
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
    return ;
}

int main()
{
    int n;
    scanf("%d",&n);
    int input[n];
    for(int i=0; i<n; i++){
        scanf("%d",&input[i]);
    }
    preprocess(input,n);
    int t,l,r,q;
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        scanf("%d %d %d",&t,&l,&r);
        if(t){
            printf("%d\n",query(l,r));
        }
        else{
            update(l,r);
        }
    }
    return 0;
}
