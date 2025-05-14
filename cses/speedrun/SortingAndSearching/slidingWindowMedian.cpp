#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    vector<ll> vec(n);
    for(int i = 0; i < n; i++) cin>>vec[i];

    multiset<ll> mih;
    multiset<ll, greater<int>> mah;

    vector<ll> temp(k);
    for(int i = 0; i < k; i++) temp[i] = vec[i];

    sort(temp.begin(), temp.end());

    for(int i = 0; i < k; i++) {
        if(i < k/2){
            mah.insert(temp[i]);
        }else{
            mih.insert(temp[i]);
        }
    }
    if(mah.size()>=mih.size()) cout<< *mah.begin()<< " ";
    else cout<< *mih.begin()<< " ";
    for(int i = 1; i < n-k+1;i++) {
        if(k%2==0){
            ll x = *mah.begin();
            if(vec[i-1] <= x){
                mah.erase(mah.find(vec[i-1]));
                if(vec[i+k-1] < *mih.begin()) mah.insert(vec[i+k-1]);
                else {
                    mah.insert(*mih.begin());
                    mih.erase(mih.begin());
                    mih.insert(vec[i+k-1]);
                }
            }else{
                mih.erase(mih.find(vec[i-1]));
                if(vec[i+k-1]<=*mah.begin()) {
                    mih.insert(*mah.begin());
                    mah.erase(mah.begin());
                    mah.insert(vec[i+k-1]);
                }
                else mih.insert(vec[i+k-1]);
            }
            cout<< *mah.begin()<< " ";
        }else{
            ll x = *mih.begin();
            if(vec[i-1] >= x){
                mih.erase(mih.find(vec[i-1]));
                if(vec[i+k-1]>=*mah.begin()){
                    mih.insert(vec[i+k-1]);
                }else{
                    mih.insert(*mah.begin());
                    mah.erase(mah.begin());
                    mah.insert(vec[i+k-1]);
                }
            }else{
                mah.erase(mah.find(vec[i-1]));
                if(vec[i+k-1]>= *mih.begin()){
                    mah.insert(*mih.begin());
                    mih.erase(mih.begin());
                    mih.insert(vec[i+k-1]);
                }else mah.insert(vec[i+k-1]);
            }
            cout<< *mih.begin()<<" ";
        }
    }
    return 0;
}
