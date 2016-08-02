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
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

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

const int MAXN=1010;

int ans[MAXN][MAXN];

int main()
{
    ll n, k, d;
    read(n);
    read(k);
    read(d);
    bool ok = 0;
    ll temp=1;
    for(int i = 0; i < d; i++)
    {
        temp *= k;
        if(temp >= n)
        {
            ok = 1;
            break;
        }
    }
    if(!ok)
    {
        printf("-1\n");
        return 0;
    }
    temp = 0;
    for(int i = 0; i < n; i++)
    {
        ll t = temp;
        for(int j = 0; j < n; j++)
        {
            ans[j][i] = t % k;
            t /= k;
        }
        temp++;
    }
    for(int i = 0; i < d; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", ans[i][j]+1, j==n-1 ? '\n':' ');
    return 0;
}