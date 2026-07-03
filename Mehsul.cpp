#include "Mehsul.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

Mehsul::Mehsul(int id, string ad, double qiymet, int stok)
    : id(id), ad(ad), qiymet(qiymet), stok(stok) {}

int Mehsul::getId() const { return id; }
string Mehsul::getAd() const { return ad; }
double Mehsul::getQiymet() const { return qiymet; }
int Mehsul::getStok() const { return stok; }

void Mehsul::MelumatAl() {
    cout << "Mehsulun id: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Mehsulun adi: ";
    getline(cin, ad);

    cout << "Qiymet: ";
    cin >> qiymet;

    cout << "Stok: ";
    cin >> stok;
}

void Mehsul::MelumatGoster() const {
    cout << left << setw(6) << id
         << setw(20) << ad
         << setw(10) << qiymet
         << setw(10) << stok << endl;
}

// Aydin adlandirma + duzgun yoxlamalar
bool Mehsul::stokdanCixar(int say) {
    if (say <= 0) {
        cout << "Mehsul sayini duzgun daxil edin!\n";
        return false;
    }
    if (say > stok) {
        cout << "Kifayet qeder mehsul yoxdur!\n";
        return false;
    }
    stok -= say;
    return true;
}

void Mehsul::FaylaYaz(ofstream& file) const {
    file << id << endl;
    file << ad << endl;
    file << qiymet << endl;
    file << stok << endl;
}

bool Mehsul::FayldanOxu(ifstream& file) {
    if (!(file >> id)) return false;
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    if (!getline(file, ad)) return false;
    file >> qiymet;
    file >> stok;
    file.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}
