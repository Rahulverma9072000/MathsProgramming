#include <iostream>
using namespace std;
//Binary Search Square Root 
double find_sqrt(int n,int p){
    int s = 0;
    int e = n;
    double root = 0.0;
    while (s <= e)
    {
        int m = s + (e-s)/2;
        if(m*m ==n){
            return m;
        }else if(m*m > n){
            e = m-1;
        }else{
            s = m+1;
        }
    }
    //Find Decimal for Precision 
    double incr = 0.1;
    for(int i=0;i<p;i++){

    }
}
int main()
{
    int n;cin>>n;
    //Precision value till how much number you want 
    int p = 3;
    cout<<find_sqrt(int n,int p)<<endl;
    return 0;
}