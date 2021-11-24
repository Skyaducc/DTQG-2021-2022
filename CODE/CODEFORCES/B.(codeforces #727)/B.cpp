// abacaba
// 1 3 4 7 8 10 11
// 1 3 -> 4
// 2 5 -> 7
// 1 7 -> 11
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
#define reset(arr) memset((arr) , 0 , sizeof(arr))
using namespace std;
const int MAXN = 1e5 + 1;
int Sum[MAXN];
string s;
int n , q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> q >> s;
    s = " " + s;
    for (int i=1 ; i<=n ; i++)
    {
    	Sum[i] = Sum[i-1] + (int)(s[i] - 'a') + 1;
    	// cout << Sum[i] << endl;
    }
    while(q--)
    {
    	int l , r;
    	cin >> l >> r;
    	cout << Sum[r] - Sum[l-1] << endl;
    }
    return 0;
}
