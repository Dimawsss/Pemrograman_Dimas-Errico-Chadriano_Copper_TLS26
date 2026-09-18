#include <iostream>
#include <string>
using namespace std;

// Mengubah huruf menjadi nilai (A=1, B=2, ..., Z=26)
int hurufKeNilai(char c) {
    return (c - 'A') + 1;
}

// Mengubah nilai menjadi huruf, dengan perhitungan ulang jika > 26
char nilaiKeHuruf(int v) {
    // Jika melebihi 26, kembali berputar dari A
    v = ((v - 1) % 26) + 1;
    return 'A' + (v - 1);
}

// Fungsi untuk mengenkripsi pesan
string enkripsiPesan(string pesanAsli) {
    string pesanSandi = pesanAsli; // salin ukuran string
    int n = pesanAsli.length();

    // Huruf pertama tidak mengalami perubahan
    pesanSandi[0] = pesanAsli[0];

    // Mulai dari huruf kedua
    for (int i = 1; i < n; i++) {
        int nilaiSekarang   = hurufKeNilai(pesanAsli[i]);
        int nilaiSebelumnya = hurufKeNilai(pesanAsli[i - 1]);

        int hasil = nilaiSekarang + nilaiSebelumnya;

        // Jika hasil melebihi 26, kurangi 26 (perhitungan kembali dari A)
        if (hasil > 26) {
            hasil -= 26;
        }

        pesanSandi[i] = nilaiKeHuruf(hasil);
    }

    return pesanSandi;
}

int main() {
    string pesan;
    cout << "Masukkan pesan asli (huruf kapital tanpa spasi): ";
    cin >> pesan;

    string hasilSandi = enkripsiPesan(pesan);

    cout << "\nProses penyandian:\n";
    cout << "Pesan Asli  : " << pesan << endl;
    cout << "Pesan Sandi : " << hasilSandi << endl;

    return 0;
}