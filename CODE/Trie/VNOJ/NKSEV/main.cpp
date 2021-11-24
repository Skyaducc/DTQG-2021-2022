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
const int MAXN = 400001;
const int MOD = 1337377;
string s;
int n , cnt;
int fns[MAXN] , child[MAXN][27] , f[MAXN];
void add(string s)
{
    int node = 0;
    for (char c : s)
    {
        int x = c - 'a';
        if(child[node][x] == 0) child[node][x] = ++cnt;
        node = child[node][x];
    }
    fns[node] = 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> s >> n;
    for (int i=1 ; i<=n ; i++)
    {
        string x;
        cin >> x;
        add(x);
    }
    f[0] = 1;
    for (int i=0 ; i<s.length() ; i++)
    {
        int node = 0 , j = i;
        while(true)
        {
            int x = s[j] - 'a';
            if (child[node][x] == 0) break;
            node = child[node][x];
            if (fns[node] == 1) f[j+1] = (f[j+1] + f[i]) % MOD;
            j++;
        }
//        cout << i << " " << f[i] << endl;
    }
    cout << f[s.length()];
    return 0;
}
