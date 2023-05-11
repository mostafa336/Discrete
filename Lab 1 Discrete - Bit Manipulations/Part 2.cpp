#include <iostream>

using namespace std;

int i, j, in1, in2;     //index counters
bool flag1, flag2;      //end-of-loops boolean variables
string elements[10000]; //universal set array
char foo;               //dummy variable that acts as a buffer allowing the user to see the results of the operation

int* unionAndIntersectFns(int len, string sub1[], string sub2[], int choice){
    int s1[len], s2[len];
    for(i = 0; i < len; ++i){           //this loop converts the subset of strings into a binary array
        flag1 = false, flag2 = false;   //to execute the bitwise operations and find union, intersection
        for(j = 0; j < len; ++j){       //and complement of the given subsets
            if(elements[i] == sub1[j]){
                flag1 = true;           //the same loop appears in the complement function but only on
            }                           //one subset
            if(elements[i] == sub2[j]){
                flag2 = true;
            }
            if(flag1 && flag2) break;
        }
        if(flag1) s1[i] = 1;
        else s1[i] = 0;
        if(flag2) s2[i] = 1;
        else s2[i] = 0;
    }
    static int ans[10000] = {0};
    for(i = 0; i < len; ++i){
        if(choice == 1) ans[i] = s1[i] | s2[i];
        else if(choice == 2) ans[i] = s1[i] & s2[i];
    }
    return ans;     //returns a pointer to the first element in the resulting array
}

int* complementFn(int len, string sub1[]){
    int s1[len];
    for(i = 0; i < len; ++i){
        flag1 = false;
        for(j = 0; j < len; ++j){
            if(elements[i] == sub1[j]){
                flag1 = true;
                break;
            }
        }
        if(flag1) s1[i] = 1;
        else s1[i] = 0;
    }
    static int ans[10000];
    for(i = 0; i < len; ++i){
        ans[i] = !s1[i];
    }
    return ans;     //returns a pointer to the first element in the resulting array
}

int main()
{
    g:
    system("cls");
    cout << "********************Sets Operations using Bits manipulation********************\n\n\n";
    cout << "Enter the universal set elements separated by spaces:       (Enter -1 when finished)" << endl;        //taking user input
    for(i = 0; i < 10001; ++i){
        cin >> elements[i];
        if(elements[i] == "-1") break;
    }
    int len = i;
    int num;
    cout << "\nEnter the number of subsets: ";
    cin >> num;
    cout << "\nEnter the subset elements separated by spaces, and every subset on a different line:      (Enter -1 when finished with each subset)" << endl;
    string subs[num][len + 1];
    for(i = 0; i < num; ++i){
        for(j = 0; j < len + 1; ++j){
            cin >> subs[i][j];
            if(subs[i][j] == "-1") break;
        }
    }
    f:
    system("cls");
    cout << "\nUniversal set: {";
    for(i = 0; i < len - 1; ++i){
        cout << elements[i] << ", ";
    }
    cout << elements[len - 1] << "}" << endl;
    cout << "Subsets: {\n";
    for(i = 0; i < num; ++i){
        cout << "(" << i << "){";
        for(j = 0; j < len + 1; ++j){
            if(subs[i][j + 1] != "-1") cout << subs[i][j] << ", ";
            else break;
        }
        cout << subs[i][j] << "}\n";
    }
    cout << "}\n";
    cout << "\nEnter 4 to restart the program, or 5 to exit\n\n" << endl;
    cout << "Select the operation:\n\n~~Union ---> Enter 1\n\n~~Intersection ---> Enter 2\n\n~~Complement ---> Enter 3\n\n";
    char choice;
    cin >> choice;
    cout << "\n\n";
    switch(choice){
    case '1':{  //union
        cout << "Enter the indices of the 2 subsets separated by a space: ";
        cin >> in1 >> in2;
        int* out = unionAndIntersectFns(len, subs[in1], subs[in2], 1);
        cout << endl;
        cout << "Result: { ";
        for(i = 0; i < len; ++i){       //printing only the elements that are set to 1 in the resulting subset
            if(out[i]) cout << elements[i] << " ";
        }
        cout << "}\nEnter anything to continue: ";
        cin >> foo;
        goto f;
    }
    case '2':{  //intersect
        cout << "Enter the indices of the 2 subsets separated by a space: ";
        cin >> in1 >> in2;
        int* out = unionAndIntersectFns(len, subs[in1], subs[in2], 2);
        cout << endl;
        cout << "Result: { ";
        for(i = 0; i < len; ++i){
            if(out[i]) cout << elements[i] << " ";
        }
        cout << "}\nEnter anything to continue: ";
        cin >> foo;
        goto f;
    }
    case '3':{  //complement
        cout << "Enter the index of the subset to find its complement: ";
        cin >> in1;
        int* out = complementFn(len, subs[in1]);
        cout << endl;
        cout << "Result: { ";
        for(i = 0; i < len; ++i){
            if(out[i]) cout << elements[i] << " ";
        }
        cout << "}\nEnter anything to continue: ";
        cin >> foo;
        goto f;
    }
    case '4':{  //restart
        goto g;
    }
    case '5':{  //exit
        return 0;
    }
    default:{
        goto f;
    }
    }

    return 0;
}
