#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 1;
vector<array<int, 2>> factors;

int spf[N];
void getSPF(){
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; i < N; i += 2) spf[i] = 2;
    for(int i= 3; i < N; i += 2){
        if(spf[i] == i){
            for(int j = 2 * i; j < N; j += i){
                spf[j] = min(spf[j], i);
            }
        }
    }
}

void getFactors(){
    factors.push_back({0,1});
    for(int i = 2; i < N; i++){
        int pfact = 0;
        int n = i;
        while(n > 1){
            n /= spf[n];
            pfact++;
        }
        factors.push_back({pfact, i});
    }

    sort(factors.begin(), factors.end());

}
void solve(){
    int n, tt = 1;
    while(cin >> n and n){
        cout << "Case "<< (tt++) << ": " << factors[n-1][1] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getSPF();
    getFactors();

    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }

    return 0;

}
