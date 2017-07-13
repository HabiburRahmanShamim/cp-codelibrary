/* Template Code Begins*/

#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define FOR(i,N) FORR(i, 0, N)
#define FORR(i,a,b) FOTR(i, a, b, 1)
#define FOTR(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define FOREACH(it, x) for(__typeof__((x).begin()) it=(x).begin();it!=(x).end();it++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define BCHK(a,x) (((a)>>(x))&1)
#define BSET(a,x) ((a)|(1<<(x)))
#define BCLR(a,x) ((a)&(~(1<<(x))))
#define BTGL(a,x) ((a)^(1<<(x)))
#define FMT(...) (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
#define read() freopen("C:\\Users\\fahim\\Documents\\GIT\\PCTemplate\\Clion_IO\\input.txt","r",stdin)
#define write() freopen("C:\\Users\\fahim\\Documents\\GIT\\PCTemplate\\Clion_IO\\output.txt","w",stdout)
#define cpp_io() {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define BUFFSIZE 30000
#define INF 1000000000
#define MAX 300001
#define MOD 1000000007
#define pb push_back
#define mkpr make_pair
#define pii pair<int, int>
#define PI acos(-1)
#define ll long long

char CRTBUFF[BUFFSIZE];
#define dbg(args...) {cout<<"-->";debugger::call(#args,args);cout<<"\n";}
struct debugger {
    static void call(const char* it) {}
    template<typename T, typename ... aT>
    static void call(const char* it, T a, aT... rest) {
        string b;
        for (; *it&&*it != ','; ++it) if (*it != ' ')b += *it;
        cout << b << "=" << a << " ";
        call(++it, rest...);
    }
};

/* Template Code Ends*/

struct BIT{
    ll bit[MAX]; int N;

    ll get(int p) {  // returns sum from 1 to p
        ll res = 0;
        for (; p >= 0; p = (p & (p + 1)) - 1) res += bit[p];
        return res;
    }
    void update(int p, ll val) {  // point update
        for (; p < N + 1; p = (p | (p + 1)))
            bit[p] += val;
    }
    ll rangeSum(int low, int high) {
        return get(high) - (low == 0 ? 0 : get(low - 1));
    }
    void reset(){
        MEM(bit, 0);
    }
    void init(int n){
        reset();
        N=n;
    }
}mBit;

int main(){
#ifndef ONLINE_JUDGE
    read();
    write();
#endif // ONLINE_JUDGE

    int T, n, m, x, y, z;
    scanf("%d", &T);
    FORR(cs, 1, T + 1) {
        scanf("%d%d", &n, &m);
        mBit.init(n);
        FOR(i, n) {
            scanf("%d", &x);
            mBit.update(i + 1, x);
        }
        printf("Case %d:\n", cs);
        FOR(QRY, m) {
            scanf("%d", &x);
            if (x == 1) {
                scanf("%d", &y);
                ll v = mBit.rangeSum(y + 1, y + 1);
                printf("%d\n", v);
                mBit.update(y + 1, -v);
            }
            else if (x == 2) {
                scanf("%d %d", &y, &z);
                mBit.update(y + 1, z);
            }
            else {
                scanf("%d %d", &y, &z);
                printf("%lld\n", mBit.rangeSum(y + 1, z + 1));
            }
        }
    }
}

/* Solved: LightOJ 1112 - Curious Robin Hood */
