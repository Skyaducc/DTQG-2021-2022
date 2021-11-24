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
#define ALL(x) x.begin() , x.end()
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 2e5 + 1;
int n;
vector<int> v;
pii a[MAXN];
int bitsum[MAXN] , bitcnt[MAXN];
void nenso(vector<int> &x)
{
	set<int> s(ALL(x));
	vector<int> tmp(ALL(s));
	foru (i , 0 , (int)x.size() - 1)
	{
		x[i] = lower_bound(ALL(tmp) , x[i]) - tmp.begin() + 1; 
	}
}
void updatesum(int x , int val)
{
	while(x <= n)
	{
		bitsum[x] += val;
		x += x & -x;
	}
}
void updatecnt(int x , int val)
{
	while(x <= n)
	{
		bitcnt[x] += val;
		x += x & -x;
	}
}
int Getsum(int x)
{
	int res = 0;
	while(x > 0)
	{
		res += bitsum[x];
		x -= x & -x;
	}
	return res;
}
int Getcnt(int x)
{
	int res = 0;
	while(x > 0)
	{
		res += bitcnt[x];
		x -= x & -x;
	}
	return res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i].fi;
    foru (i , 1 , n)	cin >> a[i].se;
    sort(a + 1 , a + 1 + n);
    foru (i , 1 , n)	v.push_back(a[i].se);
    nenso(v);
    int ans = 0;
    foru (i , 1 , n)
    {
    	int sum = Getsum(v[i-1]);
    	int cnt = Getcnt(v[i-1]);
    	ans += cnt * a[i].fi - sum;
    	updatesum(v[i-1] , a[i].fi);
    	updatecnt(v[i-1] , 1);
    }
    cout << ans;
    return 0;
}
