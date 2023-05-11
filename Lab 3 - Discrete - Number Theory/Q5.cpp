#include <iostream>
#include <cstdlib>
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

int calcPowerMod(ll x, ll y, ll p) {    //using Fermat's theorem to find large exponentiations

    ll powMod = 1;
    x = x % p;
    while(y > 0){
        if(y & 1) powMod = (powMod*x) % p;
        y /= 2;
        x = (x * x) % p;
    }
    return powMod;
}

bool miller_test(ll n, ll iterations){

    if(n < 2) return false;     //test whether the number is 0 or 1 -> not prime
    if(n < 4) return true;     //test whether the number is 2 or 3 -> prime
    if(n % 2 == 0) return false;     //test whether the number even -> not prime

    ll s = n - 1, t = 0;     //we try to find two integers s and t such that n-1 = s * 2^t
    while(s % 2 == 0){
        s /= 2;
        t += 1;
    }
    for(ll i = 0; i < iterations; ++i){
        bool flag = false;
        ll a = 2 + (rand() % (n - 3));      //pick a random number between 2 and n - 2 inclusive for testing the given number n
        ll b = calcPowerMod(a, s, n);       //define b such that b = a^s mod n
        if(b == 1 || b == n - 1) continue;      //number could be prime
        for(ll j = 0; j < t - 1; ++j){
            b = (b * b) % n;
            if(b == n - 1) {flag = true;break;}
            if(b == 1) return false;
        }
        if(!flag) return false;
    }
    return true;
}

int main(){

    cout << "Enter the number to check whether it is prime or not: ";
    ll n;
    cin >> n;
    cout << "Enter the number of desired iterations: ";
    ll iterations;
    cin >> iterations;
    if(miller_test(n, 10)) cout << n << " is prime" << endl;
    else cout << n << " is not prime" << endl;

    return 0;
}
