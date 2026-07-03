#ifndef MEHSUL_H
#define MEHSUL_H

#include <string>
#include <fstream>

class Mehsul {
private:
    int id;
    std::string ad;
    double qiymet;
    int stok;

public:
    Mehsul(int id = 0, std::string ad = "", double qiymet = 0.0, int stok = 0);

    int getId() const;
    std::string getAd() const;
    double getQiymet() const;
    int getStok() const;

    void MelumatAl();
    void MelumatGoster() const;

    bool stokdanCixar(int say);

    void FaylaYaz(std::ofstream& file) const;
    bool FayldanOxu(std::ifstream& file);
};

#endif
