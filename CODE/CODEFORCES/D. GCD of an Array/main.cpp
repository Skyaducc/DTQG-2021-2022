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
using namespace std;
const int MAXN = 2e5 + 1;
const long long MOD = 1e9 + 7;
int n , q;
int a[MAXN];
map<int , int> mu[MAXN];
int dem , pr[MAXN] ;
long long ucln = 1;
multiset<int> A[MAXN];
void erathos()
{
    for (int i=2 ; i<MAXN ; i++)
    {
        if (pr[i] == 0)
        {
            pr[i] = i;
            if (i > 10000) continue;
            for (int j = i * i; j < MAXN; j += i)
            {
                if (pr[j] == 0) pr[j] = i;
            }
        }
    }
}
void pt(int i , int tmp)
{
    int tmp1 = 1;
    while(tmp != 1)
    {
        int MIN = 0;
        int prime = pr[tmp] , dem = 0;
//        cout << prime << endl;
        while (pr[tmp] == prime)
        {
            dem++;
            tmp = tmp / prime;
        }
        if(A[prime].size() == n)
        {
            MIN = *A[prime].begin();
        }
        if(mu[i][prime] == 0)
        {
            mu[i][prime] += dem;
            A[prime].insert(mu[i][prime]);
        }
        else
        {
            A[prime].erase(A[prime].find(mu[i][prime]));
            mu[i][prime] += dem;
            A[prime].insert(mu[i][prime]);
        }
        if(A[prime].size() == n)
        {
            for (int j = MIN + 1 ; j <= *A[prime].begin() ; j++)
            {
                ucln = (long long)(ucln * prime) % MOD;
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
    erathos();
    cin >> n >> q;
    for (int i=1 ; i<=n ; i++)
    {
        cin >> a[i];
        pt(i , a[i]);
    }
    while(q--)
    {
        int i , d;
        cin >> i >> d;
        pt(i , d);
//        cout << *A[2].begin() << " " << *A[3].begin() << endl;
        cout << ucln << endl;
    }
    return 0;
}
