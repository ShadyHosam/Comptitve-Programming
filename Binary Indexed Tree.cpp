#include <bits/stdc++.h>
using namespace std;
#define  ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)

void update(int index, int oldvalue, int newvalue, vector<int> &bit) {
    for (int i = index; i < bit.size(); i += (i & -i))
        bit[i] -= oldvalue, bit[i] += newvalue;
}
vector<int> buildBit(vector<int> &arr) {
    vector<int> bit(arr.size() + 1, 0);
    for (int i = 1; i < bit.size(); i++)
        update(i, 0, arr[i - 1], bit);
    return bit;
}
int get(int right, vector<int> &bit) {
    int sum = 0;
    for (int i = right; i > 0; i -= (i & -i))
        sum += bit[i];
    return sum;
}
int doQuerey(int l, int r, vector<int> &bit) {
    return get(r, bit) - get(l - 1, bit);
}
void dowork() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int mx = 0;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
  
    vector<int> bit = buildBit(arr);
}
int main() {
       fast;
    int t;
    cin >> t;
    while (t--) {
        dowork();
        cout << "\n";

    }
}
