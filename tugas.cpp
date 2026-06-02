#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;


class TokoElektronik {
private:
    array<string, 3> etalase;


public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&) {
            throw string("Gagal Mengambil Barang : Rak nomor " +
                         to_string(nomorRak) +
                         " kosong atau tidak tersedia!");
        }
    }
};


void tampilkanBarang() {
    ifstream file("gudang.txt");
    string barang;

    cout << "\n===== DAFTAR BARANG DI GUDANG =====\n";

    if (!file) {
        cout << "Belum ada data barang.\n";
        return;
    }

    int no = 1;
    while (getline(file, barang)) {
        cout << no++ << ". " << barang << endl;
    }

    file.close();
}

void tambahBarang() {
    ofstream file("gudang.txt", ios::app);

    string barang;
    cin.ignore();

    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan!\n";
}

void updateBarang() {
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "Pilih nomor barang yang ingin diubah : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan nama barang baru : ";
    getline(cin, data[nomor - 1]);

    ofstream out("gudang.txt");

    for (string item : data) {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil diperbarui!\n";
}


void hapusBarang() {
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }

    tampilkanBarang();

    int nomor;
    cout << "Pilih nomor barang yang ingin dihapus : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size()) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    data.erase(data.begin() + nomor - 1);

    ofstream out("gudang.txt");

    for (string item : data) {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil dihapus!\n";
}
int main() {

    TokoElektronik toko;

    int pilihan;

do {
        cout << "\n====================================";
        cout << "\n TOKO ELEKTRONIK GIBRAN JAYA";
        cout << "\n====================================\n";

        tampilkanBarang();

        cout << "\n============== MENU ==============\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

  switch (pilihan) {

        case 1:
            tambahBarang();
            break;

        case 2:
            tampilkanBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            cout << "\n===== SIMULASI ETALASE =====\n";

            // Skenario 1
            try {
                cout << "Rak 1 : "
                     << toko.ambilProduk(1)
                     << endl;
            }
            catch (string pesan) {
                cout << pesan << endl;
            }
            // Skenario 2
            try {
                cout << "Rak 5 : "
                     << toko.ambilProduk(5)
                     << endl;
            }
            catch (string pesan) {
                cout << pesan << endl;
            }
            

            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 0);

    return 0;
}
      
    

