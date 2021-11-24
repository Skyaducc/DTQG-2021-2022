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
int test , n;
int sum[MAXN] , cnt[MAXN];
string s;
map<int,int> m;
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
        cin >> n >> s;
        s = " " + s;
        m.clear();
        int ans = 0;
        int sum = 0;
        m[0] = 1;
        for (int i=1 ; i<=n ; i++)
        {
            sum += (s[i] - '0') - 1;
            ans += m[sum];
            m[sum]++;
        }
        cout << ans << endl;
    }
    return 0;
}
