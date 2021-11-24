// 1 2 3 4 -> 1 4 3 2 -> 2 4 3 1 -> dãy các số bị đổi vị trí (2 , 4 , 1)
// 1) tính số cặp nghịch đảo trong các số bị đổi vị trí -> BIT
// 2) tính số cặp nghịch đảo với một số bị đổi vị trí và một số ko bị đổi vị trí
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
const int MAXN = 2e5 + 111;
int n , num;
pii a[MAXN];	
int b[MAXN] , c[MAXN];
map<int , int> mark;
set<int> s;
struct fenwickTree
{
	int n;
	vector<int> bit;
	fenwickTree(int _n = 0)
	{
		n = _n;
		bit.assign(n + 1 , 0);
	}
	void update(int x , int val)
	{
		while(x <= n)
		{
			bit[x] += val;
			x += x & -x;
		}
	}
	int get(int x)
	{
		int res = 0;
		while(x > 0)
		{
			res += bit[x];
			x -= x & -x;
		}
		return res;
	}
	void COUT()
	{
		foru (i , 1 , n)	cout << bit[i] << " ";
		cout << endl;
	}
};
int pos(int x)
{
	return lower_bound(b + 1 , b + 1 + num , x) - b;
}
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
    	cin >> a[i].fi >> a[i].se;
    	b[++num] = a[i].fi;
    	b[++num] = a[i].se;
    }
    int ans = 0;
    sort(b + 1 , b + num + 1);
	num = unique(b + 1 , b + num + 1 ) - b - 1 ;
	foru (i , 1 , num)	c[i] = i;
	foru (i , 1 , n) swap(c[pos(a[i].fi)] , c[pos(a[i].se)]);
	foru (i , 1 , num)  ans += abs(b[c[i]] - b[i]) - abs(c[i] - i);
	fenwickTree Bit(num);		
	ford (i , num , 1)
    {
    	ans += Bit.get(c[i] - 1);
    	// cout << Bit.get(c[i] - 1) << endl;
    	Bit.update(c[i] , 1);
    	// Bit.COUT();
    }
	cout << ans;
    return 0;
}