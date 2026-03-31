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
	
	vector<int> disPrime(N, 0);
	for(int i = 1; i <N; i++){
		int cnt = 0, ff = i, j = 0;
		while(ff > 1){
			if(!isPrime[ff]){
				++cnt;
				break;
			}
			bool lol = false;
			while(ff%primes[j] == 0){
				ff/= primes[j];
				lol = true;
			}
			if(lol) ++cnt;
			++j;
		}
		if(cnt == 2) disPrime[i] = 1;
	}

	for(int i = 1; i < N; i++){
		disPrime[i] += disPrime[i-1];
	}

	int n; cin >> n;
	cout << disPrime[n] << "\n";
	
	
	return 0;
}