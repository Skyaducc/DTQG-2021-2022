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
int n , m , q;
int a[1001][1001];
int main()
{
	srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    n = randnum(1 , 100);
    m = randnum(1 , 100);
    q = randnum(1 , 1000);
    cout << n << " " << m << endl;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		a[i][j] = randnum(1 , 1000);
    		cout << a[i][j] << " ";
    	}
    	cout << endl;
    }
    cout << q << endl;
    foru (i , 1 , q)
    {
    	int type = randnum(0 , 1);
    	cout << type << " ";
    	if(type == 0)
    	{
    		cout << randnum(1 , 1000) << " " << randnum(1 , 1000) << endl;
    	}
    	else
    	{
    		cout << randnum(1 , n) << " " << randnum(1 , m) << " ";
    		cout << randnum(1 , n) << " " << randnum(1 , m) << endl;
    	}
    }
    return 0;
}
