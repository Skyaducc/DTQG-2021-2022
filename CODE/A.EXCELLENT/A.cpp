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
const int MAXN = 1e5 + 11;
pair <int , pii> a[MAXN];
int n;
struct FenwickTree
{
	int n;
	vector<int> Bit;
	FenwickTree (int _n = 0)
	{
		n = _n;
		Bit.assign(n + 1 , oo);
	}
	void update(int x , int k)
	{
		while (x <= n)
		{
			Bit[x] = min(Bit[x] , k);
			x += x & -x;
		}
	}
	int Get(int x)
	{
	    int res = oo;
	    while (x > 0)
	    {
	    	res = min(res , Bit[x]);
	    	x -= x & -x;
	    }
	    return res;
	}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
        int x;
        cin >> x;
        a[x].fi = i;
    }
    foru (i , 1 , n)
    {
        int x;
        cin >> x;
        a[x].se.fi = i;
    }
    foru (i , 1 , n)
    {
        int x;
        cin >> x;
        a[x].se.se = i;
    }
    sort (a + 1 , a + 1 + n);
    FenwickTree Bit(n);
    int res = 0;
    foru (i , 1 , n)
    {
        int tmp = Bit.Get(a[i].se.se);
        if(tmp > a[i].se.fi)	res++;
        Bit.update(a[i].se.se , a[i].se.fi);
    }
    cout << res;
    return 0;
}