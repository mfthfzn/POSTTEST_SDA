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
 * @brief Fungsi untuk mencari nilai terkecil dalam sebuah BST.
 * @param root Pointer ke node root dari tree.
 * @return Nilai integer terkecil. Mengembalikan -1 jika tree kosong.
 * @logic
 * 1. Cek jika tree kosong.
 * 2. Selama masih ada anak kiri (left child), terus telusuri ke kiri.
 * 3. Node paling kiri adalah node dengan nilai terkecil.
 */
int findMinValue(Node* root) {
    // --- LENGKAPI KODE DI SINI ---

    // Mengecek apakah tree kosong, jika iya maka return -1
    if (root == nullptr) return -1;

    // Mengecek apakah tree tidak memiliki anak kiri, jika iya maka return data pada root
    // root adalah nilai terkecil bila anak kiri tidak ada
    else if (root->left == nullptr) return root->data;
    
    // Inisialisasi variabel data untuk menyimpan nilai terkecil
    int data;

    // Inisialisasi pointer temp untuk menelusuri tree
    Node* temp = root;

    // karena nilai paling kecil pada BST ada pada anak kiri maka lakuan perulangan selama masih ada anak kiri
    // perulangan akan berhenti ketika anak kiri sudah tidak ada, artinya pointer temp sudah menunjuk ke node paling kiri
    // yang mana node tersebut adalah node dengan nilai terkecil
    while (temp->left != nullptr)
    {
        // reassign pointer temp ke anak kiri
        temp = temp->left;

        // simpan nilai terkecil sementara pada variabel data
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
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Harusnya output: 20
    return 0;
}