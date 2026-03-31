#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e8+1;
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
	for(int i = 0; i < primes.size(); i+=100){
		cout << primes[i] << "\n";
	}
	
	
	
	
	return 0;
}