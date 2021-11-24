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
int test;
int mu2[62];
int calc(int x , int y)
{
	int dp[62][62];
	reset(dp);
	string tmp1 = to_string(x);
	string tmp2 = to_string(y);
	int n = tmp1.length();
	int m = tmp2.length();
	tmp1 = " " + tmp1;
	tmp2 = " " + tmp2;
	int pos = -1;
	int temp = 1;
	foru (j , 1 , m)
	{
		bool ok = true;
		foru (i , temp , n)
		{
			if(tmp1[i] == tmp2[j])
			{
				ok = false;
				temp = i;
				break;
			}
		}
		if(ok)
		{
			pos = j;
			break;
		}
	}
	pos = (pos == -1) ? m : pos;
	foru (i , 1 , n)
	{
		foru (j , 1 , pos)
		{
			if(tmp1[i] == tmp2[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			// cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	// if (y == 2048)	cout << pos << endl;
	return n + pos - 2 * dp[n][pos] + ((pos < m) ? (m - pos) : 0);
}
void solve()
{
	int n;
	cin >> n;
	int res = oo;
	foru (i , 0 , 60)
	{
		res = min(res , calc(n , mu2[i]));
	}
	cout << res << endl;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    foru (i , 0 , 60)
    {
    	mu2[i] = (1LL << i);
    }
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
