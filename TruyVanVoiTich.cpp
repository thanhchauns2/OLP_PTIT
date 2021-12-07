#include <bits/stdc++.h>
#define LL long long
 
using namespace std;
 
struct node
{
    int l,r;
    LL sum,push;
};
 
const int X=150;
const int N=50010;
 
LL prime[35];
int pr;
node tree[35][N*4];
 
void init()
{
    pr=0;
    for (int i=2;i<=X;i++)
    {
        bool flag=true;
        for (int j=2;j<i;j++) if (i%j==0) flag=false;
        if (flag)
            prime[pr++]=i;
    }
}
 
void build(int idx, int t, int l, int r)
{
    tree[idx][t].l=l; tree[idx][t].r=r;
    tree[idx][t].sum=0; tree[idx][t].push=0;
    if (l==r) return;
    int mid=(l+r)/2;
    build(idx,t*2,l,mid);
    build(idx,t*2+1,mid+1,r);
}
 
void pushdown(int idx,int t)
{
    if (tree[idx][t].l!=tree[idx][t].r)
    {
        tree[idx][t*2].push+=tree[idx][t].push;
        tree[idx][t*2+1].push+=tree[idx][t].push;
        tree[idx][t*2].sum+=tree[idx][t].push*(tree[idx][t*2].r-tree[idx][t*2].l+1);
        tree[idx][t*2+1].sum+=tree[idx][t].push*(tree[idx][t*2+1].r-tree[idx][t*2+1].l+1);
 
        tree[idx][t].push=0;
    }
}
 
LL query(int idx, int t, int l, int r)
{
    if (l<=tree[idx][t].l&&tree[idx][t].r<=r)
    {
        return tree[idx][t].sum;
    }
    int mid=(tree[idx][t].l+tree[idx][t].r)/2;
    pushdown(idx,t);
    if (r<=mid)
        return query(idx,t*2,l,r);
    else
    if (l>mid)
        return query(idx,t*2+1,l,r);
    else
        return query(idx,t*2,l,mid)+query(idx,t*2+1,mid+1,r);
}
 
void update(int idx, int t, int l, int r, int x)
{
    if (l<=tree[idx][t].l&&tree[idx][t].r<=r)
    {
        tree[idx][t].push+=x;
        tree[idx][t].sum+=x*(tree[idx][t].r-tree[idx][t].l+1);
        return;
    }
    int mid=(tree[idx][t].l+tree[idx][t].r)/2;
    pushdown(idx,t);
    if (l<=mid)
        update(idx,t*2,l,r,x);
    if (r>mid)
        update(idx,t*2+1,l,r,x);
 
    tree[idx][t].sum=tree[idx][t*2].sum+tree[idx][t*2+1].sum;
}
 
LL multi(LL x, LL k,LL p)
{
    LL ans=1;
    x=x%p;
    while(k>0)
    {
        if(k%2==1) ans=(ans*x)%p;
        k=k/2;
        x=(x*x)%p;
    }
    return ans;
}
 
int main()
{
    int T,n,m,c,l,r;
    LL p;
    scanf("%d",&T);
    init();
 
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<pr;i++) build(i,1,1,n);
 
        while(m--)
        {
            scanf("%d%d%d%I64d",&c,&l,&r,&p);
            if (c==0)
            {
                LL sum=1;
                for (int i=0;i<pr;i++)
                {
                    LL x=0;
                    if (l<=r) x=query(i,1,l,r); else x=query(i,1,l,n)+query(i,1,1,r);
                    sum=(sum*multi(prime[i],(LL)x,p))%p;
                }
                cout<<sum<<endl;
            }
            if (c==1)
            {
                for (int i=0;i<pr;i++) if (p%prime[i]==0)
                {
                    int x=0;
                    while(p%prime[i]==0) {x++; p=p/prime[i];}
                    if (l<=r) update(i,1,l,r,x); else {update(i,1,l,n,x); update(i,1,1,r,x);}
                }
            }
            if (c==2)
            {
                for (int i=0;i<pr;i++) if (p%prime[i]==0)
                {
                    int x=0;
                    while(p%prime[i]==0) {x++; p=p/prime[i];}
                    if (l<=r) update(i,1,l,r,-x); else {update(i,1,l,n,-x); update(i,1,1,r,-x);}
                }
            }
        }
    }
    return 0;
}
