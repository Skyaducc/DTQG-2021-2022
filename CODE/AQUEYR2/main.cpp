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
#define int long long
using namespace std;
const int MAXN = 1e5 + 1;
int q , k;
pii a[MAXN];
bool cmp(pii x , pii y)
{
    return x.fi < y.fi;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("A.INP" , "r" , stdin);
    //freopen("A.OUT" , "w" , stdout);
    cin >> q;
    for (int i=1 ; i<=q ; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1 , a + 1 + q , cmp);
    cin >> k;
    int i = 1;
    while(true)
    {
        if(k <= a[i].se)
        {
            cout << a[i].fi;
            break;
        }
        k -= a[i].se;
        i++;
    }
    return 0;
}
