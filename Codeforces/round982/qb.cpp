#include <iostream>
#include <vector>
#include <climits>
#define ll long long

using namespace std;

ll findMax(vector<ll> &vec, int left, int right) {
  ll max = LLONG_MIN;
  for (int i = left; i <= right; i++) {
    if (vec[i] > max) {
      max = vec[i];
    }
  }
  return max;
}
void buildTree(const vector<ll>& arr, int pos, int left, int right,vector<ll> &segTree) {
    if (left == right) { 
        segTree[pos] = arr[left];
        return;
    }

    int mid = (left + right) / 2;
    buildTree(arr, 2 * pos + 1, left, mid,segTree);       
    buildTree(arr, 2 * pos + 2, mid + 1, right,segTree);  


    segTree[pos] = max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}


ll rangeMinQuery(int ql, int qr, int pos, int left, int right,vector<ll> &segTree) {
    if (ql <= left && qr >= right) {
        return segTree[pos]; 
    }

    if (ql > right || qr < left) {
        return LLONG_MIN; 
    }

    int mid = (left + right) / 2;
    return max(rangeMinQuery(ql, qr, 2 * pos + 1, left, mid,segTree),   
               rangeMinQuery(ql, qr, 2 * pos + 2, mid + 1, right,segTree)); 
}
void solve() {
  vector<ll> segTree;
  int n;
  cin>>n;
  segTree.resize(4 * n, LLONG_MIN);
  ll x;
  vector<ll> vec(n);
  for(int i = 0; i < n; i++) {
    cin>>vec[i];
  }
  buildTree(vec, 0, 0, n - 1,segTree);
  vector<ll> leads;
  x = 0;
  for(int i = 0; i<n; i++) {
    if(vec[i]>x){
      leads.push_back(i);
      x = vec[i];
    }
  }
  // vector<ll> trails(n);
  // x = 0;
  // for(int i = n-1; i>=n; i--){
  //   if(vec[i]>x){
  //     x = vec[i];
  //   }
  //   trails[i] = x;
  // }
  int ans = 0;
  int ub = n-1,lb = 0;
  for(int i = leads.size()-1;i>0 && lb<ub ;i--){
    ll rr = vec[leads[i-1]];
    if(leads[i]==ub) {
      if(ub==lb) {
        break;
      }
      ans++;
      ub--;
      continue;
    }
    ll fm;
    if(rr>= (fm = findMax(vec,leads[i]+1,ub))){
      ans++;
      // ub = leads[i] - 1;
      vec[leads[i]] = fm;
    }else{
      if(leads[i]> ub+n+1-leads[i]) {
        ans += ub+1-leads[i];
        ub = leads[i]-1;
      }else{
        ans += leads[i];
        ub = leads[i] - 1;
        break;
      }
    }
  }
  cout<<ans<<"\n";
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    solve();
  }
}