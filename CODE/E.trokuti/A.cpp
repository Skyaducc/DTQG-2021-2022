// ax + by + c = 0 -> y = -a/b * x - c/b
// 2 dt // <=> -a/b = -a'/b' => a * b' = a' * b
// 2 dt trung nhau <=> -c/b = -c'/b' => c * b' = c' * b
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
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 3e5 + 1;
const int MOD = 1e9 + 7;
int n;
struct Line
{
	int a , b , c;
	bool operator < (const Line &tmp)	const
	{
		if (a == tmp.a) return b < tmp.b;
		return a < tmp.a;
	}
	bool operator == (const Line &tmp)	const
	{
		return a == tmp.a && b == tmp.b;
	}
} line[MAXN];
int dp[MAXN][4];
int cnt[MAXN];
int num = 0;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("trokuti.inp" , "r" , stdin);
    freopen("trokuti.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	int a , b , c;
    	cin >> a >> b >> c;
		int tmp = __gcd(a, b);
		a /= tmp;
		b /= tmp;
		if (a < 0) 
		{
			a = -a , b = -b;
		}
		line[i] = {a , b , c};
    }
    sort(line + 1 , line + 1 + n);
    dp[0][0] = 1; 
    int tmp = 1;
    foru (i , 1 , n)
    {
    	if(line[i] == line[i-1])
    	{
    		tmp++;
    	}
    	else
    	{
    		cnt[++num] = tmp;
    		tmp = 1;
    	}
    }
    int sum = 0;
    foru (i , 1 , num)	sum += cnt[i];
    if(sum != n)
    {
    	cnt[num] += n - sum;
    }
    // cout << num << endl;
    // foru (i , 1 , num)
    // {
    // 	cout << cnt[i] << " ";
    // }
    // cout << endl;
    foru (i , 1 , num)
    {
    	foru (j , 1 , 3)
    	{
    		dp[i][j] = (dp[i-1][j] + (dp[i-1][j-1] * cnt[i]) % MOD) % MOD;
    	}
    }
    int res = 0;
    foru (i , 1 , num)
    {
    	res = (res + dp[i][3]) % MOD;
    	// cout << dp[i][3] << endl;
    }
    cout << res;
    return 0;
}