#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
const int MAXN = 3001;
int r , c , h , w;
int a[MAXN][MAXN];
set<int> s[MAXN][MAXN];
pii pi[MAXN * MAXN];
int p[MAXN][MAXN];
void brute()
{
    int res = 0;
    foru (i , h , r)
    {
        foru (j , w , c)
        {
            vector<int> v;
            foru (x , i - h + 1 , i)
            {
                foru (y , j - w + 1 , j)
                {
                    v.push_back(a[x][y]);
                }
            }
            sort(v.begin() , v.end());
            res = max(res , v[(h*w+1)/2-1]);
        }
    }
    cout << res;
}
int Get(int x , int y , int i , int j)
{
    return p[i][j] - p[i][y-1] - p[x-1][j] + p[x-1][y-1];
}
bool check(int res)
{
    foru (i , 1 , r)
    {
        foru (j , 1 , c)
        {
            if(a[i][j] <= res) p[i][j] = 1;
            else p[i][j] = 0;
            p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
        }
    }
    foru (i , 1 , r - h + 1)
    {
        foru (j , 1 , c - h + 1)
        {
            int x = i + h - 1;
            int y = j + w - 1;
            if(x > r || y > c)  continue;
            int tmp = Get(i , j , x , y);
            if(tmp <= (h * w + 1) / 2)  return true;
        }
    }
    return false;
}
void full()
{
    foru (i , 1 , r)
    {
        foru (j , 1 , c)
        {
            pi[a[i][j]] = {i , j};
        }
    }
    int Left = 1;
    int Right = r * c;
    int ans = 0;
    while(Left <= Right)
    {
        int mid = (Left + Right) / 2;
        if(check(mid))
        {
            ans = mid;
            Left = mid + 1;
        }
        else Right = mid - 1;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("digits.inp" , "r" , stdin);
    freopen("digits.out" , "w" , stdout);
    cin >> r >> c >> h >> w;
    foru (i , 1 , r)
    {
        foru (j , 1 , c)
        {
            cin >> a[i][j];
        }
    }
    // if(r <= 300 && c <= 300) 
    // {
    //     brute();
    //     // return 0;
    // }
    // cout << endl;
    full();
    return 0;
}
