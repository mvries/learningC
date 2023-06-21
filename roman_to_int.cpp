//C++ Script that converts roman numeral to integer.
//Author: Martijn de Vries

//This is needed to allow for input output detection:
#include <iostream>
//This one is needed to work with strings:
#include <string>
//map is a dict like data structure:
#include <map>

//Add some convenient functions to the scope:
using namespace std;

//class used to represent a roman number:
class Roman_number {
public:
  //constructor
  Roman_number(string roman_number) {
    this->roman_number = roman_number; 
  }

  //Define conversion table from roman to normal integers:
  //I think that special cases can already be added here??
  map<string, int> conversion_table = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000}
  };

  //Function to determine length of roman number:
  int get_string_length() {
    int length = 0;
    length = roman_number.size();
    return length;
  };

  //Function to convert the roman number to corresponding integers:
  int romanToInt() {
    //Declare integer to store output:
    int roman_int = 0;
    
    //First the length is determined:
    int length = get_string_length();

    //If lengt is one we just convert the number:
    if (length == 1) {
      roman_int = conversion_table[roman_number];
    };

    //If not we have to calculate the integer:
    return roman_int;
  };

private:
  string roman_number;
};


int main() {
  //User can declare a roman numeral that will be converted:
  string input_number = "";
  cin >> input_number;

  //We create an object to represent the roman number:
  Roman_number number_to_convert(input_number);

  int roman_int = number_to_convert.romanToInt();
  cout << roman_int << "\n";
  };
