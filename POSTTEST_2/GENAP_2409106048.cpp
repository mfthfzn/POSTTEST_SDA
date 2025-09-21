#include <iostream>
using namespace std;
#include <sstream>
#include <chrono>
#include <thread>

struct Penerbangan {
  string kodePenerbangan;
  string tujuan;
  string status; 
};

struct Node
{
  Penerbangan penerbangan;
  Node *next;
};

int counterCode = 0;
Node *tail;
Node *head;
string kodePenerbangan = "JT-048";

void clearScreen() {
  system("clear || cls");
}

void pause(int detik) {
  this_thread::sleep_for(chrono::seconds(detik));
}

void addLast(Node *&head, Node *&tail, string tujuan, string status) {
  Node *newNode = new Node;

  stringstream stream;
  stream << counterCode;
  string stringCounter = stream.str();
  newNode->penerbangan.kodePenerbangan = (counterCode == 0) ? kodePenerbangan : kodePenerbangan + "-" + stringCounter;
  newNode->penerbangan.tujuan = tujuan;
  newNode->penerbangan.status = status;
  counterCode++;
  newNode->next = nullptr;

  if (tail != nullptr)
  {
    tail->next = newNode;
  }
  else
  {
    head = newNode;
  }
  tail = newNode;
}

void addLastMenu() {
  clearScreen();
  cout << "+------------------------------------------------------------+\n";
  cout << "|                 TAMBAH JADWAL PENERBANGAN                  |\n";
  cout << "+------------------------------------------------------------+\n";

  string tujuan;
  string status;

  cout << "+-----------------------------+\n";
  cout << "| Masukkan Tujuan Penerbangan |\n";
  cout << "+-----------------------------+\n";
  cout << "+-> ";
  getline(cin, tujuan);

  cout << "+-----------------------------+\n";
  cout << "| Masukkan Status Penerbangan |\n";
  cout << "+-----------------------------+\n";
  cout << "+-> ";
  getline(cin, status);

  addLast(head, tail, tujuan, status);

  cout << "\nData penerbangan berhasil ditambahkan!";
}

void addSpecific(Node *&head, Node *&tail, int posisi, string tujuan, string status) {
  
  if (posisi < 1) {
    cout << "Mana ada posisi mines bang" << endl;
    return;
  }

  if (posisi == 1)
  {
    addLast(head, tail, tujuan, status);
    return;
  }
  
  Node *temp = head;
  int hitung = 1;
  while (temp != nullptr && hitung < posisi - 1) {
    temp = temp->next;
    hitung++;
  }

  if (temp == nullptr) {
    cout << "Position invalid!" << endl;
  } else if (temp->next == nullptr){
    addLast(head, tail, tujuan, status);
  } else{
    Node *newNode = new Node;

    stringstream stream;
    stream << counterCode;
    string stringCounter = stream.str();

    newNode->penerbangan.kodePenerbangan = (counterCode == 0) ? kodePenerbangan : kodePenerbangan + "-" + stringCounter;
    newNode->penerbangan.tujuan = tujuan;
    newNode->penerbangan.status = status;
    newNode->next = temp->next;
    temp->next = newNode;
    counterCode++;
  }
}

void addSpesificMenu() {
  clearScreen();
  cout << "+------------------------------------------------------------+\n";
  cout << "|                 SISIPKAN JADWAL PENERBANGAN                |\n";
  cout << "+------------------------------------------------------------+\n";

  cout << "\nMasukkan data penerbangan yang ingin disisipkan!" << endl;

  string tujuan;
  string status;

  cout << "+-----------------------------+\n";
  cout << "| Masukkan Tujuan Penerbangan |\n";
  cout << "+-----------------------------+\n";
  cout << "+-> ";
  getline(cin, tujuan);

  cout << "+-----------------------------+\n";
  cout << "| Masukkan Status Penerbangan |\n";
  cout << "+-----------------------------+\n";
  cout << "+-> ";
  getline(cin, status);

  addSpecific(head, tail, 9, tujuan, status);

  cout << "\nData penerbangan berhasil ditambahkan!";
}

void deleteFirst(Node *&head, Node *&tail) {
  clearScreen();

  cout << "+------------------------------------------------------------+\n";
  cout << "|                 HAPUS JADWAL PALING AWAL                   |\n";
  cout << "+------------------------------------------------------------+\n";
  if (head == nullptr) {
    cout << "Tidak ada data penerbangan yang dapat dihapus!" << endl;
    return;
  }

  Node *temp = head;
  head = temp->next;
  delete temp;

  if (head == nullptr) {
    tail = nullptr;
  }

  cout << "Berhasil menghapus data penerbangan pertama!" << endl;

  pause(1);
}

