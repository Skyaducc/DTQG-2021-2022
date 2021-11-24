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
const int MAXN = 2e5 + 1;
int n;
string s;
int cnt[MAXN];
int solve(string s , int x , int y)
{
    int res = 0;
    for (char c : s)
    {
        if((int)(c - '0') == x)
        {
            res++;
            swap(x , y);
        }
        cnt[(int)(c - '0')]++;
    }
    if (x != y && res % 2 == 1)
    {
        res--;
    }
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    while(n--)
    {
        cin >> s;
        int ans = 0;
        for (int i=0 ; i<=9 ; i++)
        {
            for (int j=0 ; j<=9 ; j++)
            {
                ans = max(ans , solve(s , i , j));
            }
        }
        cout << s.size() - ans << endl;
    }
    return 0;
}
