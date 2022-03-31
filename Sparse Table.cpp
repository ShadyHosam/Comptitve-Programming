#include <bits/stdc++.h>
using namespace std;
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
    int t;
    cin >> t;
    while (t--) {
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

