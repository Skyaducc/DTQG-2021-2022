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
const int MAXN = 101;
int test , n , k;
int a[MAXN];
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
        cin >> n >> k;
        for (int i=1 ; i<=n ; i++)
        {
            cin >> a[i];
        }
        int i = 1 , j = n;
        while(true)
        {
            int tmp = a[i];
            if(a[i] == 0)
            {
                i++;
                continue;
            }
            if(i > j || k == 0)   break;
            a[i] = (k < tmp) ? a[i] - k : 0;
            a[j] = (k < tmp) ? a[j] + k : a[j] + tmp;
            k = (k <= tmp) ? 0 : k - tmp;
            i++;
            if(a[j] == 0)   j--;
        }
        for (int i=1 ; i<=n ; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
