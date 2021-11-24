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
const int MAXN = 511;
const int MOD = 998244353;
int n , k;
int cnt[MAXN][MAXN]; // cnt(i , j) : số lượng dãy độ dài i có độ dài dãy cùng màu liên tiếp dài nhất là j
int dp[MAXN][MAXN]; // dp(i , j) : số cách dựng thỏa mãn tại hàng thứ i có độ dài dãy liên tiếp dài nhất là j
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    foru (i , 0 , n)
    {
    	dp[0][i] = 1;
    	cnt[0][0] = 1;
    }
    foru (i , 0 , n)
    {
    	foru (j , 0 , min(n , k - 1))
    	{
    		foru (x , i + 1 , n)
    		{
    			if((x - i) * j < k)
    			{
    				dp[x][j] = (dp[x][j] + dp[i][j]) % MOD;
    			}
    		}
    	}
    }
	foru (i , 0 , n)
	{
		foru (j , 0 , min(i , k - 1))
		{
			foru (x , i + 1 , n)
			{
				cnt[x][max(x - i , j)] = (cnt[x][max(x - i , j)] + cnt[i][j]) % MOD;
			}
		}
	}
    // cout << dp[n][1] << endl;
    int ans = 0;
    foru (i , 1 , min(n , k - 1))
    {
    	ans = (ans + (cnt[n][i] * dp[n][i]) % MOD) % MOD;
    	// cout << cnt[n][i] << " " << dp[n][i] << endl;
    }
    cout << ans * 2 % MOD;
    return 0;
}