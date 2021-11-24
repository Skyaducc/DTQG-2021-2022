#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
int randnum(int l , int r)
{
	return l + rand() % (r - l + 1);
}
int main()
{
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("teams.inp" , "r" , stdin);
    int n = randnum(1 , 20);
    cout << n << endl;
    foru (i , 1 , n)
    {
    	int l = randnum(1 , 1000);
    	int v = randnum(l + 1 , 10000);
    	int r = randnum(v + 1 , 1000000);
    	cout << l << " " << v << " " << r << endl;
    }
    return 0;
}
