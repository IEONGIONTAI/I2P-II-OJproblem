#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> a  ;
    int time;
    cin >> time;
    while(time--) {
        string cmd;
        cin >> cmd;
        if(cmd == "insert") {
            int b;
            cin >> b;
            a.insert(b);
        }
        else if(cmd == "print") {
            if(!a.empty()) {
                for(auto i:a){
                    if(i != *a.begin())
                        cout << " ";
                    cout << i;
                }
                cout<<endl;
            }
        }
        else if(cmd == "min") {
            if(!a.empty()) {
                auto i = a.begin();
                cout << *i << endl;
            }
        }
        else if(cmd == "range_erase") {
            int lower, upper;
            cin >> lower >> upper;
            a.erase(a.lower_bound(lower), a.upper_bound(upper));
        }
    }
    return 0;
}
