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
const int MOD = 1e9 + 7;
const int MAXN = 1001;
const int MAXM = 11;
int n , m;
long long dp[MAXN][MAXM]; // dp(i , j) : số dãy độ dài j sử dụng các giá trị tử 1 -> i
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)	dp[i][1] = 1;
    foru (i , 1 , n)
    {
    	foru (j , 2 , m)
    	{
    		foru (x , 1 , i)
    		{
    			dp[i][j] = (dp[i][j] + dp[x][j-1]) % MOD;
    		}
    	}
    }
    long long res = 0;
    foru (i , 1 , n)
    {
    	foru (j , 1 , n - i + 1)
    	{
    		res = (res + (dp[i][m] * dp[j][m]) % MOD) % MOD;
    	}
    }
    cout << res;
    return 0;
}
