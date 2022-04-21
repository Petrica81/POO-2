#ifndef _CASA_H_
#define _CASA_H_
#include <string>
#include "Locuinta.h"

class Casa : public Locuinta{
private:
    int suprafataCurte;
public:
    int getsuprafataCurte() const;

    void setsuprafataCurte(int suprafataCurte_);

    Casa();

    Casa(std::string numeClient_, int suprafataUtila_, float discount_, int suprafataCurte_);

    TipLoc getType() const override;

    int calculchirie(int X, bool Y)const override;

    void print(std::ostream &os) const override;

    friend std::ostream &operator<<(std::ostream &os,const Casa &c1);

    friend std::istream &operator>>(std::istream &is, Casa &c1);

    Casa& operator=(const Casa &c);
};

#endif
