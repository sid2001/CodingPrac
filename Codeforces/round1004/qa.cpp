#include <iostream>
#include <vector>

using namespace std;

string solve() {
    int x,y;
    cin>>x>>y;

    if(y-x == 1) {
        return "yes";
    }

      if((x - y) == 8) {
        return "yes";
    }else if ((x-y - 8) % 9 == 0 && x >= y){
        return "yes";
    } 
    return "no";
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        cout<<solve()<<"\n";
    }
}