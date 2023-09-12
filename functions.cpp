#include "functions.h"
#include <array>
#include <fstream>
#include <iostream>
using namespace std;

// Grabbing array from input.txt, got help from Kevin
void arrayGet(int intArr[], int arrLength) {
  ifstream inputFile;
  int newNum;
  int iterator = 0;
  string filename;
  filename = "input.txt";
  inputFile.open(filename);
  while (inputFile.is_open() && !inputFile.eof() && iterator < arrLength) {
    inputFile >> newNum;
    intArr[iterator] = newNum;
    iterator++;
    newNum = 0;
  }
  inputFile.close();
  for (; iterator < arrLength; iterator++) {
    intArr[iterator] = 0;
  }
}

// Finds an integer and reports back
void findInt(int intArr[], int arrLength) {
  int targetNum;
  cout << "Value to search? ";
  cin >> targetNum;
  int result = -1;
  for (int i = 0; i < arrLength - 1; i++) {
    if (intArr[i] == targetNum)
      result = i;
  }
  if (result != -1)
    cout << "Found " << targetNum << " at index " << result << "." << endl;
  else
    cout << targetNum << " not found in array." << endl;
}

// Modifies the array
void modArray(int intArr[], int arrLength) {
  try {
    int targetNum, targetIndex;
    cout << "What index? ";
    cin >> targetIndex;
    cout << "What's the new value? ";
    cin >> targetNum;
    if (targetIndex >= arrLength)
      throw invalid_argument("Index out of range.");
    cout << "Old Value: " << intArr[targetIndex] << endl;
    intArr[targetIndex] = targetNum;
    cout << "New Value: " << intArr[targetIndex] << endl;
  } catch (invalid_argument x) {
    cout << x.what() << endl;
  }
}

// Inserts an array to the end of numbers not 0
void insertArray(int intArr[], int arrLength) {
  int newVal;
  try {
    for (int i = 0; i < arrLength; i++) {
      if (intArr[i] == 0) {
        cout << "New Value? ";
        cin >> newVal;
        intArr[i] = newVal;
        break;
      }
    }
    throw invalid_argument("Invalid value.");
  } catch (invalid_argument x) {
    cout << x.what() << endl;
  }
}

// "Removes" /Sets an array to 0, got help from Kevin
void removeArray(int intArr[], int arrLength) {
  int index;
  cout << "What index? ";
  cin >> index;
  intArr[index] = 0;
  int currIndex = index;
  while (currIndex + 1 < arrLength) {
    intArr[currIndex] = intArr[currIndex + 1];
    currIndex++;
  }
  intArr[arrLength - 1] = 0;
}

// Prints selection screen, input taken in main method
void displayMenu() {
  cout << endl << "   Selection     " << endl;
  cout << "1. Check if a certain integer exists in the array." << endl;
  cout << "2. Modify a value with an index" << endl;
  cout << "3. Add a new integer to the end of the array" << endl;
  cout << "4. Delete value at specified index" << endl;
  cout << "5. Display the array" << endl;
  cout << "6. Quit" << endl << endl;
  cout << "-> ";
}

// Prints the array, but filters out the 0's
void printArray(int arr[], int arraySize) {
  int endOfArray = 0;
  for (int i = 0; i < arraySize; i++) {
    if (arr[i] == 0) {
      endOfArray = i;
      break;
    }
  }
  cout << "Your array is: " << endl << endl;
  for (int j = 0; j < endOfArray; j++) {
    cout << arr[j] << " ";
  }
  cout << endl << endl;
}