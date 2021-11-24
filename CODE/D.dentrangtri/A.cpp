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
const int MAXN = 1001;
const int oo = 1e9;
int n , m;
string s[16];
int cost[16][16];
int dp[70001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 0 , m - 1)	cin >> s[i];
    foru (i , 0 , m - 2)
    {
    	foru (j , i + 1 , m - 1)
    	{
    		int tmp = 0;
    		foru (x , 0 , n - 1)
    		{
    			if(s[i][x] != s[j][x])	tmp++;
    		}
    		cost[i][j] = cost[j][i] = tmp;
    	}
    }
    memset(dp , 0x3f , sizeof(dp));
    foru (i , 0 , m - 1)
    {
    	int mask = (1 << i);
    	int cnt = 0;
    	foru (j , 0 , n - 1)
    	{
    		if(s[i][j] == '1')	cnt++;
    	}
    	dp[mask] = cnt;
    }
    int last = (1 << m);
    foru (mask , 1 , last - 1)
    {
    	if(dp[mask] >= oo)	continue;
    	foru(i , 0 , m - 1)
    	{
    		if(BIT(mask , i))
    		{
    			foru (j , 0 , m - 1)
    			{
    				if(!BIT(mask , j))
    				{
    					int new_mask = SET_ON(mask , j);
    					dp[new_mask] = min(dp[new_mask] , dp[mask] + cost[i][j]);
    				}
    			}
    		}
    	}
    }
    cout << dp[last - 1];
    return 0;
}
