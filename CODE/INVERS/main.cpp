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
int n;
const int MAXN = 1e5 + 1;
int a[MAXN] , bit[MAXN];
void update(int x , int d)
{
    while(x <= 2 * n)
    {
        bit[x] += d;
        x += x & (-x);
    }
}
int get(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += bit[x];
        x -= x & (-x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i=n ; i>=1 ; i--)
    {
        res += get(a[i]-1);
        update(a[i] , 1);
    }
    cout << res;
    return 0;
}
