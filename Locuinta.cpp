#include "Locuinta.h"
#include "Casa.h"
#include "Apartament.h"
#include <iostream>
#include <string>

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
    numeClient = numeClient_;
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

std::istream& operator>>(std::istream &is, Locuinta &l1){
    std::cout<<"Nume locuinta:";
    std::string buf;
    is>> buf;
    l1.setnumeClient(buf);
    std::cout<<"Suprafata utila:";
    is>>l1.suprafataUtila;
    std::cout<<"Discount:";
    is>>l1.discount;
    return is;
}

std::ostream& operator<<(std::ostream &os, Locuinta &l1){
    if(l1.numeClient.empty()){
        os<<"Not initialized\n";
        return os;
    }
    os<<"Nume client:"<<l1.numeClient<<"   Suprafata utila:"<<l1.suprafataUtila<<"   Discount:"<<l1.discount<<"\n";
    return os;
}

bool Locuinta::operator==(const Locuinta &rhs) const{
    return (numeClient.compare(rhs.numeClient) == 0) && (discount == rhs.discount) &&  (suprafataUtila == rhs.suprafataUtila);
}

void Locuinta::print(std::ostream &os) const {
    os <<"de "<<suprafataUtila<<"mp cu "<<discount<<"% discount "<<"locuieste "<<numeClient<<" ";
}

