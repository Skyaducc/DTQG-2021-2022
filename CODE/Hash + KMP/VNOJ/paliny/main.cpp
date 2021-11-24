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
const int MAXN = 5 * 1e4 + 1;
const int BASE = 101;
const int MOD = 1e9 + 7;
const long long MM = 1ll * MOD * MOD;
int n;
string a , b;
int hashA[MAXN] , hashB[MAXN] , POW[MAXN];
void init()
{
    for (int i=1 ; i<=n ; i++)
    {
        hashA[i] = ((hashA[i-1] * BASE) + a[i]) % MOD;
        hashB[i] = ((hashB[i-1] * BASE) + b[i]) % MOD;
    }
    POW[0] = 1;
    for (int i=1 ; i<=n ; i++)   POW[i] = (POW[i-1] * BASE) % MOD;
}

int get_hash_A(int l, int r)
{
	return (hashA[r] - hashA[l-1] * POW[r-l+1] + MM) % MOD;
}
int get_hash_B(int l , int r)
{
    return (hashB[r] - hashB[l-1] * POW[r-l+1] + MM) % MOD;
}
bool check(int len)
{
   for (int i=1 ; i<=n-len+1 ; i++)
   {
       int tmp = get_hash_A(i , i+len-1);
       int tmp1 = get_hash_B(n-(i+len-1)+1 , n-i+1);
       if(tmp == tmp1)  return true;
   }
   return false;
}
int solve(int x)
{
    int l = 1 , r = n;
    int ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        int tmp = mid;
        if(mid % 2 != x)    tmp++;
        if(check(tmp))
        {
            ans = tmp;
            l = mid + 1;
        }
        else    r = mid - 1;
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> a;
    b = string(a.rbegin() , a.rend());
    n = a.length();
    a = " " + a;
    b = " " + b;
    init();
    cout << solve(1);
//    cout << max(solve(0) , solve(1));
//    cout << get_hash_A(3 , 7) << " " << get_hash_B(3 , 7);
    return 0;
}
