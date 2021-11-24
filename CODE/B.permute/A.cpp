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
const int MAXN = 4e5 + 1;
const int MOD = 998244353;
int subtask , n;
int a[MAXN];
int cnt = 0;
int frac[MAXN] , finv[MAXN];
int Power(int x , int y)
{
    if (!y) return 1;
    if (y == 1) return x % MOD;
    int ret = Power(x , y / 2);
    ret = 1ll * ret * ret % MOD;
    if (y % 2) ret = 1ll * ret * x % MOD;
    return ret;
}
void init()
{
    frac[0] = finv[0] = 1;
    foru(i , 1 , MAXN - 1)
    {
        frac[i] = 1ll * frac[i - 1] * i % MOD;
        finv[i] = Power(frac[i] , MOD - 2);
    }
}
int ckn(int k , int n)
{
    return 1ll * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}
vector<int> v;
int mark[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("permute.inp" , "r" , stdin);
    freopen("permute.out" , "w" , stdout);
    cin >> subtask >> n;
    foru (i , 1 , n)	
    {
    	cin >> a[i];
    	if(a[i] == -1)	v.push_back(i);
    	else mark[a[i]] = 1;
    }
    for (int x : v)
    {
    	if(!mark[x])
    	{
    		cnt++;
    	}
    }
    init();
    int ans = frac[(int)v.size()];
    // cout << ans;
    int tmp = 0;
    foru (i , 1 , cnt)
    {
    	tmp = ckn(i , cnt) * frac[(int)v.size() - i] % MOD;
    	// cout << tmp << endl;
    	if(i % 2 == 1)
    	{
    		ans -= tmp;
    		if(ans < 0)	ans += MOD;
    	}
    	else
    	{
    		ans += tmp;
    		if(ans >= MOD)	ans -= MOD;
    	}
    }
    cout << ans;
    return 0;
}
