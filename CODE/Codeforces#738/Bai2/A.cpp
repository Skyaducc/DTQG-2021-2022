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
#define ll long long 
char A[] = {'B' , 'R'};
using namespace std;
void Testcase() 
{
    ll n, i = 0;
    string s;
    cin >> n >> s;
    while (s[i] == '?') ++i;
    if (i == n) 
    {
        ll x = 0;
        for (ll j = 0; j < n; ++j) 
        {
            cout << A[x];
            x = 1 - x;
        }
        cout << '\n';
        return;
    }
    i = n - 1;
    while (s[i] == '?') --i;
    ++i;
    ll xx;
    if (s[i - 1] == 'B') xx = 1; else xx = 0;
    while (i < n) 
    {
        s[i] = A[xx];
        xx = 1 - xx;
        ++i;
    }
    s += '1';
    for (ll j = 0; j < s.size() - 1; ++j) 
    {
        if (s[j] == '?' && s[j + 1] != '?') 
        {
            ll k = j;
            ll x;
            if (s[j + 1] == 'B') x = 1; else x = 0;
            while (k >= 0 && s[k] == '?') 
            {
                s[k] = A[x];
                x = 1 - x;
                --k;
            }
        }
    }
    for (ll i = 0; i < n; ++i) cout << s[i];
    cout << '\n';
}

namespace SUBTASK 
{
    void solve() 
    {
        ll t;
        cin >> t;
        while (t--) Testcase();
    }
}
int main() 
{
    SUBTASK :: solve();
    return 0;
}
