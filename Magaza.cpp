#include "Magaza.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

Mehsul* Magaza::tapId(int id) {
    for (auto& m : mehsullar)
        if (m.getId() == id) return &m;
    return nullptr;
}

void Magaza::MehsulElaveEt() {
    Mehsul m;
    m.MelumatAl();
    mehsullar.push_back(m);
    cout << "Mehsul elave edildi.\n";
}

void Magaza::MehsullariGoster() const {
    if (mehsullar.empty()) {
        cout << "Mehsul yoxdur!\n";
        return;
    }
    cout << "\n" << left << setw(6) << "ID" << setw(20) << "AD"
         << setw(10) << "QIYMET" << setw(10) << "STOK" << endl;
    cout << "-------------------------------------------\n";
    for (const auto& m : mehsullar)
        m.MelumatGoster();
}

void Magaza::Axtar(int id) const {
    for (const auto& m : mehsullar)
        if (m.getId() == id) {
            m.MelumatGoster();
            return;
        }
    cout << "Mehsul tapilmadi!\n";
}

bool Magaza::MehsulAl(int id, int say) {
    Mehsul* m = tapId(id);
    if (!m) {
        cout << "Mehsul tapilmadi!\n";
        return false;
    }
    if (m->stokdanCixar(say)) {
        cout << "Alis ugurlu!\n";
        return true;
    }
    return false;
}

void Magaza::Sirala() {
    sort(mehsullar.begin(), mehsullar.end(),
        [](const Mehsul& a, const Mehsul& b) {
            return a.getQiymet() < b.getQiymet();
        });
    cout << "Siralanma tamamlandi.\n";
}

void Magaza::FaylaYaz() const {
    ofstream file(faylAdi);
    for (const auto& m : mehsullar)
        m.FaylaYaz(file);
}

void Magaza::FayldanOxu() {
    ifstream file(faylAdi);
    if (!file) return;

    mehsullar.clear();
    Mehsul m;
    while (m.FayldanOxu(file)) {
        mehsullar.push_back(m);
        m = Mehsul();
    }
}

void Magaza::Islet() {
    FayldanOxu();

    int secim;
    do {
        cout << "\n===== MAGAZA SISTEMI =====\n";
        cout << "1. Mehsul elave et\n";
        cout << "2. Mehsullari goster\n";
        cout << "3. ID ile mehsul axtar\n";
        cout << "4. Mehsul al (ID ile)\n";
        cout << "5. Qiymete gore sirala\n";
        cout << "0. Cixis\n";
        cout << "Secim: ";
        cin >> secim;

        switch (secim) {
        case 1:
            MehsulElaveEt();
            break;
        case 2:
            MehsullariGoster();
            break;
        case 3: {
            int id;
            cout << "ID daxil et: ";
            cin >> id;
            Axtar(id);
            break;
        }
        case 4: {
            int id, say;
            cout << "ID: ";
            cin >> id;
            cout << "Miqdar: ";
            cin >> say;
            MehsulAl(id, say);
            break;
        }
        case 5:
            Sirala();
            break;
        case 0:
            cout << "Cixis edilir...\n";
            break;
        default:
            cout << "Sehv secim!\n";
        }
    } while (secim != 0);

    FaylaYaz();
}
