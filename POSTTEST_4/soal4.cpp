#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head dan data yang akan disisipkan.
 * Pointer head bisa berubah jika data baru menjadi elemen terkecil.
 */
void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // --- LENGKAPI DI SINI ---
    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    // 1. Jika data < head_ref->data, sisipkan sebelum head dan update head_ref

    // Cek apakah data baru lebih kecil dari head, jika ya sisipkan di awal dan update head_ref
    if (data < head_ref->data) {

        // inisialisasi pointer tail untuk menyimpan node terakhir
        Node* tail = head_ref->prev;

        // update newnode->next menjadi head_ref, karena head_ref akan menjadi next dari newNode
        newNode->next = head_ref;

        // update newnode->prev menjadi tail
        newNode->prev = tail;

        // update tail->next menjadi newNode
        tail->next = newNode;

        // update head_ref->prev menjadi newNode
        head_ref->prev = newNode;

        // update head_ref ke newNode
        head_ref = newNode;
        return;
    }

    // Kasus 3: Cari posisi yang tepat (tengah/akhir)
    // 1. Gunakan pointer current mulai dari head_ref
    // 2. Loop: while (current->next != head_ref && current->next->data < data)
    // 3. Setelah loop, sisipkan newNode setelah current
    // 4. Pastikan update semua pointer next dan prev dengan benar
    //
    // CATATAN: Jika data sama dengan existing data, sisipkan setelahnya
    // --- LENGKAPI DI SINI ---

    // Inisialisasi pointer current untuk mencari posisi yang tepat
    Node* current = head_ref;

    // Lakukan perulangan untuk mencari posisi yang tepat
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // Inisialisasi pointer temp untuk menyimpan node setelah current
    Node* temp = current->next;

    // update pointer current->next menjadi newNode karena newNode akan disisipkan setelah current dan sebelum temp
    current->next = newNode;
    
    // update pointer newNode->prev menjadi current
    newNode->prev = current;
    

    // update pointer newNode->next menjadi temp
    temp->prev = newNode;

    // update pointer newNode->next menjadi temp
    newNode->next = temp;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}