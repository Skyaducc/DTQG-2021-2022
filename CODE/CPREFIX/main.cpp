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
using namespace std;
string s;
const int MAXN = 1e5 + 1;
int n;
int a[MAXN] , cnt[MAXN] , ans[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("A.INP" , "r" , stdin);
    //freopen("A.OUT" , "w" , stdout);
    cin >> s;
    n = s.length();
    s = " " + s;
    for (int i=1 ; i<=n ; i++)
    {
        cnt[s[i] - 'a']++;
        ans[i] = cnt[s[i] - 'a'];
    }
    for (int i=n ; i>=1 ; i--)
    {
        cout << ans[i] << " " ;
    }
    return 0;
}
