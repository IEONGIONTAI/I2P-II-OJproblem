#include<iostream>
using namespace std;

int main(){
    unsigned long long int limit;
    while(cin>>limit){
        bool empty = true;
        unsigned long long int c;
        unsigned long long int sum = 0;
        unsigned long long int packet = 0;
        while(cin>>c){
            
            if(c == 0){
                break;
            }
            else{
                sum += c;
                if(empty){
                    packet++;
                    empty = false;
                }
                if(sum>limit){
                    packet++;
                    sum = c;
                }
            }
        }
        cout<<packet<<"\n";
        
    }
    return 0;
}
