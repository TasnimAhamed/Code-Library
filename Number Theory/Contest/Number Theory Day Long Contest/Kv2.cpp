#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define en "\n"
const int MX = 1e6;
int cnt[MX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }

    for(int i = MX; i>=1; i--){
        int div = 0;
        for(int j = i; j <= MX; j += i){
            div += cnt[j];
        }
        if(div >= 2) {
            cout << i << "\n";
            break;
        }
    }


    return 0;

}

