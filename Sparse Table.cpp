#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

ll Log(int x) { return 31 - __builtin_clz(x); }

ll lcm(ll a, ll b) { return (b / __gcd(a, b)) * a; }
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int MOD = 1e9 + 7;
int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f;
const int N = 2e5 + 10;

// Sparse Table
vector<vector<int>> buildTable(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> table(n, vector<int>(Log(n) + 1)); // [n][log2(N)]
    for (int i = 0; i < n; i++)
        table[i][0] = arr[i];          // each element is itself ..

    for (int j = 1; (1 << j) <= n; j++) // j is the power we use..
        for (int i = 0; i + (1 << j) - 1 < n; i++) // i + 2^j -1 <  n   ,, to make sure we in bounds
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);


    return table;
}

int querey(int l, int r, vector<vector<int>> &table) {
    int len = r - l + 1; // the length of the querey..
    //int j = Log(len);
    int st = l; // the first index we start at
    int mn = INT_MAX;
    // 1 -          check if its on or off
    // 2 -          5 = 101  we need to take 1 then 4
    // 3 -           then we move the st pointer to the next step
    for (int j = 0; (1 << j) <= len; j++) {
        if (len & (1 << j)) {
            mn = min(mn, table[st][j]);
            st += (1 << j);
        }
    }
    return mn;

}

int main() {
    fast;
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    // int z = 1;
    while (t--) {
        //cout << "Case #" << z++ << ": ";
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i=0 ;i<n;i++)
            cin >> arr[i];

        vector<vector<int>>table = buildTable(arr);
        int q;
        cin >> q;
        while (q--)
        {
                int l , r ;
                cin >> l >> r;
                l-- , r--;
                cout << querey(l , r ,table) <<"\n";
        }
        cout << "\n";

    }
}

