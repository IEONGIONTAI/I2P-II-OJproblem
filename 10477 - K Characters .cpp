#include<iostream>
#include<string>
#include<map>
using namespace std;


map<char,int> M;
string last = "";

void histogram(string str,int k){
    for(char c = 'A' ; c <= 'K' ; c++){
        M[c] = 0;
    }
    for(auto s:str){
        if(M[s]<k){
            M[s]++;
        }
    }
}

void gen(char start,int k,string str,string ori){
    if(k>0){
        for(start;start<='K';start++){
            char c = start;
            if(M[c] >0){
                M[c] --;
                string rstr(1,c);
                gen(c,k-1,str+rstr,ori);
                M[c] ++; 
            }
              
        }
    }
    else{
        string tmp  = str.substr(ori.length());
        if(tmp!= last){  
            last = tmp;
            cout<<tmp<<"\n";
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); //沒這個會TLE
    string str;
    int lines;
    int k;
    cin>>lines;
    while(lines--){
        cin>>str;
        cin>>k; 
        histogram(str,k);
        gen('A',k,str,str);
        cout<<"\n"; //將endl 換成 \n 會節省超多時間
    }
    
    return 0;
}
