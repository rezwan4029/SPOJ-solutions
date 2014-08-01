/*
    Rezwan_4029 , AUST
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define makeUnique(a) a.resize(unique(a.begin(), a.end()) - a.begin())
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");printf("%2d",a[i][j]);}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print
template<class T> inline void MAX(T &a , T b){ if (a < b ) a = b;}
template<class T> inline void MIN(T &a , T b){ if (a > b ) a = b;}

//Fast Reader
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
const int MX = 1e5 + 7 ;
int N ;
pll tree[ MX << 2 ];
int par[MX<<2];
pll merge(pll a , pll b ){
    Long z[5];
    z[0] = a.ff ;
    z[1] = a.ss ;
    z[2] = b.ff ;
    z[3] = b.ss ;
    sort(z,z+4);
    return mp( z[2] , z[3] );
}
void build(int v , int tl , int tr ){
    if( tl == tr ){
        int x ; read(x);
        tree[v] = mp(x,0);
        par[tl] = v ;
    }else {
        int tm = ( tl + tr ) / 2 ;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        tree[v] = merge( tree[v*2] , tree[v*2+1] );
    }
}
pll query(int v , int tl , int tr , int x , int y ) {
    if( x <= tl and tr <= y ){
        return tree[v];
    }
    if( tl > y or tr < x ) return make_pair(0,0) ;
    int tm = ( tr + tl ) / 2 ;
    if( y <= tm  )
        return query(v*2,tl,tm,x,y);
    else if( x > tm )
        return query(v*2+1,tm+1,tr,x,y);
    else
        return merge( query(v*2,tl,tm,x,y) , query(v*2+1,tm+1,tr,x,y) );
}
void update(int i , int x ){
    int v = par[i];
    tree[v] = mp( x , 0 ) ;
    v /= 2 ;
    while( v > 0 ){
        tree[v] = merge( tree[v*2] , tree[v*2+1] );
        v >>= 1 ;
    }
}
char que[5];
int main() {
    //FI ;
    read(N);
    build(1,1,N);
    int l , r , pos , x , Q ;
    read(Q);
    while(Q--){
        scanf("%s",que);
        if( que[0] == 'Q' ){
            read(l) , read(r);
            pll ans = query(1,1,N,l,r);
            printf("%lld\n",ans.ff+ans.ss);
        }else {
            read(pos) , read(x);
            update(pos,x);
        }
    }
}
