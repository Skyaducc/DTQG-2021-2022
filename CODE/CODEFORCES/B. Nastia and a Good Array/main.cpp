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
int test;
int n;
int a[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
        cin >> n;
        int x = 1e9 , pos = n;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> a[i];
            if (a[i] < x) x = a[i] , pos = i;
        }
        cout << n - 1 << endl;
        for (int i=1 ; i<=n ; i++)
        {
            if (i == pos) continue;
            cout << pos << " "  << i << " " << x << " " << x + abs(i - pos) << endl;
        }
    }
    return 0;
}
