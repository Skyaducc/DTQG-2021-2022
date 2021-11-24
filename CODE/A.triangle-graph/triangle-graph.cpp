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
const int MAXN = 51;
int n , m;
int cnt[MAXN];
vector<int> adj[MAXN];
int mark[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("triangle-graph.inp" , "r" , stdin);
    freopen("triangle-graph.out" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	cnt[u]++;
    	cnt[v]++;
    	mark[u][v]++;
    	mark[v][u]++;
    }
    int res = oo;
    foru (i , 1 , n)
    {
    	foru (j , i + 1 , n)
    	{
    		foru (k , j + 1 , n)
    		{
    			res = min(res , 3 - mark[i][j] - mark[j][k] - mark[i][k]);
    		}
    	}
    }
    cout << res;
    return 0;
}
