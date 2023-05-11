#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <string.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll  long long
#define lli  long long int
#define ld long double
using namespace std;


vector<int> intFactor(int n){
    vector<int>ans;       //vector carry the integer factors
    int i=1;
    for(;i*i<n;i++){
        if(n%i==0)
            ans.push_back(i),ans.push_back(n/i); //store i which is divisible by n and the result of n divide i.
    }
    if(i*i==n)            //check perfect square case
        ans.push_back(i);
    return ans;
}

int main() {
    FIO;
        cout<<"Enter the number to get the integer factorization"<<endl;
    int n;cin>>n;
    vector<int>V=intFactor(n);
    cout<<"Number of factors : "<<V.size()<<endl;
    cout<<"integer factors : ";
    sort(V.begin(),V.end());
    for(int x:V)cout<<x<<" ";

    return 0;
}
