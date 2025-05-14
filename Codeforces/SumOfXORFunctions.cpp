// https://codeforces.com/contest/1879/problem/D

#include <bits/stdc++.h>

using namespace std;

int main(){

  int len;
  cin>>len;
  vector<unsigned long long> vec(len);
  for(int i = 0;i<len;i++){
    cin>>vec[i];
  }
  for(int i = 1;i<len;i++){

    vec[i] = vec[i] ^ vec[i-1];
  }
  vector<unsigned long long> pro(len);
  pro[0] = vec[0];
  for(int i = 1;i<len;i++){

    pro[i] = pro[i-1] * vec[i];
  }
  unsigned long long sum = 0;
  unsigned long long m1 = 0;
  sum += pro[len-1]*((len)*(1+len)/2) + pro[len-1]*((2)*(len));
  for(int i = 1;i<len;i++){
    unsigned long long m1 = (pro[len-1-i]*((len-i)*(i+1+len)/2) + pro[len-1-i]*((i+2)*(len-i)))/pow(pro[i-1],len);
    sum += m1;
  }
  cout<<sum<<endl;
}