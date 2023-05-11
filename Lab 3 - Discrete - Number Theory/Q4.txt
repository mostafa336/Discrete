#include <iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <string.h>
#define ll  long long
#define lli  long long int
#define ld long double
using namespace std;


int ExtendedEUC(int n,int m){   //used to get inverse
    vector<vector<int>> V( 100 , vector<int> (7)); //2_d matrix to save values iteration
    //each row carry value sof iteration ,r(j),r(j+1),q(j+1),r(j+2),s(j),t(j),last j columns from left to right respectively
    V[0][5]=0;    //intial value for t(0)=0
    V[0][4]=1;    //intial value for s(0)=1
    V[1][5]=1;    //intial value for t(1)=1
    V[1][4]=0;    //intial value for s(1)=0
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
    return V[j-1][4];   //return value of an inverse
}


int chinese(int n){
    vector<vector<int>> V( n , vector<int> (3));
    //each row represent an equation,each col a(i),M(i),M(i)(bar)
    int m=1;
    for(int i=0;i<n;i++){
        cout<<"Enter the value of the equivalence(a"<<i<<"): ";
        cin>>V[i][0];
        cout<<"Enter the modulo of the equivalence(m"<<i<<"): ";
        cin>>V[i][1];
        m*=V[i][1];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=V[i][1];
        V[i][1]=m/(V[i][1]);
        V[i][2]=ExtendedEUC((V[i][1]),tmp);
        while(V[i][2]<0){V[i][2]+=tmp;}
        ans+=((((V[i][0]))*((V[i][1]))*((V[i][2])))%m);
    }
    ans%=m;
    return ans;
}

int main() {
    cout<<"Enter number of equations: ";
    int n;cin>>n;
    int ans=chinese(n);
    cout<<"The solution is : "<<ans<<endl;

    return 0;
}
