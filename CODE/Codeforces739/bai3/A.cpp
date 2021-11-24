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
int test;
void solve()
{
	int k;
	cin >> k;
	int s = sqrt(k);
	if((s * s) != k) s += 1;
	int c = s , r = 1;
	int res = ((s - 1) * (s - 1)) + 1;
	while(r <= s)
	{
		if(res == k) 
		{
			cout << r << " " << c << endl;
			return;
		}
		res++;
		r++;
	}
	r = s;
	c = s-1;
	while (c >= 0)
	{
		if(res == k) 
		{
			cout << r << " " << c << endl;
			return;
		}
		res++;
		c--;
 
	}
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
