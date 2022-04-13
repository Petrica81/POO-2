#include <iostream>
#include <vector>
#include <memory>
#include "Locuinta.h"
#include "Apartament.h"
#include "Casa.h"
class AgentieImobiliara{
private:
    static std::vector<std::shared_ptr<Locuinta>> locuinte;

    AgentieImobiliara() = delete;
public:
    static const std::vector<std::shared_ptr<Locuinta>>& getLocuinte(){
        return locuinte;
    }

    static void addLocuinta(const std::shared_ptr<Locuinta> &loc) {
        locuinte.push_back(loc);
    }

    static void printAllLoc() {
        for(auto &loc : locuinte)
            std::cout<<*loc;
    }

    static void printAllCase() {
        for(auto &loc : locuinte){
            if(loc->getType() != TipLoc::Casa)
                continue;
            auto casa = std::dynamic_pointer_cast<Casa>(loc);
            std::cout << *casa;
        }
    }
    static void printAllApart() {
        for(auto &loc : locuinte){
            if(loc->getType() != TipLoc::Apartament)
                continue;
            auto apart = std::dynamic_pointer_cast<Apartament>(loc);
            std::cout << *apart;
        }
    }
};

std::vector<std::shared_ptr<Locuinta>> AgentieImobiliara::locuinte;
void spatiere(){
    std::cout<<"\n\n\n"<<std::endl;
}
void meniu();
void meniu(){
    int x;
    std::cout<<"\nAlegeti optiunea:\n0.Inchidere meniu!\n1.Inserare locuinta noua.\n2.Listare locuinte din agentie.\n3.Listare case.\n4.Listare apartamente.\n";
    std::cin>>x;
    //if(x == 1) inserare();
    if(x == 2) {
        spatiere();
        AgentieImobiliara::printAllLoc();
        system("PAUSE");
        meniu();
    }
    if(x == 3) {
        spatiere();
        AgentieImobiliara::printAllCase();
        system("PAUSE");
        meniu();
    }
    if(x == 4) {
        spatiere();
        AgentieImobiliara::printAllApart();
        system("PAUSE");
        meniu();
    }

}
int main() {
    std::cout<<"Doresti cateva locuintele deja create?\n1.Da, imi este lene sa inserez eu altele.\n0.Nu,vreau sa ma chinui.\n";
    int x;
    std::cin>>x;
    if(x == 1) {
        auto casa1 = std::make_shared<Casa>("Ion Creanga", 120, 5, 50);
        auto casa2 = std::make_shared<Casa>("Mihai Eminescu", 100, 0, 30);
        auto apart1 = std::make_shared<Apartament>("Alex Velea", 25, 7, 1);
        auto apart2 = std::make_shared<Apartament>("Andrei Maria", 30, 2, 10);
        AgentieImobiliara::addLocuinta(casa1);
        AgentieImobiliara::addLocuinta(casa2);
        AgentieImobiliara::addLocuinta(apart1);
        AgentieImobiliara::addLocuinta(apart2);
        spatiere();
    }
    meniu();

    return 0;
}
