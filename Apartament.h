#ifndef _APARTAMENT_H_
#define _APARTAMENT_H_
#include "Locuinta.h"
class Apartament : public Locuinta{
private:
    int etaj;
public:
    int getetaj() const;

    void setetaj(int etaj_);

    Apartament();

    Apartament(std::string numeClient_, int suprafataUtila_, float discount_, int etaj_);

    TipLoc getType() const override;

    int calculchirie(int X, bool Y)const override;

    void print(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os,const Apartament &a1);

    friend std::istream &operator>>(std::istream &is, Apartament &a1);

    Apartament& operator=(const Apartament &ap);
};

#endif
