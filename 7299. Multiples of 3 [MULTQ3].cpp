/*
    Rezwan_4029
    AUST , CSE-25
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<sstream>
#include<set>
#define pb push_back
#define ms(a,v) memset(a,v,sizeof a)
using namespace std;
typedef long long ll;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++)
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
#define forstl(i,n) for(__typeof(n.begin())i = n.begin();i!=n.end();i++)

#define mx 100005
int tree[mx<<2][3];
int Lazy[mx<<2];
int swap1(int &a,int &b,int &c)
{
    int ta = a ,tb = b ,tc = c;
    a = tc;
    b = ta;
    c = tb;
}
int swap2(int &a,int &b,int &c)
{
    int ta = a ,tb = b ,tc = c;
    c = ta;
    a = tb;
    b = tc;
}
void propagate(int at,int left,int right)
{
     if( left != right )
     {
            Lazy[at*2] = (Lazy[at] + Lazy[at*2])%3;
            Lazy[at*2+1] = (Lazy[at] + Lazy [at*2+1])%3;
     }
     if( Lazy[at]==1 )
     {
            swap1(tree[at][0],tree[at][1],tree[at][2]);
     }
     if( Lazy[at]==2 )
     {
            swap2(tree[at][0],tree[at][1],tree[at][2]);
     }

    Lazy[at] = 0;      // reset the lazy value of current node
}


void Build(int at , int left , int right)
{

    if( left == right )
    {
        tree[at][0] = 1;
        tree[at][1] = tree[at][2] = 0;
        return ;
    }
    int mid = (left + right)>>1;

    Build(at<<1,left,mid);
    Build(at<<1|1,mid+1,right);

    tree[at][1] = tree[at][2] = 0;
    tree[at][0] = tree[at<<1][0] + tree[at<<1|1][0];
}

int Query(int at,int left ,int right , int start ,int end)
{

    if(Lazy[at]) propagate(at,left,right);
    if( start > right || end < left) return 0 ;
    if( start <= left && end >= right)
    {
        return tree[at][0];
    }
    int mid = (left+right)>>1;

    return Query(at*2,left,mid,start,end) + Query(at*2+1,mid+1,right,start,end);
}

void Update(int at,int left,int right,int start,int end)
{
    if(Lazy[at]) propagate(at,left,right);

    if(start > right || end < left) return ;
    if(left>=start && right<=end)
    {
        if( left != right )
        {
            Lazy[at*2] =   (1 + Lazy[at*2])%3;
            Lazy[at*2+1] = (1 + Lazy [at*2+1])%3;
        }

        swap1(tree[at][0],tree[at][1],tree[at][2]);
        return ;
    }

    int mid = (left+right)>>1;

    Update(at*2,left,mid,start,end);
    Update(at*2+1,mid+1,right,start,end);

    tree[at][0] = tree[at<<1][0] + tree[at<<1|1][0];
    tree[at][1] = tree[at<<1][1] + tree[at<<1|1][1];
    tree[at][2] = tree[at<<1][2] + tree[at<<1|1][2];
}
int main()
{
        int T  ,i , q ,n;

        scanf("%d %d",&n,&q);

        Build(1,1,n);

        while( q-- )
        {
            int typ , x , y;
            scanf("%d %d %d",&typ,&x,&y);
            x++,y++;
            if( typ == 0)
            {
                Update(1,1,n,x,y);
            }
            else if( typ == 1)
            {
                int ans = Query(1,1,n,x,y);
                printf("%d\n",ans);
            }
        }

    return 0;
}


