//This script is solves the leetcode two sum challenge
//This script can take a list of integers and a target integer.
//It returns the indexes of the integers in the list that sum up to target.
//Note that this implementation is O(n) :) 

//Include the required libraries:
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//Function to find the index of two integers summing up to target
vector<int> Two_sum(vector<int> input_vector, int target) {
  vector<int> output_vector;
  map<int, int> differences;

  int size = input_vector.size();

  
  for (int i = 0; i < size; ++i) {
    int dif = target - input_vector[i];

    if (differences.count(dif) == 0) {
      differences[dif] = i;

    } else {
      output_vector.push_back(i);
      output_vector.push_back(differences[dif]);
      
    };
    };

  return output_vector;
};


int main() {
  //Declare vector variable:
  vector<int> user_vector{3, 2, 4};

  //Find two sum:
  vector<int> Solution = Two_sum(user_vector, 6);
  
  return 0;
};
