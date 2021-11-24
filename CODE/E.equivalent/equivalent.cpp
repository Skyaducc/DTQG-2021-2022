// cho n xâu kí tự từ 0 -> 9 thuộc tập S
// từ tập S xây dựng tập T là hoán vị vòng quanh các xâu trong S 
// tìm cách chọn ra nhiều xâu nhất trong T sao cho các xâu đôi một ko tương đương
// 2 xâu tương đương khi có thể biến đổi từ xâu này sang xâu kia bằng việc hữu hạn lần phép biến đổi
// phép biến đổi : đổi 2 kí tự liên tiếp trong xâu nếu 2 kí tự có chênh lệch lớn hơn 1
// S = {017040} -> T = {017040 , 170400 , 704001 , 040017 , 400170 , 001704}
// 2 cặp xâu tương đương : (040017 , 704001) và (001704 , 400170) 
// 040017 -> 040071 -> 047001 -> 074001 -> 704001
// 001704 -> 001740 -> 001470 -> 004170 -> 400170 
// ta biến đổi từ tập S -> T bây giờ cần tìm số phần từ trong tập T sao cho ko có 2 phần tử nào tương đương
// gọi f(x) là xâu kí tự có thứ tự từ điển nhỏ nhất mà từ xâu x có thể biến đổi thành xâu y 
// 2 xâu x , y có thể biến đổi qua lại nếu f(x) = f(y)
// như vậy kết quả bài toán là số phần tử phân biệt của tập hợp f(x) với x thuộc tập hợp T
// để tính f(x) ta làm như topo sort : ta cho các số ko bị chặn (từ số này có thể đi đến số kia) bởi số nào 
// vào hàng đợi sau đó lấy ra số có giá trị nhỏ nhất đi cập nhật những số khác
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
int n;
string s[51];
vector<string> t;
map<int , string> mp;
map<string , int> ans;
void convert(string s)
{
	string ss = "";
	ss += s;
	ss += s;
	foru (i , 0 , (int)s.length() - 1)
	{
		string tmp = "";
		foru (j , i , i + (int)s.length() - 1)	tmp += ss[j];
		t.push_back(tmp);
	}
}
vector<int> block[2525]; // các số bị chặn bởi phần tử i
int numBlock[2525]; // numBlock[i] = số chữ số chặn phần tử i
int last[2525]; // vị trí đầu tiên > i có giá trị = s[i]
string minLexic(string s) // xâu có thứ tự từ điển nhỏ nhất được biến đổi từ s
{
	reset(last);
	ford (i , s.size() - 1 , 0)
	{
		int x = s[i] - '0';
		block[i].clear();
		foru (j , x - 1 , x + 1)
		{
			int pos = last[j];
			if(pos)
			{
				numBlock[pos]++;
				block[i].push_back(pos);
			}
		}
		last[x] = i;
	}
	priority_queue<pii> pq; // vị trí ko bị chặn
	foru (i , 0 , (int)s.length() - 1)
	{
		if(numBlock[i] == 0)
		{
			pq.push({- (s[i] - '0') , i});
		}
	}
	string res = "";
	// cout << s << endl;
	while (!pq.empty()) 
	{
		int u = pq.top().se;
		int du = - pq.top().fi;
		pq.pop();
		res += (du + '0');
		for (int v : block[u])
		{
			 if (--numBlock[v] == 0)
			 {
			 	 pq.push({- (s[v] - '0') , v});
			 }
		}
	}
	return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("equivalent.inp" , "r" , stdin);
    freopen("equivalent.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> s[i];
    	convert(s[i]);
    }
    foru (i , 0 , (int)t.size() - 1)
    {
    	mp[i] = minLexic(t[i]);
    	ans[mp[i]]++;
    	// cout << minLexic(t[i]) << endl;
    }
    int result = 0;
    foru (i , 0 , (int)t.size() - 1)
    {
    	if(ans[mp[i]])
    	{
    		result++;
    		ans[mp[i]] = 0;
    	}
    }
    cout << result;
    return 0;
}