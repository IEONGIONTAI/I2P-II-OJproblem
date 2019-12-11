#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution{
private:
    set<int> heart;
public:
    void insert(int x) {
        heart.insert(x);
    }
    void print() {
        if(!heart.empty()) {
            cout << *heart.begin();
            for(auto i:heart) {
                if(i != *heart.begin()) {
                    cout << " ";
                    cout << i;
                }
            }
            cout << endl;
        }
    }
    void min() {
        if(!heart.empty()) {
            auto temp = heart.begin();
            cout << *temp << endl;
        }
    }
    void range_erase(int l, int r) {
        heart.erase(heart.lower_bound(l), heart.upper_bound(r));
    }
};

int main() {
    Solution ans;
    int time;
    cin >> time;
    while(time--) {
        string cmd;
        cin >> cmd;
        if(cmd == "print") {
            ans.print();
        }
        else if(cmd == "range_erase") {
            int l, r;
            cin >> l >> r;
            ans.range_erase(l, r);
        }
        else if(cmd == "insert") {
            int x;
            cin >> x;
            ans.insert(x);
        }
        else if(cmd == "min") {
            ans.min();
        }
    }
    return 0;
}
