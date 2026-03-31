#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int legendreExponent(int n, int p) {
    int exponent = 0;
    while (n > 0) {
        n /= p;
        exponent += n;
    }
    return exponent;
}

void solve() {
    int n, p;
    cin >> n >> p;

    int result = legendreExponent(n, p);
    cout << result << "\n";
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