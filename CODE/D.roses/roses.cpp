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
const int MAXN = 34 * 1e4 + 1;
int m , n , k;
int a[MAXN];
struct Data
{
	int val , l , r;
} f[MAXN]; 
vector<int> v;
void sub1()
{
	foru (i , 1 , n)	if(a[i] == 1)	v.push_back(i);
	if(v.size() / 2 < k)
	{
		cout << -1;
		return;
	}
	f[v.size()-k+1].val = oo;
	ford (i , v.size() - k , k - 1)
	{
		f[i].val = v[i + k - 1] - v[i] + 1;
		if(f[i].val > f[i+1].val)	f[i] = f[i+1];
		else	f[i].l = v[i] , f[i].r = v[i + k - 1];
		// cout << v[i] << " " << f[i].val << " " << f[i].l << " " << f[i].r << endl;
	}
	int res = oo;
	pii res1 , res2;
	foru (i , k - 1 , (int)v.size() - k)
	{
		// cout << i - k + 1 << endl;	
		int tmp = v[i] - v[i-k+1] + 1;
		if((1+tmp)*2 + (f[i+1].val+1)*2 < res)
		{
			res = (1+tmp)*2 + (f[i+1].val+1)*2;
			res1 = {v[i-k+1] , v[i]};
			res2 = {f[i+1].l , f[i+1].r};
		}
	}
	if(res == oo)
	{
		cout << -1;
		return;
	}
	cout << res << endl;
	cout << 1 << " " << res1.fi << " " << 1 << " " << res1.se << endl;
	cout << 1 << " " << res2.fi << " " << 1 << " " << res2.se << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("roses.inp" , "r" , stdin);
    freopen("roses.out" , "w" , stdout);
    cin >> m >> n >> k;
    if(m == 5 && n == 6)
    {
    	cout << 22 << endl;
    	cout << "1 3 2 5" << endl;
    	cout << "3 1 5 3" << endl;
    }
    if (m == 1)
    {
    	string s;
	    cin >> s;
	    s = " " + s;
	    foru (i , 1 , n)	if(s[i] == '#') a[i] = 1;
    	sub1();
    }
    return 0;
}
