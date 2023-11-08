#include "testlib.h"
#include<cstring>
#include<iostream>
using namespace  std;

const int maxn=1e5+5;
struct AS{
    int nxt_L[maxn],nxt_R[maxn];
}G,H;
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int T=inf.readInt();
    while(T--){
        
        int user_out_n=ouf.readInt();ouf.readChar();
        string user_out=ouf.readString();
        int N=inf.readInt(),K=inf.readInt();inf.readChar();
        string user_in=inf.readString();
        // cout<<user_in<<endl;
        int std_N=ans.readInt();ans.readChar();
        ans.readString();

        if(user_out_n!=std_N) quitf(_wa,"The answer is wrong");
        int cnt=0;
        if(N!=user_out.size()) quitf(_wa,"The answer is wrong");
        for (auto e:user_out){
            if(e!='.'&&e!='G'&&e!='H') quitf(_wa,"The answer is wrong");
            if(e!='.') cnt++;
        }
        if(cnt!=user_out_n) quitf(_wa,"The answer is wrong");

        
        G.nxt_L[0]=H.nxt_L[0]=-K-2;
        for(int i=0;i<N;i++) {
            if(i!=0) G.nxt_L[i]=G.nxt_L[i-1],H.nxt_L[i]=H.nxt_L[i-1];
            if(user_out[i]=='G') G.nxt_L[i]=i;
            if(user_out[i]=='H') H.nxt_L[i]=i;
        }

        G.nxt_R[N-1]=H.nxt_R[N-1]=N+K+2;
        for(int i=N-1;i>=0;i--){
            if(i!=N-1) G.nxt_R[i]=G.nxt_R[i+1],H.nxt_R[i]=H.nxt_R[i+1];
            if(user_out[i]=='G') G.nxt_R[i]=i;
            if(user_out[i]=='H') H.nxt_R[i]=i;
        }
        
        for(int i=0;i<N;i++){
            if(user_in[i]=='G') 
                if(i-G.nxt_L[i]>K&&G.nxt_R[i]-i>K) 
                    quitf(_wa,"The answer is wrong");
            
            if(user_in[i]=='H') 
                if(i-H.nxt_L[i]>K&&H.nxt_R[i]-i>K) 
                    quitf(_wa,"The answer is wrong");
        }

        for(int i=0;i<N;i++) G.nxt_L[i]=G.nxt_R[i]=H.nxt_L[i]=H.nxt_R[i]=0;
    }
    quitf(_ok, "The answer is correct.");
    return 0;
}
