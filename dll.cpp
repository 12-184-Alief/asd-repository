#include <iostream>
using namespace std;

// Menginisialisai struktur node pada DLL
struct Node {
    int data; // Untuk simpan data elemen
    Node* prev; // Untuk simpan pointer ke node sebelumnya
    Node* next; // Untuk simpan pointer ke node berikutnya
};

// Inisialisasi first & last untuk menunjuk node pertama dan terakhir pada list
Node* first = NULL;
Node* last = NULL;

// Membuat fungsi untuk cek apakah list sudah ada
bool ifListEmpty() {
    return first == NULL;
}

// Membuat fungsi untuk cetak elemen dalam list
void cetakList() {
    if (ifListEmpty()) { // Cek apakah list kosong
        cout << "Listnya masih kosong." << endl; // Jika kosong maka cetak string berikut
    }
    else {
        Node* temp = first; // Mulai dari node pertama (first)
        cout << "List saat ini: ";
        // Buat looping untuk cetak setiap elemen di list
        while (temp != NULL) {
            cout << temp->data << " "; // Cetak data pada list saat ini
            temp = temp->next; // Lalu pindah ke node selanjutnya
        }
        cout << endl;
    }
}

// Fitur 1. InsertFirst
// Membuat fungsi InsertFirst untuk tambah elemen di awal list
void InsertFirst(int value) {
    Node* newNode = new Node(); // Inisialisasi node baru
    newNode->data = value; // Lalu isi data node barunya
    newNode->prev = NULL; // Sebagai node pertama, maka prev harus NULL (kosong)
    newNode->next = first; // Lalu next akan mengarah ke node pertama (first) saat ini

    if (ifListEmpty()) {
        // Jika listnya kosong, maka last juga harus menunjuk ke node baru
        last = newNode;
    }
    else {
        first->prev = newNode; // Update node sebelumnya dari first ke node yang baru
    }
    first = newNode; // Lalu ubah first ke node baru
}

// Fitur 2. InsertLast
// Membuat fungsi InsertLast untuk tambah elemen di akhir list
void InsertLast(int value) {
    Node* newNode = new Node(); // Inisialisasi node baru
    newNode->data = value; // Lalu isi data node barunya
    newNode->next = NULL; // Karena node terakhir, maka next harus NULL (kosong)
    newNode->prev = last; // Lalu prev akan mengarah ke node terakhir (last) saat ini

    if (ifListEmpty()) {
        // Jika listnya kosong, maka first juga harus menunjuk ke node baru
        first = newNode;
    }
    else {
        last->next = newNode; // Update node berikutnya dari last ke node yang baru
    }
    last = newNode; // Lalu ubah last ke node baru
}

// Fitur 3. InsertAfter
// Membuat fungsi InsertAfter untuk tambah elemen setelah node dengan nilai key tertentu
void InsertAfter(int key, int value) {
    Node* temp = first;
    // Cari node dengan nilai key yang diinput
    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        // Jika node dengan key tidak dijumpai lalu cetak string di bawah
        cout << "Key " << key << " tidak ditemukan pada list." << endl;
    }
    else {
        Node* newNode = new Node(); // Buat node baru
        newNode->data = value; // Isi data pada node baru
        newNode->prev = temp; // Node yang baru akan berada setelah node temp
        newNode->next = temp->next; // Lalu next node baru akan menunjuk ke next node temp

        if(temp->next != NULL) {
            // Jika temp bukan node terakhir, maka update prev node setelah temp
            temp->next->prev = newNode;
        }
        else {
            last = newNode; // Jika node baru ada di akhir, maka update lastnya
        }
        temp->next = newNode; // Mengupdate next dari temp ke node yang baru lalu cetak string di bawah
        cout << "Elemen " << value << " dimasukkan setelah " << key << endl;
    }
}

// Fitur 4. DeleteFirst
// Membuat fungsi DeleteFirst untuk hapus elemen pertama pada list
void DeleteFirst() {
    if (ifListEmpty()) { // Cek jika listnya kosong
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
    }
    else {
        Node* temp = first; // Simpan node pertama untuk dihapus
        first = first->next; // Hapus first ke node selanjutnya 

        if(first != NULL) {
            first->prev = NULL; // Jika masih ada elemen, prev dari first dibuat jadi NULL
        }
        else {
            last = NULL; // Jika listnya kosong, last dibuat jadi NULL
        }
        delete temp; // Hapus node yang lama
        cout << "Elemen pertama berhasil dihapus." << endl;
    }
}

