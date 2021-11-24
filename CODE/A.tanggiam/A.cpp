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
const int MAXN = 5e4 + 1;
int n , m , k;
multiset<int> s;
int a[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> k >> m >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    int res = oo;
    foru (i , 1 , m)
    {
    	auto sta = s.begin();
    	auto fns = s.end();
    	fns--;
    	s.erase(sta);
    	s.insert(*sta + k);
    	s.erase(fns);
    	s.insert(*fns - k);
    	sta = s.begin();
    	fns = s.end();
    	fns--;
    	res = min(res , (*fns - *sta));
    }
    cout << res;
    return 0;
}
