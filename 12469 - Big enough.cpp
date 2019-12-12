#include<iostream>
#include<algorithm>
#include<string> 
#include<cstring>
#include"12469.h"
using namespace std; 
#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000

BigInt BigInt::operator+(const BigInt &y ){
    BigInt x(*this);
    int i;
    int count = 0;
    long long h = 0;
    for(i = 0;i<x.l || i<y.l || h;i++){
        h += (x.m[i]*x.sign+y.m[i]*y.sign);
        x[i] = h%MAX;
        h/=MAX;
    }
    x.l = i;
    //cout<<"x.m[i-1] = "<<x.m[i-1]<<endl;
    h = 0;
    if(x.m[i-1]>0){
        for(int j =0;j<x.l;j++){
            x.m[j]+=h;
            if(x.m[j]<0){
               x.m[j] = MAX + x.m[j];
               h = -1; 
            }
            else if(x.m[j]>=0){
                h = 0;
                if(x.m[j] == 0) count++;
            }
        }
        x.sign = 1;
    }
    else if(x.m[i-1]<0){
        for(int j =0;j<x.l;j++){
            x.m[j]-=h;
            if(x.m[j]>0){
               x.m[j] = MAX + (-x.m[j]);
               h = -1; 
            }
            else if(x.m[j]<=0){
                h = 0;
                x.m[j] = -(x.m[j]);
                if(x.m[j] == 0) count++;
            }
        }
        x.sign = -1;
    }
    if(count == x.l){
        x.sign = 1;
    }
    return x;
}

BigInt BigInt::operator-(const BigInt &y ){
    BigInt x(*this);
    
    int i;
    int count = 0;
    long long h = 0;
    for(i = 0;i<x.l || i<y.l || h;i++){
        h += (x.m[i]*x.sign-y.m[i]*y.sign);
        x[i] = h%MAX;
        h/=MAX;
    }
    x.l = i;
    if(x.m[i-1]>0){
        for(int j =0;j<x.l;j++){
            x.m[j]+=h;
            if(x.m[j]<0){
               x.m[j] = MAX + x.m[j];
               h = -1; 
            }
            else if(x.m[j]>=0){
                h = 0;
                if(x.m[j] == 0) count++;
            }
        }
        x.sign = 1;
    }
    else if(x.m[i-1]<0){
        for(int j =0;j<x.l;j++){
            x.m[j]-=h;
            if(x.m[j]>0){
               x.m[j] = MAX - x.m[j];
               h = -1; 
            }
            else if(x.m[j]<=0){
                x.m[j] = -(x.m[j]);
                h = 0;
                if(x.m[j] == 0) count++;
            }
        }
        x.sign = -1;
    }
    if(count == x.l){
        x.sign = 1;
    }
    return x;
}

istream& operator>>(istream& In, BigInt& x){
    string str;
    In>>str;
    
    for(int i = 0;i<MAX_N;i++){
        x.m[i] = 0;
    }
    if(str[0] == '-'){
        x.sign = -1;
        str.erase(str.begin());
    }
    else x.sign = 1;

    reverse(str.begin(),str.end());
    int id = 0;
    for(int i = 0; i< str.length() ; i+= MAX_Bit){
        string sub = str.substr(i,MAX_Bit);
        reverse(sub.begin(),sub.end());
        x.m[id++] = stoi(sub);
    }
    x.l = id;
    return In;
}

ostream& operator<<(ostream& Out, BigInt x){
    if(x.sign == -1){
        Out<<'-';
        x.sign = -1;
    }
    int k = x.l-1;
    while(x.m[k] == 0 && k>0){
        k--;
    }
    Out<<x.m[k];
    for(int i = k-1 ;i>=0; i--){
        for(int j = MAX/10; j>1 && x.m[i]/j == 0 ;j/=10){
            Out<<'0';
        }
        Out<<x.m[i];
    }
    return Out;
}
