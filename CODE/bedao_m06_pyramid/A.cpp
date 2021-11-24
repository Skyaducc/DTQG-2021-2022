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
#define int long long
using namespace std;
const int oo = 1e9;
double X , Y , a , b , c;
int giaiPT(double a, double b, double c,double &x1, double &x2)
{
    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        x1 = x2 = 0.0;
        return 0;
    }
    else if(delta == 0)
    {
        x1 = x2 = -b / (2 * a);
        return 1;
    }
    else
    {
        delta = sqrt(delta);
        x1 = (-b + delta) / (2 * a);
        x2 = (-b - delta) / (2 * a);
        return 2;
    }
}
#define COUT(a , b , c)	cout << fixed << setprecision(9) << a << " " << b << " " << c << endl;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> X >> Y;
    double x1 , x2;
    int tmp = giaiPT(1 , - 2 * (X + Y) , - (X * X - Y * Y) , x1 , x2);
    a = x1;
	b = Y - a;
	c = X + a;
	if(a > 0 && b > 0 && c > 0)
	{
		COUT(a , b , c);
		return 0;
	}
	a = x2;
	b = Y - a;
	c = X + a;
	if(a > 0 && b > 0 && c > 0)
	{
		COUT(a , b , c);
		return 0;
	}
	b = x1;
	a = Y - b;
	c = X + b;
	if(a > 0 && b > 0 && c > 0)
	{
		COUT(a , b , c);
		return 0;
	}
	b = x2;
	a = Y - b;
	c = X + b;
	if(a > 0 && b > 0 && c > 0)
	{
		COUT(a , b , c);
		return 0;
	}
	COUT(a , b , c);
    return 0;
}
