#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define en "\n"
const int N = 100005;
bool isPrime[N];
vector<int> primes;

void sieve()
{
    isPrime[0] = isPrime[1] = true;
    for(int i = 4; i < N; i += 2) isPrime[i] = true;

    primes.push_back(2);
    for(ll i = 3; i < N; i += 2)
    {
        if(!isPrime[i])
        {
            primes.push_back(i);
            for(ll j = i * i; j < N; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int n, color = 1;
    cin >> n;
    if(n > 2){
        cout << 2 << "\n";
    }
    else{
        cout << 1 << "\n";
    }

    for(int i = 2; i <= n + 1; i++){
        if(!isPrime[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << "\n";


    return 0;

}
