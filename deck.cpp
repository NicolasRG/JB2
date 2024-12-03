#include <string>
#include "card.h"
#include <iostream>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime> 

class Deck{
    std::vector<Card*> cards;
    
    void generateAllCards(){
        std::srand(time(0));
        std::cout << "generating cards"<<std::endl;
        //declare the face cards
        std::string suites[4] = {"♠️", "♣️", "❤️", "♦️"}; 
        //generate the number cards 
        int lazyCount = 0;
        for(int i = 2; i<11; i++){
            for(int j = 0; j<4; j++){
                std::string name = std::to_string(i)+suites[j] ;
                Card* card = new Card(i, name);
                cards.push_back(card);
                lazyCount++;
            }
        }
        std::cout << "added numbered cards"<<std::endl;
        //add face cards
        std::string faceCards[] = {"Jack", "Queen", "King"}; 
        for(int i = 0; i<3; i++){
            for(int j = 0; j<4; j++){
                std::string name = faceCards[i]+suites[j] ;
                Card* card = new Card(10, name, FACE);
                cards.push_back(card);
                lazyCount++;
            }
        }
        std::cout << "added face cards"<<std::endl;
        //add ace cards
        for(int i = 0; i<4; i++){
            std::string name = "Ace " + suites[i];
            Card* card = new Card(10, name, ACE);
            cards.push_back(card);
            lazyCount++;
        }
        std::cout << "added ace cards"<<std::endl;
        //add two jacks into the deck
        for(int i = 0; i<2; i++){
            std::string name = "Joker " + suites[i];
            Card* card =new Card(10, name, FACE);
            cards.push_back(card);
            lazyCount++;
        }
        std::cout << "added joker cards ♠️"<<std::endl;
        printDeck();
    }

    void shuffleCard(){
        
        std::cout<< "Shuffling Deck Deck" << std::endl;  
        for(int i = 0; i < 10000; i++){
            int swapa = std::rand() % 53;
            int swapb = std::rand() % 53;
            std::swap(cards[swapa], cards[swapb]);
        }
        std::cout<< "Shuffled Deck" << std::endl;  
    }

    void printDeck(){
        for(int i = 0; i < cards.size(); i++){
            std::cout << i <<" : " +(*cards[i]).getName() << std::endl;
        }
         std::cout << "Supreme cnch wrap" << std::endl;
    }

    public:
    Deck(){
        std::cout<< "Initing decl";
        generateAllCards();
        shuffleCard();
        printDeck();
        printDeck();
    }

    Card drawCard(){
        Card* card = cards.back();
        cards.pop_back();
        return *card;
    }

};