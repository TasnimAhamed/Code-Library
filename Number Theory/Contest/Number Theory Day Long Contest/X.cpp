#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1015;
bool isPrime[N];
vector<int> prime;
int cnt[N];

void sieve()
{
	isPrime[0] = isPrime[1] = 1;
	for(int i = 4; i < N; i+=2){
		isPrime[i] = 1;
	}
	for(int i = 3; i*i <= N; i += 2){
		if(!isPrime[i]){
			for(int j = i * i; j < N; j += i){
				isPrime[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i < N; i+=2){
		if(!isPrime[i]){
			prime.push_back(i);
		}
	}
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	
	int n, k; cin >> n >> k;
	int cnt = 0;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < prime.size(); j++){
			if(prime[j+1] >= i) break;

			if((prime[j] + prime[j+1]+1) == i and !isPrime[i]){
				// cout << i << "\n";
				++cnt;
			}
		}
	}

	if(cnt >= k) cout << "YES\n";
	else cout << "NO\n";
	
	
	
	return 0;
}