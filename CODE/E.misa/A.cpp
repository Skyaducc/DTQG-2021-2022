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
const int MAXN = 60;
int r , c;
char a[MAXN][MAXN];
int sum , res;
int dx[] = {-1 , -1 , -1 ,  0 , 0 ,  1 , 1 , 1};
int dy[] = {-1 ,  0 ,  1 , -1 , 1 , -1 , 0 , 1};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("misa.inp" , "r" , stdin);
    freopen("misa.out" , "w" , stdout);
    cin >> r >> c;
  	foru (i , 0 , r + 1)	foru (j , 0 , c + 1)	a[i][j] = '.';
  	foru (i , 1 , r)	foru (j , 1 , c)	cin >> a[i][j];
  	foru (i , 1 , r)	foru (j , 1 , c)
    	if(a[i][j] == 'o')
        {
        	foru (k , 0 , 7)
        	{
        		sum += (a[i + dx[k]][j + dy[k]] == 'o');
        	}
        }
  	sum /= 2;
  	res = sum;
  	foru (i , 1 , r)
    {
    	foru (j , 1 , c)
      	{
	      	if (a[i][j] == '.')
	      	{
	        	int temp = 0;
	        	foru (k , 0 , 7)
	          	{
	          		temp += (a[i + dx[k]][j + dy[k]] == 'o');
	          	}
	        	res = max(res , sum + temp);
	      	}
      	}
    }
    cout << res;
    return 0;
}