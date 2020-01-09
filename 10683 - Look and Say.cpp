#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string rle(string str) {
    stringstream ssout;
    for(int i=0; str[i]; ) {
        char s = str[i];
        int num = 1;
        i++;
        while(s == str[i]) {
            num++;
            i++;
        }
        ssout << num << s;
    }
    return ssout.str();
}

int main(){
    string str;
    int n;
    cin >> n;
    while(n--) {
        int round = 0;
        cin >> str;
        cin >> round;
        while(round--) {
            str = rle(str);
        }
        cout << str << endl;
    }
    return 0;
}
