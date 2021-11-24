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
const int MAXN = 1000005;
const int MAX = 1000000;
const int oo = 1e9;
int s , t , uoc;
vector<pii> ve;
int pr[MAXN] , dp[MAXN] , h[30];
void erathos()
{
    for(int i=2 ; i*i<=MAX ; i++)
    {
        if(pr[i] == 0)
        {
            for(int j=i*i ; j<=MAX ; j+=i)
                pr[j] = i;
        }
    }
    pr[1] = 1;
    for(int i=2 ; i<=MAX ; i++)
        if(pr[i] == 0) pr[i] = i;
}
int mu(int a , int b)
{
    if(b == 0) return 1;
    int tmp = mu(a , b/2);
    if(b % 2 == 0) return tmp * tmp;
    return tmp * tmp * a;
}
void check()
{
    int s=1;
    for(int i=0 ; i<ve.size() ; i++)
        s *= mu(ve[i].fi, h[i]);
    if(s == 1 || s == uoc || s + uoc > t) return;
    dp[s+uoc] = min(dp[s+uoc], dp[uoc] + 1);
}
void calc(int i)
{
    for(int j=0 ; j<=ve[i].se ; j++)
    {
        h[i] = j;
        if(i == (ve.size() - 1)) check();
        else calc(i + 1);
    }
}
void pt(int x)
{
    ve.clear();
    while(x > 1)
    {
        int k = pr[x];
        ve.push_back({k , 0});
        while(x % k == 0)
        {
            x /= k;
            ve.back().se++;
        }
    }
    calc(0);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("divisors.inp" , "r" , stdin);
    freopen("divisors.out" , "w" , stdout);
    erathos();
    cin >> s >> t;
    if(s == t)
    {
        cout << 0;
        return 0;
    }
    if(pr[s] == s)
    {
        cout << -1;
        return 0;
    }
//    pt(30);
    for (int i=s ; i<=t ; i++)  dp[i] = oo;
    dp[s] = 0;
    for (int i=s ; i<t ; i++)
    {
        if(pr[i] == oo)   continue;
        uoc = i;
        pt(i);
    }
    if(dp[t] == oo) dp[t] = -1;
    cout << dp[t];
    return 0;
}
