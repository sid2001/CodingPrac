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