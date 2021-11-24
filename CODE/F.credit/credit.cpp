#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<long long , int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl;
#define ll long long
using namespace std;
const ll oo = 1e18;
const int MAXN = 5e5 + 111;
int subtask , n , k , res = oo , res1 = 0;
int delta[MAXN] , ans[MAXN];
int pos1[2 * MAXN] , pos2[2 * MAXN] , mp1[2 * MAXN] , mp2[2 * MAXN];
set<pii> s;
struct Data1
{
    int fi , se , id;
    bool operator < (const Data1 &tmp)  const
    {
        return fi < tmp.fi;
    }
};
vector<Data1> v;
struct Data
{
    int fi , se , id;
    bool operator < (const Data &tmp)   const
    {
        return se < tmp.se;
    }
} a[MAXN];
struct Node
{
    ll sum , cnt;
} tree[8 * MAXN];
void build(int id , int l , int r)
{
    if(l == r)
    {
        tree[id].sum = pos1[l];
        tree[id].cnt = (pos1[l]) ? 1 : 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2 , l , mid);
    build(id * 2 + 1 , mid + 1 , r);
    tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
    tree[id].cnt = tree[id * 2].cnt + tree[id * 2 + 1].cnt;
}
void Add(int id , int l , int r , int u , int v , int x)
{
    if(r < u || v < l)  return;
    if(u <= l && r <= v)
    {
        tree[id].sum = x;
        tree[id].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    Add(id * 2 , l , mid , u , v , x);
    Add(id * 2 + 1 , mid + 1 , r , u , v , x);
    tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
    tree[id].cnt = tree[id * 2].cnt + tree[id * 2 + 1].cnt;
}
void Erase(int id , int l , int r , int u , int v , int x)
{
    if(r < u || v < l)  return;
    if(u <= l && r <= v)
    {
        tree[id].sum = 0;   
        tree[id].cnt = 0;
        return;
    }
    int mid = (l + r) / 2;
    Erase(id * 2 , l , mid , u , v , x);
    Erase(id * 2 + 1 , mid + 1 , r , u , v , x);
    tree[id].sum = tree[id * 2].sum + tree[id * 2 + 1].sum;
    tree[id].cnt = tree[id * 2].cnt + tree[id * 2 + 1].cnt;
}
ll Get(int id , int l , int r , int x)
{
    if(tree[id].cnt == x)   return tree[id].sum;
    if(l == r)  return 0;
    int mid = (l + r) / 2;
    Node trai = tree[id * 2];
    if(trai.cnt >= x)   return Get(id * 2 , l , mid , x);
    else    return trai.sum + Get(id * 2 + 1 , mid + 1 , r , x - trai.cnt);
}
void truyvet()
{
    ans[a[res1].id] = 2;
    foru (i , 1 , res1 - 1) ans[a[i].id] = 1;
    foru (i , 1 , res1 - 1) s.insert({delta[i] , i});
    foru (i , res1 + 1 , n) s.insert({a[i].fi , i});
    int tmp = (res1) ? k - (res1 + 1) : k;
    int i = 0;
    while(true)
    {
        if(i >= tmp) break;
        pii pi = *s.begin();
        ans[a[pi.se].id]++;
        if(s.size() == 0)   break;
        s.erase(s.begin());
        i++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("credit.inp" , "r" , stdin);
    freopen("credit.out" , "w" , stdout);
    cin >> subtask >> n >> k;
    foru (i , 1 , n)
    {
        cin >> a[i].fi >> a[i].se;
        a[i].id = i;
    }
    sort(a + 1 , a + 1 + n);
    foru (i , 1 , n)    delta[i] = a[i].se - a[i].fi;
    foru (i , 1 , n) v.push_back({a[i].fi , 1 , i});
    foru (i , 1 , n) v.push_back({delta[i] , 2 , i});
    sort(v.begin() , v.end());
    foru(i , 0 , (int)v.size() - 1)
    {
        if(v[i].se == 1)
        {
            mp1[v[i].id] = i + 1;
            pos1[i + 1] = v[i].fi;
        }
        else
        {
            mp2[v[i].id] = i + 1;
            pos2[i + 1] = v[i].fi;
        }
    }
    build(1 , 1 , 2 * n);
    ll res = (k <= n) ? Get(1 , 1 , 2 * n , k) : oo;
    ll temp = 0;
    foru (i , 1 , n)
    {
        int tmp = k - (i + 1);
        Add(1 , 1 , 2 * n , mp2[i-1] , mp2[i-1] , delta[i-1]);
        Erase(1 , 1 , 2 * n , mp1[i] , mp1[i] , a[i].fi);
        ll result = Get(1 , 1 , 2 * n , tmp);
        if(res > result + temp + 1LL * a[i].se && tmp < n)
        {
            res = result + temp + 1LL * a[i].se;
            res1 = i;
        }
        temp += a[i].fi;
    }
    truyvet();
    cout << res << endl;
    foru (i , 1 , n)
    {
        cout << ans[i];
    }
    return 0;
}