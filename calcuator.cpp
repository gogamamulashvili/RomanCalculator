#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string arabic_to_roman(int number) {
    string result = "";
    int values[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 9; i++) {
        while (number >= values[i]) {
            result += symbols[i];
            number -= values[i];
        }
    }
    return result;
}

int roman_to_arabic(string roman){
    unordered_map<char, int> roman_to_int;
    roman_to_int['I']  = 1;
    roman_to_int['V']  = 5;
    roman_to_int['X']  = 10;
    roman_to_int['L']  = 50;
    roman_to_int['C']  = 100;
    roman_to_int['D']  = 500;
    roman_to_int['M']  = 1000;

    int result = 0;

    for (int i = 0; i < roman.length(); i++) {
        int curr_value = roman_to_int[roman[i]];
        int next_value = i + 1 < roman.length() ? roman_to_int[roman[i+1]] : 0;
        if (curr_value < next_value) {
            result -= curr_value;
        } else {
            result += curr_value;
        }
    }
    return result;
}

int calculate(int num1, int num2, string operation) {
    int result;

    if (operation == "+") {
        result = num1 + num2;
    } else if (operation == "-") {
        result = num1 - num2;
    } else if (operation == "*") {
        result = num1 * num2;
    } else if (operation == "/") {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Error: Division by zero." << endl;
            return -1;
        }
    } else {
        cout << "Please write the correct operator: " << endl;
        return -1;
    }
    
    return result;
}

int main() {
    string operation;
    string roman1;
    string roman2;
    int num1;
    int num2;


    while (operation != "exit") {
        cout << "enter number: ";
        cin >> roman1;

        cout << "enter operator(+ - / * exit): ";
        cin >> operation;

        cout << "enter number: ";
        cin >> roman2;
        
        num1 = roman_to_arabic(roman1);
        num2 = roman_to_arabic(roman2);

        int result = calculate(num1, num2, operation);
        cout << "DEBUG: " << num1 << operation << num2 << '=' << result << endl;
        cout << "Result: " << arabic_to_roman(result) << endl;
    }

    return 0;
}