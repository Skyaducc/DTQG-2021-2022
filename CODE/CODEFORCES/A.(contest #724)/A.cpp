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
const int MAXN = 301;
int test , n;
int a[MAXN];
void solve()
{
	cin >> n;
	int Ma = 0;
	bool ok = true;
	for (int i=1 ; i<=n ; i++)
	{
		cin >> a[i];
		if(a[i]  < 0)	ok = false;
		Ma = max(Ma , a[i]);
	}
	if(!ok)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl << Ma + 1 << endl;
		for (int i=0 ; i<=Ma ; i++)
		{
			cout << i << " " ;
		}
		cout << endl;
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
