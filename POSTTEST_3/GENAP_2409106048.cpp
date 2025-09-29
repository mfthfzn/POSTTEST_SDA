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
  Node *prev;
};

int length = 0;
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
  stream << length;
  string stringCounter = stream.str();
  newNode->penerbangan.kodePenerbangan = (length == 0) ? kodePenerbangan : kodePenerbangan + "-" + stringCounter;
  newNode->penerbangan.tujuan = tujuan;
  newNode->penerbangan.status = status;
  newNode->next = NULL;

  if (head == NULL && tail == NULL)
  {
    head = newNode;
    head->prev = NULL;
    tail = newNode;
    length++;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = NULL;
    length++;
  }
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
  
  if (posisi < 1 && posisi > (length + 1)) {
    cout << "Invalid position!" << endl;
    return;
  }
  
  if (posisi == length + 1)
  {
    addLast(head, tail, tujuan, status);
  }
  else
  {
    Node *newNode = new Node;
    Node *temp = head;
    for (int i = 1; i < posisi - 1; i++)
    {
      temp = temp->next;
    }
    stringstream stream;
    stream << length;
    string stringCounter = stream.str();

    newNode->penerbangan.kodePenerbangan = (length == 0) ? kodePenerbangan : kodePenerbangan + "-" + stringCounter;
    newNode->penerbangan.tujuan = tujuan;
    newNode->penerbangan.status = status;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    length++;
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
  if (head == NULL && tail == NULL)
  {
    cout << "Tidak ada data penerbangan yang dapat dihapus!" << endl;
    return;
  }
  else if (head->next == NULL)
  {
    delete head;
    head = NULL;
    tail = NULL;
    length--;
  }
  else
  {
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    length--;
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
  while (temp != NULL) {
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

void transversalHead(Node *&head) {
  if (head == NULL)
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
    while (temp != NULL)
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

void transversalTail(Node *&tail) {
  if (tail == NULL)
  {
    cout << "\nTidak ada data penerbangan yang bisa ditampilkan" << endl;
    cout << "Tekan enter untuk keluar!";
    string enter;
    getline(cin, enter);
  } else {
    cout << "\n+----+------------------+--------------------+---------------+" << endl;
    cout << "| No | Kode Penerbangan | Tujuan             | Status        |" << endl;
    cout << "+----+------------------+--------------------+---------------+" << endl;
    Node *temp = tail;
    int counter = 0;
    while (temp != NULL)
    {
      printRecord(counter, temp->penerbangan.kodePenerbangan, temp->penerbangan.tujuan, temp->penerbangan.status);
      temp = temp->prev;
      counter++;
    }
    counter = 0;
    cout << "+----+------------------+--------------------+---------------+" << endl;
    cout << "\nTekan enter untuk kembali!";
    string enter;
    getline(cin, enter);
  }
}

void searchByCodeReference(Node *&head) {
  if (head == NULL)
  {
    cout << "\nTidak ada data penerbangan yang bisa dicari" << endl;
    cout << "Tekan enter untuk keluar!";
    string enter;
    getline(cin, enter);
  } else {
    cout << "+------------------------------------------------------------+\n";
    cout << "|                 SEARCH BY KODE PENERBANGAN                 |\n";
    cout << "+------------------------------------------------------------+\n";

    string kodePenerbangan;

    cout << "+-----------------------------+\n";
    cout << "| Masukkan Kode Penerbangan   |\n";
    cout << "+-----------------------------+\n";
    cout << "+-> ";
    getline(cin, kodePenerbangan);

    Node *temp = head;
    bool found = false;
    while (temp != NULL) {
      if (temp->penerbangan.kodePenerbangan == kodePenerbangan) {
        found = true;
        break;
      }
      temp = temp->next;
    }
    if (found) {
      cout << "\n+----+------------------+--------------------+---------------+" << endl;
      cout << "| No | Kode Penerbangan | Tujuan             | Status        |" << endl;
      cout << "+----+------------------+--------------------+---------------+" << endl;
      int counter = 0;
      printRecord(counter, temp->penerbangan.kodePenerbangan, temp->penerbangan.tujuan, temp->penerbangan.status);
      cout << "+----+------------------+--------------------+---------------+" << endl;
      cout << "\nTekan enter untuk kembali!";
      counter = 0;
      string enter;
      getline(cin, enter);
    } else {
      cout << "\nData penerbangan tidak ditemukan";
    }
  }
}


int main() {
  int choice;
  string choiceStr;

  head = NULL;
  tail = NULL;

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
    cout << "| 5. Tampilkan Semua Jadwal Dari Head                       |\n";
    cout << "| 6. Tampilkan Semua Jadwal Dari Tail                       |\n";
    cout << "| 7. Search By Kode Penerbangan                             |\n";
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
        transversalHead(head);
        break;
      case 6:
        clearScreen();
        cout << "+------------------------------------------------------------+\n";
        cout << "|                          JADWAL                             |\n";
        cout << "+------------------------------------------------------------+\n";
        transversalTail(tail);
        break;
      case 7:
        clearScreen();
        searchByCodeReference(head);
        break;
      case 0:
        cout << ">> Keluar dari program...\n";
        break;
      default:
        cout << ">> Pilihan Anda tidak valid!\n";
      }
    } catch (const invalid_argument& e) {
      cout << "Error: bukan angka valid!" << endl;
      choice = -1;
    }
    cout << endl;

  } while (choice != 0);

  return 0;
}
