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
