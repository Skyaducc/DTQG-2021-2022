#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
const int MAXN = 2e5 + 1;
int test , n;
int a[MAXN] , b[MAXN] , pos[MAXN];
void solve()
{
	cin >> n;
	foru (i , 0 , n - 1)
	{
		cin >> a[i];
		pos[a[i]] = i;
	} 
	foru (i , 0 , n - 1)
	{
		cin >> b[i];
		pos[b[i]] = i;
	}
	int ans = oo;
	int min_idx = oo;
	for(int i=2*n-1 ; i>=1 ; i-=2)
	{
		int num = i;
		min_idx = min(min_idx , pos[num + 1]);
		ans = min(ans, pos[num] + min_idx);
	}
	cout << ans << endl;
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