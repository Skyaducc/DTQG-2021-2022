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
int n , q , cnt;
const int MAXN = 1e5 + 1;
int a[MAXN] , prime[MAXN] , Is_prime[MAXN] , dp[MAXN][17] , Next[MAXN];
vector<int> A[MAXN];
void erathos()
{
    for (int i=2 ; i<MAXN ; i++)
    {
        if(prime[i] == 0)
        {
            for(int j=i*2 ; j<MAXN ; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i=2 ; i<MAXN ; i++)
    {
        if(prime[i] == 0)   Is_prime[++cnt] = i;
    }
}
void tach(int i)
{
    int tmp = a[i] , k = 1;
    while(tmp > 1)
    {
        if(tmp % Is_prime[k] == 0)
        {
            A[i].push_back(Is_prime[k]);
            while(tmp % Is_prime[k] == 0)
            {
                tmp /= Is_prime[k];
            }
        }
        k++;
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
    cin >> n >> q;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        tach(i);
    }
    for (int i=1 ; i<MAXN ; i++)    Next[i] = n + 1;
    dp[n+1][0] = n + 1;
    for (int i=n ; i>=0 ; i--)
    {
        dp[i][0] = dp[i+1][0];
        for (int j : A[i])
        {
            dp[i][0] = min(dp[i][0] , Next[j]);
            Next[j] = i;
        }
    }
    for (int j=1 ; j<20 ; j++)
    {
        for (int i=1 ; i<=n ; i++)
        {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    while(q--)
    {
        int l , r;
        cin >> l >> r;
        int ans = 0;
        for (int i=17 ; i>=0 ; i--)
        {
            if(dp[l][i] <= r)
            {
                ans++;
                l = dp[l][i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
