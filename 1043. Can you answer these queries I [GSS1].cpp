#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
#define rep(i,n) for( __typeof(n)i = 0 ; i < n ; i++ )
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++ )
#define forstl(i,n) for(__typeof(n.begin()) i = n.begin() ; i != n.end() ; i++)
typedef long long ll;

#define SZ 50007

int a[SZ];

struct SegmentTree{ int prefixSum , suffixSum ,Sum ,maxSum ; };

SegmentTree tree[ SZ<<3 ];

SegmentTree merge( SegmentTree a , SegmentTree b)
{
    SegmentTree res ;

    res.Sum = a.Sum + b.Sum ;

    res.maxSum = max( max( a.maxSum , b.maxSum ) , (a.suffixSum + b.prefixSum ) ) ;

    res.prefixSum = max( a.prefixSum , a.Sum + b.prefixSum );

    res.suffixSum = max( b.suffixSum , b.Sum + a.suffixSum );

    return res ;
}

void BUILD(int node , int start , int end)
{
        if(start == end)
        {
            int X;  scanf("%d",&X);

            tree[node].prefixSum = tree[node].suffixSum = tree[node].Sum = tree[node].maxSum = X ;

            return ;
        }

        int l = node<<1 ;
        int r = node<<1|1;

        int mid = (start + end )>>1;

        BUILD(l,start,mid);
        BUILD(r,mid+1,end);

        tree[ node ] = merge( tree[l] , tree[r] );
}


SegmentTree Query(int node , int start , int end , int x , int y)
{
    if(start == x && end == y) return tree[node];

    int l = node<<1 ;
    int r = node<<1|1;

    int mid = (start + end )>>1;

    if(y <= mid ) return Query(l,start,mid,x,y); // whole side is in left

    else if( x > mid ) return Query(r,mid+1,end,x,y) ; // whole side is in right

    else
    {
        return merge( Query(l,start,mid,x,mid) , Query(r,mid+1,end,mid+1,y)  ) ; // split in two side so merging
    }
}
int main()
{
    int N ;
    while(scanf("%d",&N)==1)
    {
        BUILD(1,1,N);

        int Q ; scanf("%d",&Q);

        while(Q--)
        {
            int x , y ;
            scanf("%d %d",&x,&y);
            printf("%d\n",Query(1,1,N,x,y).maxSum );
        }
    }
}

