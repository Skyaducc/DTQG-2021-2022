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
const int MAXN = 1e6 + 1;
int n , p , q , subtask;
int a[MAXN];
struct Data
{
	int l , r , id;
	Data(int _l = 0 , int _r = 0 , int _id = 0)
	{
		l = _l ; r = _r ; id = _id;
	}
    bool operator < (const Data)    const
    {
        return l < Data.l;
    }
} query;
int last[MAXN]; // last(p) : vi trị i nhỏ nhất mà a[i] chia hết cho p
void eratos()
{
    prime[0] = prime[1] = -1;
    foru (i , 2 , MAXN)
    {
        if(prime[i] == 0)
        {
            for (int j = i ; j <= MAXN ; j += i)
            {
                prime[j] = i;
            }
        }
    }
    foru (i , 2 , MAXN) if(prime[i] == 0)   prime[i] = i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("req.inp" , "r" , stdin);
    freopen("req.out" , "w" , stdout);
    eratos();
    cin >> subtask >> n >> q >> p;
    foru (i , 1 , n)	cin >> a[i];
    foru (i , 1 , q)
    {
    	cin >> query[i].fi >> query[i].se;
    }
    sort(query + 1 , query + 1 + q , greater<pii>());
    foru (i , 1 , q)
    {
        int tmp = a[i];
        while(tmp > 1)
        {
            int pr = prime[tmp];
            int pwprime = 1;
            while(tmp % pr == 0)
            {
                tmp /= prime;
                pw *= prime;
            }
        }
    }
    return 0;
}
