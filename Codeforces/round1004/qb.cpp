#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve() {
    int n;
    cin>>n;
    vector<int> vec(n),m(10001,0),mm(10001,0);

    int r = 0;
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
        m[vec[i]]++;
        mm[vec[i]]++;
        if(m[vec[i]]%2==0) r--;
        else r++;
        // cout<<"s"<<endl;
    }
    if(r == 0) return "yes";
    sort(vec.begin(),vec.end());

    int k = vec.size()-1;
    int l = k - mm[vec[k]];
    while(k>=0 && l>=0) {
        while(k>=0 && m[vec[k]] % 2 == 0) {
            k-=mm[vec[k]];
            l -= mm[vec[l]];
            // cout<<"ssdsd"<<endl;
        }
        if (k < 0) return "yes";

        while(l>= 0 && m[vec[l]] % 2 == 0){
            // cout<<"fs"<<endl;
            l-=mm[vec[l]];
        }
        while(l>= 0 && (m[vec[l]] % 2 == 0 ||m[vec[l]] < 2)){
            l -= mm[vec[l]];
            // cout<<l<<endl;
        }
        if (l<0) return "no";
        
        m[vec[l]] -= 2;
        k -= mm[vec[k]];
        if(k>=l) {
            l = k;
            l -= mm[vec[l]];
        }
        // cout<<"k"<<endl;
    }
    if(k >= 0) return "no";
    return "yes";
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        cout<<solve()<<"\n";
    }
}