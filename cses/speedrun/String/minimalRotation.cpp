#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

string solve(string &st) {
  int curr_start = 0;
  string new_st = st + st;
  int next_start = 0;
  int cmp_indx = 0;
  for(int i = 1; i < new_st.size(); i++) {
    if((int)new_st[i]<(int)new_st[curr_start]) {
      curr_start = i;
      cmp_indx = i + 1;
      next_start = curr_start;
    } else if((int)new_st[i] == (int)new_st[cmp_indx]) {
      if(curr_start == next_start && new_st[i] == new_st[curr_start]) {
        next_start = i;
        cmp_indx = curr_start + 1;
      } else
        cmp_indx++;
    } else if((int)new_st[i] > (int)new_st[cmp_indx]) {
      cmp_indx = curr_start + 1;
      next_start = curr_start;
    } else if((int)new_st[i]<(int)new_st[cmp_indx]) {
      if((int)new_st[i]==(int)new_st[curr_start] && curr_start == next_start) {
        next_start = i;
        cmp_indx = curr_start + 1;
      } else {
        curr_start = next_start;
        cmp_indx = curr_start + 1;
      }
    }
  }
  string ans = "";
  cout<<new_st<<endl;
  for(int i = curr_start;i<curr_start + st.size();i++) {
    cout<<i<<" "<<new_st[i]<<endl;
    ans += new_st[i];
  }
  return ans;
}

int main() {
  string st;
  cin>> st;
  cout<<solve(st);
  return 0;
}