// #include <bits/stdc++.h>

// using namespace std;

// int main(){

//   int t;
//   cin>>t;
//   int flag = 1;
//   while(t--){

//     char ch;
//     int len=0;
//     int stat = -1;
//     int changes = 0;
//     string str;
//     cin>>str;
//     for(auto ch:str){
      
//       if(ch=='0'){
//         changes = 0;
//         if(stat == -1){
//           stat = 0;
//           if(len<2) flag = 0;
//         }
//         else if(stat == 1){
//           if(len<2) flag = 0;
//           else stat = 0;
//         }
//         else if(stat == 0){
//           if(len<2) flag = 0;
//           continue;
//         }
//       }
//       else if(ch=='1'){
//         if(stat==-1)
//           stat = 1;
//         else if(stat == 0){
//           if(changes==0) flag  = 0;
//           stat = 1;
//         }
//       }
//       else if(ch =='+'){
//         len++;
//       }
//       else{
//         changes=1;
//         len--;
//       }
//       if(flag)
//         cout<<"YES"<<endl;
//       else 
//         cout<<"NO"<<endl;
//     }
//   }
// }


// #include <bits/stdc++.h>

// using namespace std;

// int isPrime(int num){
//     if(num<10)
//         return 0;
//     if(num%2==0)
//         return 0;
//     for(int i = 3;i<sqrt(num)+1;i += 2){
//         if(num%i==0) return 0;
//     }
//     return 1;
// }
// void solve(int num,int indx,int size,int &check){
    
//     if(indx>size) return;
//     // if(num==3571)
//         cout<<num<<endl;
//     if(isPrime(num))
//         check = num;
//     // cout<<num<<" ";
//     int second = num%(int)pow(10,size-indx);
//     // cout<<second<<" ";
//     int first = (num/(int)pow(10,size-indx+1)) * (int)pow(10,size-indx);
    
//     // cout<<first<<" "<<second<<endl;
//     solve(first+second,indx,size-1,check);
//     solve(num,indx+1,size,check);
// }
// int main(){
    
//     int t;
//     cin>>t;
//     while(t--){
        
//         int prime = 0;
//         int num;
//         cin>>num;
//         int check = -1;
//         solve(num,1,9,check);
//         cout<<check<<endl;
//     }
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main(){

//   int t;
//   cin>>t;
  
//   while(t--){
//     int flag = 1;
//     char ch;
//     int len=0;
//     int stat = -1;
//     int changes = 0;
//     string str;
//     cin>>str;
//     int hua = 0;
//     int addition = 0;
//     for(auto ch:str){
      
//       if(ch=='0'){
//         changes = 0;
        
//         if(stat == -1){
//           stat = 0;
//           if(len<2) flag = 0;
//         }
//         else if(stat == 1){
        
//           if(len<2) flag = 0;
//           if(addition==0) flag = 0;
//           stat = 0;
//         }
//         else if(stat == 0){
//           if(len<2) flag = 0;
//         }
//       }
//       else if(ch=='1'){
//           addition = 0;
//         // if(len<1) flag = 0;
//         if(stat==-1)
//           stat = 1;
//         else if(stat == 0){
//           if(hua==0&&len>1) flag  = 0;
//           stat = 1;
//         }
//       }
//       else if(ch =='+'){
//         if(stat==0) changes++;
//         if(stat==1) addition = 1;
//         len++;
//       }
//       else{
//         if(stat==0) changes--;
//         if(changes<0) hua = 1;
//         len--;
//       }
//     }
//     if(flag)
//         cout<<"YES"<<endl;
//       else 
//         cout<<"NO"<<endl;
//   }
// }

#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){

    char ch;
    int len = 0;
    int changes = 0;
    stack<pair<int,int>> st;
    int flag = 1;
    string str;
    cin>>str;
    int added = 0;
    int removed =-1;
    for(auto ch:str){

      if(ch=='0'){
        if(len<2) {
          flag = 0;
          break;
        }
        else{
          if(removed==1&&added==0) {flag =0;break;}
          else if(st.empty()||st.top().first == 0){
            if(!st.empty()&&len==st.top().second) st.pop();
            st.push(make_pair(0,len));
            }
          else if(st.top().first==1){
            if(len==st.top().second){ flag = 0;
            break;}
            st.push(make_pair(0,len));
          }
         
      }}
      else if(ch=='1'){
        added = 0;
        removed =-1;
        if(st.empty()||st.top().first == 1){
            if(!st.empty()) st.pop();
            st.push(make_pair(1,len));
            }
        else if(st.top().first==0){
            flag = 0;
            break;
          }
      }
      else if(ch=='+'){
        len++;
        added = 1;
      }
      else{
        len--;
        if(!st.empty()){
          if(len<st.top().second)
          {
            removed = st.top().first;
            st.pop();
            
          }
        }
      }
    }
  
    if(flag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}