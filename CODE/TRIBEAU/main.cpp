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
int a , b , c , d;
int get(int x , int y)
{
    return abs(x - y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("A.INP" , "r" , stdin);
//    freopen("A.OUT" , "w" , stdout);
    cin >> a >> b >> c >> d;
    if(get(a , b) <= d && get(a , c) <= d && get(b , c) <= d)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
