#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
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
const int MAXN = 250001;
int trie[MAXN][27]; 
int n , cnt;
char str[MAXN][31];
int st[MAXN] , Isend[MAXN];
bool cmp(const int &a , const int &b)
{
	return strcmp(str[a] , str[b]) < 0;
}
void add(char *s , int t)
{
	int len = strlen(s);
	int node = 0;
	for (int i=len-1 ; i>=0 ; i--)
	{
		int x = s[i] - 'a';
		if(trie[node][x] == 0)	trie[node][x] = ++cnt;
		node = trie[node][x];
	}
	Isend[node] = t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    while(true)
    {
    	if(!gets(str[++n]))	break;
    	if(!str[n][0])	break;
    }
 	for (int i=1 ; i<n ; i++)	st[i] = i;
 	sort(st + 1 , st + n , cmp);
 	for (int i=1 ; i<n ; i++)
 	{
 		cout << st[i] << endl;
 	}
 	for (int i=1 ; i<n ; i++)
 	{
 		add(str[st[i]] , st[i]);
 	}
    return 0;
}
