#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Functions declarations
int menu();

int num_finder(int arr[], int number, int size);

void num_changer(int arr[],int size, int index, int new_num);

int* num_adder(int arr[],int size, int index, int new_num);

int* value_remover(int arr[],int& size, int index);
//Function Deffintetion
int menu() {
  int choice;
  string choice_string;
  cout << "Welcome\n1: find a number\n2: change a number\n3: add a number\n4: remove a number\n5: print array\n6: EXIT" << endl;
  cin >> choice_string;
  cout << endl; 

  while ((choice_string !="1") && (choice_string !="2") && (choice_string !="3") && (choice_string!="4") && (choice_string != "5") && (choice_string != "6")) {

    cout << "invalid choice, choose again: ";
    cin >> choice_string;
    cout << endl;
  }
  choice = stoi(choice_string);
  return choice;
}


int num_finder(int arr[], int number, int size) {

  int found_num = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == number) {
      found_num = i;
    }
  }
  return found_num;
}
void num_changer(int arr[], int size, int index, int new_num) {
    cout << "You changed " << arr[index] << " to " << new_num << endl;
  arr[index] = new_num;
}

int* num_adder(int arr[],int& size,int new_val) {

  int* new_array = new int[size+1];
  for (int i = 0; i < size; i++) {
      new_array[i] = arr[i];
  }
  new_array[size] = new_val;
  size++;
  return new_array;
}

int* value_remover(int arr[],int& size, int index) {

  int i = 0;

  while (index+i < size) {
    arr[index + i] = arr[index+ i + 1];
    i++;
  }
  size--;
  return arr;
}