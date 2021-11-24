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
using namespace std;
const int MAXN = 101;
int test , n;
int a[MAXN];
void solve()
{
	cin >> n;
	for (int i=1 ; i<=n ; i++)
	{
		cin >> a[i];
	}
	for (int i=1 ; i<=n ; i++)
	{
		if(a[i] % 2 == 0)
		{
			cout << 1 << endl << i << endl;
			return;
		}
	}
	int tmp1 = 0 , tmp2 = 0;
	for (int i=1 ; i<=n ; i++)
	{
		if(a[i] % 2 == 1)
		{
			tmp1 = i;
			break;
		}
	}
	for (int i=1 ; i<=n ; i++)
	{
		if(a[i] % 2 == 1 && i != tmp1)
		{
			tmp2 = i;
			break;
		}
	}
	if(tmp1 && tmp2)	cout << 2 << endl << tmp1 << " " << tmp2 << endl;
	else	cout << -1 << endl;
}
int main()
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
