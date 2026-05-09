#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;
// for using i128 we need to use __int128_t
// for unsigned integer use __uint128_t
// i128 mx = (((i128)1 << 126) - 1) * 2 + 1;

// Input for i128
i128 read_i128() {
    string s;
    cin >> s;

    i128 x = 0;
    int sign = 1;
    int start = 0;

    if (s[0] == '-') {
        sign = -1;
        start = 1;
    }

    for (int i = start; i < s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }

    return x * sign;
}

// Output for i128
void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    if (x < 0) {
        cout << '-';
        x = -x;
    }

    string s;

    while (x > 0) {
        s += char('0' + x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 x = read_i128();

    print_i128(x);
    cout << '\n';

    return 0;
}