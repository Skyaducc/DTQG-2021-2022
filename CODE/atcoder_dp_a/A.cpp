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
int n;
int a[MAXN];
int dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    }
    memset(dp , 0x3f , sizeof(dp));
    dp[1] = 0;
    foru (i , 2 , n)
    {
    	dp[i] = min(dp[i] , dp[i-1] + abs(a[i] - a[i-1]));
    	dp[i] = min(dp[i] , dp[i-2] + abs(a[i] - a[i-2]));
    }
    cout << dp[n];
    return 0;
}