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
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 511;
int n , k , cnt = 1;
int a[MAXN][MAXN] , mark[MAXN][MAXN];
int x[100011];
pii pi;
void dfs(int u , int par)
{
	if(mark[u][par])	
	{
		pi = {mark[u][par] , cnt + 1};
		return;
	}
	mark[u][par] = ++cnt;
	x[cnt] = u;
	dfs(a[u][par] , u);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    foru (i , 1 , n)
    {
    	foru (j , 1 , n)
    	{
    		cin >> a[i][j];
    	}
    }
    x[1] = 1;
    dfs(2 , 1);
    if(cnt >= k)
    {
    	cout << x[k];
    }
    else
    {
    	k -= pi.se;
    	k %= (pi.se - pi.fi);
    	k += pi.fi;
    	// cout << k << " " << pi.fi << endl;
    	cout << x[k];
    }
    return 0;
}