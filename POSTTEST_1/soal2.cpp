#include <iostream>
using namespace std;

int main() {

  int matriks[3][3] = 
  {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  int numberOfRow = sizeof(matriks) / sizeof(matriks[0]);
  int numberOfColumn = sizeof(matriks[0]) / sizeof(matriks[0][0]);

  int total = 0;

  for (int i = 0; i < numberOfRow; i++)
  {
    if ((i + 1) % 2 == 0)
    {
      for (int j = 0; j < numberOfColumn; j++)
      {
        total += matriks[i][j];
      }
      
    }
  }

  for (int i = 0; i < numberOfRow; i++)
  {
    for (int j = 0; j < numberOfColumn; j++)
    {
      cout << matriks[i][j] << " ";
    }
    cout << endl;
  }
  
  cout << "Hasil penjumlahan baris genap dari matriks tersebut adalah " << total;

  return 0;
}