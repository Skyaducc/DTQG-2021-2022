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
const int MAXN = 101;
int test , n;
int a[MAXN] , cnt[MAXN];
void solve()
{
    cin >> n;
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ans = *min_element(a + 1 , a + 1 + n);
    cout << n - cnt[ans] << endl;
    for (int i=1 ; i<MAXN ; i++)
    {
        cnt[i] = 0;
    }
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
