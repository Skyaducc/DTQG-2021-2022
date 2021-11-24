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
const int oo = 1e9;
int a[17][17];
int f[1 << 17][17];
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
        for (int j=0 ; j<n ; j++)
        {
            cin >> a[i][j];
        }
    }
    int last = (1 << n);
    for (int mask=0 ; mask<last ; mask++)
    {
        for (int i=0 ; i<n ; i++)
        {
            f[mask][i] = oo;
        }
    }
    for (int i=0 ; i<n ; i++)
    {
        f[1 << i][i] = 0;
    }
    for (int mask=1 ; mask<last ; mask++)
    {
        for (int i=0 ; i<n ; i++)
        {
            if(BIT(mask , i))
            {
                for (int j=0 ; j<n ; j++)
                {
                    if(!BIT(mask , j) && j != i)
                    {
                        int p = mask + (1 << j);
                        f[p][j] = min(f[p][j] , f[mask][i] + a[i][j]);
//                        cout << f[p][j] << endl;
                    }
                }
            }
        }
    }
    int ans = oo;
    for (int i=0 ; i<n ; i++)
    {
        ans = min(ans , f[last-1][i]);
//        cout << f[last-1][i] << endl;
    }
    cout << ans;
    return 0;
}
