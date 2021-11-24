#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define FORU(i , a , b) for (int i = a ; i <= b ; i++)
#define FORD(i , a , b) for (int i = a ; i >= b ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define oo 1e18
#define task "boardgame"
using namespace std;
int r , c;
vector < vector <int> > a;
int res;
bool chk = 1;
void sub2()
{
    FORU(i , 1 , c) res += a[1][i];
    cout << res;
}
void sub4()
{
    cout << min(r , c) + min(r , c) - 1 + abs(r - c);
}
void sub3()
{
    int ret = oo;
    FORU(i , 1 , c)
    {
        ret = min(ret , max(a[1][i] , a[2][i]));
        res += min(a[1][i] , a[2][i]);
    }
    cout << res + ret;
}
void input()
{
    cin >> r >> c;
    a.assign(r + 2 , vector <int> (c + 2 , 0));
    FORU(i , 1 , r) FORU(j , 1 , c)
    {
        cin >> a[i][j];
        if (a[i][j] != 1) chk = 0;
    }
}
void solve()
{
    if (r == 1)
    {
        sub2();
        return;
    }
    if (r == 2)
    {
        sub3();
        return;
    }
    if (chk) sub4();
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    input();
    solve();
    return 0;
}