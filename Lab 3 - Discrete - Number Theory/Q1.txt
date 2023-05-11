#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>
#include <iomanip>
#include <map>
#include <stdlib.h>
#include <list>
#include <vector>

using namespace std;
typedef long long ll;

void sieve(int n){

    vector<bool>isPrime(n+1,true);     //isPrime vector carry a flag of each number,1 if prime,0 if composite
    for(int i=2;i*i<=n;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){ //iterate over the multiples of i if it's value is 1
                isPrime[j]=false;         //move value 0 to the multiples of i
            }
        }
    }
    cout << "Prime numbers less than or equal to " << n << " are: " << endl;
    int cnt=0;        //counter to put only 10 items in the row.
    for(int i=2;i<=n;i++){
        if(cnt==10) {cnt=0;cout<<endl;}
        if(isPrime[i]) cout<<i<<" ", cnt++;
    }
}

int main(){

    cout<<"Enter the number to find primes less that or equal to it: ";
    int n;cin>>n;
    if(n<2){cout<<"NONE"<<endl;}
    else{
        sieve(n);
    }

    return 0;
}
