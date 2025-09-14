#include <iostream>
using namespace std;

struct Mahasiswa {
  string nama;
  string nim;
  float ipk;
};

void selectionSort(Mahasiswa arr[], int length) {
  for (int i = 0; i < length - 1; i++) {
    int minIndex = i;

    for (int j = i + 1; j < length; j++) {
      if (arr[j].ipk < arr[minIndex].ipk) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      Mahasiswa temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

int main() {

  Mahasiswa mahasiswa[4] = {
    {"Eko", "2409106001", 3.78},
    {"Kurniawan", "2409106002", 3.44},
    {"Khannedy", "2409106003", 3.90},
    {"Budi", "2409106004", 3.30},
  };

  int length = sizeof(mahasiswa) / sizeof(mahasiswa[0]);

  cout << "Sebelum atribut IPK diurutkan secara ascending : " << endl;
  for (int i = 0; i < length; i++)
  {
    cout << "Nama : " << mahasiswa[i].nama << ", NIM : " << mahasiswa[i].nim << ", IPK : " << mahasiswa[i].ipk << endl;
  }
  cout << endl;
  selectionSort(mahasiswa, length);

  cout << "Sesudah atribut IPK diurutkan secara ascending : " << endl;
  for (int i = 0; i < length; i++)
  {
    cout << "Nama : " << mahasiswa[i].nama << ", NIM : " << mahasiswa[i].nim << ", IPK : " << mahasiswa[i].ipk << endl;
  }
  cout << endl;
  return 0;
}