// 1 1 5 8 12 13 20 22
// (1 1) (5 8) (12 13) (20 22)
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
const int MAXN = 200001;
int n , k , x;
int a[MAXN];
vector<int> v;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> x;
    for (int i=1 ; i<=n ; i++)	cin >> a[i];
    sort(a + 1 , a + 1 + n);
	a[0] = a[1];
	for (int i=1 ; i<=n ; i++)
	{
		if(a[i] - a[i-1] > x)
		{
			v.push_back((a[i]-1 - a[i-1]) / x);
		}
	}
	sort(v.begin() , v.end());
	int cnt = 0 , ans = 0;
	for (int x : v)
	{
		// cout << x << endl;
		ans += x;
		if(ans > k)	break;
		cnt++;
	}
	cout << v.size() - cnt + 1;
    return 0;
}
