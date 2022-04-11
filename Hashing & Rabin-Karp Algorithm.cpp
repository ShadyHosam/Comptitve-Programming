    #include <bits/stdc++.h>
    using namespace std;
    #define  ll long long
    const int N = 3e5 + 10;
    vector<ll> xpower(N);
    ll egcd(ll a, ll b, ll &x, ll &y) { /// ax + by = gcd(a,b)
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        ll g = egcd(b, a % b, y, x);
        y -= (a / b) * x;
        return g;
    }

    ll modInverse(ll a, ll m) {
        /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
        ll x, y, g;
        g = egcd(a, m, x, y);
        if (g > 1)
            return -1;
        return (x + m) % m;
    }

    void prepower(ll x ,ll p ) {
        xpower[0] = 1;
        for (int i = 1; i <= N; i++)
            xpower[i] = (xpower[i - 1] * x) % p;
    }

    /// HASHING FUNCTION
    /// h = old hash ,  x = const we use ,  p = the prime uses in %  , ch = new char we will push back
    ll FixMOD(ll x, ll p) {
        return (x + p) % p;
    }
    ll PushBack(ll h, char ch, ll x, ll p) {
        return ((h * x) % p + ch) % p;
    }

    ll PushFront(ll h, ll xp, ll len, char ch, ll p) {
        return (h + (xp * ch) % p) % p;
    }

    ll PopFront(ll h, ll xp, char ch, ll p) {
        return FixMOD((h - (xp * ch) % p), p);
    }

    ll PopBack(ll h, char ch, ll x, ll p) {
        return (FixMOD(h - ch, p) * modInverse(x, p)) % p;
    }

     ll to (ll a , ll b , ll r)
     {
         return  a * r + b;
     }

    int main() {
        ll p = 1e9 + 7;
        ll x = 128;
        prepower(x , p );
        int t;
        cin >> t;
        while (t--) {
            solve();
            cout << "\n";
        }
    }

