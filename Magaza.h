#ifndef MAGAZA_H
#define MAGAZA_H

#include <vector>
#include <string>
#include "Mehsul.h"

class Magaza {
private:
    std::vector<Mehsul> mehsullar;
    const std::string faylAdi = "mehsullar.txt";

    Mehsul* tapId(int id);

public:
    void MehsulElaveEt();
    void MehsullariGoster() const;

    // ID ile axtaris (ad tekrarlana biler, ID yox)
    void Axtar(int id) const;
    bool MehsulAl(int id, int say);

    void Sirala();

    void FaylaYaz() const;
    void FayldanOxu();

    // Sinif-daxili menyu teskilati
    void Islet();
};

#endif
