// #include <iostream>
// using namespace std;

// void solve() {
//     long long b, c, d;
//     cin >> b >> c >> d;
    
//     long long a = 0;
//     for (int i = 0; i < 62; ++i) {
//         int bb = (b >> i) & 1;
//         int cc = (c >> i) & 1;
//         int dd = (d >> i) & 1;
//         if (dd == 0) {

//             if (bb == 1 && cc == 0) {
//                 cout << -1 << "\n";
//                 return;
//             }
//             a |= (bb << i);
//         } else {
//             if (bb == 0 && cc == 1) {
//                 cout << -1 << "\n";
//                 return;
//             }

//             a |= (1LL << i);
//         }
//     }
    
//     cout << a << "\n";
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }
#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    long long k;
    cin >> k;
    // The smallest n such that there are exactly k bulbs on is k^2
    cout << k * k << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
