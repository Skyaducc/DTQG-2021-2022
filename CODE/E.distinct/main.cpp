#include <iostream>
#include <bits/stdc++.h>
#define foru(i , a , b) for(int i=a ; i<=b ; i++)
#define ford(i , a , b) for(int i=a ; i>=b ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x , i) ((x) | MASK(i))
#define SET_OFF(x , i) ((x) & ~MASK(i))
using namespace std;
int m , n;
const int MAXN = 8101;
int a[MAXN][MAXN];
int main()
{
    freopen("distinct.inp" , "r" , stdin);
    freopen("distinct.out" , "w" , stdout);
    cin >> m >> n;
    foru (i , 1 , m)
    {
        foru (j , 1 , n)
        {
            cin >> a[i][j];
        }
    }
    int ans = 1;
    foru (i , 1 , m)
    {
        foru (j , 1 , n)
        {
            set<int> s;
            bool ok = true;
            foru (x , i , m)
            {
                foru (y , j , n)
                {
                    if(s.find(a[x][y]) != s.end())
                    {
                        if(i == 2 && j == 1)
                        {
                            cout << x << " " << y << endl;
                        }
                        ok = false;
                        break;
                    }
                    else ans = max(ans , (x - i + 1) * (y - j + 1));
                    s.insert(a[x][y]);
                }
                if(!ok) break;
            }
        }
    }
    cout << ans;
    return 0;
}
