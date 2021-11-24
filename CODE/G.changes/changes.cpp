// cho n tờ tiền v1 , v2 , ... vn . tìm cách thêm một số tiền vào túi nhỏ nhất sao cho không 
// thể trả cho khách bằng thuật toán tham lam : 
// chọn tờ tiền mệnh giá cao nhất nhỏ hơn số tiền cần trả lại 
// c = 12 , v : 3 , 4 , 5 -> thêm tờ 5 vào -> 3 , 4 , 5 , 5
// +) chọn 5 -> 3 , 4 , 5 ; c = 7
// +) chọn 5 -> 3 , 4 ; c = 2
// +) không chọn được tờ tiền nào < 2 có trong 
// tìm cách đưa số tiền cần trả lại c sao cho 0 < c < min(vi) => min(vi) > 1
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
const int MAXN = 5001;
int subtask , test;
int c , n;
int v[MAXN];
bool die[MAXN][MAXN]; // die(i,j) = true <=> số tiền cần trả là i và có các tờ tiền từ j -> n
					  // thì thuật toán tham lam thất bại
int cur[MAXN];
int Get_pos(int x) 
{
    int l = 0, r = n + 1;
    while (l + 1 < r) 
    {
        int mid = (l + r) / 2;
        if (v[mid] > x)	l = mid;
        else	r = mid;
    }
    return r;
}
void sub3()
{
	cin >> c >> n;
	foru (i , 1 , n)	cin >> v[i];
	sort(v + 1 , v + 1 + n , greater<int>());
	foru (i , 1 , c)	die[i][n+1] = true;
	die[0][n + 1] = false;
	ford (j , n , 1)
	{
		foru (i , 1 , c)
		{
			if(i >= v[j])	// số tiền cần trả lớn hơn tờ tiền đang có
			{
				die[i][j] = die[i-v[j]][j+1];
			}
			else
			{
				die[i][j] = die[i][j+1];
			}
		}
	}
	cur[0] = cur[1] = c;
	foru (i , 1,  n)	
	{
		if(cur[i] >= v[i])	cur[i] -= v[i];
		cur[i+1] = cur[i];
	}
}
/*void sub12()
{
	int f[MAXN][MAXN]; // f(i , j) : số tiền nhỏ nhất cần thêm nếu số tiền cần trả là i 
  				   // và còn các đồng tiền j -> n
	cin >> c >> n;
	foru (i , 1 , n)	cin >> v[i];
	sort(v + 1 , v + 1 + n , greater<int>());
	foru (i , 1 , c)	f[i][n+1] = 0;
	f[0][n+1] = oo;
	ford (j , n , 1)
	{
		foru (i , 0 , c)
		{
			f[i][j] = oo;
			if(i < v[j])
			{
				f[i][j] = f[i][j+1];
			}
			else
			{
				f[i][j] = min(f[i][j] , f[i-v[j]][j+1]);
				foru (x , v[j] + 1 , i-1)
				{
					f[i][j] = min(f[i][j] , f[i-x][j] + x);
 				}
			}
		}
	}
	if(f[c][1] == oo)	cout << -1 << " ";
	else	cout << f[c][1] << " ";
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("changes.inp" , "r" , stdin);
    freopen("changes.out" , "w" , stdout);
    cin >> subtask >> test;
    while(test--)
    {
     	// if(subtask <= 2)	sub12();	
     	if(subtask <= 3)	sub3();
    }
    return 0;
}