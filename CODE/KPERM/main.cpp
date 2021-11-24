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
const int MAXN = 1e5 + 1;
int ans[MAXN];
int n , k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    int tmp = 0 , tmp1 = 0 , tmp2 = k + 2;
    for (int i=1 ; i<=n ; i++)
    {
        if(i <= k + 1)
        {
            if(i % 2 == 0)
            {
                tmp++;
                ans[i] = tmp;
            }
            else
            {
                ans[i] = 1 + k - tmp1;
                tmp1++;
            }
        }
        else
        {
            ans[i] = tmp2;
            tmp2++;
        }
    }
    for (int i=1 ; i<=n ; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
