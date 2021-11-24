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
const int MAXN = 1e6 + 1;
int n , k;
pii a[MAXN];
vector<pii> v1 , v2;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("shipping.inp" , "r" , stdin);
    freopen("shipping.out" , "w" , stdout);
    cin >> n >> k;
    foru (i , 1 , n)
    {
    	cin >> a[i].fi >> a[i].se; // fi : toa do , se : need
    	if(a[i].fi >= 0)
    	{
    		v1.push_back({a[i].fi , a[i].se});
    	}
    	else 	v2.push_back({ - a[i].fi , a[i].se});
    }
    v1.push_back({oo , oo}) , v2.push_back({oo , oo});
    sort(v1.begin() , v1.end() , greater<pii>());
    sort(v2.begin() , v2.end() , greater<pii>());
    long long res1 = 0 , res2 = 0;
    int i = 1;
    if(v1.size() > 1)
    {
    	while (i <= v1.size()) 
	    {
	    	if (v1[i].se % k) 
			{
				int tmp = v1[i].se - v1[i].se % k + k;
				res1 += (tmp / k) * v1[i].fi * 2;
				int du = tmp - v1[i].se;
				i++;
				while (du >= v1[i].se && i <= v1.size()) 
				{
					du -= v1[i].se;
					i++;
				}
				if (du > 0 && i <= v1.size()) 
				{
					v1[i].se -= du;
				}
			}
			else 
			{
				res1 += (v1[i].se / k) * v1[i].fi * 2;
				i++;	
			}
		}
    }
	i = 1;
	if(v2.size() > 1)
	{
		while (i <= v2.size()) 
	    {
	    	if (v2[i].se % k) 
			{
				int tmp = v2[i].se - v2[i].se % k + k;
				res2 += (tmp / k) * v2[i].fi * 2;
				int du = tmp - v2[i].se;
				i++;
				while (du >= v2[i].se && i <= v2.size()) 
				{
					du -= v2[i].se;
					i++;
				}
				if (du > 0 && i <= v2.size()) 
				{
					v2[i].se -= du;
				}
			}
			else 
			{
				res2 += (v2[i].se / k) * v2[i].fi * 2;
				i++;	
			}
		}
	}
    cout << res1 + res2;
    return 0;
}
