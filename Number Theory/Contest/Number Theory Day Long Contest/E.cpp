#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e7+5;
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
	
	int sz = primes.size();
	vector<int> isFormed(sz+1, 0);

	for(int i = 0; i < sz; i++){
		int ff = sqrt(primes[i]);
		for(int j = 1; j*j <= ff; j++){
			int ss = primes[i] - j*j*j*j;
			int sq = sqrt(ss);
			if((sq * sq) == ss){
				isFormed[i] = 1;
				break;
			}
		}
	}

	for(int  i = 1; i < sz; i++){
		isFormed[i] += isFormed[i-1];
	}

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n == 1) cout << 0 << "\n";
		else{
			int idx = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
			cout << isFormed[idx] << "\n";
		}
	}
	

	
	
	
	return 0;
}