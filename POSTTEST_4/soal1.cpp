#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Fungsi Push dan Pop manual bisa dibuat di sini atau di dalam fungsi utama.
// Disarankan untuk membuatnya terpisah agar lebih rapi.

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // --- LENGKAPI DI SINI ---
    // 1. Push setiap karakter dari string s ke dalam stack.
    // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    // --- LENGKAPI DI SINI ---

    // Lakukan perulangan untuk setiap karakter dalam string s
    for (char character : s)
    {
        // Push karakter ke dalam stack
        push(stackTop, character);
    }

    // Inisialisasi variabel dengan nilai char sembarang untuk menyimpan karakter yang di-pop
    char poppedChar = 'a';

    // Lakukan perulangan selama stack tidak kosong
    while (poppedChar != '\0')
    {
        // Assign hasil pop ke variabel poppedChar
        poppedChar = pop(stackTop);

        // Jika tidak sama dengan '\0' atau stack tidak kosong, tambahkan ke string reversed
        if (poppedChar != '\0') {
            reversed += poppedChar;
        }
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}