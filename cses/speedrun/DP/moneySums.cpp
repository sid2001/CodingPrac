// #include <iostream>
// #include <vector>
// #include <set>
// #include <climits>
#include <algorithm>
// using namespace std;

// void solve(vector<int> &vec,set<int> &ans,vector<set<int>> &dp,int curr = 0,int sum = 0) {
//   if(curr>=vec.size()){
//     if(sum != 0){
//       // if(ans.find(sum) != ans.end()) cout<<"YES"<<"\n";
//       // cout<<"a: "<<sum<<"\n";
//       ans.insert(sum);
//     }
//     return;
//   }
//   if(dp[curr].find(sum) != dp[curr].end()) {
//     // cout<<"y"<<"\n";
//     return;
//   }
//   dp[curr].insert(sum);
//   solve(vec, ans, dp, curr+1, sum+vec[curr]);
//   solve(vec, ans, dp, curr+1, sum);
  
//   return;
// }

// int main() {
//   int n;
//   cin>>n;
//   vector<int> vec(n);
//   for(int i = 0; i < n; i++) cin>>vec[i];
//   sort(vec.begin(),vec.end());
//   vector<set<int>> dp(n);
//   set<int> ans;
//   solve(vec,ans,dp);
//   cout<<ans.size()<<"\n";
//   for(auto v : ans) {
//     cout<<v<<" ";
//   }
// }

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  
  set<int> ans;
  ans.insert(0);  // Start with a sum of 0

  for (int num : vec) {
    vector<int> new_sums;
    for (int sum : ans) {
      new_sums.push_back(sum + num);  // Compute new sums by adding current number
    }
    for (int new_sum : new_sums) {
      ans.insert(new_sum);  // Add new sums to the set
    }
  }

  cout << ans.size() - 1 << "\n"; // Subtract 1 if 0-sum is not needed
  // sort(ans.begin(), ans.end());
  for (auto it = ans.begin(); it != ans.end(); ++it) {
    if (*it != 0) cout << *it << " ";
  }
  cout << "\n";

  return 0;
}
