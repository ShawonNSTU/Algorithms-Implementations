#include<bits/stdc++.h>
#define LL long long
#define mx 100005
using namespace std;

LL arr[mx];
LL n,q;

struct info {
    LL prop, sum;
} tree[mx * 4];

void Clear()
{
    for(LL i=1;i<=n*4;i++){
        tree[i].sum = 0;
        tree[i].prop=0;
    }
}

void build(LL node, LL a, LL b)
{
    if (a == b) {
        tree[node].sum = arr[a];
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    build(Left, a, mid);
    build(Right, mid + 1, b);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(LL node, LL a, LL b, LL i, LL j, LL value)
{
    if (i > b || j < a)
        return;
    if (a >= i && b <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[node].sum += ((b - a + 1) * value); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
        tree[node].prop += value; //নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }
    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;
    update(Left, a, mid, i, j, value);
    update(Right, mid + 1, b, i, j, value);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (b - a + 1) * tree[node].prop;
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}

LL query(LL node, LL a, LL b, LL i, LL j, LL carry = 0)
{
    if (i > b || j < a)
        return 0;

    if (a >= i and b <= j)
        return tree[node].sum + carry * (b - a + 1); //সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা

    LL Left = node << 1;
    LL Right = (node << 1) + 1;
    LL mid = (a + b) >> 1;

    LL q1 = query(Left, a, mid, i, j, carry + tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    LL q2 = query(Right, mid + 1, b, i, j, carry + tree[node].prop);

    return q1 + q2;
}

int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--){
    scanf("%lld %lld",&n,&q);

    for(LL i=1;i<=n;i++) scanf("%d",&arr[i]);

    build(1,1,n);

    for(int i=1;i<=q;i++){
        LL u;
        scanf("%lld",&u);
        if(u==0){
            LL p,q,v;
            scanf("%lld %lld %lld",&p,&q,&v);
            update(1,1,n,p,q,v);
        }
        if(u==1){
            LL p,q;
            scanf("%lld %lld",&p,&q);
            printf("%lld\n",query(1,1,n,p,q));
        }
    }
    /* clear */
    Clear();
    }
    return 0;
}
