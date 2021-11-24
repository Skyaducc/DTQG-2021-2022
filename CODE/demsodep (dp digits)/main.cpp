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
int test , l , r;
vector<int> digitsL , digitsR;
int dp[20][2][20];
int dem[11];
void get_digits(vector<int>& digits , long long x)
{
    while(x)
    {
        digits.push_back(x%10);
        x /= 10;
    }
    reverse(digits.begin() , digits.end());
}
int Count(int idx , int tight , int cnt , vector<int>& digits)
{
    if(idx == digits.size())
    {
        if(cnt <= 3)
        {
            return 1;
        }
        return 0;
    }
    if(dp[idx][tight][cnt] != -1 && tight != 1)
    {
        return dp[idx][tight][cnt];
    }
    int ret = 0;
    int k = (tight) ? digits[idx] : 9;
    for (int i=0 ; i<=k ; i++)
    {
        int new_tight = (digits[idx] == i) ? tight : 0;
        int new_cnt = cnt;
        if(i != 0)  new_cnt++;
        ret += Count(idx + 1 , new_tight , new_cnt , digits);
    }
    if(!tight)
    {
        dp[idx][tight][cnt] = ret;
    }
    return ret;
}
void solve()
{
    cin >> l >> r;
    get_digits(digitsL , l-1);
    get_digits(digitsR , r);
    memset(dp , -1 , sizeof(dp));
    int ans1 = Count(0 , 1 , 0 , digitsL);
    memset(dp , -1 , sizeof(dp));
    int ans2 = Count(0 , 1 , 0 , digitsR);
//    cout << ans2 << " " << ans1 << endl;
    cout << ans2 - ans1 << endl;
    digitsL.clear();
    digitsR.clear();
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
        solve();
    }
    return 0;
}
