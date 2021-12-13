

// Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n] using O(nloglogn) operations.


#include<bits/stdc++.h>
using namespace std;

vector<int> primes;

void pre(int n){
    vector<int> v(n+1);
    for(int i=2;i<=n;i++){
        if(!v[i]){
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                v[j]=1;
            }
        }
    }
}

int main(){

    int n=100;
    pre(n);
    for(auto it:primes)
        cout<<it<<" ";

    return 0;
}



