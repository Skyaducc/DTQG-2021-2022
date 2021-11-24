// cho n tọa độ , mỗi tọa độ cần gán tung độ hoặc hoành độ = 0 
// (x , y) -> (x , 0) || (0 , y)
// tìm cách gán sao cho khoảng cách giữa 2 điểm xa nhất là nhỏ nhất
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
const int oo = 1e18;
const int MAXN = 5 * 1e5 + 1;
int n;
pii a[MAXN];
int bp(int x)
{
	return x * x;
}
int getmin_dist(pii x , pii y)
{
	int tmp1 = bp(abs(x.fi)) + bp(abs(y.se));
	int tmp2 = bp(abs(x.se)) + bp(abs(y.fi));
	int tmp3 = bp(abs(x.fi - y.fi));
	int tmp4 = bp(abs(x.se - y.se));
	return min({tmp1 , tmp2 , tmp3 , tmp4});
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("points.inp" , "r" , stdin);
    freopen("points.out" , "w" , stdout);
    cin >> n;
    foru(i , 1 , n)	cin >> a[i].fi >> a[i].se;
    int ans = 0;
    foru(i , 1 , n - 1)
    {
    	foru(j , i + 1 , n)
    	{
    		ans = max(getmin_dist(a[i] , a[j]) , ans);
    		if(getmin_dist(a[i] , a[j]) == 3062500)	cout << i << " " << j << endl;
    	}
    }
    cout << ans;
    return 0;
}
