//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=100010;

int ans=0,a[MAXN];
int n,x,y,h1,h2;


bool check()
{
	priority_queue<int>que;
	int hit=0,num=0;
	for(int i=1;i<=n;i++)
	{
		hit++;
		num=max(num,hit);
		h1-=a[i];
		que.push(max(a[i],y));
		if(hit*x>=h2)
		{
			ans=i;
			return true;
		}
		while(!que.empty() && h1<=0)
		{
			h1+=que.top();
			que.pop();
			hit--;
		}
	}
	ans=num*x;
	return false;
}


int main()
{
	while(read(n)&&read(x)&&read(y)&&read(h1)&&read(h2))
	{
		for(int i=1;i<=n;i++)
			read(a[i]);
		if(check())
		{
			puts("Win");
			write(ans),putchar('\n');
		}
		else
		{
			puts("Lose");
			write(ans),putchar('\n');
		}
	}
	return 0;
} 