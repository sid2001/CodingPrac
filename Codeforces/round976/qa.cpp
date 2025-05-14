#include <iostream>
#include <vector>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k == 1) {
      cout << n << "\n";
      return;
    }
    while (n > 0) {
        ll power = 1;
        if(n<k) {
          ans += n;
          break;
        }
        if(k == n) {
          ans++;
          break;
        }
        while (power * k <= n) {
            power *= k;
        }
        n -= power;
        ans++;
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
