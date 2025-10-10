#include <iostream>
using namespace std;
// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

/**
 * @brief Fungsi untuk mencari nilai terbesar dalam sebuah BST.
 * @param root Pointer ke node root dari tree.
 * @return Nilai integer terbesar. Mengembalikan -1 jika tree kosong.
 * @logic
 * 1. Cek jika tree kosong.
 * 2. Selama masih ada anak kanan (right child), terus telusuri ke kanan.
 * 3. Node paling kanan adalah node dengan nilai terbesar.
 */
int findMaxValue(Node* root) {
    // --- LENGKAPI KODE DI SINI ---

    // Mengecek apakah tree kosong, jika iya maka return -1
    if (root == nullptr) return -1;

    // Mengecek apakah tree tidak memiliki anak kanan, jika iya maka return data pada root
    // root adalah nilai terbesar bila anak kanan tidak ada
    else if (root->right == nullptr) return root->data;

    // Inisialisasi variabel data untuk menyimpan nilai terbesar
    int data;

    // Inisialisasi pointer temp untuk menelusuri tree
    Node* temp = root;

    // karena nilai paling besar pada BST ada pada anak kanan maka lakuan perulangan selama masih ada anak kanan
    // perulangan akan berhenti ketika anak kanan sudah tidak ada, artinya pointer temp sudah menunjuk ke node paling kanan
    // yang mana node tersebut adalah node dengan nilai terbesar
    while (temp->right != nullptr)
    {

        // reassign pointer temp ke anak kanan
        temp = temp->right;

        // simpan nilai terbesar sementara pada variabel data
        data = temp->data;
    }
    
    return data;
    // -----------------------------
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Harusnya output: 80
    return 0;
}