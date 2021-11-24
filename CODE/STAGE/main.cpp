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
int a[7];
const int oo = 1e8;
int x[7] , d[7];
int GET(int x , int y , int x1 , int y1 , int x2 , int y2)
{
    int ans =  x * y + x1 * y1 + x2 * y2
          - min(x, x1) * min(y, y1)
          - min(x1, x2) * min(y1, y2)
          - min(x2, x) * min(y2, y)
          + min({x, min(x1, x2)}) * min({y, min(y1, y2)});
    return ans;
}
int ans = oo;
void check()
{
    memset(d , 0 , sizeof(d));
    for (int i=1 ; i<=6 ; i++)
    {
        d[x[i]]++;
        if(i % 2 == 0)
        {
            if(d[1] != d[2]) return;
        }
    }
    if(x[1] == 2 && x[2] == 1)  swap(a[1] , a[2]);
    if(x[3] == 2 && x[5] == 1)  swap(a[3] , a[4]);
    if(x[5] == 2 && x[6] == 1)  swap(a[5] , a[6]);
    int tmp = GET(a[1] , a[2] , a[3] , a[4] , a[5] , a[6]);
    ans = min(ans , tmp);
}
void sinh(int i)
{
    for(int j=1 ; j<=2 ; j++) // 1 la chieu rong , 2 la chieu dai
    {
        x[i] = j;
        if(i == 6)
        {
            check();
        }
        else    sinh(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    while(true)
    {
        ans = oo;
        for (int i=1 ; i<=6 ; i++)
        {
            cin >> a[i];
        }
        if(a[1] == a[2] && a[1] == 0)   break;
        sinh(1);
        cout << ans << endl;
    }
    return 0;
}
