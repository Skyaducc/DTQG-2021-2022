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
int n;
int a[MAXN] , dp[MAXN] , prime[MAXN];
void erathos()
{
    for (int i=2 ; i<MAXN ; i++)
    {
        if(prime[i] == 0)
        {
            for (int j=i*2 ; j<MAXN ; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    erathos();
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i=1 ; i<=n ; i++)
    {
        for (int j=i-5; j<=i+5 ; j++)
        {
            if(j >= 1 && j<=n && a[j] < a[i] && prime[a[i] - a[j]] == 0)
            {
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
    }
    cout << dp[n];
    return 0;
}
