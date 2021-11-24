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
const int MAXN = 1e5 + 111;
int n , q;
int a[MAXN] , sum[MAXN] , Prev[MAXN];
int res = 0;
set<int> s[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	s[a[i]].insert(i);
    }
    foru (i , 1 , n)
    {
    	sum[i] = sum[i-1] + i - Prev[a[i]];
    	Prev[a[i]] = i; 
    	res += sum[i];
    }
    cin >> q;
    while(q--)
    {
    	int i , x;
    	cin >> i >> x;
    	s[a[i]].insert(0);
    	s[x].insert(0);
    	auto l = prev(s[a[i]].lower_bound(i));
    	auto l1 = prev(s[x].lower_bound(i));
    	auto r = s[a[i]].upper_bound(i);
    	auto r1 = s[x].upper_bound(i);
    	int Left = (l == s[a[i]].end())	? 0 : *l;
    	int Left1 = (l1 == s[x].end()) ? 0 : *l1;
    	int Right = (r == s[a[i]].end()) ? 0 : *r;
    	int Right1 = (r1 == s[x].end()) ? 0 : *r1;
        int tmp1 = 0 , tmp2 = 0;
        // a[i]
        tmp1 -= (n - i + 1) * (i - Left);
        if(Right != 0)
        {
            tmp1 -= (n - Right + 1) * (Right - i);
            tmp1 += (n - Right + 1) * (Right - Left);
        }
        // x
        tmp2 += (n - i + 1) * (i - Left1);
        if(Right1 != 0)
        {
            tmp2 += (n - Right1 + 1) * (Right1 - i);
            tmp2 -= (n - Right1 + 1) * (Right1 - Left1);
        }
        res += tmp1 + tmp2;
        cout << res << endl;
        // cout << res << " "  << tmp1 << " " << tmp2 << endl;
    	// cout << Left << " " << Left1 << " " << Right << " " << Right1 << endl;
    	s[a[i]].erase(i);
    	s[x].insert(i);
        a[i] = x;
    }
    return 0;
}
