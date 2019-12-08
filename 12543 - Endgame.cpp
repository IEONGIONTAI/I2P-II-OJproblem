#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct People{
    int age;
    string name;
	friend bool operator == (const People& lhs, const People& rhs)
	{
		return lhs.age == rhs.age && lhs.name == rhs.name;
	}
};

bool compare(const People &a, const People &b)
{
    return a.age < b.age;
}

int main() {
    vector <People> member;
    People master;
    string name;
    string cmd;
    int n, age;
    cin >> n;
    while(n--) {
        cin >> cmd;
        if(cmd == "born") {
            cin >> name >> age;
            master.age = age;
            master.name = name;
            member.push_back(master);
        }
        else if(cmd == "find") {
            People temp;
            bool flag = false;
            cin >> name >> age;
            for(int i=0; i<member.size(); i++) {
                temp = member[i];
                if(temp.name == name && temp.age == age){
                    flag = true;
                    cout << "YES" << endl;
                    break;
                }
            }
            if(flag == false) cout << "NO" << endl;
        }
        else if(cmd == "kill") {
            People temp;
            cin >> name >> age;
            temp.age = age;
            temp.name = name;
            member.erase(remove(member.begin(), member.end(), temp), member.end());
        }
        else if(cmd == "young") {
            sort(member.begin(), member.end(), compare);
            cout << member[0].name << " " << member[0].age << endl;
        }
    }
    return 0;
}
