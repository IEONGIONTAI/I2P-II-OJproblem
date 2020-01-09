#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;

map<char,char> parthn{{'{','}'},{'(',')'},{'<','>'},{'[',']'}};


int main(){ 
    string str;
    int lines;
    cin>>lines;
    getline(cin,str);
    for(int i =1;i<=lines;i++){
        bool valid = true;
        //cin>>str;
        stack<char> s;
        getline(cin,str);
        for(char c:str){
            if(c == '(' || c == '{' || c== '[' || c == '<'){
                s.push(c);
            }
            else if(c == ')' || c == '}' || c == ']' || c == '>'){
                if(s.empty()){  //不可與下一個判斷式顛倒順序
                    valid = false;
                    break;
                }
                
                else if(parthn[s.top()] != c ){
                    valid = false;
                    break;
                }
                
                else {
                    s.pop();
                }
            }
        }
        if(!s.empty()) valid = false;
        cout<<"Case "<<i<<": ";
        if(valid) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";   

    }
    

    

}
