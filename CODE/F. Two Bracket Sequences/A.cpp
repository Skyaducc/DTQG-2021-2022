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
const int MAXN = 201;
string s , t;
int dp[MAXN][MAXN][2 * MAXN]; // dp(i , j , k) : độ dài dãy ngoặc nhỏ nhất là tiền tố của dãy ngoặc đúng
							  // đã xây dựng i kí tự đầu của dãy 1 , j kí tự đầu của dãy 2 và 
							  // số dư là k (để dãy ngoặc đúng thì 0 <= số dư < 200)
struct Data
{
	int i , j , k;
	Data (int _i = 0 ,int _j = 0 , int _k = 0)
	{
		i = _i ; j = _j ; k = _k;
	}

};
Data trace[MAXN][MAXN][2 * MAXN];
string res;
void truyvet(int i , int j , int k)
{
	// cout <<  i << " " << j << " " << k << endl;
	if(i == 0 && j == 0 && k == 0)	return;
	int newi = trace[i][j][k].i;
	int newj = trace[i][j][k].j;
	int newk = trace[i][j][k].k;
	if(newk == k + 1) res += ')';
	if(newk == k - 1) res += '(';
	truyvet(newi , newj , newk);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> s >> t;
    memset(dp , 0x3f , sizeof(dp));
    dp[0][0][0] = 0;
    foru (i , 0 ,(int)s.length())
    {
    	foru (j , 0 , (int)t.length())
    	{
    		foru (k , 0 , 2 * MAXN - 1)
    		{
    			if(dp[i][j][k] > oo)	continue;
    			int newi = i + (i < (int)s.length() && s[i] == '(');
    			int newj = j + (j < (int)t.length() && t[j] == '(');
    			if(k + 1 < 2 * MAXN && dp[newi][newj][k+1] > dp[i][j][k] + 1)
    			{
    				dp[newi][newj][k+1] = dp[i][j][k] + 1;
    				trace[newi][newj][k+1] = {i , j , k};
    			}
    			newi = i + (i < (int)s.length() && s[i] == ')');
    			newj = j + (j < (int)t.length() && t[j] == ')');
    			if(k + 1 > 0 && dp[newi][newj][k-1] > dp[i][j][k] + 1)
    			{
    				dp[newi][newj][k-1] = dp[i][j][k] + 1;
    				trace[newi][newj][k-1] = {i , j , k};
    			}
    		}
    	}
    }
    int newk = 0;
	foru (k , 0 , 2 * MAXN - 1)
	{
		if (dp[(int)s.length()][(int)t.length()][k] + k < dp[(int)s.length()][(int)t.length()][newk] + newk) 
		{
			newk = k;
		}
	}
	cout << newk << endl;
	foru (i , 1 , newk)	res += ')';
    int ans = dp[(int)s.length()][(int)t.length()][newk];
    cout << ans << endl;
    truyvet((int)s.length() , (int)t.length() , newk);
    reverse(res.begin() , res.end());
    cout << res;
    return 0;
}