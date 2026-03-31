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
	
	int n;
	while(cin >> n && n){
		map<int,int> mp;
		for(auto prime: primes){
			while(n%prime == 0){
				mp[prime]++;
				n/= prime;
			}
		}

		if(n != 1) mp[n]++;

		for(auto pr : mp){
			cout << pr.first << "^" << pr.second << " ";
		}
		cout << "\n";
	}


	

	return 0;
}