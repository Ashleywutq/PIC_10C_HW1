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
    srand(time(nullptr));
    
    //add two players
    Player P(100);
    int dealer=900;
    
    //start one round
    do{
        double player_point=0;
        double dealer_point=0;
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
        
        //ask player for cards
        Card firstcard;
        cout<<"Your cards:"<<endl;
        print_card(firstcard);
        player_point +=firstcard.get_point();
        player_hand.add(firstcard);
        cout<<"Your total is "<<player_point<<". Do you want another card (y/n)";
        string ans;
        cin>>ans;
        
        while (ans=="y"){
            //player draw a card, add to the hand
            Card newcard;
            cout<<"New card:"<<endl;
            print_card(newcard);
            player_point += newcard.get_point();
            player_hand.add(newcard);
            
            //print hand
            cout<<endl<<"Your cards:"<<endl;
            for (int i=0; i<player_hand.size();++i){
                print_card(player_hand.getcard(player_hand.size()-1-i));
            }
            
            //ask for continuation
            cout<<"Your total is "<<player_point<<". Do you want another card (y/n)?";
            cin>>ans;
        }
        
        //ask dealer for card
        Card dealerfirstcard;
        cout<<"Dealer's cards: ";
        print_card(dealerfirstcard);
        dealer_point +=dealerfirstcard.get_point();
        dealer_hand.add(dealerfirstcard);
        cout<<"The dealer's total is "<<dealer_point<<"."<<endl;
        
        while (dealer_point<5.5){
            //dealer draw
            Card newcard;
            cout<<endl<<"New card:"<<endl;
            print_card(newcard);
            dealer_point += newcard.get_point();
            dealer_hand.add(newcard);
            
            //print hand and total
            cout<<endl<<"Dealer's cards:"<<endl;
            for (int i=0; i<dealer_hand.size();++i){
                print_card(dealer_hand.getcard(i));
            }
            cout<<"The dealer's total is "<<dealer_point<<"."<<endl;
        }
        
        //determine result
        if (player_point>7.5){
            P.change_money(-1*betnum);
            dealer+=betnum;
            cout<<endl<<"Too bad. You lose "<<betnum<<"."<<endl<<endl;
        }else if (player_point<=7.5 && dealer_point>7.5){
            P.change_money(betnum);
            dealer-=betnum;
            cout<<endl<<"You win "<<betnum<<"."<<endl<<endl;
        }else if (7.5-player_point<7.5-dealer_point){
            P.change_money(betnum);
            dealer-=betnum;
            cout<<endl<<"You win "<<betnum<<"."<<endl<<endl;
        }else if (7.5-player_point>7.5-dealer_point){
            P.change_money(-1*betnum);
            dealer+=betnum;
            cout<<endl<<"Too bad. You lose "<<betnum<<"."<<endl<<endl;
        }else{
            cout<<endl<<"Tie!"<<endl<<endl;
        }
    }while(P.get_money()>0 && dealer>0);
    
    //exit sentence 
    if(P.get_money()==0){
        cout<<"You have $0. GAME OVER!"<<endl<<"Come back when you have more money."<<endl<<endl<<"Bye!";
    }else{
        cout<<"Congratulations. You beat the casino!"<<endl<<endl<<"Bye!";
    }
   
    
    
    return 0;
}







