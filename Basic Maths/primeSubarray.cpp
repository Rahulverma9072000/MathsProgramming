#include <iostream>
using namespace std;
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
int main() {
	//code
	int t;cin>>t;
// 	PreComputation would be Sieve Array 
    int n = 1e4 + 3;
    bool* sieve = new bool[n];
    sieve[0] = sieve[1] = true;
    for(int i=2;i*i<=n;i++){
        if(!sieve[i]){
            for(int j=i*2;j<=n;j+=i){
                sieve[j] = true;
            }
        }
    }
    //Now the false index numbers are prime 
	while(t--){
	    int n;cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        //Now you have to check the Sum of the Subarray's 
        int res = 0;
        for(int i=0;i<n;i++){
            //so i will be the starting index of the Subarray 
            //and in the next loop we will be checking all the Subarray starting from index i
            int currSum = 0;
            for(int j=i;j<n;j++){
                currSum += arr[j];
                if(!sieve[currSum]){
                    cout<<"Hi I am adding "<<currSum<<" "<<isPrime(currSum)<<endl;
                    res += 1;
                }
            }
        }
        cout<<res<<endl;
	}
	return 0;
}