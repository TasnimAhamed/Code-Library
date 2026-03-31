#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 5;
bool isPrime[N];
vector<int> prime;

bool checkPrime(ll n)
{
    if(n < 2) return false;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void sieve()
{
    isPrime[0] = isPrime[1] = true;
    for(int i = 4; i < N; i += 2) isPrime[i] = true;

    prime.push_back(2);
    for(ll i = 3; i < N; i += 2)
    {
        if(!isPrime[i])
        {
            prime.push_back(i);
            for(ll j = i * i; j < N; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    map<ll,ll> mp;

    int j = 0;
    while(n > 1 and j < prime.size())
    {
        ll pp = prime[j];
        while(n%pp == 0)
        {
            n /= pp;
            mp[pp]++;
        }
        ++j;
    }
    int ans = 0;
    if(n > 1) ans++;
    for(auto [key, val] :mp) {
        int cal = (-1 + (sqrt(1 + 8 * val)))/2;
        ans += cal;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;

}
