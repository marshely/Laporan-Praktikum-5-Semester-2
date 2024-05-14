#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Struktur data untuk menyimpan data mahasiswa
struct Mahasiswa {
    int NIM;
    int nilai;
};

// Kelas hash table
class HashTable {
private:
    static const int hash_size = 10; // Ukuran tabel hash
    vector<list<Mahasiswa>> table; // Tabel hash

    // Fungsi hash untuk menghitung indeks dalam tabel hash
    int hashFunction(int NIM) {
        return NIM % hash_size;
    }

public:
    // Konstruktor
    HashTable() {
        table.resize(hash_size);
    }

    // Fungsi untuk menambahkan data mahasiswa baru
    void tambahData(int NIM, int nilai) {
        Mahasiswa mhs;
        mhs.NIM = NIM;
        mhs.nilai = nilai;
        int index = hashFunction(NIM);
        table[index].push_back(mhs);
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(int NIM) {
        int index = hashFunction(NIM);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->NIM == NIM) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariByNIM(int NIM) {
        int index = hashFunction(NIM);
        for (const auto &mhs : table[index]) {
            if (mhs.NIM == NIM) {
                cout << "Data ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data tidak ditemukan" << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    void cariByRange() {
        for (int i = 0; i < hash_size; ++i) {
            for (const auto &mhs : table[i]) {
                if (mhs.nilai >= 80 && mhs.nilai <= 90) {
                    cout << "NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                }
            }
        }
    }

    // Fungsi untuk menampilkan seluruh data mahasiswa
    void tampilkanSemuaData() {
        for (int i = 0; i < hash_size; ++i) {
            for (const auto &mhs : table[i]) {
                cout << "NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Menampilkan menu
    cout << "Menu:" << endl;
    cout << "1. Tambah data mahasiswa" << endl;
    cout << "2. Hapus data mahasiswa" << endl;
    cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
    cout << "4. Cari data mahasiswa berdasarkan rentang nilai (80 - 90)" << endl;
    cout << "5. Tampilkan semua data mahasiswa" << endl;
    cout << "0. Keluar" << endl;

    int choice;
    do {
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int NIM, nilai;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                hashTable.tambahData(NIM, nilai);
                break;
            }
            case 2: {
                int NIM;
                cout << "Masukkan NIM yang ingin dihapus: ";
                cin >> NIM;
                hashTable.hapusData(NIM);
                break;
            }
            case 3: {
                int NIM;
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> NIM;
                hashTable.cariByNIM(NIM);
                break;
            }
            case 4: {
                cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
                hashTable.cariByRange();
                break;
            }
            case 5: {
                cout << "Semua data mahasiswa:" << endl;
                hashTable.tampilkanSemuaData();
                break;
            }
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 0);

    return 0;
}
