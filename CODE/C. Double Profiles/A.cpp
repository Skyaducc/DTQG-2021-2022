#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
const int MAXN = 1e6 + 1;
const int BASE = 131;
const int MOD = 1e9 + 7;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
vector<int> adj[MAXN];
int n , m;
long long Hash[MAXN] , id[MAXN];
long long Get_rand(long long l , long long r)
{
	return l + rand() % r;
}
map<long long , int> cnt;
int main()
{
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
	foru (i , 1 , m)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	foru (i , 1 , n)
	{
		id[i] = rng();
		// cout << id[i] << endl;
	}
	foru (i , 1 , n)
	{
		for (int j : adj[i]) 
		{
			Hash[i] += id[j];
		}
	}
	long long ans=0;
	foru (i , 1 , n)
	{
		ans += cnt[Hash[i]];
		// cout << cnt[Hash[i]] << endl;	
		cnt[Hash[i]]++;
	}
	foru (i , 1 , n)
	{
		for (int j : adj[i]) 
		{
			if(i < j)
			{
				ans += (Hash[i] + id[i]) == (Hash[j] + id[j]);
			}
		}
	}
	cout << ans;
    return 0;
}