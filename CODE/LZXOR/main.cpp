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
const int MAXN = 1e5 + 1;
const int oo = 1e9;
int n , q;
int a[MAXN];
struct data
{
    int val , lazy;
} tree[4*MAXN][18];
void build(int id , int l , int r)
{
    if(l == r)
    {
        for (int i=0 ; i<=17 ; i++)
        {
            tree[id][i].val = BIT(a[l] , i);
        }
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2 , l , mid);
    build(id * 2 + 1 , mid + 1 , r);
    for (int i=0 ; i<=17 ; i++)
    {
        tree[id][i].val = tree[id*2][i].val + tree[id*2+1][i].val;
    }
}
void push(int id , int l , int r)
{
    int nn = (l + r) / 2;
    int n1 = nn - l + 1;
    int n2 = r - nn;
    for (int i=0 ; i<=17 ; i++)
    {
        int t = tree[id][i].lazy;
        tree[id*2][i].lazy ^= t;
        tree[id*2+1][i].lazy ^= t;
        if(BIT(t , i) == 1)
        {
            tree[id*2][i].val = n1 - tree[id*2][i].val;
            tree[id*2+1][i].val = n2 - tree[id*2+1][i].val;
        }
        tree[id][i].lazy = 0;
    }
}
void update(int id , int l , int r , int u , int v , int x)
{
    if(r < u || v < l)
    {
        return;
    }
    if(u <= l && r <= v)
    {
        int nn = r - l + 1;
        for (int i=0 ; i<=17 ; i++)
        {
            tree[id][i].lazy ^= BIT(x , i);
            if(BIT(tree[id][i].lazy , i) == 1)
            {
                tree[id][i].val = nn - tree[id][i].val;
            }
        }
        return;
    }
    push(id , l , r);
    int mid = (l + r) / 2;
    update(id * 2 , l , mid , u , v , x);
    update(id * 2 , mid + 1 , r , u , v , x);
    for (int i=0 ; i<=17 ; i++)
    {
        tree[id][i].val = tree[id*2][i].val + tree[id*2+1][i].val;
    }
}
int GET(int id , int l , int r , int u , int v)
{
    if(r < u || v < l)
    {
        return 0;
    }
    if(u <= l && r <= v)
    {
        int ans = 0;
        for (int i=0 ; i<=17 ; i++)
        {
            cout << tree[id][i].val;
            ans += tree[id][i].val * (1 << i);
        }
        cout << endl;
        return ans;
    }
    int mid = (l + r) / 2;
    int trai = GET(id * 2 , l , mid , u , v);
    int phai = GET(id * 2 + 1 , mid + 1 , r , u , v);
    return trai + phai;
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
    }
    build(1 , 1 , n);
    cin >> q;
    while(q--)
    {
        int type , l , r , x;
        cin >> type ;
        if(type == 0)
        {
            cin >> l >> r >> x;
            update(1 , 1 , n , l , r , x);
        }
        else
        {
            cin >> l >> r;
            cout << GET(1 , 1 , n , l , r) << endl;
        }
    }
    return 0;
}
