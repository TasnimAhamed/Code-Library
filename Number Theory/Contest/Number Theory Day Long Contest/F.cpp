#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e8+5;
vector<bool> isPrime(N);
vector<int> primes;

void sieve(){
	isPrime[0] = isPrime[1] = true;
	for(int i = 4; i < N; i+=2) isPrime[i] = true;
	primes.push_back(2);

	for(int i = 3; i < N; i+=2){
		if(!isPrime[i]){
			primes.push_back(i);
			for(int j = i*i; j < N; j += i){
				isPrime[j] = true;
			}
		}
	}
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(isPrime[n]) cout << -1 << "\n";
		else{
			int idx = (lower_bound(primes.begin(), primes.end(), n) - primes.begin()) + 1;
			// cout << idx << "\n";
			int mm = ceil((-1 + sqrt(1.0 + 4.0 * 1 * 2*idx))/2.0);
			int cc = idx - (mm * (mm -1)/2);
			cout << mm << ' ' << cc << "\n";
		}
	}
	

	
	
	
	return 0;
}