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
typedef vector<pll> vpii;

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
int N , Q , p , q , X ;
int Start[MX] , End[MX] , nB , A[MX] , Idx[MX];
vi Blk[MX];
int BS( vi vec , int val ){
    int cnt = upper_bound( vec.begin() , vec.end() , val ) - vec.begin() ;
    return cnt ;
}
int main(){
    //FI ;
    read(N) , read(Q);
    int SQRT = sqrt(N);
    for( int j , i = 1 ; i <= N ; i += SQRT ) {
        ++nB;
        Start[ nB ] = i ; // Start of this block
        for( j = i ; j < i + SQRT && j <= N ; j++ ){
            read( A[j] );
            Idx[j] = nB ; // means jth element is in nB-th block
            Blk[ nB ].push_back( A[j] );
        }
        End[ nB ] = j - 1 ; // End of this block
        sort( Blk[ nB ].begin() , Blk[ nB ].end() );
    }
    while(Q--){
        char que[3];
        scanf("%s",&que);
        if( que[0] == 'C' ){
            read(p) , read(q) , read(X);
            int Ans = 0 ;
            for( int i = Idx[p] ; i <= Idx[q] ; i++ ){
                if( p <= Start[i] && q >= End[i] ) { // If the range full of the current block
                    Ans += BS(Blk[i],X);
                }else {
                    for( int j = max(Start[i],p) ; j <= min(End[i],q) ; j++ ) // if range have some portion in this blocks
                        Ans += ( A[j] <= X ) ;
                }
            }
            printf("%d\n",Ans);
        }else {
            read(p) , read(X);
            int bNo = Idx[p] ; // find the block number of pTh position
            for( int i = 0 ; i < Blk[ bNo ].size() ; i++ ){
                if( Blk[ bNo ][i] == A[p] ) {
                    A[p] = X ;
                    A[p] = Blk[ bNo ][i] = X ;
                    sort( Blk[ bNo ].begin() , Blk[ bNo ].end() );
                    break ;
                }
            }
        }
    }
}
