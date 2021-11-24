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
const int MAXN = 1e5 + 1;
int n , k;
int h[MAXN];
int dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    foru (i , 1 , n)
    {
    	cin >> h[i];
    }
    memset(dp , 0x3f , sizeof(dp));
    dp[1] = 0;
    foru (i , 2 , n)
    {
    	foru (j , max(1 , i - k) , i - 1)
    	{
    		dp[i] = min(dp[i] , dp[j] + abs(h[i] - h[j]));
    	}
    }
    cout << dp[n];
    return 0;
}