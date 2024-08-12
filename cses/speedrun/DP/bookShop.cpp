#include <iostream>
#include <vector>
#include <algorithm>

void maxPages(std::vector<std::pair<int,int>> vec,  int rem, int x,int curr_p ,int &max_p,std::vector<int> &tab, int idx = 0) {
  //std::cout<<"x: "<<x<<" curr_p: "<<curr_p<<" tab[x]: "<<tab[x]<<" max_p: "<<max_p<<" rem: "<<rem<<" price[idx]: "<<price[idx]<<"\n";
  
  if(idx >= vec.size() && x >= 0) {
      max_p = std::max(max_p, curr_p);
      return;
    }
  else if(x < 0 ) return;
  else if(tab[x] > curr_p) return;
  else if(curr_p + rem < max_p) return;
  
  if(curr_p > max_p) {
    max_p = curr_p;
  }
  
  tab[x] = curr_p;

  //std::cout<<curr_p<<"\n";
  maxPages(vec, rem-vec[idx].second, x-vec[idx].first, curr_p+vec[idx].second, max_p,tab,idx+1);
  maxPages(vec, rem-vec[idx].second,x,curr_p,max_p,tab, idx+1);
  return;
}



int solve(std::vector<std::pair<int,int>> vec, int x,int total_pages) {
  int rem = total_pages;
  int max_p = 0;
  std::vector<int> tab(x+1,0);
  maxPages(vec, rem, x,0,max_p,tab);

  return max_p;
}

int comparefn(std::pair<int,int> l1, std::pair<int,int> l2) {
  if((float)l1.second/(float)l1.first > (float)l2.first/(float)l2.second) return 0;
  else return 1;
}
int main() {
  int n, x;
  std::cin>>n>>x;
  std::vector<std::pair<int,int>> vec(n);
  int total_pages = 0;
  int y;
  for(int i=0; i<n; i++) {
    std::cin>>y;
    vec[i] = {y,0};
  }
  for(int i = 0; i<n; i++) {
    std::cin>>y;
    total_pages += y;
    vec[i].second = y; 
  }
  std::sort(vec.begin(),vec.end(),comparefn);
  //display(vec);
  std::cout<<solve(vec,x,total_pages)<<"\n";

  return 0;
}