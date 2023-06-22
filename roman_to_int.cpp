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

class Roman_number {
public:

  //Constructor:
  string input_number;
  Roman_number(string input_number) {
    this->input_number = input_number;
  };

  //Function to determine length of roman number:
  int get_length() {
    int length = 0;
    length = input_number.size();
    return length;
  };

  //Function to convert roman char to int:
  int get_roman_int(char roman_character) {
    int converted_number = 0;

    //Conversion table:
    map<char, int> table = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
    };
    
    converted_number = table[roman_character];
    return converted_number;
  };

  //Function to return char from string at certain positions:
  char get_character(int position) {
    char outcharacter = ' ';

    outcharacter = input_number[position];
    
    return outcharacter;
  };

  //Function that converts roman number to integer:
  int roman_to_int() {
    int converted_number = 0;

    //First we determine the length of the input number:
    int input_length = 0;
    input_length = get_length();

    //If the length is one we just convert the input number:
    if (input_length == 1) {
      converted_number = get_roman_int(input_number[0]);
    }
    else {
      //if not we have to perform the conversion:
      for (int i = 1; i <= input_length; ++i) {
	char current_character = get_character(i);
	char previous_character = get_character(i - 1);

	int current_character_int = get_roman_int(current_character);
	int previous_character_int = get_roman_int(previous_character);
	
	//Now we check for edge cases:

	//First 9 and 4:
	if (previous_character == 'I') {
	  if (current_character == 'V' || current_character == 'X') {
	    ++i;
	    converted_number += (current_character_int -
				 previous_character_int);
	    continue;
	  }
	};

	//Then 40 and 90:
	if (previous_character == 'X') {
	  if (current_character == 'L' || current_character == 'C') {
	    ++i;
	    converted_number += (current_character_int -
				 previous_character_int);
	    continue;
	  }
	};

	//Finally 400 and 900:
	if (previous_character == 'C') {
	  if (current_character == 'D' || current_character == 'M') {
	    ++i;
	    converted_number += (current_character_int -
				 previous_character_int);
	    continue;
	  }
	};

	//If not an edge case do something ...
	converted_number += (current_character_int + previous_character_int);
	++i;
      };
    };
    
    return converted_number;
    
  };
};

int main() {
  //User can declare a roman numeral that will be converted:
  string user_input_number = "";
  cin >> user_input_number;

  //Make object:
  Roman_number user_number_object = Roman_number(user_input_number);

  int test = 0;
  test = user_number_object.roman_to_int();
  cout << test << "\n";
  return test;
  };
