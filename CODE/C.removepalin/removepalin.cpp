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
const int MAXN = 1000010;
string a;
int n;
string candidates[MAXN];
int dp[MAXN][5][5];
/*int s[MAXN];
int n;
int dp[MAXN][26][26];
int get_cost(int x , int y)
{
	int tmp = abs(x - y);
	return min(tmp , 26 - tmp); 
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("removepalin.inp" , "r" , stdin);
    freopen("removepalin.out" , "w" , stdout);
    cin >> a;
    n = a.length();
    a = " " + a;
    foru (i , 1 , n)
    {
    	foru(j , -2 , 2)
    	{
    		candidates[i][j+2] = (a[i] - 'a' + j + 26) % 26 + 'a';
    	}
    }
    memset(dp , 0x3f , sizeof(dp));
    foru (i , 0 , 4)
    {
    	foru (j , 0 , 4)
    	{
    		if (candidates[1][i] != candidates[2][j])
    		{
    			dp[2][i][j] = min(dp[2][i][j] , abs(i - 2) + abs(j - 2));	
    		}
    	}
    }
    foru (i , 2 , n - 1)
    {
    	foru (last , 0 , 4)
    	{
    		foru (prev , 0 , 4)
    		{
    			if(dp[i][last][prev] < oo)
    			{
    				foru (next , 0 , 4)
    				{
    					if(candidates[i + 1][next] != candidates[i - 1][last] 
    					&& candidates[i + 1][next] != candidates[i][prev])
    					{
    						dp[i + 1][prev][next] = min(dp[i + 1][prev][next] , dp[i][last][prev] + abs(next - 2));
    					}
    				}
    			}
    		}
    	}
    }
    int best = oo;
    foru (i , 0 , 4)
    {
    	foru (j , 0 , 4)
    	{
    		best = min(best , dp[n][i][j]);
    	}
    }
    if(best == oo)	best = 0;
    cout << best;
    /*
    memset(dp , 0x3f , sizeof(dp));
    foru (i , 1 , n)	s[i] = a[i] - 'a';
    foru (i , 0 , 25)
    {
    	foru (j , 0 , 25)
    	{
    		if(i != j)	dp[2][i][j] = min(dp[2][i][j] , get_cost(s[1] , j) + get_cost(s[2] , i));
    	}
    } 
    foru (i , 2 , n - 1)
    {
    	foru (last , 0 , 25)
    	{
    		foru (prev , 0 , 25)
    		{
    			if(dp[i][last][prev] < oo)
    			{
    				foru (next , 0 , 25)
    				{
    					if(next != last && next != prev)
    					{
    						dp[i+1][next][last] = min(dp[i+1][next][last] , dp[i][last][prev] + get_cost(s[i+1] , next));
    					}
    				}
    			}
    		}
    	}
    }
    int best = oo;
    foru (i , 0 , 25)
    {
    	foru (j , 0 , 25)
    	{
    		best = min(best , dp[n][i][j]);
    	}
    }
    if(best == oo)	best = 0;
    cout << best;*/
    return 0;
}
