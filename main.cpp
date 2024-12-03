#include <iostream>
#include "./deck.cpp"
#include "./hand.cpp"
#include "card.h"
#include <cstdlib> // Needed for rand() and srand()
#include <ctime> 
using namespace std;

int main(){
    cout<<"Doing a thing"<<endl;
    //calculate cpu answer
    std::srand(time(0));
    int cpuAnswer = rand()%10 + 11;
    //create game loop
    Deck* deck = new Deck();
    Hand* hand = new Hand();
    //draw cards
    Card card;
    card = deck->drawCard();
    hand->addCardToHand(card);

    bool gameOver = false;
    do{
        //draw a card
        Card cardt;
        cardt = deck->drawCard();
        cout << "drew card" << endl;
        hand->printHand();
        cout << "drew card" << endl;
        try{
            hand->addCardToHand(cardt);
        }catch(Error err){
            cout<< err.message <<endl;
            cout<< "you broke my game, leave"<<endl;
            gameOver = true;
            delete &err;
            break;
        }
        hand->printHand();
        if(hand->didBust()){
            cout<< "you lost LMAO"<<endl;
            gameOver = true;
        }else if(hand->numberOfCards() >4){
            cout<< "you won, with 5 card in your hand!!"<<endl;
            gameOver = true;
        }else{
            cout << "your hand is:"<< endl;
            hand->printHand();
            cout << "Hit?"<< endl;
            string ans;
            cin >> ans;
            if(ans == "Y" || ans == "y"){
                continue;
            }else{
                int finalTotal = hand->getTotal();
                cout<< "Your total is  : " << finalTotal<<endl;
                cout<< "House total is  : " << cpuAnswer<<endl;
                if( cpuAnswer > finalTotal){
                    cout<< "CPU won"<<endl;
                    gameOver = true;
                }else{
                    cout<< "You won"<<endl;
                    gameOver = true;
                }
            }
        }
    }while(!gameOver);

    // b.eval if lost or won
    return 0;
}