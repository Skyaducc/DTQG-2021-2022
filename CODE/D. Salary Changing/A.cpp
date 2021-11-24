// cnp kq , kiểm tra xem x có là trung vị của dãy được ko
// chọn các số sao cho có (n - 1) / 2 số lớn hơn x và (n - 1) / 2 số nhỏ hơn x
// và tổng các số được chọn <= s - x , x thuộc bất kì đoạn [li <= x <= ri]
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
const int MAXN = 2e5 + 1;
int test;
int n , s;
pii pi[MAXN];
int mark[MAXN];
bool check(int x)
{
	vector<int> v;
	int res = 0 , cnt = 0;
	foru (i , 1 , n)
	{
		if(pi[i].se < x)
		{
			res += pi[i].fi;
		}	
		else if(pi[i].fi >= x)
		{
			res += pi[i].fi;
			cnt++;
		}
		else v.push_back(pi[i].fi);
	}
	sort(v.begin(), v.end());
	int need = max(0LL , (n + 1) / 2 - cnt);
	if(need > v.size())	return false;
	foru (i , 0 , (int)v.size() - 1)
	{
		if(i < (int)v.size() - need)	res += v[i];
		else res += x;
	}
	return res <= s;
}
void solve()
{
	cin >> n >> s;
	foru (i , 1 , n)
	{
		cin >> pi[i].fi >> pi[i].se;
	}
	sort(pi + 1 , pi + 1 + n);
	int l = 1 , r = 1e9 , ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
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
