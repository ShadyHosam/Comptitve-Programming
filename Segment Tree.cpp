#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)

// To create Segment Tree
// 1- create array of closet power of 2 to the size of numbes..
// 2- create array  to store the values
// 3-read the values of array and assign values of element[i] to V
struct segtree {
    int size;
    vector<ll> sums;

    void init(int n) {
        size = 1;
        while (size < n)size *= 2;
        sums.assign(2 * size, 0LL);
    }

    // x is the node we start to go deep from it , lx is the left border , rx is the right border.
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) { // we reached the node
            sums[x] = v;
            return;
        }
        // the middle pos of current segemnt will be (rx + lx) / 2
        int m = (rx + lx) / 2;
        if (i < m)// then we will go to the left subtree
        {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        // calc the sum of the node will be
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l)
            return 0;

        if (lx >= l and r >= rx)return sums[x];

        int m = (rx + lx) / 2;

        ll left_subtree = sum(l, r, 2 * x + 1, lx, m);
        ll right_subtree = sum(l, r, 2 * x + 2, m, rx);
        return left_subtree + right_subtree;
    }

    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};


void dowork() {
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        st.set(i, value);
    }
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int index, v;
            cin >> index >> v;
            st.set(index, v);
        } else {
            int l, r;
            cin >> l >> r;
           cout << st.sum(l, r) <<"\n";
        }
    }
}

int main() {
    fast;
    //freopen("files.in", "r", stdin);
    //  freopen("output.txt", "w", stdout);
//    int t;
//    cin >> t;
//    int z = 0;
//    while (t--)
    {
        //   cout << "Case #" << ++z << ": ";
        dowork();
        cout << "\n";

    }
}
