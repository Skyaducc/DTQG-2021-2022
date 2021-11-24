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
#define db1 x == 1 && y == 2 && ok == -1
#define db2 x == 1 && y == 2 && ok == 1
#define db3 x == 3 && y == 3 && ok == -1
#define db4 x == 4 && y == 4 && ok == 11
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 2e5 + 1;
const int LOGN = 20;
int test;
string s;
int n;
int height[MAXN] , weight[MAXN];
int f[MAXN][LOGN + 1][5];
int Get(int l , int r , int x)
{
	if(l > r)	return 0;  
	int k = log2(r - l + 1);
	if(x == 1 || x == 3)	return max(f[l][k][x] , f[r-(1<<k)+1][k][x]);
	else return min(f[l][k][x] , f[r-(1<<k)+1][k][x]);
}
int Calc(int x , int y , int ok)
{
	int x1 = (x == 1) ? 3 : 1;
	int y1 = (y == 2) ? 4 : 2;
	int temp1 = Get(1 , n , x1);
	int temp2 = Get(1 , n , y1);
	int ret = ((temp1 < 0) ? 0 : temp1) - ((temp2 > 0) ? 0 : temp2) + 1;
	int tmp = oo;
	foru (i , 1 , n)
	{
		int new_i = i;
		if((s[i] == 'S' || s[i] == 'W') && x == 1)	new_i++;
		if((s[i] == 'A' || s[i] == 'D') && x == 3)	new_i++;
		int Ma1 = Get(1 , new_i - 1 , x);
		int Mi1 = Get(1 , new_i - 1 , y);
		Ma1 = (Ma1 < 0) ? 0 : Ma1;
		Mi1 = (Mi1 > 0) ? 0 : Mi1;
		int Ma2 = Get(i , n , x) + ok;
		int Mi2 = Get(i , n , y) + ok;
		tmp = min(tmp , max(Ma1 , Ma2) - min(Mi1 , Mi2) + 1);
	}
	return ret * tmp;
}
void solve()
{
	cin >> s;
	n = s.length();
	s = " " + s;
	foru (j , 0 , 19)
	{
		foru (i , 1 , n)
		{
			f[i][j][1] = f[i][j][3] = 0;
			f[i][j][3] = f[i][j][4] = oo;
		}
	}
	foru (i , 1 , n)
	{
		height[i] = height[i-1];
		weight[i] = weight[i-1];
		if(s[i] == 'W' || s[i] == 'S')	height[i] += (s[i] == 'W') ? 1 : -1;
		else weight[i] += (s[i] == 'D') ? 1 : -1;
		f[i][0][1] = f[i][0][2] = height[i]; // 1 : max , 2 : min , height
		f[i][0][3] = f[i][0][4] = weight[i]; // 3 : max , 4 : min , weight
	}
	foru (j , 1 , 19)
	{
		foru (i , 1 , n - (1 << j) + 1)
		{
			f[i][j][1] = max(f[i][j-1][1] , f[i+(1<<(j-1))][j-1][1]);
			f[i][j][2] = min(f[i][j-1][2] , f[i+(1<<(j-1))][j-1][2]);
			f[i][j][3] = max(f[i][j-1][3] , f[i+(1<<(j-1))][j-1][3]);
			f[i][j][4] = min(f[i][j-1][4] , f[i+(1<<(j-1))][j-1][4]);
		}
	}
	// cout << Calc(1 , 2 , -1) << " " << Calc(1 , 2 , 1) << endl;
	// cout << Calc(3 , 4 , -1) << " " << Calc(3 , 4 , 1) << endl;
	int res1 = min(Calc(1 , 2 , -1) , Calc(1 , 2 , 1)); // S  W
	int res2 = min(Calc(3 , 4 , -1) , Calc(3 , 4 , 1)); // A  D
	cout << min(res1 , res2) << endl;
}
main()
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