// #include <iostream>
// #include <vector>
// #include <cmath>
// #define ll long long
// using namespace std;

// int countPatterns(int s) {
//   int div = 10000;
//   int c = 0;
//   while(s > 999) {
//     if(s%div==1100) c++;
//     s /= 10;
//   }
//   return c;
// }

// int countDigits(int s) {
//   int c = 0;
//   while(s>0){
//     s /= 10;
//     c++;
//   }
//   return c;
// }

// void query(int &s, int a, int b,int digits,int &count){
//   int r = digits - a;
//   int sb = s;
//   int div = (r>0)?((int)pow(10,r)):1;
//   int ad = (s/div)%10;
//   if(ad==b) {
//     if(count>0) cout<<"YES"<<"\n";
//     else cout<<"NO"<<"\n";
//     return;
//   }
//   if(r>3) {
//     int dd = (int)pow(10,r-3);
//     s /= dd;
//   }
//   int t = 4;
//   while(t-- && s > 999 ) {
//     if(s % 10000 == 1100) {
//       count--;
//       break;
//     }
//     s /= 10;
//   }
//   sb = (sb/(div*10))*(div*10) + b*div + sb%div;
//   s = sb;
//   t = 4;
//   if(r>3) {
//     int dd = (int)pow(10,r-3);
//     sb /= dd;
//   }
//   while(t-- && sb > 999 ) {
//     if(sb % 10000 == 1100) {
//       count++;
//       break;
//     }
//     sb /= 10;
//   }
//   if(count>0) cout<<"YES"<<"\n";
//   else cout<<"NO"<<"\n";
//   return;
// }

// void solve() {
//   int s,q;
//   cin>>s>>q;
//   int a,b;
//   int count = countPatterns(s);
//   int digits = countDigits(s);
//   for(int i = 0; i < q; i++){
//     cin>>a>>b;
//     if(s<1000) {
//       cout<<"NO"<<"\n";
//       continue;
//     }
//     query(s,a,b,digits,count);
//   }
// }

// int main() {
//   int t;
//   cin>>t;
//   while(t--)  {
//     solve();
//   }
// }

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

// Function to check if "1100" exists starting from index pos
bool has1100(const string &s, int pos) {
    if (pos >= 0 && pos + 3 < s.size()) {
        return s.substr(pos, 4) == "1100";
    }
    return false;
}

void solve() {
    string s;
    int q;
    cin >> s >> q;

    // Set to store the starting indices of "1100"
    set<int> patterns;
    int n = s.size();

    // Initialize the set with all occurrences of "1100" in the original string
    for (int i = 0; i <= n - 4; i++) {
        if (has1100(s, i)) {
            patterns.insert(i);
        }
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int pos;
        char v;
        cin >> pos >> v;
        pos--;  // Convert to 0-based index

        // Update the pattern set for positions affected by the change
        for (int j = max(0, pos - 3); j <= min(n - 4, pos); j++) {
            if (has1100(s, j)) patterns.erase(j);  // Remove old pattern if it exists
        }

        // Perform the update on the string
        s[pos] = v;

        // Check again and add new patterns if present
        for (int j = max(0, pos - 3); j <= min(n - 4, pos); j++) {
            if (has1100(s, j)) patterns.insert(j);
        }

        // Output result
        if (!patterns.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
