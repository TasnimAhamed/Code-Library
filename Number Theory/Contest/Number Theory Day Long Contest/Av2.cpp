#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 3005;
vector<bool> isPrime(N);
vector<int> primes;

void sieve(){
	isPrime[0] = isPrime[1] = true;
	for(int i = 4; i < N; i+=2) isPrime[i] = true;
	for(int i = 3; i < N; i+=2){
		if(!isPrime[i]){
			for(int j = i*i; j < N; j += i){
				isPrime[j] = true;
			}
		}
	}
	primes.push_back(2);
	for(int i = 3; i < N; i += 2){
		if(!isPrime[i]){
			primes.push_back(i);
		}
	}
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	
	int n; cin >> n;
	int ans = 0;
	for(int i = 2; i <= n; i++){
		int cnt = 0;
		for(auto prime : primes){
			if(prime > i) break;
			if(i%prime == 0) ++cnt;
		}
		if(cnt == 2) ans++;
	}
	cout << ans << "\n";
	
	
	return 0;
}