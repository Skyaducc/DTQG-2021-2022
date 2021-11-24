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
const int MAXN = 1e4 + 1;
const int oo = 1e8;
int n , m , cnt;
string s;
int child[MAXN][26];
int ans[MAXN];
void add(string s)
{
    int node = 0;
    for (char c : s)
    {
        int x = c - 'a';
        if(child[node][x] == 0) child[node][x] = ++cnt;
        node = child[node][x];
        ans[node]++;
    }
}
int found(string s)
{
   int node = 0;
   for (char c : s)
   {
       int x = c - 'a';
       node = child[node][x];
   }
   return ans[node];
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
        cin >> s;
        add(s);
    }
    cin >> m;
    while(m--)
    {
        cin >> s;
        cout << found(s) << endl;
    }
    return 0;
}
