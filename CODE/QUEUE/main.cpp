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
int a[21][21];
int f[1 << 20 + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=0 ; i<n ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            cin >> a[i][j];
        }
    }
    f[0] = 0;
    int last = (1 << n) - 1;
    for (int mask=0 ; mask<=last ; mask++)
    {
        int k = __builtin_popcount(mask);
        for (int i=0 ; i<n ; i++)
        {
            if(BIT(mask , i) == 0)
            {
                int p = mask + (1 << i);
                f[p] = max(f[p] , f[mask] + a[i][k+1]);
            }
        }
    }
    cout << f[last];
    return 0;
}
