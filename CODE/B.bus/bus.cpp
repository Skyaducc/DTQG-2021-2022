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
const int MAXN = 1e5 + 1;
int m , n , k;
vector<int> v;
int b[MAXN];
struct Data
{
	int x , y , w;
	bool operator < (const Data &tmp)	const
	{
		return (x == tmp.x) ? y < tmp.y : x < tmp.x;
	}
} a[MAXN];
int bit[MAXN];
int Get(int x)
{
	int res = 0;
	while(x > 0)
	{
		res = max(res , bit[x]);
		x -= x & -x;
	}
	return res;
}
void update(int x , int val)
{
	while(x <= k)
	{
		bit[x] = max(bit[x] , val);
		x += x & -x;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> m >> n >> k;
    foru (i , 1 , k)
    {
    	int x , y , w;
    	cin >> x >> y >> w;
    	a[i] = {x , y , w};
    	v.push_back(y);
    }
    sort(a + 1 , a + 1 + k);
    sort(v.begin() , v.end());
    foru (i , 1 , k)
    {
        b[i] = lower_bound(v.begin() , v.end() , a[i].y) - v.begin() + 1;
    }
    int ans = 0;
    foru (i , 1 , k)
    {
    	int tmp = a[i].w + Get(b[i]);
    	ans = max(ans , tmp);
    	update(b[i] , tmp);
    }
    cout << ans;
    return 0;
}
