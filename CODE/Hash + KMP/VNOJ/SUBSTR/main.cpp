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
const int MAXN = 1e6 + 1;
string a , b;
int n , m;
int lps[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> a >> b;
    n = a.length() , m = b.length();
    int tmp = 0;
    for (int i=1 ; i<m ; i++)
    {
        while(tmp > 0 && b[tmp] != b[i])   tmp = lps[tmp - 1];
        if(b[tmp] == b[i])  lps[i] = ++tmp;
        else    lps[i] = 0;
    }
    tmp = 0;
    for (int i=0 ; i<n ; i++)
    {
        while(tmp > 0 && b[tmp] != a[i])   tmp = lps[tmp - 1];
        if(b[tmp] == a[i])
        {
            tmp++;
            if(tmp == m)
            {
                cout << i - m + 2 << " ";
                tmp = lps[tmp - 1];
            }
        }
    }
    return 0;
}
