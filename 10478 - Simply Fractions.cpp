#include <iostream>
#include <vector>

using namespace std;

long long int gcd(long long int a, long long int b) {
    while(b != 0) {
        long long int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long int lcm(long long int a, long long int b) {
    long long val = gcd(a, b);
    return a*b/val;
}

int main() {
    int n;
    int p, q;
    while(cin >> n) {
        long long int LCM = 1;
        long long int sum = 0;
        vector<long long int> a, b;
        for(int i=0; i<n; i++) {
            cin >> q >> p;
            a.push_back(q); // 分子
            b.push_back(p); // 分母
            LCM = lcm(LCM, p);
        }
        for(int i=0; i<n; i++) {
            a[i] = a[i] * (LCM/b[i]);
            sum += a[i];
        }
        long long int temp = gcd(LCM, sum);
        if(temp == 1) cout << sum << "/"<< LCM << endl;
        else {
            cout << sum/temp << "/" << LCM/temp << endl;
        }
    }
    return 0;
}