// Fitur 5. DeleteLast
// Membuat fungsi DeleteLast untuk hapus elemen terakhir pada list
void DeleteLast() {
    if (ifListEmpty()) { // Cek jika listnya kosong
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
    }
    else {
        Node* temp = last; // Simpan node terakhir untuk dihapus
        last = last->prev; // Hapus last ke node sebelumnya

        if(last != NULL) {
            last->next = NULL; // Jika masih ada elemen, next dari last dibuat jadi NULL
        }
        else {
            first = NULL; // Jika listnya kosong, first dibuat jadi NULL
        }
        delete temp; // Hapus node yang lama
        cout << "Elemen terakhir berhasil dihapus." << endl;
    }
}

// Fitur 6. DeleteByValue
// Membuat fungsi DeleteByValue untuk hapus elemen berdasarkan nilai yang diinput
void DeleteByValue(int value) {
    Node* temp = first;
    // Cari node dengan nilai value
    while(temp != NULL && temp->data != value) {
        temp = temp->next; // Pindah ke node berikutnya
    }

    if (temp == NULL) {
        // Jika nilai tidak ada
        cout << "Data " << value << " tidak ditemukan dalam list." << endl; 
    }
    else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next; // Update next dari node sebelumnya
        }
        else {
            first = temp->next; // Jika node pertama yang dihapus, maka update firstnya
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev; // Update prev dari node yang berikutnya
        }
        else {
            last = temp->prev; // Jika node terakhir yang dihapus, maka update lastnya
        }

        delete temp; // Hapus node yang lama
        cout << "Data " << value << " telah dihapus dari list." << endl; 
    }
}

// Fitur 7. ReversePrintList
// Membuat fungsi ReversePrintList untuk cetak elemen dalam list secara terbalik
void ReversePrintList() {
    if (ifListEmpty()) {
        cout << "List masih kosong." << endl;
    }
    else {
        Node* temp = last; // Mulai dari node terakhir (last)
        cout << "List yang telah dibalik: ";
        // Looping untuk cetak setiap elemen dari node belakang
        while(temp != NULL) {
            cout << temp->data << " "; // Cetak data pada node saat ini
            temp = temp->prev; // Lalu akan pindah ke node sebelumnya
        }
        cout << endl;
    }
}

// Fitur InputElementList
// Membuat fungsi InputElementList untuk terima input elemen dari user
void InputElementList(int jumlah) {
    int value;
    for (int i = 0; i < jumlah; i++)
    {
        cout << "Inputkan Elemen ke-" << i+1 << ": ";
        cin >> value;
        InsertLast(value); // Untuk tambah elemen di akhir list
    }
}

int main() {
    // Deklarasi variabel yang dibutuhkan untuk menjalankan program
    int pil, value, key, jumlah;
    char confirm;

    do {
        cout << "\nDouble Linked List Menu:\n";
        cout << "1. Tampilkan List \n";
        cout << "2. Input Elemen List\n";
        cout << "3. Insert First\n";
        cout << "4. Insert Last\n";
        cout << "5. Insert After\n";
        cout << "6. Delete First\n";
        cout << "7. Delete Last\n";
        cout << "8. Delete by Value\n";
        cout << "9. Reverse Print List\n";
        cout << "10. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> pil;

        switch (pil) {
        case 1: // Cetak list yang ada
            cetakList();
            break;
        case 2: // Terima inputan list dari user
            cout << "Masukkan jumlah elemen yang mau diinputkan: ";
            cin >> jumlah;
            InputElementList(jumlah);
            break;
        case 3: // Fitur InsertFirst
            cout << "Inputkan nilai: ";
            cin >> value;
            InsertFirst(value);
            break;
        case 4: // Fitur InsertLast
            cout << "Inputkan nilai: ";
            cin >> value;
            InsertLast(value);
            break;
        case 5: // Fitur InsertAfter
            cout << "Inputkan key: ";
            cin >> key;
            cout << "Inputkan nilai elemen yang baru: ";
            cin >> value;
            InsertAfter(key, value);
            break;
        case 6: // Fitur DeleteFirst
            cout << "Kamu yakin mau hapus elemen pertama? (y/n): ";
            cin >> confirm;
            if(confirm == 'y' || confirm == 'Y') {
                DeleteFirst();
            }
            break;
        case 7: // Fitur DeleteLast
            cout << "Kamu yakin mau hapus elemen terakhir? (y/n): ";
            cin >> confirm;
            if(confirm == 'y' || confirm == 'Y') {
                DeleteLast();
            }
            break;
        case 8: // Fitur DeleteByValue
            cout << "Inputkan nilai yang mau dihapus: ";
            cin >> value;
            DeleteByValue(value);
            break;
        case 9: // Fitur ReversePrintList
            ReversePrintList();
            break;
        case 10: // Exit program
            cout << "Berhasil keluar dari program." << endl;
            break;
        default: // Cetak jika user input keliru
            cout << "Pilihan kamu tidak valid." << endl;
        }
    } while (pil != 10); // Akan terus looping hingga user pilih exit program
    
    return 0;
}
