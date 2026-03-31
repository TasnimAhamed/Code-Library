#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e6+5;
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
	
	int sz = primes.size();
	vector<int> isFear(sz+1, 0);

	for(int i = 0; i < sz; i++){
		int pp = primes[i];
		if(checkZero(pp)){
			continue;
		}
		int paisi = 1;
		while( pp > 0){
			if(isPrime[pp]){
				paisi = 0;
				break;
			}
			int pw = log10(pp);
			int ff =  pow(10,pw);
			pp = pp - (pp / ff * ff);
		}
		if(paisi) isFear[i] = 1;
	}

	for(int i = 1; i < sz; i++){
		isFear[i] += isFear[i-1];
	}

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n == 1) cout << 0 << "\n";
		else{
			int idx = upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
			cout << isFear[idx] << "\n";
		}
	}


	

	return 0;
}