#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e6+5;
vector<bool> isPrime(N);
vector<int> primes;
vector<int> divCount(N);

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

void divisors()
{
	divCount[1] = 1;
	for(int i = 2; i < N; i++){
		map<int,int> mp;
		int num = i;
		for(auto prime : primes){
			if(prime * prime > num) break;
			while(num%prime == 0){
				mp[prime]++;
				num /= prime;
			}
		}
		if(num > 1) mp[num]++;
		int ans  = 1;
		for(auto pr : mp){
			ans *= (pr.second + 1);
		}
		divCount[i] = ans;
	}
}


int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	divisors();

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		
		cout << divCount[n] << "\n";
	}

	return 0;
}