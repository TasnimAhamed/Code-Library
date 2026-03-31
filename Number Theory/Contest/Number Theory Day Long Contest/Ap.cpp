#include<bits/stdc++.h>
using namespace std;
#define int long long int

bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t; scanf("%lld", &t);
	while(t--){
		int m, n; scanf("%lld %lld", &m, &n);
		if(m <= 2) cout << 2 << "\n";
		if(m%2 == 0) ++m;
		for(int i = m; i <= n; i+=2){
			if(isPrime(i)) cout << i << "\n";
		}
	}
	
	return 0;
}