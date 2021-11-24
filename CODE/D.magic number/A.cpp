// topic : dp digits
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
const int MAXN = 2011;
const int MOD = 1e9 + 7;
int m , d;
string a , b;
vector<int> digitsA , digitsB;
int dp[MAXN][MAXN][2]; // dp(i , j , k) : chữ số thứ i , số dư là j , k : chữ số có bị giới hạn hay ko
void Get_digits(vector<int> &digits , string &s) // lấy chữ số cho vào vector
{
	foru (i , 0 , (int)s.length() - 1)	digits.push_back(s[i] - '0');
}
bool check() // kiểm tra xem số a có t/m không
{
	bool ok = true;
	int du = 0;
	foru (i , 0 , (int)a.length() - 1)
	{
		if(i % 2)
		{
			if(a[i] - '0' != d) ok = false;
		}
		else if(a[i] - '0' == d) ok = false;
		du = (du * 10 + a[i] - '0') % m;
	}
	return (du == 0 && ok == true);
}
int Calc(int idx , int du , int tight , vector<int> &digits)
{
	if(idx == (int)digits.size())	return (du == 0);
	if(dp[idx][du][tight] != -1)	return dp[idx][du][tight];
	int &ret = dp[idx][du][tight];
	ret = 0;
	int k = (tight) ? 9 : digits[idx];
	foru (j , 0 , k)
	{
		if(idx % 2 == 0)
		{
			if(j != d) continue;
		}
		else if(j == d) continue;
		int new_tight = (tight || j < digits[idx]);
		int new_du = (du * 10 + j) % m;
		ret = (ret + Calc(idx + 1 , new_du , new_tight , digits)) % MOD;
	}
	return ret;
}
void input()
{
	cin >> m >> d >> a >> b;
	digitsA.push_back(0);
	digitsB.push_back(0);
	Get_digits(digitsA , a);
	Get_digits(digitsB , b);
}
void solve()
{
	memset(dp , -1 , sizeof(dp));
	long long res = Calc(1 , 0 , 0  , digitsB);
	memset(dp , -1 , sizeof(dp));
	res -= Calc(1 , 0 , 0 , digitsA);
	if(res < 0)	res += MOD;
	cout << res + check();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    input();
    solve();
    return 0;
}