#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    int total;
    while(cin>>total && total!=0){
        bool isempty = true;
        unordered_map<int,int> m;

        for(int i = 0;i<total;i++){
            int num;
            cin>>num;
            if(m.count(num)) m[num]++;
            else m.insert({num,1});
        }
        int total2;
        cin>>total2;
        vector<int> s;
        for(int j = 0;j<total2;j++){
            int num;
            cin>>num;
            if(m.count(num)){
                s.push_back(num);
                if(m[num] == 1){
                    m.erase(num);
                }
                else m[num]--;
            }
        }
        
        if(s.empty()) cout<<"empty";
        else{
            sort(s.begin(),s.end());
            for(int i =0;i<s.size();i++){
                if(i == 0) cout<<s[i];
                else cout<<" "<<s[i];
            }
        }
        cout<<"\n";
    }
    
}
