// 6 15 10
// 2 * 3    3 * 5    2 * 5  -> 2^2 * 3^2 * 5^2
// 2 3 6 6
// 2 3 2*3 2*3
// cho một mảng độ dài n mỗi phần tử trong mảng có không quá 7 ước
// tìm độ dài dãy con dài nhất của mảng a không rỗng sao cho tích của dãy này 
// là một số chính phương
// một số là số chính phương khi phân tích số đó ra tsnt thì các mũ của nó phải bằng 2
// mỗi một số trong mảng đã cho có không quá 7 ước -> tích các mũ của tsnt + 1 <= 7(2 * 3 || 2 * 2)
// -> mỗi số trong mảng khi pt ra có không quá 2 tsnt
// ta chuẩn hóa mảng ban đầu để tính toán dễ dàng :
// khi pt mỗi số nếu pt ra một số chính phương (có mũ 2) ta chia nó cho số chính phương đấy
// cho đến khi không chứa bất kì scp nào. nếu số đấy bằng 1 thì kết quả bài toán là 1.
// bài toán quy về tìm dãy con ngắn nhất của mảng a sao cho :
// mỗi phần tử là tsnt trong dãy chỉ suất hiện 2 lần 
// do mỗi phần tử trong dãy chỉ xuất hiện 2 lần ta nhìn nó như một chu trình của đồ thị
// (2 -> 3 -> 5 -> 2)
// ta biểu diễn bài toán dưới dạng đồ thị như sau :
// +) do mỗi phần tử trong mảng chỉ pt ra được 2 tsnt nên ta nối 2 phần tử đó là một cạnh của đồ thị
// (nếu có 1 phần tử nối 1 với nó)
// +) sau khi đã có đồ thị ra cần tìm đường đi ngắn nhất suất phát từ một đỉnh u sau đó quay trở lại
// đỉnh u tạo thành một chu trình (trên đường đi mỗi cạnh chỉ được đi qua một lần)
// +) kết quá của bài toán là số đỉnh của chu trình đó
// các bước của bài toán :
// b1 : pt mỗi phần tử của mảng ra tsnt trong log(10 ^ 6)
// b2 : nối 2 đỉnh của đồ thị là 2 tsnt sau khi đã phân tích
// b3 : bfs tìm đường đi ngắn nhất tạo chu trình
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
using namespace std;
const int MAXN = 1000001;
const int oo = 1e9;
int n , cnt;
int a[MAXN] , pr[MAXN] , visit[MAXN] , par[MAXN];
int d[MAXN];
vector<int> adj[MAXN];
int ans = oo;
void pt(int x)
{
	for(int i=2 ; i*i<=x ; i++)
	{
		if(x % i == 0)
		{
			while(x % (i * i) == 0)
			{
				x /= i * i;
			}
		}
	}
	int p1 = x , p2 = 1;
	for(int i=2 ; i*i<=x ; i++)
	{
		if(x % i == 0)
		{
			p1 = x / i;
			p2 = i;
		}
	}
	adj[p1].push_back(p2);
	adj[p2].push_back(p1);
}
void bfs(int u)
{
	for (int i=0 ; i<MAXN ; i++)	d[i] = oo;
	queue<int> q;
	d[u] = 0;
	q.push(u);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for (int v : adj[u])
		{
			if(v != par[u])
			{
				if(d[v] == oo)
				{
					par[v] = u;
					d[v] = d[u] + 1;
					q.push(v);
				}
				else
				{
					ans = min(ans , d[u] + d[v] + 1);
				}
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++)
    {
    	cin >> a[i];
    	if(a[i] == 1)
    	{
    		cout << 1;
    		return 0;
    	}
    	pt(a[i]);
    }
    for (int i=1 ; i*i<MAXN ; i++)
    {
    	bfs(i);
    }
    if(ans == oo)	ans = -1;
    cout << ans;
    return 0;
}
