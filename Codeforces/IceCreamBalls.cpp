#include <bits/stdc++.h>
#define ul long double
#define ll long long int
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    ul x;
    cin>>x;
    // ul ans = 1;
    // for(ul i = 1;i<=100000000000000001;i++){
    //   if(i*(i -1) ==2*x)
    //   {
    //     cout<<i<<endl;
    //     break; 
    //   }
    //   else if(i*(i-1)>2*x){
    //     ul k = ((i-1)*(i-2))/2;
    //     k = x-k;
    //     cout<<i-1+k<<endl;
    //     break;
    //   }

    // }
    ul ans = (1+pow((1+4*x),1/2))/2.0;
    cout<<ans<<endl;
    ll an = (ll)ans;
    if(an<ans)
      an += (x-(an*(an-1))/2);
    cout<<an<<endl;
  }
}