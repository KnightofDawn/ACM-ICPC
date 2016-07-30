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
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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
    T x = 0, tmp = 1; char c = getchar();
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

const int MAXN=500010;
ll sum[MAXN],cnt[MAXN];
int n,temp;

int main()
{
//	freopen("data.txt","r",stdin);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(sum[i]);
		sum[i]+=sum[i-1];
	}
	cout<<endl;
	ll ans=0;
	if(sum[n]%3!=0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	cnt[n+1]=0;
	for(int i=n-1;i>=1;i--)
	{
		cnt[i]=cnt[i+1];
		if(3*sum[i]==sum[n])
			ans+=cnt[i];
		if(3*sum[i]==2*sum[n])
			cnt[i]++;
	}
	write(ans),putchar('\n');
	return 0;
}