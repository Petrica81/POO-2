#include "Casa.h"
#include "Locuinta.h"
#include <string>
#include <iostream>

int Casa::getsuprafataCurte() const{
    return this->suprafataCurte;
}

void Casa::setsuprafataCurte(int suprafataCurte_){
    this->suprafataCurte = suprafataCurte_;
}

Casa::Casa()
        : Locuinta(){
    this->suprafataCurte = 0;
}
Casa::Casa(std::string numeClient_, int suprafataUtila_, float discount_, int suprafataCurte_)
        : Locuinta(numeClient_, suprafataUtila_, discount_) {
    this->suprafataCurte = suprafataCurte_;
}

const TipLoc Casa::getType() const {
    return TipLoc::Casa;
}

const float Casa::calculchirie(int X, bool Y) const {
    float calcul = X*(this->getsuprafataUtila() +0.2*suprafataCurte) * (1-Y*this->getdiscount()/100.0);
    return calcul;
}

void Casa::print(std::ostream &os) const{
    std::cout<<"In casa ";
    Locuinta::print(os);
    std::cout<<"si are o curte de "<<suprafataCurte<<"mp.\n";
}

std::ostream &operator<<(std::ostream &os, Casa &c1){
    c1.print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Casa &c1){
    std::cout<<"Nume:";
    std::string buf;
    is>> buf;
    c1.setnumeClient(buf);
    std::cout<<"Suprafata utila:";
    int x;
    is>>x;
    c1.setsuprafataUtila(x);
    std::cout<<"Discount:";
    float y;
    is>>y;
    c1.setdiscount(y);
    std::cout<<"Suprafata curte:";
    is>>c1.suprafataCurte;
    return is;
}
