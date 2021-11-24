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
int test;
int n , m;
void solve()
{
    cin >> m >> n;
    if(n > m)   swap(n , m);
    int last = 1 << n;
    int f[m+1][last];
    for (int mask=0 ; mask<=last ; mask++)
    {
        f[0][mask] = 1;
    }
    for (int i=0 ; i<m ; i++)
    {
        for (int mask=0 ; mask<last ; mask++)
        {
//            f[i][mask] = 0;
            for (int j=0 ; j<n-1 ; j++)
            {
                if(BIT(mask , j) != BIT(mask , j+1))
                {
                    if(!BIT(mask , j))
                    {
                        f[i+1][(mask) & ~(1 << (j+1))] += f[i][mask];
                        f[i+1][mask] += f[i][mask];
                        int p = mask + (1 << j);
                        p = SET_OFF(p , (j+1));
                        f[i+1][p] += f[i][mask];
                        f[i+1][mask + (1 << j)] += f[i][mask];
                    }
                    else
                    {
                        f[i+1][(mask) & ~(1 << j)] += f[i][mask];
                        f[i+1][mask + (1 << (j+1))] += f[i][mask];
                        int p = mask + (1 << (j+1));
                        p = SET_OFF(p , (j+1));
                        f[i+1][p] += f[i][mask];
                        f[i+1][mask] += f[i][mask];
                    }
                }
                if(BIT(mask , j) == BIT(mask , j+1))
                {
                    if(!BIT(mask , j))
                    {
                        f[i+1][mask + (1 << (j+1))] += f[i][mask];
                        f[i+1][mask + (1 << j)] += f[i][mask];
                        f[i+1][mask + (1 << j) + (1 << (j+1))] += f[i][mask];
                    }
                    else
                    {
                        f[i+1][(mask) & ~(1 << j)] += f[i][mask];
                        f[i+1][(mask) & ~(1 << (j+1))] += f[i][mask];
                        f[i+1][(mask) & ~(1 << j) & ~(1 << (j+1))] += f[i][mask];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int mask=0 ; mask<last ; mask++)
    {
        ans += f[m-1][mask];
    }
    cout << ans;
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
