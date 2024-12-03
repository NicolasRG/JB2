#include "card.h"
#include "bjerror.cpp"
#include <iostream>
#include <vector>

//std::string CARD_ERROR = "Issue with hand action";
// this is the class
class Hand{
    std::vector<Card*> cards;
    int total = 0;


    //algo will update the total to the highest possible value with out busting
    int calculateTotal(){
        int runningTotal = 0;
        int numberOfAces = 0;
        Card activeCard;
    
        for(int i = 0 ;cards.size() > i ; i++){
            activeCard =  (*cards[i]);
            if(activeCard.getType() == ACE){
                numberOfAces++;
            }else{
                runningTotal =runningTotal + activeCard.getValue();
            }
            std::cout<< runningTotal<<std::endl;
        }


        //if there are any aces calculate the max value it can be
        if(numberOfAces > 1){
            // two aces busts so 
            runningTotal += (numberOfAces-1);
            
        }

        if(numberOfAces > 0){
            //add 11 if it doesnt bust the hand
            if( runningTotal > 10){
                runningTotal += 1;
            }else{
                runningTotal += 11;
            }
        }

        total = runningTotal;
        return total;
    }

    public:

    int addCardToHand(Card card){
        //get value of card
        int val = card.getValue();
        int size = cards.size();
        std::cout << size <<std::endl;
        if(size > 5){
            //FXIME this can create a memroy leak LMAO::::::
            throw new Error("Issue wixwwth hand action", "Hand Is Full You Bum!!");
        }
        //store card
        std::cout << "New card : " << card.getName() << std::endl;
        cards.push_back(&card);
        // update total and return it
        calculateTotal();
        std::cout << "Total : " << total << std::endl;
        return total;
    }

    int getTotal(){
        return total;
    }

    int printHand(){
        int numberOfCards = cards.size();
        for(int i = 0 ;numberOfCards > i ; i++){
            std::cout << (*cards[i]).getName() + " : "<< cards[i] << std::endl;
        }
        return numberOfCards;
    }

    bool didBust(){
        return total > 21;
    }

    int numberOfCards(){
        return cards.size();
    }
};


