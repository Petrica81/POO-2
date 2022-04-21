#include "Apartament.h"
#include "Locuinta.h"
#include <string>
#include <iostream>
#include <utility>

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
                : Locuinta(std::move(numeClient_), suprafataUtila_, discount_) {
    this->etaj = etaj_;
}

TipLoc Apartament::getType() const{
    return TipLoc::Apartament;
}

int Apartament::calculchirie(int X, bool Y)const {
    int calcul = (int)(X * this->getsuprafataUtila() * (1-Y * this->getdiscount()/100.0));
    std::cout<<this->getnumeClient()<<" plateste la chirie "<<calcul<<" de lei.\n";
    return calcul;
}
void Apartament::print(std::ostream &os) const{
    os<<"In apartamentul ";
    os<<"de "<<this->getsuprafataUtila()<<"mp cu "<<this->getdiscount()<<"% discount "<<"locuieste "<<this->getnumeClient()<<" ";
    os<<"si admira privelistea de la etajul "<<etaj<<".\n";
}

std::ostream &operator<<(std::ostream &os,const Apartament &a1){
    a1.print(os);
    return os;
}
std::istream &operator>>(std::istream &is, Apartament &a1){
    Locuinta *loc = &a1;
    is>>loc;
    std::cout<<"Etaj:";
    is>>a1.etaj;
    return is;
}
Apartament &Apartament::operator=(const Apartament &ap){
    (*this).Locuinta::operator=(ap);
    this->etaj = ap.etaj;
    return *this;
}





