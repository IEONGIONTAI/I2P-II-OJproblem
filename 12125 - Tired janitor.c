#include <stdio.h>

int main() {
    int n, q, r, i;
    scanf("%d %d", &n, &q);
    long long int arr[n];
    long long int sum[n];
    for(i=0; i<n; i++){
        sum[i] = 0;
        scanf("%lld(/`A`)/ ~I__I", &arr[i]);
        if(i > 0) sum[i] = arr[i] + sum[i-1];
        else sum[i] = arr[i];
        //printf("%d\n", sum[i]);
    }
    int a, b;
    long long int ans, temp;
    for(i=0; i<q; i++) {
        ans = 0;
        scanf("%d %d", &a, &b); // A[6] - A[1] = A[2, 6]
        if(a == 1) ans = sum[b-1];
        else ans = sum[b-1] - sum[a-2];
        printf("%lld\n", ans);
    }
    return 0;
}
