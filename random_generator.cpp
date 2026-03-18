#include <bits/stdc++.h>
using namespace std;
#define int int64_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ran(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

int32_t main() {
	
	// Your Code goes here

	return 0;
}