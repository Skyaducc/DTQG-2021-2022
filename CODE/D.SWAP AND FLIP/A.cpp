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
const int MAXN = 19;
int n;
int a[MAXN] , b[MAXN];
int dp[MAXN][1 << 19]; // dp(i , j) số thao tác tối thiểu với vị trí cuối cùng i và các số bit1 trong j
int c[MAXN];
bool check(int l , int r)
{
	return (abs(r - l) % 2 == 0);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i];
    foru (i , 1 , n)	cin >> b[i];
    memset(dp , 0x3f , sizeof(dp));
    int last = (1 << n) - 1;
    ford (i , n , 1)	c[i] = c[i+1] | (1 << i);
    foru (i , 0 , n - 1)
    {
        dp[i][1 << i] = 0;
    }	
    foru (mask , 1 , last)
    {
    	int k = __builtin_popcount(mask);
    	foru (i , 0 , n - 1)
    	{
    		if(BIT(mask , i))
    		{
    			int tmp = (check(i , k - 1)) ? a[i+1] : b[i+1];
    			foru (j , 0 , n - 1)
    			{
    				if(!BIT(mask , j))
    				{
    					int tmp1 = check(j , k) ? a[j+1] : b[j+1];
    					if(tmp1 < tmp)	continue;
    					int new_mask = SET_ON(mask , j);
    					int cost = __builtin_popcount(mask & c[j+1]);
    					dp[j][new_mask] = min(dp[j][new_mask] , dp[i][mask] + cost);
     				}
    			}
    		}
    	}
    }
    int ans = oo;
    foru (i , 0 , n - 1)	ans = min(ans , dp[i][last]);
    cout << ((ans == oo) ? -1 : ans);
    return 0;
}