#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan nilai K awal        : ";
    cin >> k;

    // Buat lingkaran astronot bernomor 1..N
    list<int> astronot;
    for (int i = 1; i <= n; i++) {
        astronot.push_back(i);
    }

    vector<int> urutanEliminasi;

    // Iterator awal menunjuk ke astronot nomor 1 (awal hitungan pertama)
    auto it = astronot.begin();

    while (astronot.size() > 1) {
        // Astronot yang ditunjuk 'it' dihitung sebagai hitungan ke-1,
        // jadi kita perlu melangkah (k-1) kali lagi untuk mencapai hitungan ke-K
        for (int langkah = 1; langkah < k; langkah++) {
            ++it;
            if (it == astronot.end()) {
                it = astronot.begin(); // lingkaran, kembali ke awal
            }
        }

        int nomorEliminasi = *it;
        urutanEliminasi.push_back(nomorEliminasi);

        // Simpan posisi setelah astronot yang dieliminasi (untuk mulai hitungan berikutnya)
        auto itBerikut = next(it);
        if (itBerikut == astronot.end()) {
            itBerikut = astronot.begin();
        }

        // Hapus astronot dari lingkaran
        it = astronot.erase(it);
        // Jika erase mengembalikan end(), samakan dengan itBerikut yang sudah dihitung
        it = itBerikut;

        // Update nilai K sesuai aturan
        if (nomorEliminasi % 2 == 0) {
            k++;              // genap -> K bertambah 1
        } else {
            k--;              // ganjil -> K berkurang 1
        }
        if (k < 2) {
            k = 2;            // K tidak boleh kurang dari 2
        }
    }

    // Output hasil
    cout << "\nUrutan astronot yang dieliminasi: ";
    for (int x : urutanEliminasi) {
        cout << x << " ";
    }
    cout << "\nAstronot yang bertahan (terakhir): " << astronot.front() << endl;

    return 0;
}