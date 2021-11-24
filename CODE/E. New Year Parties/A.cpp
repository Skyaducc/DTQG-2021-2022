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
int a[MAXN];
int dp[MAXN] , f[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i];
    foru (i , 1 , n)
    {
    	if(a[i] > a[i-1])
    	{
    		f[i] = f[i-1] + 1;
    		dp[i] = dp[i-1] + 1;
    	}
    	else f[i] = 1 , dp[i] = 1;
    	if(a[i] > a[i-2] && i > 1)
    	{
    		dp[i] = max(dp[i] , f[i-2] + 1);
    	}
    }
    int ans = 0;
    foru (i , 1 , n)	ans = max(ans , max(f[i] , dp[i]));
    cout << ans;
    return 0;
}
