// topic : dp digits
// đếm số lượng số x sao cho:
// +) x có n chữ số
// +) tồn tại số y là hậu tố của x sao cho y chia hết cho k
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
#define ll long long
using namespace std;
const int oo = 1e9;
const int MAXN = 1111 , MAXM = 111;
int n , k , m;
ll dp[MAXN][MAXM][2]; // dp(i , j , ok) : chữ số thứ i từ phải qua trái , dư là j , và hậu tố lớn 0 hay chưa
ll cnt[MAXN]; // cnt(i) : số lượng chữ số có thể xây dựng độ dài i
ll Pow[MAXN]; // Pow(i) : 10 ^ i % k
void prepare()
{
	cnt[0] = 9;
	foru (i , 1 , n)	cnt[i] = (cnt[i-1] * 10) % m;
	Pow[0] = 1;
	foru (i , 1 , n)	Pow[i] = (Pow[i-1] * 10) % k;
}
int calc (int idx , int du , int ok)
{
	if (idx == -1)	return (ok && du == 0); // nếu thỏa mãn hậu tố > 0 và hậu tố % k = 0 thì +1 vào kq
	if (du == 0 && ok)	return cnt[idx]; // nếu đã thỏa mãn đk thì từ vị trí 1 -> idx xây dựng chữ số nào cũng thỏa mãn
	if(dp[idx][du][ok] != -1)	return dp[idx][du][ok];
	ll &ret = dp[idx][du][ok];
	ret = 0;
	foru (j , 0 , 9)
	{
		int new_du = (du + j * Pow[n - 1 - idx]) % k; // xây dựng thêm chữ số sang bên trái
		int new_ok = (ok || j != 0); // nếu đã lớn hơn 0 hoặc xây dựng thêm chữ số lớn hơn 0 thì ok = true
		ret = (ret + calc(idx - 1 , new_du , new_ok)) % m;
	}
	return ret;
}
void solve()
{
	memset(dp , -1 , sizeof(dp));
	cout << calc(n - 1 , 0 , 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> m;
    prepare();
    solve();
    return 0;
}