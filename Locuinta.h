#ifndef _LOCUINTA_H_
#define _LOCUINTA_H_
#include <string>

enum class TipLoc {
    Casa,
    Apartament
};

class Locuinta {
private:
    std::string numeClient;
    int suprafataUtila;
    float discount;
public:
    std::string getnumeClient() const;

    int getsuprafataUtila() const;

    float getdiscount() const;

    void setnumeClient(std::string numeClient_);

    void setsuprafataUtila(int suprafataUtila_);

    void setdiscount(float discount_);

    Locuinta();

    Locuinta(std::string numeClient_, int suprafataUtila_, float discount_);

    friend std::istream& operator>>(std::istream &is, Locuinta *l1);

    friend std::ostream& operator<<(std::ostream &os, Locuinta &l1);

    bool operator==(const Locuinta &rhs) const;

    Locuinta& operator=(const Locuinta &loc);

    virtual void print(std::ostream &os) const;

    const virtual TipLoc getType() const = 0;

    const virtual int calculchirie(int X, bool Y)const = 0;

    virtual ~Locuinta() = default;

};

#endif