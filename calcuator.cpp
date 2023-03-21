#include <iostream>
#include <map>
#include <string>

using namespace std;


int to_arabic(string roman){
    // Romauls gadaikvans arabulshi
    map<string, int> m{{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}};
    // @TODO implement
}

string to_roman(int num){
    // Arabuls gadaikvans romaulshi
    // @TODO: implement
}

int main(){
    int number_1 = to_arabic("XIX");
    int number_2 = to_arabic("IX");
    int result;

    char calc_operator = '*';

    if(calc_operator == '*'){
        result = number_1 * number_2;
    }else if(calc_operator == '+'){
        result = number_1 + number_2;
    }else if (calc_operator == '-'){
        result = number_1 - number_2;
    }else if (calc_operator == '/'){
        result = number_1 / number_2;
    }

    string roman_result = to_roman(result);
    cout << "Shedegi: " << roman_result << endl;

    return 0;
}