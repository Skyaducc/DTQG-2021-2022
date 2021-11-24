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
const int MAXN = 5001;
int n;
int a[MAXN] , dp[MAXN][MAXN];
vector<int> ve;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=0 ; i<n ; i++)
    {
        cin >> a[i];
        if(a[i] == 1)   ve.push_back(i);
    }
    for (int i=0 ; i<=n ; i++)
    {
        for (int j=0 ; j<=n ; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<=ve.size() ; j++)
        {
            if(dp[i][j] == 1e9) continue;
            dp[i+1][j] = min(dp[i][j] , dp[i+1][j]);
            if(a[i] == 0 && j < ve.size())
            {
                dp[i+1][j+1] = min(dp[i][j] + abs(ve[j] - i) , dp[i+1][j+1]);
            }
        }
    }
    cout << dp[n][ve.size()];
    return 0;
}
