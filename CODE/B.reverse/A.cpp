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
int n , res;
int a[MAXN];
string s[MAXN], s1[MAXN];
int f[MAXN][2];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("reverse.inp" , "r" , stdin);
    freopen("reverse.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n) cin >> a[i];
    foru (i , 1 , n) 
    {
        cin >> s1[i];
        s[i] = s1[i];
        reverse(s1[i].begin(), s1[i].end());
    }
    f[1][0] = 0; 
    f[1][1] = a[1];
    foru (i , 2 , n)
    {
        f[i][0] = f[i][1] = oo;
        if (s[i - 1] <= s[i]) f[i][0] = min(f[i][0] , f[i - 1][0]);
        if (s1[i - 1] <= s[i]) f[i][0] = min(f[i][0] , f[i - 1][1]);
        if (s[i - 1] <= s1[i]) f[i][1] = min(f[i][1] , f[i - 1][0] + a[i]);
        if (s1[i - 1] <= s1[i]) f[i][1] = min(f[i][1] , f[i - 1][1] + a[i]);
    }
    res = min(f[n][0] , f[n][1]);
    cout << ((res == oo) ? -1 : res);
    return 0;
}