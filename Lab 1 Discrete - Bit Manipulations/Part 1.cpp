#include <iostream>

using namespace std;

int getBit(int number, int position){
    number >>= position;
    return 1 & number;
}

int setBit(int number, int position){
    int temp = 1;
    temp <<= position;
    return number | temp;
}

int clearBit(int number, int position){ //in this function, we get the number of digits
    int temp = number, len = 0, x = 0;  //in the binary number, then we initialize a
    while(temp > 0) temp >>= 1, len++;  //a variable 'x' that will eventually be a binary
    for(int i = 0; i < len; ++i){       //string of ones except for a zero in the position
        x <<= 1;                        //that we want to clear, and we return the original
        x |= 1;                         //number bitwise AND-ed with 'x' to clear the bit
        if(i == len - position - 1) x -= 1;
    }
    return number & x;
}

int updateBit(int number, int position, bool value){
    if(value) return setBit(number, position);
    else return clearBit(number, position);
}

int n, p, up; //'n' holds the number, 'p' holds the position that the operation will be executed on
              //'up' holds the choice of whether we want to clear or set a bit (used in the updateBit function)

char c, choice; //'c' is a dummy variable that acts as a buffer allowing the user to see the results of the operation
                //'choice' holds the operation number used in the switch block

int main()
{

    f:
    system("cls");
    cout << "************ Basic Bit Operations ************" << endl;
    cout << "\n\n\n\n" << endl;
    cout << "~~getBit ---> Enter 1\n" << endl;
    cout << "~~setBit ---> Enter 2\n" << endl;
    cout << "~~clearBit ---> Enter 3\n" << endl;
    cout << "~~updateBit ---> Enter 4\n" << endl;       //taking user input
    cin >> choice;
    system("cls");
    switch(choice){
    case '1':   //getBit
        cout << "Enter a number: ";
        cin >> n;
        cout << "\nFind the bit value at position: ";
        cin >> p;
        cout << "\nResult: " << getBit(n, p) << endl;
        cout << "\nEnter anything to go back" << endl;
        cin >> c;
        goto f;
    case '2':   //setBit
        cout << "Enter a number: ";
        cin >> n;
        cout << "\nSet bit at position: ";
        cin >> p;
        cout << "\nResult: " << setBit(n, p) << endl;
        cout << "\nEnter any number to go back" << endl;
        cin >> c;
        goto f;
    case '3':   //clearBit
        cout << "Enter a number: ";
        cin >> n;
        cout << "\nClear bit at position: ";
        cin >> p;
        cout << "\nResult: " << clearBit(n, p) << endl;
        cout << "\nEnter any number to go back" << endl;
        cin >> c;
        goto f;
    case '4':   //updateBit
        cout << "Enter a number: ";
        cin >> n;
        cout << "\nUpdate bit at position: ";
        cin >> p;
        cout << "enter 0 for clearing and 1 for setting: ";
        cin >> up;
        cout << "\nResult: " << updateBit(n, p, up);
        cout << "\nEnter any number to go back" << endl;
        cin >> c;
        goto f;
    default:    //restart
        goto f;
    }


    return 0;
}
