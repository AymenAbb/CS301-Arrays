#include "functions.h"
#include <array>
#include <iostream>
using namespace std; // Yes this is bad practice but it's useful here

int main() {
  int arrLength = 100; // Big length in case you wanna insert a lot of numbers into the array
  int *intArr = new int[arrLength];
  arrayGet(intArr, arrLength);
  
  // initial setup and selection screen call
  int choice = 0;
  while (choice != 6) {
    displayMenu();
    cin >> choice;
    // function calling begins
    switch(choice){
      case 1:
        findInt(intArr, arrLength);
        break;
      case 2:
        modArray(intArr, arrLength);
        break;
      case 3:
        insertArray(intArr, arrLength);
        break;
      case 4:
        removeArray(intArr, arrLength);
        break;
      case 5:
        printArray(intArr, arrLength);
        break;
      case 6:
        break;
    }
  }
}