void updateStatusMenu(Node *&head) {
  cout << "+------------------------------------------------------------+\n";
  cout << "|                 UPDATE STATUS PENERBANGAN                  |\n";
  cout << "+------------------------------------------------------------+\n";

  string kodePenerbangan;

  cout << "+-----------------------------+\n";
  cout << "| Masukkan Kode Penerbangan   |\n";
  cout << "+-----------------------------+\n";
  cout << "+-> ";
  getline(cin, kodePenerbangan);

  Node *temp = head;
  bool found = false;
  while (temp != nullptr) {
    if (temp->penerbangan.kodePenerbangan == kodePenerbangan) {
      found = true;
      break;
    }
    temp = temp->next;
  }

  if (found) {
    string status;
    cout << "\n Data penerbangan ditemukan, silahkan masukkan status penerbangan yang baru!" << endl;
    cout << "+-----------------------------+\n";
    cout << "| Masukkan Status Penerbangan |\n";
    cout << "+-----------------------------+\n";
    cout << "+-> ";
    getline(cin, status);

    temp->penerbangan.status = status;

    if (temp->penerbangan.status == status) {
      cout << "\nStatus berhasil diubah!";
    }
  } else {
    cout << "\nData penerbangan tidak ditemukan";
  }
}

void printRecord(int &counter, string &kodePenerbangan, string &tujuan, string &status) {
  cout << "| " << counter + 1;
  counter + 1 < 10 ? cout << "  " : cout << " ";
  cout << "| " << kodePenerbangan;
  for (int j = kodePenerbangan.length(); j < 17; j++) {
    cout << " ";
  }
  cout << "| " << tujuan;
  for (int j = tujuan.length(); j < 19; j++) {
    cout << " ";
  }
  cout << "| " << status;
  for (int j = status.length(); j < 14; j++) {
    cout << " ";
  }
  cout << "|" << endl;
}

void transversal(Node *head) {
  if (head == nullptr)
  {
    cout << "\nTidak ada data penerbangan yang bisa ditampilkan" << endl;
    cout << "Tekan enter untuk keluar!";
    string enter;
    getline(cin, enter);
  } else {
    cout << "\n+----+------------------+--------------------+---------------+" << endl;
    cout << "| No | Kode Penerbangan | Tujuan             | Status        |" << endl;
    cout << "+----+------------------+--------------------+---------------+" << endl;
    Node *temp = head;
    int counter = 0;
    while (temp != nullptr)
    {
      printRecord(counter, temp->penerbangan.kodePenerbangan, temp->penerbangan.tujuan, temp->penerbangan.status);
      temp = temp->next;
      counter++;
    }
    counter = 0;

    cout << "+----+------------------+--------------------+---------------+" << endl;
    cout << "\nTekan enter untuk kembali!";
    string enter;
    getline(cin, enter);
    
  }
}

int main() {
  int choice;
  string choiceStr;

  head = nullptr;
  tail = nullptr;

  addLast(head, tail, "Surabaya (SUB)", "Tepat Waktu");
  addLast(head, tail,  "Jakarta (CGK)", "Naik Pesawat");
  addLast(head, tail,  "Medan (KNO)", "Terlambat");
  addLast(head, tail,  "Makassar (UPG)", "Tepat Waktu");
  addLast(head, tail,  "Yogyakarta (YIA)", "Naik Pesawat");
  addLast(head, tail,  "Denpasar (DPS)", "Terlambat");
  addLast(head, tail,  "Bandung (BDO)", "Tepat Waktu");
  addLast(head, tail,  "Semarang (SRG)", "Naik Pesawat");
  addLast(head, tail,  "Palembang (PLM)", "Terlambat");
  addLast(head, tail,  "Balikpapan (BPN)", "Tepat Waktu");

  do {
    pause(1);

    clearScreen();

    cout << "\n+-----------------------------------------------------------+\n";
    cout << "|                  FLIGHT SCHEDULE SYSTEM                   |\n";
    cout << "|            [ MIFTAHUL FAUZAN - 2409106048 ]               |\n";
    cout << "+-----------------------------------------------------------+\n";
    cout << "| 1. Tambah Jadwal Penerbangan                              |\n";
    cout << "| 2. Sisipkan Jadwal Penerbangan                            |\n";
    cout << "| 3. Hapus Jadwal Paling Awal                               |\n";
    cout << "| 4. Update Status Penerbangan                              |\n";
    cout << "| 5. Tampilkan Semua Jadwal                                 |\n";
    cout << "| 0. Keluar                                                 |\n";
    cout << "+-----------------------------------------------------------+\n";
    cout << "Masukkan pilihan Anda : ";
    getline(cin, choiceStr);

    try {
      choice = stoi(choiceStr);
      switch (choice) {
      case 1:
        addLastMenu();
        break;
      case 2:
        addSpesificMenu();
        break;
      case 3:
        deleteFirst(head, tail);
        break;
      case 4:
        clearScreen();
        updateStatusMenu(head);
        break;
      case 5:
        clearScreen();
        cout << "+------------------------------------------------------------+\n";
        cout << "|                          JADWAL                             |\n";
        cout << "+------------------------------------------------------------+\n";
        transversal(head);
        break;
      case 0:
        cout << ">> Keluar dari program...\n";
        break;
      default:
        cout << ">> Pilihan Anda tidak valid!\n";
      }
    } catch (const invalid_argument& e) {
      cout << "Error: string bukan angka valid!" << endl;
      choice = -1;
    }
    cout << endl;

  } while (choice != 0);

  return 0;
}
