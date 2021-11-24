// 5 4 21
// 0 4 8 12 16
// 21 25 29 33 37
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
int test;
void solve()
{
	int n , x , t;
	cin >> n >> x >> t;
	int tmp = t / x;
	if(tmp > n)
	{
		cout << 1LL * (1 + n - 1) * (n - 1) / 2 << endl;
	}
	else	cout << 1LL * ((n - tmp) * tmp) + tmp * tmp - (1 + tmp) * tmp / 2 << endl;
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
