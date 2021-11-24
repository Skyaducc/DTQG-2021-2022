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
int n , m;
int a[MAXN];
int cnt[MAXN];
vector<int> f;
void brute()
{
    int ans = 0;
    for (int i=1 ; i<=n ; i++)
    {
        int mask = 0;
        mask += (1 << i);
        for (int j=i+1 ; j<=n ; j++)
        {
            if(BIT(mask , a[j]) == 0)
            {
                mask += (1 << a[j]);
            }
            int k = __builtin_popcount(mask);
            if(k > m)   break;
            ans = max(ans , j - i + 1);
        }
    }
    cout << ans;
}
void full()
{
    int k = 0;
    f.push_back(1);
    for (int i=1 ; i<=n ; i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]] == 1)  k++;
        f.push_back(k);
        cout << f[i] << " " ;
    }
    cout << endl;
    for (int i=1 ; i<=n ; i++)
    {
        int tmp = f[i] + m - f[i-1];
        int x = *upper_bound(f.begin() , f.end() , tmp);
        cout << tmp << " " << x << endl;
//        if(x == *f.end())   cout << a[n] << " ";
//        else    cout << x-1 << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
    }
//    brute();
    full();
    return 0;
}
