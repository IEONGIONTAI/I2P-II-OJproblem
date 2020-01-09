#include<iostream>
#include<set>
#include<string>

using namespace std;

class Node{
    public:
        int prev;
        int next;
};

Node s[1000003];

int main(){
    std::ios_base::sync_with_stdio(false);
    int N;

    cin>>N;
    for(int i = 0; i<=N ; i++){
        s[i].next = i+1;
        s[i].prev = i-1;
    }

    while(1){
        string str;
        cin>>str;
        if(str == "Exit" ) break;

        int a,b;
        cin>>a>>b;

        int p,q,r;
        p = s[a].next;
        q = s[b].prev;
        if(a == q) continue;
        r = s[0].next;

        s[a].next = b;
        s[b].prev = a;
        s[r].prev = q;
        s[q].next = r;
        s[0].next = p;
        s[p].prev = 0;
    }

    if(N>0){
        int t = s[0].next;
        cout<<t;
        --N;
        while(N){
            t = s[t].next;
            cout<<" "<<t;
            --N;
        }

        cout<<"\n";
    }

}
