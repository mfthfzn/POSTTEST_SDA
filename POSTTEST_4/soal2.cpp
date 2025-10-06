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

// Anda bisa menggunakan fungsi push dan pop dari soal sebelumnya.

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    string reversed = "";

    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
    // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
    //    a. Apakah stack kosong? Jika ya, return false.
    //    b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
    // --- LENGKAPI DI SINI ---

    // Lakukan perulangan untuk setiap karakter dalam string expr
    for (char character : expr)
    {
        // Cek apakah karakter adalah kurung buka, jika ya, push ke stack
        if (character == '(' || character == '{' || character == '[')
        {
            push(stackTop, character);
        }
        // Cek apakah karakter adalah kurung tutup, jika ya, cek kecocokan dengan kurung buka
        else if (character == ')' || character == '}' || character == ']')
        {
            // Jika stack kosong, return false
            if (stackTop == nullptr) return false;

            char poppedChar = pop(stackTop);

            // Cek variabel poppedChar dan karakter, apakah ada yang tidak cocok antara keduanya, jika tidak cocok return false
            if ((character == ')' && poppedChar != '(') ||
                (character == '}' && poppedChar != '{') ||
                (character == ']' && poppedChar != '['))
            {
                return false;
            }
        }
    }
    
    // Jika stack kosong, return true. Jika tidak, return false.
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}