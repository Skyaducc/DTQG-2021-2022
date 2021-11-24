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
int test;
char a[] = {'N' , 'P' , 'C' , 'R'};
void solve()
{
	string s1 , s2 , s3 , s4 , s5 , s6 , s;
	cin >> s1 >> s2 >> s3 >> s >> s4 >> s5 >> s6;
	int sum1 = 0 , sum2 = 0;
	sum1 += (s1[0] == 'A') ? 1 : s1[0] - '0';
	sum1 += (s2[0] == 'A') ? 1 : s2[0] - '0';
	sum1 += (s3[0] == 'A') ? 1 : s3[0] - '0';
	sum2 += (s4[0] == 'A') ? 1 : s4[0] - '0';
	sum2 += (s5[0] == 'A') ? 1 : s5[0] - '0';
	sum2 += (s6[0] == 'A') ? 1 : s6[0] - '0';
	sum1 = (sum1 % 10 == 0) ? 10 : sum1 % 10;
	sum2 = (sum2 % 10 == 0) ? 10 : sum2 % 10;
	if(sum1 > sum2)	
	{
		cout << "Yes" << " ";
		return;
	}
	if(sum1 < sum2)
	{
		cout << "No" << " ";
		return;
	}
	int ma1 = 0 , ma2 = 0;
	foru (i , 0 , 3)
	{
		ma1 = max(ma1 , (s1[1] == a[i]) ? i : 0);
		ma1 = max(ma1 , (s2[1] == a[i]) ? i : 0);
		ma1 = max(ma1 , (s3[1] == a[i]) ? i : 0);
		ma2 = max(ma2 , (s4[1] == a[i]) ? i : 0);
		ma2 = max(ma2 , (s5[1] == a[i]) ? i : 0);
		ma2 = max(ma2 , (s6[1] == a[i]) ? i : 0);
		ma1 = max(ma1 , (s1[1] == a[i]) ? i : 0);
	}
	if(ma1 > ma2)
	{
		cout << "Yes" << " ";
		return;
	}
	if(ma1 < ma2)
	{
		cout << "No" << " ";
		return;
	}
	int tmp1 = 0 , tmp2 = 0;
	foru (i , 0 , 3)
	{	
		tmp1 = max(tmp1 , (s1[1] == a[i] && i == ma1) ? (s1[0] == 'A') ? 10 : s1[0] - '0' : 0);
		tmp1 = max(tmp1 , (s2[1] == a[i] && i == ma1) ? (s2[0] == 'A') ? 10 : s1[0] - '0' : 0);
		tmp1 = max(tmp1 , (s3[1] == a[i] && i == ma1) ? (s3[0] == 'A') ? 10 : s1[0] - '0' : 0);
		tmp2 = max(tmp2 , (s4[1] == a[i] && i == ma2) ? (s4[0] == 'A') ? 10 : s2[0] - '0' : 0);
		tmp2 = max(tmp2 , (s5[1] == a[i] && i == ma2) ? (s5[0] == 'A') ? 10 : s2[0] - '0' : 0);
		tmp2 = max(tmp2 , (s6[1] == a[i] && i == ma2) ? (s6[0] == 'A') ? 10 : s2[0] - '0' : 0);
	}
	cout << ((tmp1 > tmp2) ? "Yes" : "No") << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("3cay.inp" , "r" , stdin);
    freopen("3cay.out" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}