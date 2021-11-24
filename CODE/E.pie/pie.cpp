// n ngày m loại bánh tìm tổng số tiền ít nhất để mua bánh sao cho n ngày có bánh
// nếu mua k bánh trong một ngày thì phải trả thêm k^2
// dp(i , j) : tổng số tiền phải trả khi đi được i - 1 ngày và số bánh đã mua là j
// -> minimize(dp(i , j + x) , dp(i-1 , j) + sum(1->x) + x^2)  
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
const int MAXN = 301;
int n , m;
void minimize(int &x , int y)
{
	if(x > y)	x = y;
}
int c[MAXN][MAXN];
int dp[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("pie.inp" , "r" , stdin);
    freopen("pie.out" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n)
    {
    	foru (j , 1 , m)
    	{
    		cin >> c[i][j];
    	}
    	sort (c[i] + 1 , c[i] + 1 + m);
    }
    memset(dp , 0x3f , sizeof(dp));
    dp[0][0] = 0;
    foru (i , 1 , n)
    {
    	foru (j , i - 1 , n) // số bánh đã mua khi đi hết ngày i - 1
    	{
    		int sum = 0;
    		foru (x , 0 , m) // mua thêm x cái bánh
    		{
    			if(j + x > n)	break;
    			sum += c[i][x];
    			if(j + x >= i) // nếu đủ bánh đi đến ngày i
    			{
    				minimize(dp[i][j+x] , dp[i-1][j] + sum + x * x);
    			}
    		}
    	}
    }
    cout << dp[n][n];
    return 0;
}
