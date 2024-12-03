#include <string>
#include "card.h"

    Card::Card(int val, std::string nam, CardType cardType){
        value = val;
        name = nam;
        type = cardType;
    }

    // Class Member Method
    void Card::setValue(int val) {
     value = val;
    }

    int Card::getValue() {
     return value;
    }

    void Card::setName(std::string val) {
     name = val;
    }

    std::string Card::getName() {
     return name;
    }

    CardType Card::getType(){
        return type;
    }
