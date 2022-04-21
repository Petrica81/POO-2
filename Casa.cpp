#include "Casa.h"
#include "Locuinta.h"
#include <string>
#include <iostream>
#include <utility>

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
        : Locuinta(std::move(numeClient_), suprafataUtila_, discount_) {
    this->suprafataCurte = suprafataCurte_;
}

TipLoc Casa::getType() const {
    return TipLoc::Casa;
}

int Casa::calculchirie(int X, bool Y) const {
    int calcul = (int)(X*(this->getsuprafataUtila() +0.2*suprafataCurte) * (1-Y*this->getdiscount()/100.0));
    std::cout<<this->getnumeClient()<<" plateste la chirie "<<calcul<<" de lei.\n";
    return calcul;
}

void Casa::print(std::ostream &os) const{
    os<<"In casa ";
    os<<"de "<<this->getsuprafataUtila()<<"mp cu "<<this->getdiscount()<<"% discount "<<"locuieste "<<this->getnumeClient()<<" ";
    os<<"si are o curte de "<<suprafataCurte<<"mp.\n";
}

std::ostream &operator<<(std::ostream &os,const Casa &c1){
    c1.print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Casa &c1){
    Locuinta *loc = &c1;
    is>>loc;
    std::cout<<"Suprafata curte:";
    is>>c1.suprafataCurte;
    return is;
}

Casa &Casa::operator=(const Casa &c){
    (*this).Locuinta::operator=(c);
    this->suprafataCurte = c.suprafataCurte;
    return *this;
}