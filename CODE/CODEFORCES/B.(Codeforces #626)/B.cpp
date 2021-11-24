// k = 2
// 1 0 1
// 1 1 1
// 1*2  2*1
// với 1*2 -> dãy con liên tiếp độ dài 1 ở trên dãy a và dãy con liên tiếp độ dài 2 ở trên dãy b
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
#define int long long
using namespace std;
const int MAXN = 40111;
int n , m , k;
int a[MAXN] , b[MAXN];
int res = 0;
int solve(int x , int y)
{
	// cout << x << " " << y << endl;
	int i=1 , j=1;
	int ans1 = 0 , ans2 = 0;
	while(true)
	{
		if(a[i] == 1)
		{
			j = i;
			while(true)
			{
				if(a[j+1] == 0 || j+1 > n)	break;
				j++;
			}
			if(j - i + 1 >= x)	ans1 += (j - i + 1) - x + 1;
			// if(x == 1 && y == 6)	cout << i << " " << j << " " << ans1 << endl;
		}
		if(a[i] == 0)
		{
			i++;
			continue;
		}
		if(j > i)	i = j + 1;
		else	i++;
		if(i > n || j >= n)	break;
	}
	i = 1 , j = 1;
	while(true)
	{
		// cout << i << " " << j << endl;;
		if(b[i] == 1)
		{
			j = i;
			while(true)
			{
				if(b[j+1] == 0 || j+1 > m)	break;
				j++;
			}
			if(j - i + 1 >= y)	ans2 += (j - i + 1) - y + 1;
			// if(x == 1 && y == 6)	cout << i << " " << j << " " << ans2 << endl;
		}
		if(b[i] == 0 && i <= m)
		{
			i++;
			continue;
		}
		if(j > i)	i = j + 1;
		else	i++;
		if(i > m || j >= m)	break;
	}
	// cout << ans1 << " " << ans2 << endl;
	return ans1 * ans2;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    int cnt1 = 0 , cnt2 = 0;
    for (int i=1 ; i<=n ; i++)
    {
    	cin >> a[i];
    	if(a[i] == 1)	cnt1++;
    }
    for (int i=1 ; i<=m ; i++)
    {
    	cin >> b[i];
    	if(b[i] == 1)	cnt2++;
    }
    if(k == 1)
    {
    	cout << 1LL * cnt1 * cnt2 << endl;
    	return 0;
    }
    for (int i=1 ; i * i <= k ; i++)
    {
    	if(k % i == 0)
    	{
    		// cout << i << " " << k/i << endl;
    		if(i == k/i)
    		{
    			res += solve(i , k/i);
    			continue;
    		}
    		res += solve(i , k/i);
    		res += solve(k/i , i);
    		
    	}
    }
    cout << res;
    return 0;
}
