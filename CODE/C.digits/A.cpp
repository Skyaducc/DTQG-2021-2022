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
const int MAXN = 50001;
const int MOD = 1e9 + 19972207;
int n , k , p;
int dp[2][201][31]; // dp(i , j , k) : số cách chia đoạn từ 1 -> i thành j đoạn và dư của đoạn cuối cùng là k 
string s;
void add(int &x , int y)
{
	x += y;
	if(x >= MOD) x -= MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("digits.inp" , "r" , stdin);
    freopen("digits.out" , "w" , stdout);
    cin >> n >> k >> p >> s;
    s = " " + s;
    dp[1][1][(s[1] - '0') % p] = 1;
    foru (i , 1 , n - 1)
    {
    	foru (j , 1 , k)
    	{
    		foru (rem , 0 , p - 1)
    		{
    			bool prev = i & 1;
    			bool next = !prev;
    			if(dp[prev][j][rem] > 0)
    			{
    				int x = s[i + 1] - '0';
    				add(dp[next][j][(rem * 10 + x) % p] , dp[prev][j][rem]);
    				if(j < k && rem == 0)
    				{
    					add(dp[next][j+1][x % p] , dp[prev][j][rem]);
    				}
    				dp[prev][j][rem] = 0;
    			}
    		}
    	}
    }
    cout << dp[n & 1][k][0];
    return 0;
}