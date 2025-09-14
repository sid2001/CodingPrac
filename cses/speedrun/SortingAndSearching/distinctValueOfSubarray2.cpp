#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    long long ans = 0;
    long long n, k;
    cin>>n>>k;
    vector<long long> vec(n);
    for(long long i = 0; i < n; i++) cin>>vec[i];

    map<long long,long long> mp;
    long long curr = 0;
    long long l = 0;
    long long prev = -1;
    long long tot = (n*(n + 1))/2;
    for(long long i = 0; i < n; i++) {
        mp[vec[i]];
        if(mp[vec[i]] == 0) {
            curr++;
            mp[vec[i]] = 1;
        }else mp[vec[i]]++;
        while(curr > k) {
            mp[vec[l]]--;
            if(mp[vec[l]] == 0) curr--;
            l++;
        }
        long long right = (n - i - 1);
        long long left = (l - 1 - prev - 1);
        ans += (long long)(left + 1)*(long long)(right + 1);
        prev = l - 1;
    }
    cout<<tot - ans<<endl;

    return 0;
}