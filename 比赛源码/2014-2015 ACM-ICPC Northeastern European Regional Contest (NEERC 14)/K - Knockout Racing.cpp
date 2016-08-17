//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXN=1111; 
struct Node
{
    ll x,y;
}a[MAXN];

int main()
{
        freopen("knockout.in","r",stdin);
    freopen("knockout.out","w",stdout);
    int n,m;
    while(read(n)&&read(m))
    {
        for(int i=0;i<n;i++)
            read(a[i].x),read(a[i].y);
        while(m--)
        {
            ll xx,yy,t;
            read(xx),read(yy),read(t);
            int count=0;
            for(int i=0;i<n;i++)
            {
                int tx=0;
                if(t<(a[i].y-a[i].x))
                {
                    tx=a[i].x+t;
                } 
                else
                {
                     int  u=t%(a[i].y-a[i].x);
                     int  v=t/(a[i].y-a[i].x); 
                     if(v&1) 
                        tx=a[i].y-u; 
                     else
                        tx=a[i].x+u; 
                  } 
                  if(tx>=xx&&tx<=yy)
                      count++;
            }
            printf("%d\n",count);
        }
    }
    
    return 0;
}