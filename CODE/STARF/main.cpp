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
int test;
int n , s;
const int MAXN = 1e5 + 1;
int w[MAXN] , v[MAXN];
int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("A.INP" , "r" , stdin);
//    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
        ans = 0;
        cin >> n >> s;
        for (int i=1 ; i<=n ; i++)  cin >> w[i];
        for (int i=1 ; i<=n ; i++)
        {
            cin >> v[i];
            ans += v[i];
        }
        for (int i=1 ; i<=n ; i++)
        {
            if(w[i] > s)
            {
                ans -= v[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
