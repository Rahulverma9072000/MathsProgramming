#include<iostream>
using namespace std;
// Prime Numbers : Numbers that can  only divisble by 1 and itself . 
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    //Start by dividing by 2
    int c = 2;
    while(c*c <= n){
        if(n%c==0){
            return false;
        }
        c +=1;
    }
    return true;
}
//Question : Given n , Find the number that are prime till n 
//Sieve of Eratothenes 
void isPrimeSieve(int n){
    bool* primes = new bool[n+1];
    for(int i=2;i*i<=n;i++){
        if(!primes[i]){
            for(int j=i*2;j<=n;j+=i){
                primes[j] = true;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!primes[i]){
            cout<<"Prime Number "<<i<<endl;
        }
    }
}
//Time Complexity of Sieve of Eratothenese : O(nlog(logn))
//Space Complexity of Sieve of Eratothenese : O(n)
int main(){
    int n;cin>>n;
    // for(int i=1;i<=n;i++){
    //     if(isPrime(i)){
    //         cout<<i<<" is Prime"<<endl;
    //     }
    // }
    isPrimeSieve(30);
    return 0;
}