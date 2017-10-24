//
//  Ashley Wu
//  siete_y_medio.cpp
//  PIC_10C_HW1
//
//  some suggested libraries plus a stub for the main routine.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"
using namespace std;

// Global constants (if any)


// print card in " 	Dos de copas   (Two of cups)." format
void print_card (Card C);


// Non member functions implementations
void print_card (Card C){
    string s_name = C.get_spanish_rank() + " de " + C.get_spanish_suit();
    string e_name = C.get_english_suit() + " of " + C.get_english_rank();
    cout<<"     "<<setw(20)<<left<<s_name<<"("<<e_name<<")."<<endl;
}

//main
int main(){
    //add two players
    Player P(100);
    int dealer=900;
    
    //start one round
    int player_point=0;
    int dealer_point=0;
    Hand player_hand;
    Hand dealer_hand;
    
    //get betnum input
    cout<<"You have $"<< P.get_money()<<". Enter bet:";
    int betnum;
    cin>>betnum;
    
    //if bet is invalid ask for input again
    while (P.check_bet(betnum) == false){
        cout<<"You have $"<< P.get_money()<<". Enter bet:";
        cin>>betnum;
    }
    
    //player draw a card, add to the hand
    Card newcard;
    cout<<"Your cards:"<<endl;
    print_card(newcard);
    player_point += newcard.get_point();
    player_hand.add(newcard);
    
    //ask for continuation
    cout<<"Your total is "<<player_point<<". Do you want another card (y/n)?";
    string ans;
    cin>>ans;
    
    //if ans is y do another end, if not end player's end
    if (ans == "y"){
        
        
        
        
    }
    
    
    
    return 0;
}







