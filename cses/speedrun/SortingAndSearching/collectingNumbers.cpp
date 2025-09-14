#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> vec(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        vec[i] = {x, i};
    }

    sort(vec.begin(), vec.end(), compare);

    int ans = 1;
    // int prev = 0;
    for(int i = 0; i < n - 1; i++) {
        if(vec[i][1] > vec[i+1][1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}