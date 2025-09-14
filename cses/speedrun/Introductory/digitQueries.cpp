#include <iostream>
#include <cmath>
#define ull unsigned long long 

using namespace std;

int solve(ull base,ull counted ,ull x) {
    for(ull i = 1; ;i++) {
        if(counted + 9 * (ull)pow(10,i-1) * i < x) {
            base += 9 * (ull)pow(10,i-1);
            counted += 9 * (ull)pow(10,i-1) * i;
        }else if(counted + 9 * (ull)pow(10,i-1) * i == x) return 9;
        else if(counted + 9 * (ull)pow(10,i-1) * i > x){
            // cout<<"s"<<endl;
            ull inc = (x - counted) / i;
            ull xx = (ull)pow(10,i-1);
            base = xx + inc - 1;
            ull y = (x - counted) % i;
            if(y == 0) return base % 10;
            else return (++base / (ull)pow(10,i - y)) % 10;
        }
    }
    return 0;
}

int main() {
    int q;
    cin>>q;
    ull x;
    while(q--) {
        cin>>x;
        if(x<10) cout<<x<<"\n";
        else {
            cout << solve(0,0,x) <<"\n";
        }
    }
}