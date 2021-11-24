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
const int MAXN = 1e6 + 1;
const int BASE = 101;
const int MOD = 1e9 + 7;
const int MM = 1ll * MOD * MOD;
string a , b;
int hashB[MAXN] , H[MAXN];
int hashA;
int GET_HASH(int x , int y)
{
    return ( hashB[y] - hashB[x-1] * H[y-x+1] + MM) % MOD;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> a >> b;
    int n = a.length() , m = b.length();
    a = " " + a;
    b = " " + b;
    H[0] = 1;
    for (int i=1 ; i<=m ; i++)
    {
        hashB[i] = ((hashB[i-1] * BASE) + b[i]) % MOD;
    }
    for (int i=1 ; i<=m ; i++)
    {
        H[i] = (H[i-1] * BASE) % MOD;
    }
    for (int i=1 ; i<=n ; i++)
    {
        hashA = (hashA * BASE + a[i]) % MOD;
    }
    vector<int> res;
    for (int i=n ; i<=m ; i++)
    {
        int j = i - n + 1;
        if(GET_HASH(j , i) == hashA)
        {
            res.push_back(j);
        }
    }
    cout << res.size() << endl;
    for (int x : res)   cout << x << " ";
    return 0;
}
