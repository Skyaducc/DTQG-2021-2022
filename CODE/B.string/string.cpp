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
int x , y , k;
int c[27] , a[27] , cnt;
bool flag = true;
vector<string> res;
// void sub1()
// {
// 	string ans = "";
// 	int cnt = 0;
// 	foru (i , 1 , 26)
// 	{
// 		if(c[i])
// 		{
// 			foru (j , 1 , c[i])
// 			{
// 				ans += char(i - 1 + 'a');
// 				cnt++;
// 				if(cnt == x)
// 				{
// 					cout << "YES" << endl;
// 					cout << ans;
// 					return;
// 				}
// 			}
// 		}
// 	}
// 	cout << "NO" << endl;
// }
// void sub2()
// {
// 	vector<int> v;
// 	foru (i , 1 , 26)
// 	{
// 		if(c[i])
// 		{
// 			v.push_back(i);
// 		}
// 	}
// 	int cnt = 0;
// 	vector<string> ve;
// 	while(next_permutation(v.begin() , v.end()))
// 	{
// 		string ans = "";
// 		cnt++;
// 		if(cnt > k)	break;
// 		for(int x : v)	ans += char(x - 1 + 'a');
// 		ve.push_back(ans);
// 	}
// 	if((int)ve.size() < k)
// 	{
// 		cout << "NO" << endl;
// 	}
// 	else
// 	{
// 		cout << "YES" << endl;
// 		for (string s : ve)	cout << s << " ";
// 		cout << endl;
// 	}
// }
int m = 0;
int b[27] , input[27] , pos[27];
int dem = 0;
string cur;
void backtrack() 
{
    if ((int)cur.size() >= x) 
    {
        res.push_back(cur);
        if ((int)res.size() == k) throw 1;
    }
    if ((int)cur.size() == y) return;
    foru (i , 1 , 26) 
    {
        if (limit[i] > 0) 
        {
            limit[i]--;
            cur.push_back('a' + i - 1);
            backtrack();
            cur.pop_back();
            limit[i]++;
        }
    }
}
void sub3()
{
	try 
    {
        backtrack();
    } catch (...) 
    {
        cout << "YES" << endl;
        for (string x : res)    cout << x << " ";
        cout << endl;
        return;
    }
    cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.inp" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    while(cin >> x >> y >> k)
    {
    	foru (i , 1 , 26)	cin >> c[i];
    	bool ok = true;
    	foru (i , 1 , 26)
    	{
    		if(c[i] < 0 || x > y)
    		{
    			cout << "NO" << endl;
    			ok = false;
    			break;
    		}
    	}
    	if(!ok)	continue;
    	sub3();
    	cout << endl;
    }
    return 0;
}
