#include "Functions.h"

#include <iostream>

using namespace std;

//main fucntion
int main() {
  //initalize varioubles
  int size = 100;
  int choice = 0;
  //create array
  int* array = new int[size];
  //open the input file
  ifstream file("A1input.txt");
  int value;
  int i = 0;
  //iterates thrugh the file adding data to each index of the array
  while (file >> value) {
    array[i] = value;
    i++;
  }
  //close the file
  file.close();
  //start the while loop the program will run adn it stips when the user enters 6
  while (choice != 6){
    choice = menu();// activate a function to give the user choice
    
    if (choice == 1) {
      //find the number
      int number, num_index;
      cout << "what number are you wanting to find: ";
      cin >> number;
      cout << endl;
      num_index = num_finder(array, number, size);
      //if -1 the number is not present
      if (num_index != -1) {
        cout << "the index that " << number << " is at is " << num_index << endl;
      } else {cout << "the number is not in the array\n";}
    } else if (choice == 2) {
      //use try to stop errors, change the number to a differnt integer
      try {
        //initalize variables
        string s_index,s_temp;
        int index;
        int temp;
        cout << "what index do you want to edit" << endl;
        cin >> s_index;
        cout << endl;
        index = stoi(s_index);
        //check if the index is in range
        if (index >= size || index < 0) {
          throw runtime_error("Index is not in range");
        }
        cout << "the value you want to edit is: " << array[index] << endl;
        cout << "what is the value you want to change it to: ";
        cin >> s_temp;
        cout << endl;
        temp = stoi(s_temp);

        num_changer(array, 100,index,temp);
      }
        catch(const runtime_error& e) {
          cerr << "Error: " << e.what() << endl; 
        } catch(const invalid_argument& e) {
          cerr << "Error: " << e.what() << endl;
        }
    } else if (choice == 3) {
      //use try to catch errors, addes a number to the end of the array
      try {
        int new_number;
        string new_string_number;
        //size++;
        cout << "What value do you want to add: ";
        cin >> new_string_number;
        cout << endl;
        new_number = stoi(new_string_number);
        array = num_adder(array, size, new_number);
        
        cout << endl;
      } catch (const invalid_argument& e) {
        cerr << "invalid input ERROR: " << e.what() << endl;
      }
    } else if (choice == 4) {
      //removes a number from the integer
      int rem_index;
      cout << "what index do you want to remove: ";
      cin >> rem_index;
      
      array = value_remover(array, size, rem_index);
      
    } else if (choice == 5) {
      //prints the array contents
      cout << endl;
      for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
      }
      cout << endl;
    }
  }
  
  return 0;
}