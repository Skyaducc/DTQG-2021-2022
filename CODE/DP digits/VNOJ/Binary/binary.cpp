// cho số nguyên không âm N. đếm xem có bao nhiêu số nguyên từ 0 -> N mà
// khi biểu diễn dưới dạng nhị phân có đúng k chữ số 0
// -> dp digits
// biểu diễn N dưới dạng nhị phân
// với mỗi vị trí từ 0 -> vị trí bit 1 cuối cùng của N ta kiểm soát
// các biến (i , tight , cnt) là vị trí bit , kiểm tra tại vị trí i
// số đó có bị giới hạn hay ko , số bit 0.
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
int n , k;
int dp[32][2][2][32];
int Get(int idx , int tight , int ok , int cnt)
{
	if(idx == -1)
	{
		return (cnt == k);
	}
	int &ret = dp[idx][tight][ok][cnt];
	if(ret != -1)	return ret;
	int cur = (n >> idx) & 1;
	ret = 0;
	foru(i , 0 , 1)
	{
		if(tight || i <= cur)
		{
			ret += Get(idx - 1 , tight || (i < cur) , ok || (i > 0) , cnt + (i == 0 && ok));
		}
	}
	return ret;
}
void solve()
{
	memset(dp , -1 , sizeof(dp));
	cout << Get(30 , 0 , 0 , 0) + (k == 1) - (k == 0) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    while(cin >> n >> k)
    {
    	solve();
    }
    return 0;
}
