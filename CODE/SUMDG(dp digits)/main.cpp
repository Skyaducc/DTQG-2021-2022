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
int x , y;
vector<int> digitsX , digitsY;
int dp[16][180][2];
void get_digits(vector<int>& digits , int x)
{
    while(x)
    {
        digits.push_back(x%10);
        x/=10;
    }
}
int digit_sum(int idx , int tight , int sum , vector<int>& digits)
{
    if(idx == digits.size())   return sum;
    if(dp[idx][tight][sum] != -1 && tight != 1)
    {
        return dp[idx][tight][sum];
    }
    int ret = 0;
    int k = (tight) ? digits[idx] : 9;
    for (int i=0 ; i<=k ; i++)
    {
        int new_tight = (digits[idx] == i) ? tight : 0;
        ret += digit_sum(idx + 1 , new_tight , sum + i , digits);
    }
    if(!tight)
    {
        dp[idx][sum][tight] = ret;
    }
    return ret;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> x >> y;
    get_digits(digitsX , x-1);
    get_digits(digitsY , y);
    memset(dp , -1 , sizeof(dp));
    int ans1 = digit_sum(0 , 1 , 0 , digitsX);
    memset(dp , -1 , sizeof(dp));
    int ans2 = digit_sum(0 , 1 , 0 , digitsY);
    cout << ans2 - ans1;
    return 0;
}
