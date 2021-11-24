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
const int MAXN = 250001;
int n , cnt;
int child[MAXN][27];
int dem[MAXN] , f[MAXN];
string s[MAXN];
void add(string s)
{
    int node = 0;
    for (char c : s)
    {
        int x = c - 'a';
        if(child[node][x] == 0)
        {
            child[node][x] = ++cnt;
//            cout << c << " " << child[node][x] << " " << node << endl;
        }
        node = child[node][x];
    }
    dem[node] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> s[i];
        add(s[i]);
    }
    for(int i=cnt ; i>=0 ; i--)
    {
        for (int j=0 ; j<26 ; j++)
        {
            if(child[i][j])
            {
                f[i] = max(f[i] , f[child[i][j]]);
            }
        }
        f[i] += dem[i];
    }
    cout << f[0] << endl;
    return 0;
}
