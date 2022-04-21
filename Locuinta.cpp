#include "Locuinta.h"
#include <iostream>
#include <string>
#include <utility>

class InvalidArea : public std::exception {
public:
    InvalidArea() = default;

    const char *what() const noexcept override {
        return "Invalid area!";
    }
};

std::string Locuinta::getnumeClient() const{
    return numeClient;
}

int Locuinta::getsuprafataUtila() const{
    return suprafataUtila;
}

float Locuinta::getdiscount() const{
    return discount;
}

void Locuinta::setnumeClient(std::string numeClient_){
    numeClient = std::move(numeClient_);
}

void Locuinta::setsuprafataUtila(int suprafataUtila_){
    if(suprafataUtila_ < 0)
        throw InvalidArea();
    else
        suprafataUtila = suprafataUtila_;
}

void Locuinta::setdiscount(float discount_){
    discount = discount_;
}

Locuinta::Locuinta(){
    numeClient = "\n";
    suprafataUtila = 0;
    discount = 0;
}

Locuinta::Locuinta(std::string numeClient_, int suprafataUtila_, float discount_)
                : numeClient(move(numeClient_)), suprafataUtila(suprafataUtila_), discount(discount_){
    if(suprafataUtila_ < 0)
        throw InvalidArea();
}

std::istream& operator>>(std::istream &is, Locuinta *l1){
    std::cout<<"Nume locuinta:";
    std::string buf;
    is>> buf;
    l1->setnumeClient(buf);
    std::cout<<"Suprafata utila:";
    is>>l1->suprafataUtila;
    std::cout<<"Discount:";
    is>>l1->discount;
    return is;
}

std::ostream& operator<<(std::ostream &os, Locuinta *l1){
    if(l1->numeClient[0] == '\n'){
        os<<"Not initialized\n";
        return os;
    }
   l1->print(os);
    return os;
}

bool Locuinta::operator==(const Locuinta &rhs) const{
    return (numeClient == rhs.numeClient) && (discount == rhs.discount) &&  (suprafataUtila == rhs.suprafataUtila);
}

Locuinta &Locuinta::operator=(const Locuinta &loc) {
    this->numeClient = loc.numeClient;
    this->suprafataUtila = loc.suprafataUtila;
    this->discount = loc.discount;
    return *this;
}

void Locuinta::print(std::ostream &os) const {
}

