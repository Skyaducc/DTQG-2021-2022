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
int test;
int n , d;
vector<int> vert[MAXN];
int numnode[MAXN] , par[MAXN];
void solve()
{
	cin >> n >> d;
	int node = 1 , deep = 0 , sumdeep = 0;
	int cnt = 1;
	foru (i , 0 , n)	numnode[i] = 0; // số nút ở mỗi độ sâu
	numnode[0] = 1;
	while(true) // tính tổng độ sâu tối thiểu
	{
		cnt *= 2;
		deep++;
		node += cnt;
		numnode[deep] = cnt;
		if(node >= n)
		{
			cnt -= (node - n);
			numnode[deep] = cnt;
			foru (i , 1 , cnt)	sumdeep += deep;
			break;
		}
		foru (i , 1 , cnt)	sumdeep += deep;
	}
	if(d < sumdeep || d > (n - 1) * n / 2) // tồn tại đáp án hay không
	{
		cout << "NO" << endl;
		return;
	}
	int need = d - sumdeep; // số nút lá cần chuyển lên nút có độ cao sâu hơn
	int newdeep = deep; // độ cao sau khi chuyển nút lá
	int i = deep;
	while(need) // đk chuyển : số nút ở độ cao (i + 1) > 2 * số nút ở độ cao i
	{
		if(numnode[i] > 1)
		{
			int j = i + 1;
			if(numnode[j] > 2 * numnode[i] || numnode[j] == 0) // nếu ko t/m đk chuyển
			{
				while(true)
				{
					if(j >= newdeep) // chuyển nút j lên nút sâu hơn
					{
						newdeep++;
						numnode[newdeep - 1]--;
						if(numnode[newdeep] > 1)    i = newdeep;
						numnode[newdeep]++;
						break;
					}
					if(numnode[j] > 2 * numnode[i])
					{
						j++;
						continue;
					}
				}
				need--;
				continue;
			}
			numnode[i]--;
			numnode[j]++;
			if(numnode[j] > 1)	i = j;
		}
		else 
		{
			i--;
			continue;
		}
		need--;
	}
	// dựng đồ thị khi biết trước mỗi độ sâu có bao nhiêu nút
	foru (i , 0 , newdeep)	vert[i].clear();
	int dinh = 0;
	foru (i , 0 , newdeep)
	{
		foru (j , 1 , numnode[i])
		{
			dinh++;
			vert[i].push_back(dinh);
		}
	}
	foru (i , 0 , newdeep - 1)
	{
		numnode[i] = 0;
		int j = 0;
		for (int x : vert[i])
		{
			if(j < (int)vert[i+1].size())	par[vert[i+1][j]] = x;
			j++;
			if(j < (int)vert[i+1].size())	par[vert[i+1][j]] = x;
			j++;
		}
	}
	cout << "YES" << endl;
	foru (i , 2 , n)	cout << par[i] << " ";
	cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}
