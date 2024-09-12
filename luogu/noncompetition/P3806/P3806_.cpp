#include <bits/stdc++.h>
#define lld I64d
using namespace std ;
inline long long Readin() {
    long long K = 0 , F = 1 ; char C = ' ' ;
    while( C < '0' or C > '9' ) F = C == '-' ? -1 : 1 , C = getchar() ;
    while( C <= '9' and C >= '0' ) K = ( K << 1 ) + ( K << 3 ) + C - '0' , C = getchar() ;
    return F * K ;
}
const int MaxQ = 100 + 10 ;
const int MaxN = 10000 + 10 ;
const int MaxM = 20000 + 10 ;
const int MaxK = 10000000 + 10 ;
int N , Q , Asks[MaxQ] ;
bool Anss[MaxQ] ;
int Cnt , Head[MaxN] , To[MaxM] , Next[MaxM] , Val[MaxM] ;
inline void Add( int U , int V , int W ) {
    Next[++Cnt] = Head[U] ;
    Head[U] = Cnt ;
    To[Cnt] = V ;
    Val[Cnt] = W ;
}
int Fa[MaxN] , Size[MaxN] , D[MaxN] , Hson[MaxN] ;
bool Apr[MaxK] ;
int Depp ;
void Dfs( int Nod ) {
    Size[Nod] = 1 ;
    for(register int i = Head[Nod] ; i ; i = Next[i] ) 
        if( To[i] ^ Fa[Nod] ) {
            Fa[To[i]] = Nod ;
            D[To[i]] = D[Nod] + Val[i] ;
            Dfs( To[i] ) ;
            if( Size[To[i]] > Size[Hson[Nod]] ) Hson[Nod] = To[i] ;
            Size[Nod] += Size[To[i]] ;
        }
}
inline void C( int Nod ) {
    for(register int i = 0 ; ++i <= Q ; )
        if( Asks[i] - D[Nod] + Depp >= 0 )
            Anss[i] |= Apr[Asks[i]-D[Nod]+Depp] ;
}
void Calc( int Nod ) {
    C( Nod ) ;
    for(register int i = Head[Nod] ; i ; i = Next[i] )
        if( To[i] ^ Fa[Nod] ) Calc( To[i] ) ;
}
void Upd( int Nod ) {
    Apr[D[Nod]] = true ;
    for(register int i = Head[Nod] ; i ; i = Next[i] )
        if( To[i] ^ Fa[Nod] ) Upd( To[i] ) ;
}
void Clear( int Nod ) {
    Apr[D[Nod]] = false ;
    for(register int i = Head[Nod] ; i ; i = Next[i] )
        if( To[i] ^ Fa[Nod] ) Clear( To[i] ) ;
}
void Dfs( int Nod , bool Tag ) {
    for(register int i = Head[Nod] ; i ; i = Next[i] )
        if( To[i] ^ Fa[Nod] and To[i] ^ Hson[Nod] ) Dfs( To[i] , true ) ;
    if( Hson[Nod] ) Dfs( Hson[Nod] , false ) ;
    Depp = D[Nod] << 1 ;
    Apr[D[Nod]] = true ;
    C( Nod ) ;
    for(register int i = Head[Nod] ; i ; i = Next[i] )
        if( To[i] ^ Fa[Nod] and To[i] ^ Hson[Nod] ) Calc( To[i] ) , Upd( To[i] ) ;
    if( Tag ) Clear( Nod ) ;
}
int main() {
    freopen ("P3806.in", "r", stdin);
    freopen ("P3806_.out", "w", stdout);
    N = Readin() ;
    Q = Readin() ;
    for(register int i = 0 , U , V , W ; ++i < N ; ) {
        U = Readin() ;
        V = Readin() ;
        W = Readin() ;
        Add( U , V , W ) ;
        Add( V , U , W ) ;
    }
    for(register int i = 0 ; ++i <= Q ; Asks[i] = Readin() ) ;
    Dfs( 1 ) ;
    Dfs( 1 , false ) ;
    for(register int i = 0 ; ++i <= Q ; puts( Anss[i] ? "AYE" : "NAY" ) ) ;
    return 0 ;
}