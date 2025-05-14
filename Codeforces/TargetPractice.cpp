#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){
    int score = 0;
    for(int i =1;i<11;i++){
      for(int j = 1;j<11;j++){

        char c;
        cin>>c;
        if(c=='X')
        {
          if(i<=5){
            if(j<=5){
              if(j<=i)
                score += j;
              else
                score += i;
            }
            else{
              if(j<=10-i+1)
                score += i;
              else
                score += 10-j+1;
            }
          }
          else{
            if(j<=5){
              if(j>10-i)
                if(i!=10)
                score += 6 - i%5;
                else 
                  score += 5;
              else
                score += j;
            }
            else{
              if(j<=i)
                if(i!=10)
                score += 6-i%5;
              else score += 5;
              else
                score += 10-j+1;
            }
          }
        }
      }
    }
    cout<<score<<endl;
  }
}