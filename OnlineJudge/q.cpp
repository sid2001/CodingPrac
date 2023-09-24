#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--){

		double hr ,mi;
		cin>>hr>>mi;
		double hra = hr*30 + mi*0.5;
		double mina = mi*6;

        int ans = abs(hra-mina);
        if(ans>180) ans = 360-ans;
		cout<<(int)ans<<endl;

	}
	return 0;
}