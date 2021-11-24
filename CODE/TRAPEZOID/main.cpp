// Start time: 10h45
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define task ""
using namespace std;
const int MaxN = 5001;
int n, t;
vector<long long> edge;          // edge: lưu những cạnh xuất hiện >= 2 lần
map<int, int> cnt;               // đếm số lần xuất hiện của a[i]
long long ans, s[MaxN], a[MaxN]; // s: tính tổ hợp chập 2
bool check[MaxN];
long long combination(int n, int k) // Tính tổ hợp
{
    if (k == 2)
        return 1ll * n * (n - 1) / 2;
    if (k == 3)
        return 1ll * n * (n - 1) * (n - 2) / 6;
    if (k == 4)
        return 1ll * n * (n - 1) * (n - 2) * (n - 3) / 24;
    return 0;
}
main()
{
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cnt.clear();
        edge.clear();
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            check[i] = true;
            if (cnt[a[i]] == 2)
                edge.push_back(a[i]); // Cho những cạnh xuất hiện >= 2 lần vào xét
        }
        if (edge.empty()) // edge rỗng thì ans = 0
        {
            cout << 0 << '\n';
            continue;
        }
        sort(a + 1, a + 1 + n);         // Sắp xếp lại a theo chiều tăng độ dài
        sort(edge.begin(), edge.end()); // Sắp xếp lại edge theo chiều tăng độ dài
        for (int i = 1; i <= n; i++)
        {
            if (cnt[a[i]] >= 2) // Cạnh đơn được đánh dấu là true
                check[i] = false;
        }
        for (int i = 1; i <= edge.size(); i++)
        {
            s[i] = s[i - 1] + combination(cnt[edge[i - 1]], 2);
        }
        // TH1: Hình có 4 cạnh bằng nhau
        for (int i = 0; i < edge.size(); i++)
        {
            if (cnt[edge[i]] >= 4)
                ans += combination(cnt[edge[i]], 4);
        }
        // TH2: Hình có 3 cạnh bằng nhau
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < edge.size(); j++)
            {
                if (a[i] != edge[j])
                    ans += (abs(edge[j] - a[i]) / 2 < edge[j]) ? combination(cnt[edge[j]], 3) : 0;
            }
        }
        // TH3: Hình có 2 cặp cạnh bằng nhau
        for (int i = 0; i < edge.size(); i++)
        {
            for (int j = i + 1; j < edge.size(); j++)
            {
                ans += combination(cnt[edge[i]], 2) * combination(cnt[edge[j]], 2);
            }
        }
        // TH4: Hình có 2 cạnh bằng nhau
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] != a[j])
                {
                    int pos = -1, l = 0, r = edge.size() - 1;
                    while (l <= r)
                    {
                        int mid = (l + r) / 2;
                        if (edge[mid] > (a[j] - a[i]) / 2)
                        {
                            pos = mid;
                            r = mid - 1;
                        }
                        else
                            l = mid + 1;
                    }
                    if (pos != -1)
                    {
                        ans += s[edge.size()] - s[pos];
                        if (!check[i] && (a[j] - a[i]) / 2 < a[i])
                            ans -= combination(cnt[a[i]], 2);
                        if (!check[j] && (a[j] - a[i]) / 2 < a[j])
                            ans -= combination(cnt[a[j]], 2);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
