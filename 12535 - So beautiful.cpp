#include<map>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {
    int N;
    int count;
    char ch;
    map<int, map<char, vector<string>>> bucket;
    cin >> N;
    while(N--) {
        count = 0;
        string str;
        cin >> str;
        for(int i=0; i<str.length(); i++) {
           if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                count++;
                ch = str[i];
           }
        }
        bucket[count][ch].push_back(str);
    }
    vector<pair<string, string>> comp;
    vector<pair<string, string>> uncomp;
    for(auto &smap : bucket) {
        for(auto &v : smap.second) {
            while(v.second.size() >= 2) {
                pair<string , string> a(*(v.second.end()-1), *(v.second.end()-2));
                comp.push_back(a);
                v.second.erase(v.second.end()-1);
                v.second.erase(v.second.end()-1);
            }
        }
        vector<string> temp;
        for(auto &s : smap.second) {
            if(!s.second.empty()) {
                temp.push_back(s.second[0]);
            }
            if(temp.size() >= 2) {
                pair<string, string> b(temp[0], temp[1]);
                temp.clear();
                uncomp.push_back(b);
            }

        }
    }
    int NumComp = comp.size();
    int NumUncomp = uncomp.size();
    if(NumUncomp > NumComp) cout << NumComp << endl;
    else {
        int remain = (NumComp - NumUncomp)/2;
        cout << remain + NumUncomp << endl;
    }
    return 0;
}
