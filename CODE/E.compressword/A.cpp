#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<long long , int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl;
#define ll long long
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 1e6 + 1;
const int BASE = 2333333;
const int MOD = 1e9 + 7;
const ll MM = 1LL * MOD * MOD;
int n;
string s , ans;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    cin >> ans;
    foru (i , 2 , n)
    {
        cin >> s;
        long long Hash1 = 0 , Hash2 = 0 , tmp = 1;
        int pos = 0;
        foru (i , 1 , min(ans.size() , s.size()))
        {
            Hash1 = (Hash1 * BASE + ans[ans.size() - i]) % MOD;
            Hash2 = (s[i-1] * tmp + Hash2) % MOD;
            tmp = tmp * BASE % MOD;
            if (Hash1 == Hash2) pos = i;
        }
        ans += s.substr(pos);
    }
    cout << ans;
    return 0;
}