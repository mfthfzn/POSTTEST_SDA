#include <iostream>
using namespace std;

int length;

void revereseArray(int (*array)[]) {

  for (int i = 0; i < (length / 2); i++)
  {
    int temp = (*array)[i];
    (*array)[i] = (*array)[length - i - 1];
    (*array)[length - i - 1] = temp;
    
  }

}

int main() {

  int arrayOfInteger[7] = {
    2, 3, 5, 7, 11, 13, 17
  };
  length = sizeof(arrayOfInteger) / sizeof(arrayOfInteger[0]);

  cout << "Array sebelum direverse : ";
  for (int i = 0; i < length; i++)
  {
    cout << arrayOfInteger[i] << " ";
  }
  cout << endl;
  
  revereseArray(&arrayOfInteger);
  
  cout << "Array sesudah direverse : ";
  for (int i = 0; i < length; i++)
  {
    cout << arrayOfInteger[i] << " ";
  }
  cout << endl;
  
  return 0;
}