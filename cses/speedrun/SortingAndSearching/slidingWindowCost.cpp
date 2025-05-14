#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  vector<ll> vec(n);
  
  for(int i = 0; i < n; i++) cin>>vec[i];
  ll lsum = 0, rsum = 0;
  multiset<ll> mih;
  multiset<ll,greater<int>> mah;
  vector<ll> temp(k);
  for(int i = 0; i < k; i++) {
    temp[i] = vec[i];
  }
  
  sort(temp.begin(), temp.end());
  for(int i = 0; i < k; i++) {
    if(i < k/2) {
      mah.insert(temp[i]);
      lsum += temp[i];
    }
    else {
      mih.insert(temp[i]);
      rsum += temp[i];
    }
  }

  if(mah.size()==mih.size()) cout<< ((*mah.begin()*(k/2) - lsum) + (rsum - *mah.begin()*(k/2)))<<" ";
  else{
    cout<< ((*mih.begin()*(k/2) - lsum) + (rsum - *mih.begin()*(k/2 + 1)))<<" ";
  }

  for(int i = 1; i < n-k+1;i++) {
    if(k%2==0){
      ll x = *mah.begin();
      if(vec[i-1] <= x){
        mah.erase(mah.find(vec[i-1]));
        lsum -= vec[i-1];
        if(vec[i+k-1] < *mih.begin()) {
          lsum += vec[i+k-1];
          mah.insert(vec[i+k-1]);
        }
        else {
          lsum += *mih.begin();
          rsum -= *mih.begin();
          mah.insert(*mih.begin());
          mih.erase(mih.begin());
          mih.insert(vec[i+k-1]);
          rsum += vec[i+k-1];
        }
      }else{
        mih.erase(mih.find(vec[i-1]));
        rsum -= vec[i-1];
        if(vec[i+k-1]<=*mah.begin()) {
          rsum += *mah.begin();
          lsum -= *mah.begin();
          mih.insert(*mah.begin());
          mah.erase(mah.begin());
          mah.insert(vec[i+k-1]);
          lsum += vec[i+k-1];
        }
        else {
          mih.insert(vec[i+k-1]);
          rsum += vec[i+k-1];
        }
      }
      cout<< ((*mah.begin()*(k/2)- lsum) + (rsum - *mah.begin()*(k/2)))<<" ";
    }else{
      ll x = *mih.begin();
      if(vec[i-1] >= x){
        mih.erase(mih.find(vec[i-1]));
        rsum -= vec[i-1];
        if(vec[i+k-1]>=*mah.begin()){
          mih.insert(vec[i+k-1]);
          rsum += vec[i+k-1];
        }else{
          rsum += *mah.begin();
          lsum -= *mah.begin();
          mih.insert(*mah.begin());
          mah.erase(mah.begin());
          mah.insert(vec[i+k-1]);
          lsum += vec[i+k-1];
        }
      }else{
        mah.erase(mah.find(vec[i-1]));
        lsum -= vec[i-1];
        if(vec[i+k-1]>= *mih.begin()){
          lsum += *mih.begin();
          rsum -= *mih.begin();
          mah.insert(*mih.begin());
          mih.erase(mih.begin());
          mih.insert(vec[i+k-1]);
          rsum += vec[i+k-1];
        }else {
          lsum += vec[i+k-1];
          mah.insert(vec[i+k-1]);
        }
      }
      // cout<<"lsum: "<<lsum<<" rsum: "<<rsum<<" med: "<<*mih.begin()<<"\n";
      cout<< (((*mih.begin())*(k/2) - lsum)) + ((rsum - (*mih.begin())*(k/2 + 1)))<<" ";
    }
  }
}