#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
using namespace std;
const int oo = 1e9;
const int MAXN = 2e5 + 1;
int n;
vector<int> adj[MAXN];
int farin[MAXN] , farout[MAXN] , h[MAXN] , trace[MAXN] , f[MAXN];
set<int> s[MAXN];
void calcfarin(int u , int par)
{
	for (int v : adj[u])
	{
		if(v == par)	continue; 
		calcfarin(v , u);
		farin[u] = max(farin[u] , farin[v] + 1);
	}
}
void calcfarout(int u , int par)
{
	int MaxFarIn = -1 , SecondMaxFarIn = -1;
    for (int v : adj[u])
    {
        if(v == par)    continue;
        if(MaxFarIn < farin[v])
        {
            SecondMaxFarIn = MaxFarIn;
            MaxFarIn = farin[v];
        }
        else    SecondMaxFarIn = max(SecondMaxFarIn , farin[v]);
    }
    for (int v : adj[u])
    {
        if(v == par)    continue;
        farout[v] = max(1 , farout[u] + 1);
        farout[v] = max(farout[v] , ((farin[v] == MaxFarIn) ? SecondMaxFarIn : MaxFarIn) + 2);
        calcfarout(v , u);
    }
}
void dfs1(int u , int par)
{
    for (int v : adj[u])
    {
        if(v == par)    continue;
        h[v] = h[u] + 1;
        trace[v] = u;
        dfs1 (v , u);
    }
}
void dfs2(int u , int par)
{
    for (int v : adj[u])
    {
        if(v == par)    continue;
        f[v] = (s[u].find(v) == s[u].end()) ? f[u] + 1 : f[u];
        dfs2(v , u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    calcfarin(1 , 0);
    calcfarout(1 , 0);
    int vert1 = 1 , vert2 = 1 , vert3 = 1 , dist = 0;
    foru (i , 1 , n)
    {
        if(dist < max(farin[i] , farout[i]))
        {
            dist = max(farin[i] , farout[i]);
            vert1 = i;
        }
    }
    dist = 0;
    dfs1(vert1 , 0);
    foru (i , 1 , n)
    {
        if(dist < h[i])
        {
            dist = h[i];
            vert2 = i;
        }
    }
    int v = vert2;
    while(v != vert1)
    {
        int tmp = trace[v];
        s[tmp].insert(v);
        v = tmp;
    }
    dfs2(vert1 , 0);
    int dist1 = 0;
    foru (i , 1 , n) 
    {
        if(i != vert1 && i != vert2)
        {
            vert3 = i;
            break;
        }
    }
    foru (i , 1 , n)
    {
        if(dist1 < f[i] && i != vert1 && i != vert2)
        {   
            dist1 = f[i];
            vert3 = i;
        }
    }
    cout << dist + dist1 << endl;
    cout << vert1 << " " << vert2 << " " << vert3;
    return 0;
}
