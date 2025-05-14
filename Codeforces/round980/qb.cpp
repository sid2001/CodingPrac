// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>

// #define ll unsigned long long 

// using namespace std;

// void solve() {
//   ll n, k;
//   cin>>n>>k;
//   vector<ll> vec(n);
//   for(ll i = 0; i<n; i++) {
//     cin>>vec[i];
//   }
//   sort(vec.begin(), vec.end());
//   ll idx = 0;
//   ll c = 0;
//   ll ans = 0;
//   while(idx<n) {
//     ll x = vec[idx];
//     if((x-c)*n>=k) {
//       ans = ans + k;
//       break;
//     }else{
//       ans = ans + (x-c)*n;
//       k = k - (x-c)*n;
//       if(k==0)break;
//       c = x;
//       while(c==vec[idx]){
//         idx++;
//         ans = ans + 1;
//         n = n-1;
//       }
//     }
//   }
//   cout<<ans<<"\n";
// }

// int main() {
//   int t;
//   cin>>t;
//   while(t--) {
//     solve();
//   }
// }

#include <iostream>
#include <vector>
#include <algorithm>

#define ll unsigned long long 

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);

    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    
    ll c = 0;
    ll ans = 0;
    ll idx = 0;
    
    while (k > 0 && idx < n) {
        ll x = vec[idx];
        ll presses_needed = (x - c) * (n - idx);  
        
        if (presses_needed >= k) {
            ans += k;
            k = 0;
        } else {
            ans += presses_needed;
            k -= presses_needed;
            c = x;
            
            while (idx < n && vec[idx] == c) {
                idx++;
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
