#include<bits/stdc++.h>
using namespace std;
#define int long long int



int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int sum = 0;
		for(int i = 1; i *i <= n; i++){
			if(n%i == 0){
				sum += i;
				if(n/i != i){
					sum += n/i;
				}
			}
		}

		cout << sum - n << "\n";
	}
	
	
	return 0;
}