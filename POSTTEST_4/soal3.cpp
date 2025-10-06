#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // --- LENGKAPI DI SINI ---
    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    // --- LENGKAPI DI SINI ---

    // Cek apakah queue kosong, jika iya update front dan rear ke newNode
    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } 
    // Jika queue tidak kosong
    else
    {
        // update rear->next menjadi newNode
        rear->next = newNode;

        // update rear ke newNode
        rear = newNode;
    }
    
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // --- LENGKAPI DI SINI ---
    // 1. Simpan data dari front node
    // 2. Geser front ke front->next
    // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    // 4. Delete node lama dan return data
    // --- LENGKAPI DI SINI ---

    // inisialisasi pointer temp untuk menyimpan node front
    Node* temp = front;

    // simpan data dari front node
    string document = temp->document;

    // assign front ke front->next
    front = front->next;

    // jika front menjadi nullptr, set rear juga ke nullptr
    if (front == nullptr) rear = nullptr;

    // delete node temp
    delete temp;

    return document;
}

void processAllDocuments(Node*& front, Node*& rear) {
    // --- LENGKAPI DI SINI ---
    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    // Format: "Memproses: [nama_dokumen]"
    // --- LENGKAPI DI SINI ---

    // Lakukan perulangan selama queue tidak kosong
    while (front != nullptr) {
        // Inisialisasi variabel document untuk menyimpan hasil dequeue
        string document = dequeue(front, rear);
        
        cout << "Memproses: " << document << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}