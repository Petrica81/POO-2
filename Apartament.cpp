#include "Apartament.h"
#include "Locuinta.h"
#include <string>
#include <iostream>

int Apartament::getetaj() const{
    return this->etaj;
}

void Apartament::setetaj(int etaj_){
    this->etaj = etaj_;
}

Apartament::Apartament()
                : Locuinta(){
    this->etaj = 0;
}

Apartament::Apartament(std::string numeClient_, int suprafataUtila_, float discount_, int etaj_)
                : Locuinta(numeClient_, suprafataUtila_, discount_) {
    this->etaj = etaj_;
}

const TipLoc Apartament::getType() const{
    return TipLoc::Apartament;
}

const float Apartament::calculchirie(int X, bool Y)const {
    float calcul = X * this->getsuprafataUtila() * (1-Y * this->getdiscount()/100.0);
    return calcul;
}
void Apartament::print(std::ostream &os) const{
    std::cout<<"In apartamentul ";
    Locuinta::print(os);
    std::cout<<"si admira privelistea de la etajul "<<etaj<<".\n";
}

std::ostream &operator<<(std::ostream &os, Apartament &a1){
    a1.print(os);
    return os;
}
std::istream &operator>>(std::istream &is, Apartament &a1){
    std::cout<<"Nume:";
    std::string buf;
    is>> buf;
    a1.setnumeClient(buf);
    std::cout<<"Suprafata utila:";
    int x;
    is>>x;
    a1.setsuprafataUtila(x);
    std::cout<<"Discount:";
    float y;
    is>>y;
    a1.setdiscount(y);
    std::cout<<"Suprafata curte:";
    is>>a1.etaj;
    return is;
}





