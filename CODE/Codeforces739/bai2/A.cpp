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
int test;
void solve()
{
	int a , b , c;
	cin >> a >> b >> c;
	int tmp = abs(a - b);
	if(tmp * 2 < c)
	{
		cout << -1 << endl;
		return;
	}
	if(a < b)
	{
		if(a * 2 > b)
		{
			cout << -1 << endl;
			return;
		}
	}
	else
	{
		if(a < b * 2)
		{
			cout << -1 << endl;
			return;
		}
	}
	if(c + tmp > tmp * 2)	cout << c - tmp << endl;
	else cout << c + tmp << endl;
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
