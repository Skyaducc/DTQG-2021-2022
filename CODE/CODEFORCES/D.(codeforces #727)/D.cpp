// 2 7
// 2 8
// 1 2
// 2 4
// 1 8
// tong tien = 16 - giam gia = 4  =>  12
// gia su da mua duoc i mon hang thi mon hang co b(i) = i se mua voi gia 1 
// tim cach toi uu mua hang de duoc giam gia nhieu nhat
// kq = tong so tien neu ko giam gia - tong so tien co the giam gia
// 
#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define int long long
using namespace std;
const int MAXN = 1e5 + 1;
int n; 
vector<pii> v;
bool cmp(pii x , pii y)
{
	return x.se < y.se;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
    	int a , b;
    	cin >> a >> b;
    	v.push_back({a , b});
    }
    // 1 3
    // 3 4
    // 1 5
    sort(v.begin() , v.end() , cmp);
    int i=0 , j=v.size() - 1;
    int cost = 0 , tmp = 0;
    while(i <= j)
    {
    	if(tmp < v[i].se)
    	{
    		int need = v[i].se - tmp;
    		if(v[j].fi < need)
    		{
    			cost += 2 * v[j].fi;
    			tmp += v[j].fi;
    			v[j].fi = 0;
    			j--;
    		}
    		else
    		{
    			cost += 2 * need;
    			v[j].fi -= need;
    			tmp += need;
    		}
    	}
    	else
    	{
    		tmp += v[i].fi;
    		cost += v[i].fi;
    		v[i].fi = 0;
    		i++;
    	}
    }
    cout << cost;
    return 0;
}
