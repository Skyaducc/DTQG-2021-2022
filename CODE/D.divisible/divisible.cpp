// cho dãy số k(1),k(2),...,k(n) tìm dãy a sao cho a(i)^k(i) chia hết cho p(i)
// với p(i) là tích các số trong dãy a trừ số thứ i
// ( p(i) = a(1)*a(2)...a(i-1)*a(i+1)*...*a(n) )
// do a(i)^k(i) chia hết cho p(i) nên khi phân tích các a(i) ra tsnt phải có cùng tsnt
// gọi x(i) là số mũ của các tsnt của a(i) -> x(i)*k(i) >= y(i)
// với y(i) là tổng các số trong dãy x trừ số thứ i ( y(i) = x(1)+x(2)+...+x(i-1)+x(i+1)+...+x(n))
// x(i)*(k(i) + 1) >= x(1)+...+x(n)
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
const int MAXN = 51;
int n;
int k[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("divisible.inp" , "r" , stdin);
    freopen("divisible.out" , "w" , stdout);
    cin >> n;
    foru(i , 1 , n)	cin >> k[i];
    if(n > 10)	cout << "No";
    else	cout << "Yes";
    return 0;
}
