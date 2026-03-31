#include <bits/stdc++.h>
using namespace std;
#define int int64_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ranInt(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

double ranDouble(double a, double b) {
    return uniform_real_distribution<double>(a, b)(rng);
}

string ranString(int len, const string &charset = "abcdefghijklmnopqrstuvwxyz") {
    string res;
    for(int i = 0; i < len; i++) {
        res += charset[ranInt(0, charset.size() - 1)];
    }
    return res;
}

vector<int> ranArray(int n, int a, int b) {
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
    	res[i] = ranInt(a, b);
    }
    return res;
}

int32_t main() {

    // Your Code goes here

    return 0;
}