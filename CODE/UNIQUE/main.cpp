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
const int MAXN = 2 * 1e5 + 1;
int n;
int a[MAXN];
int cnt[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("A.INP" , "r" , stdin);
//    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 1e9;
    int res = 0;
    for (int i=1 ; i<=n ; i++)
    {
        if(cnt[a[i]] == 1)
        {
            if(ans > a[i])
            {
                ans = a[i];
                res = i;
            }
        }
    }
    if(ans == 1e9)
    {
        cout << -1;
    }
    else    cout << res;
    return 0;
}
