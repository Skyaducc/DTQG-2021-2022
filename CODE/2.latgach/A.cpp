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
const int MAXN = 1e5 + 11;
const int MAXK = 51;
int n , k , g1 , g2 , g3 , num3 , y;
string s;
int res;
int dp[MAXN][MAXK];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> g1 >> g2 >> g3 >> s;
    s = " " + s;
    foru (i , 1 , n)
    {
    	if(s[i] == '#' && s[i-1] == '.' && s[i+1] == '.')	num3++;	
    	if(s[i] == '#')	y++;
    }
    memset(dp , -0x3f , sizeof(dp));
    dp[0][0] = 0;
    foru (i , 1 , n)
    {
    	foru (x3 , 0 , num3)	dp[i][x3] = dp[i-1][x3];
    	foru (x3 , 0 , num3)
    	{
    		if(s[i] == '.' && s[i-1] == '.')	dp[i][x3] = max(dp[i][x3] , dp[i-2][x3] + 1);
			else if(i >= 3 && x3 >= 1 && s[i] == '.' && s[i-1] == '#' && s[i-2] == '.')	
			{
				dp[i][x3] = max(dp[i][x3] , dp[i-3][x3-1]);
			}
    	}
    }
    // foru (x3 , 0 , num3)	cout << x3 << " " << dp[n][x3] << endl;	
    foru (x3 , 0 , num3)
	{
		if(2 * g1 <= g2)
		{
			int x2 = dp[n][x3];
			int x1 = min(k , n - 2 * x2 - 3 * x3 - (y - x3));
			if(x1 >= 0 && x2 >= 0 && x3 >= 0)	res = max(res , x1 * g1 + x2 * g2 + x3 * g3);
			// cout << x1 << " " << x2 << " " << x3 << " " << res <<endl;
		}
		else
		{
			int x1 = min(k , n - 3 * x3 - (y - x3));
			int x2 = min((n - 3 * x3 - (y - x3) - x1) / 2 , dp[n][x3]);
			if(x1 >= 0 && x2 >= 0 && x3 >= 0)	res = max(res , x1 * g1 + x2 * g2 + x3 * g3);
			// cout << x3 << " " << x2 << " " << x1 << " " << res << endl;
			if((n - 3 * x3 - (y - x3) - x1) % 2 == 1)
			{
				x1--;
				x2++;
				if(x1 >= 0 && x2 >= 0 && x3 >= 0)	res = max(res , x1 * g1 + x2 * g2 + x3 * g3);
			}
		}
	}
    cout << res;
    return 0;
}