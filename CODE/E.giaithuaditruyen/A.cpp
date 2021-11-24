#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
using namespace std;
const int oo = 1e9;
const int MAXN = 21;
int n;
int a[MAXN] , b[MAXN] , pos1[MAXN] , pos2[MAXN];
int ok[MAXN][MAXN];
long long dp[1 << 20];
vector<int> candidate[MAXN];
int cnt[21];
vector<int> v[1 << 20];
int dd[21];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
        cin >> a[i];
        pos1[a[i]] = i;
    }
    foru (i , 1 , n)
    {
        cin >> b[i];
        pos2[b[i]] = i;
    }
    foru (i , 0 , n - 1)
    {
        foru (j , pos1[i+1] + 1 , n)    candidate[i].push_back(a[j]);
        foru (j , pos2[i+1] + 1 , n)    candidate[i].push_back(b[j]);
        sort(candidate[i].begin() , candidate[i].end());
        candidate[i].erase(unique(candidate[i].begin() , candidate[i].end()) , candidate[i].end());
    }
    foru (i , 0 , n - 1)
    {
        int tmp = 0;
        for (int x : candidate[i])
        {
            tmp = SET_ON(tmp , x - 1);
        }
        dd[i] = tmp;
    }
    int last = (1 << n);
    foru (i , 0 , n - 1)
    {
        dp[1 << i] = 1;
    }
    foru (mask , 1 , last - 1)
    {
        int tmp = last - 1;
        foru (i , 0 , n - 1)
        {
            if(BIT(mask , i))   tmp &= dd[i];
        }
        foru (i , 0 , n - 1)
        {
            if(BIT(tmp , i) == 1)
            {
                v[mask].push_back(i);
            }
        }
        for (int x : v[mask])
        {
            if(!BIT(mask , x))
            {
                int new_mask = SET_ON(mask , x);
                dp[new_mask] += dp[mask];
            }
        }
    }
    cout << dp[last - 1];
    return 0;
}