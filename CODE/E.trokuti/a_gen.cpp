#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
int randnum(int l , int r)
{
	return rand() % (r - l + 1) + l;
}
int main()
{
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    freopen("trokuti.out" , "w" , stdout);
    cin.tie(0);
    cout.tie(0);
    int n = 1000;
    int m = 1000;
    cout << n << " " << m << endl;
    foru (i , 1 , n)
    {
        foru (j , 1 , m)
        {
            cout << randnum(0 , 1) << " ";
        }
        cout << endl;
    }
    return 0;
}