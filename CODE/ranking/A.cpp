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
const int MAXN = 2001;
int n;
struct Data
{
	int x , y , z , id;
	bool operator < (const Data & tmp)	const
	{
		return (x == tmp.x) ? y < tmp.y : x < tmp.x;
	}
} a[MAXN];
pii res[MAXN];
bool check(int i , int m , int j , int n) // i rank m va j rank n
{
	int tmp1[4] , tmp2[4];
	tmp1[1] = a[i].x , tmp1[2] = a[i].y , tmp1[3] = m;
	tmp2[1] = a[j].x , tmp2[2] = a[j].y , tmp2[3] = n;
	sort(tmp1 + 1 , tmp1 + 1 + 3);
	sort(tmp2 + 1 , tmp2 + 1 + 3);
	foru (i , 1 , 2)
    {
        if (tmp1[i] == tmp1[i + 1])
        {
            tmp1[i + 1]++;
            tmp1[i] = 0;
        }
        if (tmp2[i] == tmp2[i + 1])
        {
            tmp2[i + 1]++;
            tmp2[i] = 0;
        }
    }
    sort(tmp1 + 1 , tmp1 + 1 + 3);
    sort(tmp2 + 1 , tmp2 + 1 + 3);
    ford (i , 3 , 1)
    {
        if (tmp2[i] < tmp1[i]) return 1;
        if (tmp2[i] > tmp1[i]) return 0;
    }
    return 0;
}
void Getmin(int i)
{
	int x = n - i + 2;
	res[a[i].id].fi = 1;	
	ford (j , i - 1 , 1)
	{
		while(x <= n && check(i , 1 , j , x))	x++;
		if(x > n)	res[a[i].id].fi++;
		x++;
	}
}
void Getmax(int i)
{
	int x = n - i;
	res[a[i].id].se = i;
	foru (j , i + 1 , n)
	{
		while (x >= 1 && !check(i , n , j , x)) x--;
        if (x >= 1) res[a[i].id].se++;
        x--;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i].x;
    foru (i , 1 , n)
    {
    	cin >> a[i].y;
    	if(a[i].x < a[i].y)	swap(a[i].x , a[i].y);
    	a[i].id = i;
    }
    sort(a + 1 , a + 1 + n);
    foru (i , 1 , n)
    {
    	Getmin(i);
    	Getmax(i);
    }
    foru (i , 1 , n)
    {
    	cout << res[i].fi << " " << res[i].se << endl;
    }
}
