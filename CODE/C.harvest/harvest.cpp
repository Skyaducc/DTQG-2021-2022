// chặt nhị phân kiểm tra với số x có thể tới được tất cả vị trí khóm hoa hay không
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
#define ll long long
using namespace std;
const ll oo = 1e18;
const int MAXN = 1e5 + 11;
int n , m;
ll a[MAXN] , b[MAXN];
bool check(ll x)
{
	int i = 1 , j = 1;
	while(i <= n)
	{
		if(a[i] - b[j] > x)	return false;
		if(b[j] >= a[i])
		{
			while(b[j] - a[i] <= x)	j++;
		}
		else
		{
			int j1 = j , j2 = j;
			while(b[j1] < a[i] || b[j1] - b[j] + a[i] - b[j] <= x)	j1++;
			while(b[j2] - b[j] + abs(b[j2] - a[i]) <= x)	j2++;
			j = max(j1, j2);
		}
		if(j > m)	return true;
		i++;
	}
	return j > m;
}
void solve()
{
	foru (i , 1 , n)	cin >> a[i];
	foru (i , 1 , m)	cin >> b[i];
	sort (a + 1 , a + 1 + n);
	sort(b + 1 , b + 1 + m);
	ll l = 0 , r = 1e18 , ans = 0;
	b[m + 1] = oo;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1; 
		}
		else	l = mid + 1;
	}
	cout << ans << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("harvest.inp" , "r" , stdin);
    freopen("harvest.out" , "w" , stdout);
    while(cin >> n >> m)
    {
    	if(n == 0 && m == 0)	break;
    	solve();
    }
    return 0;
}
