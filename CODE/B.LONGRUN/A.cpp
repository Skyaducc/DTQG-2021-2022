// có n học sinh chạy vòng quanh sân có chu vi C , chạy L vòng
// tính số lần mà một bạn vượt qua bạn khác trong quá trình chạy
// +) học sinh i vượt học sinh j khi vận tốc của i > j
// +) thời gian chạy là C * L / vận tốc học sinh lớn nhất = T
// +) nếu bạn i chạy x vòng và bạn j chạy y vòng thì số lần bạn i vượt qua bạn j là x - y
// +) gọi d(i) là số vòng mà bạn thứ i chạy
// +) d(i) = (V(i) * T) / C
// +) kq = tổng các d(j) - d(i) (d(j) > d(i)) (1 <= i <= n , i + 1 <= j <= n)
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
const int MAXN = 1e5 + 11;
int n , L , C;
struct cow 
{
	long long speed;
	long long modulus;
	int rank;
};
cow cows[MAXN];
long long max_speed = 0;
int bit[MAXN];
int bitlen;
void bit_init(int n) 
{
	foru (i , 1 , n)
	{
		bit[i] = 0;
	}
	bitlen = n;
}
int bit_prefix_sum(int i) 
{
	int sum = 0;
	for(int j = i ; j > 0; j -= (j & (-j))) 
	{
		sum += bit[j];
	}
	return sum;
}
void bit_inc(int i) 
{
	for(int j = i ; j <= bitlen ; j += (j & (-j))) 
	{
		bit[j]++;
	}
}
bool sort_cow_by_modulus(cow a , cow b) 
{
	return a.modulus < b.modulus;
}
bool sort_cow_by_speed(cow a , cow b) 
{
	return a.speed < b.speed;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> L >> C;
    foru (i , 0 , n - 1)
    {
		cin >> cows[i].speed;
		max_speed = max(max_speed , cows[i].speed);
	}
	foru (i , 0 , n - 1)
	{
		cows[i].modulus = (L * C * cows[i].speed) % (C * max_speed);
	}
	sort(cows , cows + n , sort_cow_by_modulus);
	int a = 0;
	int rank = 1;
	while(a < n) 
	{
		int b = a + 1;
		while(b < n && cows[a].modulus == cows[b].modulus) 
		{
			b++;
		}
		foru (i , a , b - 1)
		{
			cows[i].rank = rank;
		}
		a = b;
		rank++;
	}
	sort(cows , cows + n, sort_cow_by_speed);
	bit_init(n);
	long long res = 0;
	long long sum_of_floors = 0;
	foru (i , 0 , n - 1)
	{
		long long floor = (L * cows[i].speed) / (max_speed);
		long long addition = floor * i - sum_of_floors - (long long)i + (long long)bit_prefix_sum(cows[i].rank);
		res += addition;
		sum_of_floors += floor;
		bit_inc(cows[i].rank);
	}
	cout << res;
    return 0;
}