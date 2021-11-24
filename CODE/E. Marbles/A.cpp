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
const int MAXN = 4e5  + 1;
int n;
int a[MAXN];
int cnt[21][21]; // cnt(i , j) : số thao tác ít nhất để màu i luôn đứng trước màu j 
vector<int> color[21];
set<int> s;
long long dp[1 << 21];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	a[i]--;
    	color[a[i]].push_back(i);
    }
    foru (i , 0 , 19)
    {
    	foru (j , 0 , 19)
    	{
    		if(i == j || (int)color[i].size() == 0 || (int) color[j].size() == 0)	continue;
    		int pos = 0;
    		for (int x : color[i])
    		{
    			while(true)
    			{
    				if(pos == (int)color[j].size() - 1 || color[j][pos+1] > x)	break;
    				pos++;
    			}
    			if(x > color[j][pos])	cnt[i][j] += pos + 1;
    		}
    	}
    }
    memset(dp , 0x3f , sizeof(dp));
    dp[0] = 0;
    int last = (1 << 20) - 1;
    foru (mask , 0 , last)
    {
    	vector<int> v;
    	foru (i , 0 , 19)
    	{
    		if(BIT(mask , i))	v.push_back(i);
    	}
    	foru (i , 0 , 19)
    	{
    		if(!BIT(mask , i))
    		{
    			long long sum = 0;
    			for (int x : v)
    			{
    				sum += cnt[x][i];
    			}
    			int new_mask = SET_ON(mask , i);
    			dp[new_mask] = min(dp[new_mask] , dp[mask] + sum);
    		}
    	}
    }
    cout << dp[last];
    return 0;
}
