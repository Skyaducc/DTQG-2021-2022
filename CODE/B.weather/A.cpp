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
const int MAXN = 1e5 + 11;
const int MOD = 1e9 + 7;
string s;
int n;
int dp[MAXN];
string str[] = {"NW" , "WS" , "SE" , "EN"};
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> s;
    n = s.length();
    s = " " + s;
    dp[0] = 1;
    foru (i , 1 , n)
    {
    	dp[i] += dp[i-1];
    	dp[i] %= MOD;
    	string tmp = "";
    	tmp += s[i-1];
    	tmp += s[i];
    	foru (j , 0 , 3)
    	{
    		if(tmp == str[j])
    		{
    			dp[i] += dp[i-2];
    			dp[i] %= MOD;
    		}
    	}
    }
    cout << dp[n];
    return 0;
}