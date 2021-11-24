#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
using namespace std;
const int MAXN = 101;
const int oo = 1e9;
int n , e;
int m[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> e;
    for (int i=1 ; i<=n ; i++)
    {
    	cin >> m[i];
    }
    int ans = oo;
    for (int i=1 ; i<=n ; i++)
    {
    	for (int j=i+1 ; j<=n ; j++)
    	{
    		int res = 0;
    		int mi = 0;
    		for (int x=1 ; x<i ; x++)
    		{
    			int tmp = 2 * abs(m[x] - m[i]);
    			mi += tmp;
    		}
    		res += mi , mi = 0;
    		for (int x=i+1 ; x<j ; x++)
    		{
    			int tmp = abs(2 * m[x] - (m[i] + m[j]));
    			mi += tmp;
    		}
    		res += mi , mi = 0;
    		for (int x=j+1 ; x<=n ; x++)
    		{
    			int tmp = abs(m[x] - m[j]);
    			mi += tmp;
    		}
    		res += mi;
    		ans = min(ans , res);
    		// cout << i << " " << j << " " << res << endl;
    	}
    }
    cout << 2 << " " << ans;
    return 0;
}
