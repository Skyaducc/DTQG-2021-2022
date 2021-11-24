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
const int MAXN = 50001;
const int MOD = 1e9 + 7;
const int BASE = 101;
const long long MM = 1LL * MOD * MOD;
long long Hash[MAXN];
long long POW[MAXN];
long long a[MAXN];
int n , k;
string s;
void init()
{
    POW[0] = 1;
    for (int i=1 ; i<=n ; i++)
    {
        Hash[i] = (Hash[i-1] * BASE + s[i]) % MOD;
        POW[i] = (POW[i-1] * BASE) % MOD;
    }
}
long long get_hash(int l , int r)
{
    return (Hash[r] - Hash[l-1] * POW[r-l+1] + MM) % MOD;
}
bool check(int x)
{
    int pos = 0;
    for(int i=1 ; i<=n-x+1 ; i++)
    {
        long long tmp = get_hash(i , i+x-1);
        a[pos++] = tmp;
    }
    sort(a , a + pos);
    int res = 1;
    for (int i=1 ; i<pos ; i++)
    {
        if(a[i] == a[i-1])
        {
            res++;
            if(res >= k)    return true;
        }
        else    res = 1;
    }
    return false;
}
int solve()
{
    int l = 1 , r = n;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else    r = mid - 1;
    }
    if(ans == 49999)    ans = 50000;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> s;
    s = " " + s;
    init();
    cout << solve();
    return 0;
}
