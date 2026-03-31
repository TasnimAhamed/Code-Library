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

bool checkZero(int pp){
	while(pp > 0){
		int rem = pp%10;
		pp/=10;
		if(rem == 0) return true;
	}

	return false;
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	
	int n; 
	while(cin >> n){
		map<int,int> pfact;
		int i = 0;
		while(n > 1){
			if(!isPrime[n]){
				pfact[n]++;
				break;
			}
			while(n%primes[i] == 0){
				pfact[primes[i]]++;
				n/=primes[i];
			}
			i++;
		}
		cout << 1 ;
		for(auto pr : pfact){
			for(int i = 0; i < pr.second; i++){
				cout << " x " << pr.first;
			}
		}
		cout << "\n";
	}


	

	return 0;
}