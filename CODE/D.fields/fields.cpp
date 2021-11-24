// có n cánh đồng tìm số cánh đồng tối đa vận chuyển lúa về kho với chi phí ko quá b đồng
// kiểm tra có thể vận chuyển x cánh đồng với chi phí <= b đồng không
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
const int MAXN = 1e5 + 1;
int subtask , r , l , b;
int a[MAXN] , sum[MAXN];
int Get(int l , int r)
{
	return sum[r] - sum[l-1];
}
bool check(int x)
{
	foru (i , 1 , r - x + 1)
	{
		int j = i + x - 1;
		int mid = (i + j) / 2;
		foru (k , mid , mid + 1)
		{
			int left = (k - i) * a[k] - Get(i , k - 1);
			int right = Get(k + 1 , j) - (j - k) * a[k];
			int dist = left + right;
			if(dist <= b)	return true;
		}
	}
	return false;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("fields.inp" , "r" , stdin);
    freopen("fields.out" , "w" , stdout);
    cin >> subtask >> r >> l >> b;
    foru (i , 1 , r)	cin >> a[i];	
    sort(a + 1 , a + 1 + r);
    foru (i , 1 , r)
    {
    	sum[i] = sum[i-1] + a[i];	
    }
    int le = 1 , ri = r;
    int ans = 1;
    while(le <= ri)
    {
    	int mid = (le + ri) / 2;
    	if(check(mid))
    	{
    		ans = mid;
    		le = mid + 1;
    	}
    	else	ri = mid - 1;
    }
    cout << ans;
    return 0;
}
