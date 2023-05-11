#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <string.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll  long long
#define lli  long long int
#define ld long double
using namespace std;



vector<vector<int>> ExtendedEUC(int n,int m){
    vector<vector<int>> V( 100 , vector<int> (7)); //2_d matrix to save the values of each iteration
    //each row carry values of each iteration ,r(j),r(j+1),q(j+1),r(j+2),s(j),t(j),last j columns from left to right respectively
    V[0][5]=0;    //initial value for t(0)=0
    V[0][4]=1;    //initial value for s(0)=1
    V[1][5]=1;    //initial value for t(1)=1
    V[1][4]=0;    //initial value for s(1)=0
    V[0][0]=max(n,m); //make sure the greatest element first
    V[0][1]=min(n,m); //make sure the smaller element second
    int i=0;       //counter of rows
    while(1){
        V[i][2]=((V[i][0])/(V[i][1]));  //q(j+1)=quotient floor of( r(j) / r(j+1) )
        V[i][3]=((V[i][0])%(V[i][1]));  //r(j+2)(j)=mod OF r(j) % r(j+1)
        if(V[i][3]==0){break;}          // break when r(j+2)=0
        i++;
        V[i][0]=V[i-1][1];              //r(j)new=r(j+2)previous
        V[i][1]=V[i-1][3];              //r(j+1)new=r(j+2)previous
    }
    int j=2;
    for(;j<=i+1;j++){
        V[j][4]=(V[j-2][4])-((V[j-2][2])*(V[j-1][4])); //s(j)=s(j-2)-s(j-2)*q(j-2)
        V[j][5]=(V[j-2][5])-((V[j-2][2])*(V[j-1][5])); //t(j)=t(j-2)-t(j-2)*q(j-2)
    }
    V[0][6]=(j-1);
    return V;
}



int main() {
    FIO;
        cout<<"Enters the two numbers\nto calculate gcd using Extended euclidean algorithm"<<endl;
    int x,y;cin>>x>>y;
    vector<vector<int>> V( 100 , vector<int> (7)) ;
    V= ExtendedEUC(x,y);
    int s=V[V[0][6]][4],t=V[V[0][6]][5] ;
    int a=max(x,y),b=min(x,y);
    int d=s*a+t*b;
    cout<<"The solution:"<<endl;
    cout<<"GCD("<<x<<", "<<y<<"): "<<d<<", s = "<<s<<", t = "<<t<<endl;
    cout<<d<<" = "<<a<<" x "<<s<<" + "<<b<<" x "<<t;

    return 0;
}
