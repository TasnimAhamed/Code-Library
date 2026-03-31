#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a, b; cin >> a >> b;
    int gcd = __gcd(a, b);
    int cnt = 0;
    for(int i = 1; i*i <= gcd; i++){
        if(gcd%i == 0){
            ++cnt;
            if(gcd/i != i) ++cnt;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;

}

