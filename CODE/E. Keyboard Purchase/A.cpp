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
const int MAXN = 1e5 + 1;
const int oo = 1e9;
int n , m;
string s;
int a[MAXN];
int cnt[21][21];
int dp[1 << 20];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> s;
    s = " " + s;
    memset(dp , 0x3f , sizeof(dp));
    foru (i , 1 , n)
    {
    	a[i] = s[i] - 'a';
    	if(i > 1)
    	{
    		cnt[a[i]][a[i-1]]++;
    		cnt[a[i-1]][a[i]]++;
    	} 
    }
    dp[0] = 0;
    int last = (1 << m);
    foru (mask , 0 , last - 1) // trạng thái
    {
    	int now = __builtin_popcount(mask);
    	foru (j , 0 , m - 1) // thêm số j
    	{
    		if(BIT(mask , j) == 0)
    		{
    			int new_mask = SET_ON(mask , j);
    			int cost = 0;
    			foru (i , 0 , m - 1) // xét các vị trí cuối cùng
    			{
    				if(i == j)	continue;
    				if(BIT(mask , i))
    				{
    					cost += cnt[i][j];
    				}
    				else cost -= cnt[i][j];
    			}
    			dp[new_mask] = min(dp[new_mask] , dp[mask] + cost * now); 
    		}
    	}
    }	
    cout << dp[last - 1];
    return 0;
}
