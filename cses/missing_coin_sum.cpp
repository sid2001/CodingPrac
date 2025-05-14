#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  long x;
  vector<int> vec(n);
  for (int i = 0; i < n; i++)
  { 
    cin>>x;
    vec[i] = x;
  }
  int min_index=0,current_index=0;
  sort(vec.begin(),vec.end());
  for(int i=1;i<vec[n-1];i++){
    long sum =0;
    sum = vec[0];
    while(true){
      if(i==sum){
        continue;
      }
      if(i-sum>0){
        sum += 
      }
    }
  }

}