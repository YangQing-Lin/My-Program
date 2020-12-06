#include<iostream>
using namespace std;

void C(void);
void D(void);

int main() {
    char choice = getchar();
    getchar();
    if(choice == 'C') {
        C();
    } else {
        D();
    }
    return 0;
}

void C(void) {
    int arr_int[1000] = {0};
    char arr_char[1000];
    string temp_string;
    int size = 1;
    char temp_char;
    char last_temp_char = getchar();
    int address = 0;
    getline(cin, temp_string);
    for(int i = 0; i < temp_string.length(); i++) {
        temp_char = temp_string[i];
        if (temp_char == last_temp_char) {
            size++;
        } else {
            arr_int[address] = size;
            arr_char[address] = last_temp_char;
            size = 1;
            address++;
        }
        last_temp_char = temp_char;
    }
    arr_int[address] = size;
    arr_char[address] = last_temp_char;
    size = 1;
    address++;
    for (int i = 0; i < address; i++) {
        if(arr_int[i] == 1) {
            cout << arr_char[i];
        } else {
            cout << arr_int[i] << arr_char[i];
        }
    }
    cout << endl;
}

void D(void) {
    string temp_string;
    int size = 0;
    char temp_char;
    getline(cin, temp_string);
    for(int i = 0; i < temp_string.length(); i++) {
        temp_char = temp_string[i];
        if(temp_char >= '0' && temp_char <= '9') {
            size = size * 10 + (temp_char - '0');
        } else {
            if(size == 0) {
                cout << temp_char;
            } else {
                for (int j = 0; j < size; j++) {
                    cout << temp_char;
                }
            }
            size = 0;
        }
    }
    cout << endl;
}