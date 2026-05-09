#include<bits/stdc++.h>
using namespace std;
using ll = long long;


ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

ll fact(int n, ll mod) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i % mod;
    }
    return res;
}

ll nCr(int n, int r, int mod) {
    if (r > n) return 0;

    ll numerator = fact(n, mod);
    ll denominator = fact(r, mod) * fact(n - r, mod) % mod;

    return numerator * modInverse(denominator, mod) % mod;
}

ll lucas(int n, int r, int p) {
	if (r == 0) {
		return 1;
	}
	return (lucas(n/ p, r / p, p) * nCr(n % p , r % p, p) % p);
}

void solve() {
    // int n, r, p; cin >> n >> r >> p; // p is a prime;
    // ll res = lucas(n, r, p);

    int n, p; cin >> n >> p;
    ll res = modInverse(n, p);

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}