#include <iostream>
using namespace std;
//2 integers m and n 
//calculate sum of all prime numbers which exists in the range [m,n]
int main() {
    int t;cin>>t;
    //Sieve array should be precomputation here 
    int n = 1e6 + 3;
    long long int* sieve = new long long int[n];
    sieve[1] = sieve[0] = 0;
    //Mark all the number as prime from 2 
    for(int i=2;i<=n;i++) sieve[i]=1;
    //Fill the sieve 
    for(int i=2;i*i<=n;i++){
        if(sieve[i]){
            //mark all the non prime as true 
            for(int j=i*2;j<=n;j+=i){
                sieve[j] = 0;
            }
        }
    }
    //Now precompute the sum 
    for(int i=2;i<=n;i++){
        long long int currSum = sieve[i-1];
        if(sieve[i]){
            //include the current value 
            currSum += i;
        }
        sieve[i] = currSum;
    }
    while(t--){
        int m,n;cin>>m>>n;
        //Find the sum of all primeNumbers which exist in the range m to n 
        // have to make sieve for this 
        //the array is already precomputed 
        //find the sum 
        cout<<(sieve[n]-sieve[m-1])<<endl;
    }
	return 0;
}