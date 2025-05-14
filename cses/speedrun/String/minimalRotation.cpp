#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <limits.h>

using namespace std;

void radixsort(vector<pair<int,int>> &vec, vector<int> &p) {
  vector<int> cnt(vec.size(),0);
  for(int i = 0; i < vec.size(); i++) {
    cnt[vec[i].second]++;
  }
  for(int i = 1; i < cnt.size(); i++){
    cnt[i] += cnt[i-1];
  }

  vector<int> temp_p(p.size(), 0);
  for(int i = vec.size() - 1; i >= 0; i--) {
    temp_p[--cnt[vec[i].second]] = i;
  }

  for(int i = 0; i < cnt.size(); i++) {
    cnt[i] = 0;
  }

  for(int i = 0; i < vec.size(); i++) {
    cnt[vec[i].first]++;
  }
  for(int i = 1; i < cnt.size(); i++){
    cnt[i] += cnt[i-1];
  }

  for(int i = temp_p.size()-1; i >= 0 ; i--) {
    p[--cnt[vec[temp_p[i]].first]] = temp_p[i];
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // ifstream MyReadFile("./test_input.txt");
  string st;
  cin>>st;
  int ll = st.size();
  
  // MyReadFile >> st;
  // cout<<INT_MAX<<endl;

  vector<int> p(st.size(),0), c(st.size(),0), cnt(256,0);
  vector<pair<int,int>> vec(st.size());
  for(int i = 0; i < st.size(); i++) {
    cnt[st[i] - '$']++;
  }
  for(int i = 1; i < cnt.size(); i++) {
    cnt[i] += cnt[i-1];
    // cout<<"flag2"<<endl;
  }
  for(int i = st.size()-1; i >= 0; i--) {
    p[--cnt[st[i] - '$']] = i;
    // cout<<"flag3"<<endl;
  }

  int rank = 0;
  c[p[0]] = rank;
  for(int i = 1; i < p.size(); i++) {
    if(st[p[i-1]] == st[p[i]]) c[p[i]] = rank;
    else {
      c[p[i]] = ++rank;
      }
  }
  int len = 1;
  for(int i = 1; i <= st.size(); i *= 2){
    for(int j = 0; j < vec.size(); j++){
      vec[j] = {c[j], c[(j+i) % st.size()]};
    }
    radixsort(vec, p);
    rank = 0;
    c[p[0]] = 0;
    for(int j = 1; j < c.size(); j++){
      if(vec[p[j]].first == vec[p[j-1]].first && vec[p[j]].second == vec[p[j-1]].second) c[p[j]] = rank;
      else c[p[j]] = ++rank;
    }

    if(rank - 1 == vec.size()) break;
  }
  int k = 0;
  int ii = p[0];
  while(k < ll){
    cout<<st[(ii + k++)%vec.size()];
  }
  cout<<endl;
  return 0;
}

