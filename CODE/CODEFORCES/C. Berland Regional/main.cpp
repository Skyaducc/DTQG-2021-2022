#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,long long>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
using namespace std;
const long long oo = 1e18;
const int MAXN = 2 * 1e5 + 1;
int test;
int n;
int u[MAXN];
long long s[MAXN];
pii pi[MAXN];
bool cmp(pii x , pii y)
{
    if(x.fi == y.fi)    return x.se > y.se;
    else    return x.fi < y.fi;
}
long long ans[MAXN] , res[MAXN];
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
        cin >> n;
        for (int i=1 ; i<=n ; i++)
        {
            ans[i] = 0;
        }
        vector<pii> ve[n+1];
        for (int i=1 ; i<=n ; i++)  cin >> u[i];
        for (int i=1 ; i<=n ; i++)  cin >> s[i];
        for (int i=1 ; i<=n ; i++)
        {
            pi[i].fi = u[i];
            pi[i].se = s[i];
        }
        int cnt = 0 , cnt1 = 0;
        sort(pi + 1 , pi + 1 + n , cmp);
        for (int i=1 ; i<=n ; i++)
        {
            if(pi[i].fi != pi[i-1].fi)  cnt++;
            ve[cnt].push_back({pi[i].fi , pi[i].se});
        }
        int MAX = 0;
        cout << cnt << " " << MAX << endl;
        for (int i=1 ; i<=cnt ; i++)
        {
            res[0] = ve[i][0].se;
            for (int j=1 ; j<ve[i].size() ; j++)
            {
                res[j] = res[j-1] + ve[i][j].se;
            }
            for (int j=1 ; j<=MAX ; j++)
            {
                int tmp = (int)(ve[i].size() / j) * j;
                ans[j] += res[tmp-1];
            }
        }
        for (int i=1 ; i<=n ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
