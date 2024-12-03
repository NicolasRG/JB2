#ifndef CARD_H
#define CARD_H

#include<iostream>

#include <string>
    enum CardType{
        ACE,
        NUMBER,
        FACE,
    };

    class Card {
        private:
        CardType type;
        // Attribute
        int value;
        std::string name;
        public:
        Card(int val = 1, std::string nam = "name", CardType cardType = NUMBER);
        void setValue(int val);
        int getValue();
        void setName(std::string val);
        std::string getName();
        CardType getType();
    };
#endif