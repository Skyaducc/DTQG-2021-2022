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
int r , c , k;
int dx[] = {1 , 0 , 0 , -1};
int dy[] = {0 , -1 , 1 , 0};
int a[10][5], idx[10][5], tp[25];
    int cnt = 0, res = -1e9;
 
    bool isbanned(int x, int y) {
        if (x > 0 && y > 0 && x <= r && y <= c)
            return 0;
        return 1;
    }
 
    void check() {
        int s = 0, dem = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (tp[idx[i][j]] > 0) {
                    dem++;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (isbanned(x, y))
                            continue;
                        if (tp[idx[x][y]] > 0)
                            return;
                    }
                    s += a[i][j];
                }
            }
        }
 
        if (dem == K)
            res = max(res, s);
    }
 
    void backtrack(int i) 
    {
    	foru (j , 0 , 1)
        {
        	x[i] = j;
            if (i == cnt)
                check();
            else
                backtrack(k + 1);
        }
    }
 
    void sol() {
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
                idx[i][j] = ++cnt;
            }
        backtrack(1);
        cout << res;
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("jump.inp" , "r" , stdin);
    freopen("jump.out" , "w" , stdout);
    return 0;
}