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
int a , b , k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> a >> b >> k;
    if((b <= 1 && k > 0) || (k != 0 && k > a + b - 2) || (a == 0 && k > 0))
    {
        cout << "NO" << endl;
        return 0;
    }
    string x , y;
    for(int i=0 ; i<b ; i++)
    {
        x += '1';
    }
    for(int i=0 ; i<a ; i++)
    {
        x += '0';
    }
    if(k != 0 && x[k+1] != '0')
    {
        x[k+1] = '0';
        x[x.length()-1] = '1';
    }
    y = x;
    if (k > 0)
    {
        y[1] = '0';
        y[k+1] = '1';
    }
    cout << "YES" << endl;
    cout << x << endl << y << endl;
    return 0;
}
