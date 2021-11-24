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
const int MAXN = 5e5 + 1;
int test , n;
int cnt[MAXN][2];
string s;
pii get_ps(int a , int b)
{
	int tmp = __gcd(a , b);
	a /= tmp;
	b /= tmp;
	return {a , b};
}
void solve()
{
	memset(cnt , 0 , sizeof(cnt));
	cin >> n >> s;
	s = " " + s;
	int D = 0 , K = 0;
	map<pii , int> mp;
	for (int i=1 ; i<=n ; i++)
	{
		if(s[i] == 'D')	D++;
		else K++;
		cout << ++mp[get_ps(D , K)] << " ";
	}
	cout << endl;
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
