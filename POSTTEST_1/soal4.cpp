#include <iostream>
using namespace std;

void swapValue(int &firstValue, int &secondValue) {
  int temp = firstValue;
  firstValue = secondValue;
  secondValue = temp;
}

int main() {
  
  int firstValue = 10;
  int secondValue = 20;

  cout << "Sebelum value ditukar :" << endl;
  cout << "Value pertama : " << firstValue << endl;
  cout << "Value kedua : " << secondValue << endl;
  cout << endl;
  swapValue(firstValue, secondValue);

  cout << "Sesudah value ditukar :" << endl;
  cout << "Value pertama : " << firstValue << endl;
  cout << "Value kedua : " << secondValue << endl;
}