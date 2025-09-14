#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n, a, b;
    int ans = 1;
    int curr = 1;
    cin>>n;
    vector<pair<int,int>> start(n);
    vector<pair<int,int>> end(n);
    vector<int> room(n);
    for(int i = 0; i < n; i++) {
        cin>>a>>b;
        start[i] = {a, i};
        end[i] = {b, i};
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    stack<int> available;

    int l = 0, r = 0;
    while(l < n) {
        if(start[l].first <= end[r].first) {
            if(available.empty())
                room[start[l].second] = curr;
            else {
                room[start[l].second] = available.top();
                available.pop();
            }
            ans = max(ans, curr);
            curr++;
            l++;
        }else{
            available.push(room[end[r].second]);
            curr--;
            r++;
        }
    }
    cout<<ans<<"\n";
    for(int& a : room) cout<<a<<" ";
    return 0;
}