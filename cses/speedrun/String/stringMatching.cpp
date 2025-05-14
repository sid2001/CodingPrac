#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &v){
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
}

int kmp(string &st, vector<int> &pi, string &key) {
    int p = 0, ans = 0;
    for(int i = 0; i < st.size(); i++) {
        if(key[p] == st[i]){
            p++;
        }else{
            p = pi[p-1];
            while(p > 0 && key[p] != st[i]) {
                p = pi[p-1];
            }
            if(key[p] == st[i]){
                p++;
            }
        }

        if(p == key.size()-1) {
            // ans.push_back(i - p + 1);
            ans++;
            // p = pi[p-1];
        }
    }
    return ans;
}

void calc_pi(vector<int> &pi, string &key) {
    int p = 0, s = 1;
    pi[0] = 0;
    while(s < key.size()) {
        if(key[p] == key[s]) {
            pi[s] = p + 1;
            p++;
        }else{
            p = pi[p-1];
            while(p > 0 && key[p] != key[s]){
                p = pi[p-1];
            }
            if(key[p] == key[s]) {
                pi[s] = p + 1;
                p++;
            }
        }
        s++;
    }
} 

int main() {
    string st, key;
    cin>>st>>key;
    key = key + "#";
    vector<int> pi(key.size(),0);
    calc_pi(pi,key);
    // display(pi);
    cout<<kmp(st, pi, key);
}