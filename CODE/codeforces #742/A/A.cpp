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
const int oo = 1e9;
const int MAXN = 1e5 + 1;
int test;
int n;
void solve()
{
	ll l, ans = 0, count = 0, n, m, x=0, y=0,r;
    string s;
    map<ll,ll>mp1;
    ll maxa = -1e18 , mina = 1e18;
    cin >> s;
    n=s.length();
    foru (i , 0 , n - 1)
    {
        if(i % 2) x = x * 10 + (s[i] - '0');
        else y = y * 10 + (s[i] - '0');

    }
    cout<<(x+1)*(y+1)-2<<"\n";
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
