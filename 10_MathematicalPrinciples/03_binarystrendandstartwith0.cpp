#include<iostream>
#include<math.h>
using namespace std;
int main(){
    //Count the number of binary string that start or end with 0 
    int n;cin>>n;
    int res = 0;
    //First count the number of string that start with 0 
    res += (pow(2,n-1));
    //Count the number of string that end with 0 
    res += (pow(2,n-1));
    //Subtract the number of string that start and end with 0 
    res -= (pow(2,n-2));
    cout<<res<<endl;
    return 0;
}