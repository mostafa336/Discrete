#include <iostream>

using namespace std;

int n;  //number of strings in the given set

void take_input(string input_array[]){  //self explanatory
	cout << "Enter the first string: ";
	cin >> input_array[0];
	for(int i = 1; i < n; i++){
        cout << "Enter the next string: ";
        cin >> input_array[i];
	}
}

////////////////////////////////////////////////////////////

void iterative(string input_array[]){   //bitmask approach for finding the subsets using bit manipulations
    for(int mask = 0; mask < (1 << n); mask++){
        string ans[n];
        int current_index = 0;
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                ans[current_index++] = input_array[i];
            }
        }
        cout << "{";
        for(int i = 0; i < current_index - 1; i++){
            cout << ans[i] << ", ";
        }
        if(current_index != 0) cout << ans[current_index - 1];
        cout << "}" << endl;
    }
}

////////////////////////////////////////////////////////////

void recursive(string input_array[], int index, string current){    //recursive approach for finding the subsets
    if(index == n){                                                 //since each string can either exist or be excluded
        if(current[0] != ',')                                       //from the resulting subset, we recursively call the function
        cout << "{" << current << "}" << endl;                      //twice, once with the next string added to the subset, and
        else{                                                       //once excluded from it
            cout << "{";
            for(int i = 2; i < (int)current.length(); i++){
                cout << current[i];
            }
            cout << "}" << endl;
        }
        return;
    }
    recursive(input_array, index + 1, current + ", " + input_array[index]);
    recursive(input_array, index + 1, current);
}

////////////////////////////////////////////////////////////

int main() {
	while(true){
        system("cls");
        cout << "Enter 1 for recursive solution \n";
        cout << "Enter 2 for iteration solution \n";
        cout << "Enter 3 to exit "<<endl;
        char x;
        cin >> x;
        if(x == '3')break;
        if(x != '1' && x != '2'){
            continue;
        }
        system("cls");
        cout << "Enter the number of distinct strings: ";
        cin >> n;
        string input_array[n];
        take_input(input_array);
        if(x == '1')recursive(input_array, 0, "");
        else iterative(input_array);
        cout << "Enter anything to continue: ";
        cin >> x;
	}
	return 0;
}
