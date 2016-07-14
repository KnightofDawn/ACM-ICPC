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

const int M=1000000;
const int N=310;
int n,m,k,q;

struct Graph    
{    
    struct node    
    {    
        int v,next,w,flow;    
        node(){};    
        node(int a,int b,int c,int d){    
            next=a;v=b;w=c;flow=d;    
        }    
    }E[2*M];    
    int head[N],pre[N],dis[N];
	int beg,end,flow,cost; 
	bool h[N];    
    int path[N];    
    int NE,NV; 
    void resize(int n)
    {
    	this->NV=n;	
    }
    void init(int n)    
    {    
        NE=0;    
        NV=n;    
        memset(head,-1,sizeof(int)*(n+10));    
    }    
    void insert(int u,int v,int flow,int w)    
    {    
        E[NE]=node(head[u],v,w,flow);    
        head[u]=NE++;    
        E[NE]=node(head[v],u,-w,0);    
        head[v]=NE++;    
    }    
    bool update(int u,int v,int w)    
    {    
        if(dis[u]+w<dis[v])    
        {    
            dis[v]=dis[u]+w;    
            return true;    
        }    
        return false;    
    }    
    bool spfa()    
    {    
        CLR(pre,-1);    
        CLR(h,0);    
        for(int i=0;i<=NV;i++)
        	dis[i]=INF;
        dis[beg]=0;    
        queue<int> q;    
        q.push(beg);    
        while(!q.empty())    
        {    
            int u=q.front();    
            q.pop();    
            h[u]=0;    
            for(int i=head[u];i!=-1;i=E[i].next)    
            {    
                int v=E[i].v;    
                if(E[i].flow>0&&update(u,v,E[i].w))    
                {    
                    pre[v]=u;    
                    path[v]=i;    
                    if(!h[v])    
                    {    
                        h[v]=1;    
                        q.push(v);    
                    }    
                }    
            }    
        }    
        if(pre[end]==-1)    
            return false;    
        return true;    
    }    
    int mincost_maxflow(int s,int t)    
    {    
    	this->beg=s;this->end=t;
        flow=0,cost=0;
        while(spfa())    
        {    
            int Min=INT_MAX;    
            for(int i=end;i!=beg;i=pre[i])    
                if(Min>E[path[i]].flow)    
                    Min=E[path[i]].flow;    
            for(int i=end;i!=beg;i=pre[i])    
            {    
                E[path[i]].flow-=Min;    
                E[path[i]^1].flow+=Min;    
            }    
            flow+=Min;    
            cost+=dis[end];    
        }
        return cost;    
    }    
}g;


int main()
{
	int u,v,w,s,t;
	while(read(n)&&read(m)&&read(k)&&read(q))
	{
		g.init(n+m+2);
		s=0,t=n+m+1;
		for(int i=1;i<=n;i++)
		{
			read(u);
			g.insert(s,u,1,0);
		}
		for(int i=1;i<=k;i++)
		{
			read(u),read(v),read(w);
			g.insert(u,v,INF,w);g.insert(v,u,INF,w);
		}
		for(int i=1;i<=q;i++)
		{
			read(u),read(v),read(w);
			g.insert(v,u+m,1,w);
		}
		for(int i=1;i<=n;i++)
			g.insert(i+m,t,1,0);
		cout<<g.mincost_maxflow(s,t)<<endl;
	}
	return 0;
}