#include <iostream>

using namespace std;

char w; //used to restart or exit the program

int main()
{
    start:
    system("cls");
    cout << "**************Applications for bits manipulation**************\n\n" << endl;
    cout << "Part one: Enter 1\nPart two: Enter 2\n" << endl;       //taking user input
    char choice;
    cin >> choice;
    system("cls");
    if(choice == '1'){  //part one
        cout << "Enter the number of elements: ";
        int n;
        cin >> n;
        cout << "\nEnter the elements separated by spaces: ";
        long long arr[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i){     //we use the bitwise XOR to omit the elements that appear twice
            ans ^= arr[i];              //and only keep the unique number
        }
        cout << "\nResult: " << ans << "\n\nRestart (Enter R)\nExit (Enter E)" << endl;
        cin >> w;
        if(w == 'R' || w == 'r') goto start;
        else if(w == 'E' || w == 'e') return 0;
    }else if(choice == '2'){    //part two
        unsigned long long x;
        cout << "Enter the unsigned integer: ";
        cin >> x;
        int ans = 0;
        while(x > 0){           //we keep shifting the number until it becomes zero, and every time we find a '1'
            if(1 & x) ans++;    //at the rightmost bit we increment the answer by one
            x >>= 1;
        }
        cout << "\nResult: " << ans << "\n\nRestart (Enter R)\nExit (Enter E)" << endl;
        cin >> w;
        if(w == 'R' || w == 'r') goto start;
        else if(w == 'E' || w == 'e') return 0;
    }


    return 0;
}
