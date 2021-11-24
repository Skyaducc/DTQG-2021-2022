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
using namespace std;
const int oo = 1e9;
int test;
void solve()
{
    int n;
    cin >> n;
    int a[n];
    foru (i , 0 , n - 1)    cin >> a[i];
    foru (i , 1 , n - 1)
    {
        if(a[i-1] == 0 && a[i] == 1)
        {
            foru (j , 0 , i - 1)
            cout << j+1 << " ";
            cout << n+1 << " ";
            foru (j , i , n - 1)
            cout << j+1 << " ";
            cout << endl;
            return;
        }
    }
    if(a[0] == 1)
    { 
        cout << n + 1 << " ";
        foru (i , 0 , n - 1)   cout << i + 1 << " ";
        cout << endl;
        return;
    }
    if(a[n-1] == 0)
    {
        foru (i , 0 , n - 1)
        cout << i+1 << " ";
        cout << n+1 << " ";
        cout << endl;
        return; 
    }
 
    cout << "-1" << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
