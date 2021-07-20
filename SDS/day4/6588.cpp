#include <iostream>

int prime[1000001];

void getPrime() {
    for(int i = 1; i <= 1000000; ++i) {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2; i <= 1000; ++i) {
        for(int j = i; i*j <= 1000000; j+=1) {
            prime[i*j] = 0;
        }
    }
}

int main() {
    int k = -1;
    getPrime();
    while(true) {
        scanf("%d", &k);
        if(k == 0) return 0;
        if(k % 2 == 1) {
            printf("Goldbach's conjecture is wrong.\n");
        } else {
            bool found = false;
            for(int j = 3; j <= k/2; ++j) {
                if(prime[j] && prime[k-j]) {
                    printf("%d = %d + %d\n", k, j, k-j);
                    found = true; 
                    break;
                }
            }
            if(found) continue;
        }
    }
}