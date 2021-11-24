#include <iostream>
#define foru(i , a , b) for(int i=a ; i<=b ; i++)
#define ford(i , a , b) for(int i=a ; i>=b ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x , i) ((x) | MASK(i))
#define SET_OFF(x , i) ((x) & ~MASK(i))
using namespace std;
const int MAXN = 5001;
int r , c , n , m;
int a[MAXN][MAXN];
char str[MAXN][MAXN];
int Get(char x)
{
	if ('0' <= x && x <= '9') return x - '0';
	if ('A' <= x && x <= 'Z') return x - 'A' + 10;
	if ('a' <= x && x <= 'z') return x - 'a' + 36;
	if (x == '#') return 62;
	if (x == '$') return 63;
}
int main()
{
    freopen("skynight.inp" , "r" , stdin);
    freopen("skynight.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> r >> c >> n >> m;
    foru (i , 1 , r)
	{
		string s;
		cin >> s;
		int cnt = 0;
		bool ok = true;
		foru (j , 0 , (int)s.length() - 1)
		{
			int x = Get(s[j]);
			foru (k , 0 , 5)
			{
				if (cnt + 1 <= c) a[i][++cnt] = BIT(x , k);
				else
				{
					ok = false;
					break;
				}
			}
			if (!ok)  break;
		}
	}
	int ans = 0;
	foru (i , 1 , r)
	{
		foru (j , 1 , c)
		{
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	foru (i , 1 , r)
	{
		foru (j , 1 , c)
		{
			int x = i + n - 1;
			int y = j + m - 1;
			if (x > r || y > c) continue;
			ans = max(ans , a[x][y] - a[i-1][y] - a[x][j-1] + a[i-1][j-1]);
		}
	}
	cout << ans;
    return 0;
}
