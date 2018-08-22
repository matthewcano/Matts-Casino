// This is a work in progress, 3 of the 5 desired games are completed

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <time.h>

using namespace std;

//for actual cards
struct cards {
 int value = 0;
 string name = "";
 string suit = "";
 int bjvalue = 0;
}; 

//for poker
struct hand {
 int value = 0;
 string name = "";
 string suit = "";
}; 

//for random shuffling 
int myrandom (int i) {
    return std::rand()%i; 
 }
 
//for roulette
void chart();

//for craps (can be used for programs pausing i.e. wait(#);  )   
void wait (int seconds){
	int endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

//********************* begin main ********************************

int main()
{

//mainframe variables
char leave;
int choose;
char playagain1, playagain2, playagain3, playagain4, playagain5;

//money variable
int money = 1000;

//card variables (poker and blackjack)
    cards card[52];
    vector<int> myvector;

//poker variables
    int handsize = 5;//needs to be local
    hand myhand[handsize];

    bool pair = false, 
         twopair = false, 
         toak = false, 
         straight = false, 
         flush = false, 
         fullhouse = false, 
         foak = false; 

    bool check1= false;
    bool check2= false;
    bool check3= false;
    bool check4= false;

//roullette variables
   int choice[5];
   int i = 0;
   int ball;
   int winnings = 0;
   string color; 
   string parity; 
   int row; 
   int column; 
   int half;  

//blackjack variables
    int dealertotal = 0;
    int playertotal = 0;

    char hit1, hit2, hit3;
 
//craps variables
int diceone; 
int dicetwo;
int rollnum = 0;
int bet[5];
int j = 0;

bool checker = true;
int size = 0;

   
//cards
    card[0].value = 1; card[0].name = "Ace"; card[0].suit = "Clubs"; card[0].bjvalue = 11;
    card[1].value = 2; card[1].name = "Two"; card[1].suit = "Clubs"; card[1].bjvalue = 2;
    card[2].value = 3; card[2].name = "Three"; card[2].suit = "Clubs"; card[2].bjvalue = 3;
    card[3].value = 4; card[3].name = "Four"; card[3].suit = "Clubs"; card[3].bjvalue = 4;
    card[4].value = 5; card[4].name = "Five"; card[4].suit = "Clubs"; card[4].bjvalue = 5;
    card[5].value = 6; card[5].name = "Six"; card[5].suit = "Clubs"; card[5].bjvalue = 6;
    card[6].value = 7; card[6].name = "Seven"; card[6].suit = "Clubs"; card[6].bjvalue = 7;
    card[7].value = 8; card[7].name = "Eight"; card[7].suit = "Clubs"; card[7].bjvalue = 8;
    card[8].value = 9; card[8].name = "Nine"; card[8].suit = "Clubs"; card[8].bjvalue = 9;
    card[9].value = 10; card[9].name = "Ten"; card[9].suit = "Clubs"; card[9].bjvalue = 10;
    card[10].value = 11; card[10].name = "Jack"; card[10].suit = "Clubs"; card[10].bjvalue = 10;
    card[11].value = 12; card[11].name = "Queen"; card[11].suit = "Clubs"; card[11].bjvalue = 10;
    card[12].value = 13; card[12].name = "King"; card[12].suit = "Clubs"; card[12].bjvalue = 10;

    card[13].value = 1; card[13].name = "Ace"; card[13].suit = "Diamonds"; card[13].bjvalue = 11;
    card[14].value = 2; card[14].name = "Two"; card[14].suit = "Diamonds"; card[14].bjvalue = 2;
    card[15].value = 3; card[15].name = "Three"; card[15].suit = "Diamonds"; card[15].bjvalue = 3;
    card[16].value = 4; card[16].name = "Four"; card[16].suit = "Diamonds"; card[16].bjvalue = 4;
    card[17].value = 5; card[17].name = "Five"; card[17].suit = "Diamonds"; card[17].bjvalue = 5;
    card[18].value = 6; card[18].name = "Six"; card[18].suit = "Diamonds"; card[18].bjvalue = 6;
    card[19].value = 7; card[19].name = "Seven"; card[19].suit = "Diamonds"; card[19].bjvalue = 7;
    card[20].value = 8; card[20].name = "Eight"; card[20].suit = "Diamonds"; card[20].bjvalue = 8;
    card[21].value = 9; card[21].name = "Nine"; card[21].suit = "Diamonds"; card[21].bjvalue = 9;
    card[22].value = 10; card[22].name = "Ten"; card[22].suit = "Diamonds"; card[22].bjvalue = 10;
    card[23].value = 11; card[23].name = "Jack"; card[23].suit = "Diamonds"; card[23].bjvalue = 10;
    card[24].value = 12; card[24].name = "Queen"; card[24].suit = "Diamonds"; card[24].bjvalue = 10;
    card[25].value = 13; card[25].name = "King"; card[25].suit = "Diamonds"; card[25].bjvalue = 10;
    
    card[26].value = 1; card[26].name = "Ace"; card[26].suit = "Hearts"; card[26].bjvalue = 11;
    card[27].value = 2; card[27].name = "Two"; card[27].suit = "Hearts"; card[27].bjvalue = 2;
    card[28].value = 3; card[28].name = "Three"; card[28].suit = "Hearts"; card[28].bjvalue = 3;
    card[29].value = 4; card[29].name = "Four"; card[29].suit = "Hearts"; card[29].bjvalue = 4;
    card[30].value = 5; card[30].name = "Five"; card[30].suit = "Hearts"; card[30].bjvalue = 5;
    card[31].value = 6; card[31].name = "Six"; card[31].suit = "Hearts"; card[31].bjvalue = 6;
    card[32].value = 7; card[32].name = "Seven"; card[32].suit = "Hearts"; card[32].bjvalue = 7;
    card[33].value = 8; card[33].name = "Eight"; card[33].suit = "Hearts"; card[33].bjvalue = 8;
    card[34].value = 9; card[34].name = "Nine"; card[34].suit = "Hearts"; card[34].bjvalue = 9;
    card[35].value = 10; card[35].name = "Ten"; card[35].suit = "Hearts"; card[35].bjvalue = 10;
    card[36].value = 11; card[36].name = "Jack"; card[36].suit = "Hearts"; card[36].bjvalue = 10;
    card[37].value = 12; card[37].name = "Queen"; card[37].suit = "Hearts"; card[37].bjvalue = 10;
    card[38].value = 13; card[38].name = "King"; card[38].suit = "Hearts"; card[38].bjvalue = 10;
    
    card[39].value = 1; card[39].name = "Ace"; card[39].suit = "Spades"; card[39].bjvalue = 11;
    card[40].value = 2; card[40].name = "Two"; card[40].suit = "Spades"; card[40].bjvalue = 2;
    card[41].value = 3; card[41].name = "Three"; card[41].suit = "Spades"; card[41].bjvalue = 3;
    card[42].value = 4; card[42].name = "Four"; card[42].suit = "Spades"; card[42].bjvalue = 4;
    card[43].value = 5; card[43].name = "Five"; card[43].suit = "Spades"; card[43].bjvalue = 5;
    card[44].value = 6; card[44].name = "Six"; card[44].suit = "Spades"; card[44].bjvalue = 6;
    card[45].value = 7; card[45].name = "Seven"; card[45].suit = "Spades"; card[45].bjvalue = 7;
    card[46].value = 8; card[46].name = "Eight"; card[46].suit = "Spades"; card[46].bjvalue = 8;
    card[47].value = 9; card[47].name = "Nine"; card[47].suit = "Spades"; card[47].bjvalue = 9;
    card[48].value = 10; card[48].name = "Ten"; card[48].suit = "Spades"; card[48].bjvalue = 10;
    card[49].value = 11; card[49].name = "Jack"; card[49].suit = "Spades"; card[49].bjvalue = 10;
    card[50].value = 12; card[50].name = "Queen"; card[50].suit = "Spades"; card[50].bjvalue = 10;
    card[51].value = 13; card[51].name = "King"; card[51].suit = "Spades"; card[51].bjvalue = 10;

//begin overall do while
do{

system("clear");

cout << endl;
cout << "**************WELCOME TO MATTS CASINO PLUS PLUS**************"<<endl<<endl;
cout << "Money: " << money << "$" <<endl <<endl;
cout << "1. Poker" << endl;
cout << "2. Roulette" << endl;
cout << "3. Black Jack" << endl;
cout << "4. Craps (in progress...)" << endl;
cout << "5. Baccarat (comming soon...)" << endl;
cout << "6. Quit"<<endl <<endl;
cout << "Please Enter a choice of game (a wrong choice will ask you to chose again):"<< endl;
cin >> choose;

//begin gamning do while
do{

//begin master switch
switch (choose)
{
//begin case 1 and poker game
case (1): 

system("clear"); 

    cout << endl << endl << "********WELCOME TO MATTS POKER GAME********"<< endl << endl << endl
         << "Cost per hand is 100$" << endl << endl 
         << "Your money: " << money << "$" << endl << endl;
    
 do{

    char playagain; 

     //reset hand
     myhand[0].name = ""; myhand[0].suit = ""; myhand[0].value = 0;
     myhand[1].name = ""; myhand[1].suit = ""; myhand[1].value = 0;
     myhand[2].name = ""; myhand[2].suit = ""; myhand[2].value = 0;
     myhand[3].name = ""; myhand[3].suit = ""; myhand[3].value = 0;
     myhand[4].name = ""; myhand[4].suit = ""; myhand[4].value = 0;
             
    money = money - 100;         
             
    int discard;

    srand (time(NULL));

    for (int i=0; i<52; ++i) myvector.push_back(i);

    random_shuffle ( myvector.begin(), myvector.end(), myrandom );

//     for (vector<int>::iterator x=myvector.begin(); x!=myvector.end(); ++x)
//      {}  
//      this was for troubleshooting the shuffled deck
      
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
     
    cout << endl << "which card(s) would you like to discard?? " << endl;
    cout << endl << "EXAMPLE: if you want to discard 1 & 3 & 4 enter: 134" << endl;
    cout << "********** if you want to keep the hand as is use 0 ************" << endl << endl;
    cin >> discard;

    switch (discard){
        case (0) :
        break;
        case(1):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(2):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(3):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[5]].name; myhand[2].suit = card[myvector[5]].suit; myhand[2].value = card[myvector[5]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(4):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[5]].name; myhand[3].suit = card[myvector[5]].suit; myhand[3].value = card[myvector[5]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(5):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;

     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[5]].name; myhand[4].suit = card[myvector[5]].suit; myhand[4].value = card[myvector[5]].value;
        break;
        case(12):
        case(21):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(13):
        case(31):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(14):
	case(41):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[6]].name; myhand[3].suit = card[myvector[6]].suit; myhand[3].value = card[myvector[6]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(15):
	case(51):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[6]].name; myhand[4].suit = card[myvector[6]].suit; myhand[4].value = card[myvector[6]].value;
        break;
        case(23):
	case(32):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(24):
	case(42):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[6]].name; myhand[3].suit = card[myvector[6]].suit; myhand[3].value = card[myvector[6]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(25):
	case(52):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[6]].name; myhand[4].suit = card[myvector[6]].suit; myhand[4].value = card[myvector[6]].value;
        break;
        case(34):
	case(43):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 4 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[5]].name; myhand[2].suit = card[myvector[5]].suit; myhand[2].value = card[myvector[5]].value;
     myhand[3].name = card[myvector[6]].name; myhand[3].suit = card[myvector[6]].suit; myhand[3].value = card[myvector[6]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(35):
	case(53):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[5]].name; myhand[2].suit = card[myvector[5]].suit; myhand[2].value = card[myvector[5]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[6]].name; myhand[4].suit = card[myvector[6]].suit; myhand[4].value = card[myvector[6]].value;
        break;
        case(45):
	case(54):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 5 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[5]].name; myhand[3].suit = card[myvector[5]].suit; myhand[3].value = card[myvector[5]].value;
     myhand[4].name = card[myvector[6]].name; myhand[4].suit = card[myvector[6]].suit; myhand[4].value = card[myvector[6]].value;
        break;
        case(123):
        case(132):
        case(213):
        case(231):
        case(312):
        case(321):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[7]].name; myhand[2].suit = card[myvector[7]].suit; myhand[2].value = card[myvector[7]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(124):
	case(142):
	case(214):
	case(241):
	case(412):
	case(421):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[7]].name; myhand[3].suit = card[myvector[7]].suit; myhand[3].value = card[myvector[7]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(125):
	case(152):
	case(215):
	case(251):
	case(512):
	case(521):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[7]].name; myhand[4].suit = card[myvector[7]].suit; myhand[4].value = card[myvector[7]].value;
        break;
        case(134):
	case(143):
	case(314):
	case(341):
	case(413):
	case(431):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[7]].name; myhand[3].suit = card[myvector[7]].suit; myhand[3].value = card[myvector[7]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(135):
	case(153):
	case(315):
	case(351):
	case(513):
	case(531):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[7]].name; myhand[4].suit = card[myvector[7]].suit; myhand[4].value = card[myvector[7]].value;
        break;
        case(145):
	case(154):
	case(415):
	case(451):
	case(514):
	case(541):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 5 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[6]].name; myhand[3].suit = card[myvector[6]].suit; myhand[3].value = card[myvector[6]].value;
     myhand[4].name = card[myvector[7]].name; myhand[4].suit = card[myvector[7]].suit; myhand[4].value = card[myvector[7]].value;
        break;
        case(234):
	case(243):
	case(324):
	case(342):
	case(423):
	case(432):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[7]].name; myhand[3].suit = card[myvector[7]].suit; myhand[3].value = card[myvector[7]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(235):
	case(253):
	case(325):
	case(352):
	case(523):
	case(532):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[7]].name; myhand[4].suit = card[myvector[7]].suit; myhand[4].value = card[myvector[7]].value;
        break;
        case(245):
	case(254):
	case(425):
	case(452):
	case(524):
	case(542):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 5 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[6]].name; myhand[3].suit = card[myvector[6]].suit; myhand[3].value = card[myvector[6]].value;
     myhand[4].name = card[myvector[7]].name; myhand[4].suit = card[myvector[7]].suit; myhand[4].value = card[myvector[7]].value;
        break;
        case(345):
	case(354):
	case(435):
	case(453):
	case(534):
	case(543):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 4 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 5 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[5]].name; myhand[2].suit = card[myvector[5]].suit; myhand[2].value = card[myvector[5]].value;
     myhand[3].name = card[myvector[6]].name; myhand[3].suit = card[myvector[6]].suit; myhand[3].value = card[myvector[6]].value;
     myhand[4].name = card[myvector[7]].name; myhand[4].suit = card[myvector[7]].suit; myhand[4].value = card[myvector[7]].value;
        break;
        case(1234):
	case(1243):
	case(1342):
	case(1324):
	case(1423):
	case(1432):
	case(2134):
	case(2143):
	case(2314):
	case(2341):
	case(2413):
	case(2431):
	case(3124):
	case(3142):
	case(3214):
	case(3241):
	case(3421):
	case(3412):
	case(4123):
	case(4132):
	case(4231):
	case(4213):
	case(4312):
	case(4321):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 4 : " << card[myvector[8]].name << " of " << card[myvector[8]].suit << endl;
     cout << "card 5 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[7]].name; myhand[2].suit = card[myvector[7]].suit; myhand[2].value = card[myvector[7]].value;
     myhand[3].name = card[myvector[8]].name; myhand[3].suit = card[myvector[8]].suit; myhand[3].value = card[myvector[8]].value;
     myhand[4].name = card[myvector[4]].name; myhand[4].suit = card[myvector[4]].suit; myhand[4].value = card[myvector[4]].value;
        break;
        case(2345):
	case(2354):
	case(2435):
	case(2453):
	case(2534):
	case(2543):
	case(3245):
	case(3254):
	case(3425):
	case(3452):
	case(3524):
	case(3542):
	case(4235):
	case(4253):
	case(4352):
	case(4325):
	case(4532):
	case(4523):
	case(5432):
	case(5423):
	case(5342):
	case(5324):
	case(5234):
	case(5243):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 5 : " << card[myvector[8]].name << " of " << card[myvector[8]].suit << endl;
     
     myhand[0].name = card[myvector[0]].name; myhand[0].suit = card[myvector[0]].suit; myhand[0].value = card[myvector[0]].value;
     myhand[1].name = card[myvector[5]].name; myhand[1].suit = card[myvector[5]].suit; myhand[1].value = card[myvector[5]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[7]].name; myhand[3].suit = card[myvector[7]].suit; myhand[3].value = card[myvector[7]].value;
     myhand[4].name = card[myvector[8]].name; myhand[4].suit = card[myvector[8]].suit; myhand[4].value = card[myvector[8]].value;
        break;
        case(1245):
	case(1254):
	case(1425):
	case(1452):
	case(1524):
	case(1542):
	case(2145):
	case(2154):
	case(2451):
	case(2415):
	case(2541):
	case(2514):
	case(4125):
	case(4152):
	case(4215):
	case(4251):
	case(4521):
	case(4512):
	case(5421):
	case(5412):
	case(5124):
	case(5142):
	case(5214):
	case(5241):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 4 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 5 : " << card[myvector[8]].name << " of " << card[myvector[8]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[2]].name; myhand[2].suit = card[myvector[2]].suit; myhand[2].value = card[myvector[2]].value;
     myhand[3].name = card[myvector[7]].name; myhand[3].suit = card[myvector[7]].suit; myhand[3].value = card[myvector[7]].value;
     myhand[4].name = card[myvector[8]].name; myhand[4].suit = card[myvector[8]].suit; myhand[4].value = card[myvector[8]].value;
        break;
        case(1345):
	case(1354):
	case(1435):
	case(1453):
	case(1543):
	case(1534):
	case(3145):
	case(3154):
	case(3415):
	case(3451):
	case(3541):
	case(3514):
	case(4135):
	case(4153):
	case(4315):
	case(4351):
	case(4513):
	case(4531):
	case(5431):
	case(5413):
	case(5314):
	case(5341):
	case(5134):
	case(5143):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 4 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 5 : " << card[myvector[8]].name << " of " << card[myvector[8]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[1]].name; myhand[1].suit = card[myvector[1]].suit; myhand[1].value = card[myvector[1]].value;
     myhand[2].name = card[myvector[6]].name; myhand[2].suit = card[myvector[6]].suit; myhand[2].value = card[myvector[6]].value;
     myhand[3].name = card[myvector[7]].name; myhand[3].suit = card[myvector[7]].suit; myhand[3].value = card[myvector[7]].value;
     myhand[4].name = card[myvector[8]].name; myhand[4].suit = card[myvector[8]].suit; myhand[4].value = card[myvector[8]].value;
        break;
        case(1235):
	case(1253):
	case(1325):
	case(1352):
	case(1532):
	case(1523):
	case(2135):
	case(2153):
	case(2315):
	case(2351):
	case(2513):
	case(2531):
	case(3125):
	case(3152):
	case(3251):
	case(3215):
	case(3512):
	case(3521):
	case(5123):
	case(5132):
	case(5213):
	case(5231):
	case(5312):
	case(5321):
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 2 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     cout << "card 3 : " << card[myvector[7]].name << " of " << card[myvector[7]].suit << endl;
     cout << "card 4 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 5 : " << card[myvector[8]].name << " of " << card[myvector[8]].suit << endl;
     
     myhand[0].name = card[myvector[5]].name; myhand[0].suit = card[myvector[5]].suit; myhand[0].value = card[myvector[5]].value;
     myhand[1].name = card[myvector[6]].name; myhand[1].suit = card[myvector[6]].suit; myhand[1].value = card[myvector[6]].value;
     myhand[2].name = card[myvector[7]].name; myhand[2].suit = card[myvector[7]].suit; myhand[2].value = card[myvector[7]].value;
     myhand[3].name = card[myvector[3]].name; myhand[3].suit = card[myvector[3]].suit; myhand[3].value = card[myvector[3]].value;
     myhand[4].name = card[myvector[8]].name; myhand[4].suit = card[myvector[8]].suit; myhand[4].value = card[myvector[8]].value;
        break;
    }//end of card exchange switch 
    
    //Start checking hands 
    //PAIR
   if (myhand[0].name==myhand[1].name || 
       myhand[0].name==myhand[2].name || 
       myhand[0].name==myhand[3].name || 
       myhand[0].name==myhand[4].name ||
       myhand[1].name==myhand[2].name || 
       myhand[1].name==myhand[3].name || 
       myhand[1].name==myhand[4].name ||
       myhand[2].name==myhand[3].name || 
       myhand[2].name==myhand[4].name ||
       myhand[3].name==myhand[4].name)
       { pair = true; }
        
    //2 PAIR
   if ( (myhand[0].name==myhand[1].name && myhand[2].name==myhand[3].name) ||
        (myhand[0].name==myhand[1].name && myhand[2].name==myhand[4].name) ||
        (myhand[0].name==myhand[1].name && myhand[3].name==myhand[4].name) ||
        (myhand[0].name==myhand[2].name && myhand[1].name==myhand[3].name) ||
        (myhand[0].name==myhand[2].name && myhand[1].name==myhand[4].name) ||
        (myhand[0].name==myhand[2].name && myhand[3].name==myhand[4].name) ||
        (myhand[0].name==myhand[3].name && myhand[1].name==myhand[2].name) ||
        (myhand[0].name==myhand[3].name && myhand[1].name==myhand[4].name) ||
        (myhand[0].name==myhand[3].name && myhand[2].name==myhand[4].name) ||
        (myhand[0].name==myhand[4].name && myhand[1].name==myhand[2].name) ||
        (myhand[0].name==myhand[4].name && myhand[1].name==myhand[3].name) ||
        (myhand[0].name==myhand[4].name && myhand[2].name==myhand[3].name) ||
        (myhand[1].name==myhand[2].name && myhand[0].name==myhand[3].name) ||
        (myhand[1].name==myhand[2].name && myhand[0].name==myhand[4].name) ||
        (myhand[1].name==myhand[2].name && myhand[3].name==myhand[4].name) ||
        (myhand[1].name==myhand[3].name && myhand[0].name==myhand[2].name) ||
        (myhand[1].name==myhand[3].name && myhand[0].name==myhand[4].name) ||
        (myhand[1].name==myhand[3].name && myhand[2].name==myhand[4].name) ||
        (myhand[1].name==myhand[4].name && myhand[0].name==myhand[2].name) ||
        (myhand[1].name==myhand[4].name && myhand[0].name==myhand[3].name) ||
        (myhand[1].name==myhand[4].name && myhand[2].name==myhand[3].name)  )
        { twopair = true; } 

    //3 of a kind 
    if( (myhand[0].name==myhand[1].name && myhand[1].name==myhand[2].name) ||
        (myhand[0].name==myhand[2].name && myhand[2].name==myhand[3].name) ||
        (myhand[0].name==myhand[3].name && myhand[3].name==myhand[4].name) ||
        (myhand[1].name==myhand[2].name && myhand[2].name==myhand[3].name) ||
        (myhand[1].name==myhand[3].name && myhand[3].name==myhand[4].name) ||
        (myhand[0].name==myhand[2].name && myhand[2].name==myhand[4].name) ||
        (myhand[0].name==myhand[1].name && myhand[1].name==myhand[3].name) ||
        (myhand[0].name==myhand[1].name && myhand[1].name==myhand[4].name) ||
        (myhand[1].name==myhand[2].name && myhand[2].name==myhand[4].name) ||
        (myhand[2].name==myhand[3].name && myhand[3].name==myhand[4].name) )
        { toak = true; }
          
    //4 of a kind
    if( (myhand[0].name==myhand[1].name && myhand[1].name==myhand[2].name && myhand[2].name==myhand[3].name) || 
        (myhand[1].name==myhand[2].name && myhand[2].name==myhand[3].name && myhand[3].name==myhand[4].name) || 
        (myhand[0].name==myhand[2].name && myhand[2].name==myhand[3].name && myhand[3].name==myhand[4].name) || 
        (myhand[0].name==myhand[1].name && myhand[1].name==myhand[2].name && myhand[2].name==myhand[4].name) || 
        (myhand[0].name==myhand[1].name && myhand[1].name==myhand[3].name && myhand[3].name==myhand[4].name) ) 
        { foak = true; }
        
    //flush
    if( myhand[0].suit == myhand[1].suit && myhand[1].suit == myhand[2].suit && 
        myhand[2].suit == myhand[3].suit && myhand[3].suit == myhand[4].suit)
        { flush = true; }
         
    //straight
    const int SIZE = 5;
    int arr[SIZE];
    arr[0] = myhand[0].value;
    arr[1] = myhand[1].value;
    arr[2] = myhand[2].value;
    arr[3] = myhand[3].value;
    arr[4] = myhand[4].value;
    int min = 0;

    for (int i=0; i < 5; i++){
    if (arr[i] < min)
    min = arr[i];}

    //make ace high if min = 10 
    if ( min == 10 && myhand[0].value == 1)
          myhand[0].value = 14;

    if ( min == 10 && myhand[1].value == 1)
          myhand[1].value = 14;

    if ( min == 10 && myhand[2].value == 1)
          myhand[2].value = 14;
     
    if ( min == 10 && myhand[3].value == 1)
          myhand[3].value = 14;

    if ( min == 10 && myhand[4].value == 1)
          myhand[4].value = 14;

    min = min +1;

    for (int i = 0; i < 5 ; i++)
    {if (min == arr[i])
    check1 = true;}
    
    min = min + 1;
    
    for (int i = 0; i < 5 ; i++)
    {if (min == arr[i])
    check2 = true;}
    
    min = min + 1;
    
    for (int i = 0; i < 5 ; i++)
    {if (min == arr[i])
    check3 = true;}
    
    min = min + 1;
    
    for (int i = 0; i < 5 ; i++)
    {if (min == arr[i])
    check4 = true;}

    if (check1 == true && check2 ==true && check3==true && check4==true)
    { straight = true;  }

    //end hand checks, starts evaluating hand and awards $

    if (pair && !toak && !twopair && !fullhouse && !foak)
     {cout << endl << "Pair" << endl;
     money = money + 100;
     cout << endl << "you won 100 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (pair && toak && !twopair && !foak && !fullhouse)
     {cout << endl << "3 of a kind" << endl;
     money = money + 300;
     cout << endl << "you won 300 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (pair && toak && foak && !fullhouse && !twopair)
     {cout << endl << "4 of a kind" << endl;
     money = money + 500;
     cout << endl << "you won 500 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}

     else if (fullhouse && pair && toak && twopair && !foak)
     {cout << endl << "full house" << endl;
     money = money + 1000;
     cout << endl << "you won 1,000 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (twopair && pair && !toak && !foak && !fullhouse)
     {cout << endl << "2 pair" << endl;
     money = money + 5000;
     cout << endl << "you won 5,000 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (straight && !flush && !pair && !toak && !foak && !fullhouse && !twopair)
     {cout << endl << "straight" << endl;
     money = money + 10000;
     cout << endl << "you won 10,000 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (flush)
     {cout << endl << "flush" << endl;
     money = money + 50000;
     cout << endl << "you won 50,000 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (straight && flush && min < 10)
     {cout << endl << "straight flush" << endl;
     money = money + 125000;
     cout << endl << "you won 125,000 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else if (straight && flush && min == 10)
     {cout << endl << "Royal Flush" << endl;
     money = money + 1000000;
     cout << endl << "you won 1,000,000 $" << endl;
     cout << endl << "Your Money : " << money << "$" << endl;}
     
     else cout << endl << "nothing, you lose "<< endl << endl 
               << "Your Money : " << money << "$" << endl << endl; 
     
    //reset variables back to false so next hand works
     check1 = false;
     check2 = false;
     check3 = false;
     check4 = false;
     pair = false; 
     twopair = false; 
     toak = false;
     straight = false; 
     flush = false;
     fullhouse = false; 
     foak = false; 

     cout << endl << "Would you like to cash out (exit) y for yes n for no" << endl;
           cin>> playagain1;

system("clear");

    }while (playagain1 == 'n');

           break;//end of poker game
           
//begin case 2 and roulette game
 case (2):    

system("clear");

    cout << endl << endl << "*********WELCOME TO MATTS ROULETTE GAME*********"<< endl
         << endl << endl 
         << "Cost per bet is 100$" << endl << endl 
         << "Maximum of 5 bets" << endl << endl
         << "Your money: " << money << "$" << endl << endl;

do {
    
   char playagain;

   chart();
   
 // if statemenets if user has less that 500$ left (not implimented yet)
   
    bool check = true;
    int size = 0;
   
   if (check)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> choice[i]; size++; money = money - 100;
     if (choice[i] == 0)
     {check = false;}}
      
     i++;
    
   if (check)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> choice[i];size++; money = money - 100;
     if (choice[i] == 0)
     {check = false;size--;}}
     
    i++;
     
   if (check)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> choice[i];size++; money = money - 100;
      if (choice[i] == 0)
     {check = false;size--;}}

     i++;

   if (check)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> choice[i];  size++; money = money - 100;
     if (choice[i] == 0)
     {check = false;size--;}}

     i++;

   if (check)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> choice[i];size++; money = money - 100;}
 
    cout << endl; 
 
    for (int i = 0 ; i < size ; i++)
    {cout << "you bet " << choice[i] << endl;}
         
   srand (time(NULL));
    ball = rand() % 38 + 1; 
  
//  ball = 25; //for testing 
    

   cout << endl << endl << "Ball Spinning . . ." << endl;

   wait(4);
 
    cout <<  endl << "the ball landed on : "
         << ball
         << " !!!" << endl;
 
    switch (ball)
{
    case (1):
    color = "red"; parity = "odd";row = 1;column = 1;half = 1;  
    break;
    
    case (2):
    color = "blk";parity = "even";row = 2;column = 1;half = 1;
    break;
    
    case (3):
    color = "red";parity = "odd";row = 3;column = 1;half = 1;
    break;
    
    case (4):
    color = "blk";parity = "even";row = 1;column = 1;half = 1;
    break;
    
    case (5):
    color = "red";parity = "odd";row = 2;column =1;half = 1;
    break;
    
    case (6):
    color ="blk";parity = "even";row = 3;column = 1;half = 1;
    break;
    
    case (7):
    color ="red";parity = "odd";row = 1;column =1;half = 1;
    break;
    
    case (8):
    color ="blk";parity ="even";row = 2;column =1;half = 1;
    break;
    
    case (9):
    color ="red";parity = "odd";row = 3;column =1;half = 1;
    break;
    
    case (10):
    color ="blk";parity = "even";row = 1;column =1;half = 1;
    break;
    
    case (11):
    color = "blk";parity = "odd";row = 2;column =1;half = 1;
    break;
    
    case (12):
    color = "red";parity = "even";row = 1;column = 3;half = 1;
    break;
    
    case (13):
    color = "blk";parity = "odd";row = 1;column = 2;half = 1;
    break;
    
    case (14):
    color = "red";parity = "even";row = 2;column =2;half = 1;
    break;
    
    case (15):
    color = "blk";parity = "odd";row = 3;column =2;half = 1;
    break;
    
    case (16):
    color = "red";parity = "even";row = 1;column =2;half = 1;
    break;
    
    case (17):
    color ="blk";parity = "odd";row = 2;column =2;half = 1;
    break;
    
    case (18):
    color = "red";parity = "even";row = 3;column =2;half = 1;
    break;
    
    case (19):
    color ="red";parity = "odd";row = 1;column =2;half = 2;
    break;
    
    case (20):
    color = "blk";parity = "even";row = 2;column =2;half = 2;
    break;
    
    case (21):
    color = "red";parity = "odd";row = 3;column =2;half = 2;
    break;
    
    case (22):
    color = "blk";parity = "even";row = 1;column =2;half = 2;
    break;
    
    case (23):
    color ="red";parity = "odd";row = 2;column =2;half = 2;
    break;
    
    case (24):
    color ="blk";parity = "even";row = 3;column =2;half = 2;
    break;
    
    case (25):
    color ="red";parity = "odd";row = 1;column =3;half = 2;
    break;
    
    case (26):
    color = "blk";parity = "even";row = 2;column =3;half = 2;
    break;
    
    case (27):
    color ="red";parity = "odd";row = 3;column =3;half = 2;
    break;
    
    case (28):
    color ="blk";parity = "even";row = 1;column =3;half = 2;
    break;
    
    case (29):
    color ="blk";parity = "odd";row = 2;column =3;half = 2;
    break;
    
    case (30):
    color ="red";parity = "even";row = 3;column =3;half = 2;
    break;
    
    case (31):
    color = "blk";parity = "odd";row = 1;column =3;half = 2;
    break;
    
    case (32):
    color = "red";parity = "even";row = 2;column =3;half = 2;
    break;
    
    case (33):
    color ="blk";parity = "odd";row = 3;column =3;half = 2;
    break;
    
    case (34):
    color ="red";parity = "even";row = 1;column =3;half = 2;
    break;
    
    case (35):
    color ="blk";parity = "odd";row = 2;column =3;half = 2;
    break;
    
    case (36):
    color ="red";parity = "even";row = 3;column =3;half = 2;
    break;
    
    case (37):
    color ="none";parity = "none";row = 0;column =0;half = 0;
    break;
    
    case (38):
    color ="none";parity = "none";row = 0;column =0;half = 0;
    break;
}//end switch statement for roulette

    i = 0;

    for (int i = 0 ; i < size ; i++)
    {
    if (choice[i] == ball)
       {cout<< endl << " YOU GUESSED IT WITH!!!! YOU WIN 35,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
        money = money + 35000;}

    if (choice[i] == 39 && column == 1 && ( ball >=1 && ball <= 12))
       {cout << endl << " YOU GUESSED THE 12 !!! YOU WIN 2,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
        money = money + 2000;}
        
    if (choice[i] == 40 && column == 2 && ( ball >=13 && ball <= 24))
       {cout << endl << " YOU GUESSED THE 12 !!! YOU WIN 2,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
        money = money + 2000;}
      
    if (choice[i] == 41 && column == 3 && ( ball >=25 && ball <= 36))
       {cout << endl <<  " YOU GUESSED THE 12 !!! YOU WIN 2,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
        money = money + 2000;}  
        
    if (choice[i] == 42 && row == 1 &&
         (ball == 1 || ball == 4 || ball == 7 || ball == 10 ||
          ball == 13 || ball == 16 || ball == 19 || ball == 22 ||
          ball == 25 || ball == 28 || ball == 31 || ball == 34 ))
          {cout << endl << " YOU GUESSED THE ROW!!! YOU WIN 2,000$ " << endl;
          money = money + 2000;}
          
    if (choice[i] == 43 && row == 2 &&
         (ball == 2 || ball == 5 || ball == 8 || ball == 11 ||
          ball == 14 || ball == 17 || ball == 20 || ball == 23 ||
          ball == 26 || ball == 29 || ball == 32 || ball == 35 ))
          {cout << endl << " YOU GUESSED THE ROW!!! YOU WIN 2,000$ " << endl;
          cout << endl << " your correct guess was :" << choice[i] << endl;
          money = money + 2000;}
          
    if (choice[i] == 44 && row == 3 &&
         (ball == 3 || ball == 6 || ball == 9 || ball == 12 ||
          ball == 15 || ball == 18 || ball == 21 || ball == 24 ||
          ball == 27 || ball == 30 || ball == 33 || ball == 36 ))
          {cout << endl << " YOU GUESSED THE ROW!!! YOU WIN 2,000$ " << endl;
           cout << endl << " your correct guess was :" << choice[i] << endl;
          money = money + 2000;}
        
    if (choice[i] == 45 && color == "red")
        {cout << endl << " YOU GUESSED THE COLOR !! YOU WIN 1,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
         money = money + 1000;}
         
    if (choice[i] == 46 && color == "blk")
        {cout << endl << " YOU GUESSED THE COLOR !! YOU WIN 1,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
         money = money + 1000;}
         
    if (choice[i] == 47 && parity == "even")
        {cout << endl << " YOU GUESSED THE PARITY !! YOU WIN 1,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
         money = money + 1000;}
        
    if (choice[i] == 48 && parity == "odd")
        {cout << endl << " YOU GUESSED THE PARITY !! YOU WIN 1,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
         money = money + 1000;}
        
    if (choice[i] == 49 && half == 1)
       {cout << endl << " YOU GUESSED THE HALF !! YOU WIN 1,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
        money = money + 1000;}
        
    if (choice[i] == 50 && half == 2)
       {cout << endl << " YOU GUESSED THE HALF !! YOU WIN 1,000$ " << endl;
        cout << endl << " your correct guess was :" << choice[i] << endl;
        money = money + 1000;}        
    }// end of for statement to check bets 
 
    cout << endl << endl << "Your money: "<< money<< "$" << endl << endl;

     cout << "Would you like to cash out (exit) y for yes n for no" << endl;
           cin>> playagain2;

system("clear");

    }while (playagain2 == 'n');

           break;//end of roulette  game
           
 //begin case 3 and black jack game  
 case (3):

system("clear");
 
    cout << endl << endl << "********WELCOME TO MATTS BLACK JACK GAME********"<< endl
         << endl << endl
         << "Cost per hand is 100$, win per hand is 200$" << endl << endl
         << "Your money: " << money << "$" << endl << endl;

 do{
    char playagan;
    
    money = money - 100;
     
    srand (time(NULL));
    
    for (int i=0; i<52; ++i) myvector.push_back(i);

    random_shuffle ( myvector.begin(), myvector.end(), myrandom );

//    for (vector<int>::iterator x=myvector.begin(); x!=myvector.end(); ++x)
//     {}  

 
//initial deal    
     cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 2 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;

     dealertotal = dealertotal + card[myvector[0]].bjvalue + card[myvector[1]].bjvalue;
     playertotal = playertotal + card[myvector[2]].bjvalue + card[myvector[3]].bjvalue;

//ask is player wants a hit
     cout << endl << endl << "Your Total :" << playertotal << endl;
     cout << endl << endl << "would you like a Hit ?? ( 'y' for yes or 'n' for no )" << endl << endl;
     cin >> hit1;
    if  (hit1 == 'y' || hit1 == 'Y')
    { cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 2 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 3 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     playertotal = playertotal + card[myvector[4]].bjvalue;
     cout << endl << endl << "Your Total :" << playertotal << endl;}
     else if(hit1 == 'n' || hit1 == 'N'){
     cout << endl << endl << "********* You chose to stay **********" << endl;
     cout << endl << endl << "Your Total :" << playertotal << endl;}

//makes sure player can have another hit   
     if (playertotal < 21 && (hit1 == 'y' || hit1 == 'Y')){
     cout << endl << endl << "would you like a Hit ?? ( 'y' for yes or 'n' for no )" << endl << endl;
     cin >> hit2;

//if player wants second hit card
     if ((hit2 == 'y' || hit2 == 'Y') && (hit1 == 'y' || hit1 == 'Y'))
    { cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 2 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 3 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     cout << "card 4 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     playertotal = playertotal + card[myvector[5]].bjvalue;
    cout << endl << endl << "Your Total :" << playertotal << endl;}
     else if((hit2 == 'n' || hit2 == 'N') && (hit1 == 'y' || hit1 == 'Y')){
     cout << endl << endl << "********* You chose to stay **********" << endl;
     cout << endl << endl << "Your Total :" << playertotal << endl;}}

//makes sure player can have another hit   
     if (playertotal < 21 && (hit2 == 'y' || hit2 == 'Y')){
     cout << endl << endl << "would you like a Hit ?? ( 'y' for yes or 'n' for no )" << endl << endl;
     cin >> hit3;

//if player wants third hit card
    if ((hit3 == 'y' || hit3 == 'Y') && (hit2 == 'y' || hit2 == 'Y') && (hit1 == 'y' || hit1 == 'Y'))
    {cout << endl << "Your Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[2]].name << " of " << card[myvector[2]].suit << endl;
     cout << "card 2 : " << card[myvector[3]].name << " of " << card[myvector[3]].suit << endl;
     cout << "card 3 : " << card[myvector[4]].name << " of " << card[myvector[4]].suit << endl;
     cout << "card 4 : " << card[myvector[5]].name << " of " << card[myvector[5]].suit << endl;
     cout << "card 5 : " << card[myvector[6]].name << " of " << card[myvector[6]].suit << endl;
     playertotal = playertotal + card[myvector[6]].bjvalue;
     cout << endl << endl << "Your Total :" << playertotal << endl;}
     else if((hit3 == 'n' || hit3 == 'N') && (hit1 == 'y' || hit1 == 'Y') && (hit2 == 'y' || hit2 == 'Y') ){
     cout << endl << endl << "********* You chose to stay **********" << endl;
     cout << endl << endl << "Your Total :" << playertotal << endl;}}

//print dealer total
    if (dealertotal <= 21)
    cout << endl << endl <<  "Dealer Total : " << dealertotal << endl << endl;

//check if dealer needs another hit (hit 1)    
    if (dealertotal < playertotal && playertotal <= 21)
    {cout << endl << "Dealers Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[10]].name << " of " << card[myvector[10]].suit << endl;
     dealertotal = dealertotal + card[myvector[10]].bjvalue;
     cout << endl << endl << "Dealer Total : " << dealertotal << endl << endl;
     cout << "Your Total :" << playertotal << endl;}

//check if dealer needs another hit (hit 2)
     if (dealertotal < playertotal && playertotal <= 21)
    {cout << endl << "Dealers Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[10]].name << " of " << card[myvector[10]].suit << endl;
     cout << "card 3 : " << card[myvector[11]].name << " of " << card[myvector[11]].suit << endl;
     dealertotal = dealertotal + card[myvector[11]].bjvalue;
     cout << endl << endl << "Dealer Total : " << dealertotal << endl << endl;
     cout << "Your Total :" << playertotal << endl;}

//check if dealer needs another hit (hit 3)     
    if (dealertotal < playertotal && playertotal <= 21)
    {cout << endl << "Dealers Hand : "<< endl << endl;
     cout << "card 1 : " << card[myvector[0]].name << " of " << card[myvector[0]].suit << endl;
     cout << "card 2 : " << card[myvector[1]].name << " of " << card[myvector[1]].suit << endl;
     cout << "card 3 : " << card[myvector[10]].name << " of " << card[myvector[10]].suit << endl;
     cout << "card 3 : " << card[myvector[11]].name << " of " << card[myvector[11]].suit << endl;
     cout << "card 3 : " << card[myvector[12]].name << " of " << card[myvector[12]].suit << endl;
     dealertotal = dealertotal + card[myvector[12]].bjvalue;
     cout << endl << endl << "Dealer Total : " << dealertotal << endl << endl;
     cout << "Your Total :" << playertotal << endl;}

//    fix this (ace hi low) 
//    card[0].bjvalue = 1;
//    card[13].bjvalue = 1;
//    card[26].bjvalue = 1;
//    card[39].bjvalue = 1;

     
    // compare hands 
    if ( dealertotal == playertotal)                            //tie
    {cout << endl << "Tie!!! " << endl << endl;
    cout << "Your money: " << money << "$"<< endl << endl;}
    else if (dealertotal > 21 && playertotal < 21)             //dealer busts
    {cout << endl << "Dealer Busts..." << endl << endl << "YOU WIN!!!" << endl << endl;
    money = money + 200;
    cout << "Your money: " << money << "$"<< endl << endl;}
    else if (dealertotal <= 21 && dealertotal > playertotal)  // dealer wins
    {cout << endl << "Dealer wins you lose..." << endl << endl;
    money = money - 100;
    cout << "Your money: " << money << "$"<< endl << endl;}
    else if (playertotal > 21 && dealertotal <= 21)          // player busts
    {cout << endl << "You bust... Dealer wins..." << endl << endl;
    money = money - 100;
    cout << "Your money: " << money << "$"<< endl << endl;}
    else if (playertotal <=21 && playertotal > dealertotal) // player wins 
    {cout << endl << "YOU WIN!!!!! " << endl << endl;
    money = money + 200;
    cout << "Your money: " << money << "$"<< endl << endl;}  
    
    //reset totals
    dealertotal = 0;
    playertotal = 0;
 
     cout << "Would you like to cash out (exit) y for yes n for no" << endl;
           cin>> playagain3;

system("clear");

    }while (playagain3 == 'n');

           break;//end of blackjack game
           
 case (4):
   
system("clear");
     
    cout << endl << endl << "*********WELCOME TO MATTS CRAPS GAME*********"<< endl << endl
          << "Cost per bet is 100$" << endl << endl 
	  << "Maximum of 5 bets" << endl << endl
          << "Your money: " << money << "$" << endl << endl;

do{
cout <<"\t======================================================   =============================================" <<endl;
cout <<"\t|   |   |      |        !!! MAIN CHART !!!          ||   ||       !!! S I D E  C H A R T !!!        ||" <<endl;
cout <<"\t| p | d | dont |====================================||   =============================================" <<endl;
cout <<"\t| a | o | come |     |     |     |     |     |      ||   ||             * Any SEVEN *               ||" <<endl;
cout <<"\t| s | n | bar  |  4  |  5  | six |  8  | nine|  10  ||   ||    4 to 1       (19)       4 to 1       ||" <<endl;
cout <<"\t| s | t | (3)  | (4) | (5) | (6) | (8) | (9) | (10) ||   ||-----------------------------------------||" <<endl;
cout <<"\t|   |   |-------------------------------------------||   ||    double 3's    ||   double 5's        ||" <<endl;
cout <<"\t| l | p |                                           ||   ||    9 to 1  (20)  ||   7 to 1  (21)      ||" <<endl;
cout <<"\t| i | a |                                           ||   ||-----------------------------------------||" <<endl;
cout <<"\t| n | s |                                           ||   ||    double 4's    ||   double 2's        ||" <<endl;
cout <<"\t| e | s |                C  O  M  E                 ||   ||    9 to 1  (22)  ||   7 to 1  (23)      ||" <<endl;
cout <<"\t|   |   |                    (7)                    ||   ||-----------------------------------------||" <<endl;
cout <<"\t|   | b |                                           ||   ||   1 & 2   || double 1's  ||  double 6's ||" <<endl;
cout <<"\t|   | a |                                           ||   ||  15 to 1  ||  30 to 1    ||   30 to 1   ||" <<endl;
cout <<"\t|   | r |                                           ||   ||    (24)   ||    (25)     ||     (26)    ||" <<endl;
cout <<"\t|   |___|___________________________________________||   ||-----------------------------------------||" <<endl;
cout <<"\t|   |   \\     ___                             ___   ||   ||    6 & 5         ||    2 & 3            ||" <<endl;
cout <<"\t|   |    \\    |2| * 3  *  4 *  9 * 10 * 11 * |12|   ||   ||   15 to 1  (27)  ||   Hopping  (28)     ||" <<endl;
cout <<"\t|   |     \\   |_|  (13) (14) (15) (16) (17)  |__|   ||   ||-----------------------------------------||" <<endl;
cout <<"\t|   | big  \\   2X                             3x    ||   ||              * Any Craps *              ||" <<endl;
cout <<"\t|   | 6 or  \\ (12)        F I E L D          (18)   ||   ||      7 to 1      (29)       7 to 1      ||" <<endl;
cout <<"\t|   |  8     \\                                      ||   =============================================" <<endl;
cout <<"\t|   | (11)    \\------------------------------------ ||                                                " <<endl;
cout <<"\t|   |          \\        dont pass bar (2)           ||                                                " <<endl;
cout <<"\t|   \\---------------------------------------------- ||                                                " <<endl;
cout <<"\t|                          pass line   (1)          ||                                                 " <<endl;
cout <<"\t|===================================================||                                                 " <<endl;
cout <<"\t                                                                                                       " <<endl;

   
   if (checker)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> bet[j]; size++; money = money - 100;
     if (bet[j] == 0)
     {checker = false;}}
      
     j++;
    
   if (checker)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> bet[j];size++; money = money - 100;
     if (bet[j] == 0)
     {checker = false;size--;}}
     
    j++;
     
   if (checker)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> bet[j];size++; money = money - 100;
      if (bet[j] == 0)
     {checker = false;size--;}}

     j++;

   if (checker)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> bet[j];  size++; money = money - 100;
     if (bet[j] == 0)
     {checker = false;size--;}}

     j++;

   if (checker)
   {cout << "Place your bet (enter 0 to stop bets) : ";
     cin >> bet[j];size++; money = money - 100;}
 
    cout << endl; 
 
    for (int i = 0 ; i < size ; i++)
    {cout << "you bet " << bet[i] << endl;}

    cout << endl;

srand (time(NULL));
diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

diceone = rand() % 6 + 1;
dicetwo = rand() % 6 + 1;
rollnum++;
cout << "Roll # " << rollnum <<  "\t Dice 1: " << diceone << "\t Dice 2: " << dicetwo << "\t total : " << diceone + dicetwo << endl;
wait(2);

rollnum = 0;

cout <<  endl << endl << "functionality in progress......." << endl;

           cout << " would you like to cash out (exit) y for yes n for no" << endl;
           cin>> playagain4;

system("clear");

           }while(playagain4 == 'n');
           break;
           
 case (5):cout << "this is the Baccarat heading!!!!" << endl << endl;
            do{
           cout << "this is the Baccarat game(comming soon...), would you like to cash out (exit) y for yes n for no" << endl;
           cin>> playagain5;
           }while(playagain5 == 'n');
           break;
           
 case (6):
           system("clear");
           cout<< endl<< endl<< "You chose to quit, Thanks for playing !!!" << endl <<endl<< endl;
           break; 
           
  default: cout<< endl << "***********wrong choice.... try again********" << endl << endl; 

}                      //end gaming switch bracket 

}while(leave == 'n'); //end heading do while 

}while(choose !=6);   // end overall program do while


return 0;
}                     // end of actual program 

void chart()
{
   cout << "\t********************** Chart *********************"  << endl << endl;
   cout << "\t=================================================="  << endl;
   cout << "\t|         0 (37)        | |        00 (38)       | " << endl;
   cout << "\t=================================================="  << endl;
   cout << "\t|         |    1 Red   |    2 Blk   |    3 Red   | " << endl;
   cout << "\t|   1st   |--------------------------------------| " << endl;
   cout << "\t|         |    4 Blk   |    5 Red   |    6 Blk   | " << endl;
   cout << "\t|   12    |--------------------------------------| " << endl;
   cout << "\t|         |    7 Red   |    8 Blk   |    9 Red   | " << endl;
   cout << "\t|  (39)   |--------------------------------------| " << endl;
   cout << "\t|         |   10 Blk   |   11 Blk   |   12 Red   | " << endl;
   cout << "\t=================================================="  << endl;     
   cout << "\t|         |   13 Blk   |   14 Red   |   15 Blk   | " << endl;
   cout << "\t|   2nd   |--------------------------------------| " << endl;
   cout << "\t|         |   16 Red   |   17 Blk   |   18 Red   | " << endl;
   cout << "\t|   12    |--------------------------------------| " << endl;
   cout << "\t|         |   19 Red   |   20 Blk   |   21 Red   | " << endl;
   cout << "\t|  (40)   |--------------------------------------| " << endl;
   cout << "\t|         |   22 Blk   |   23 Red   |   24 Blk   | " << endl;
   cout << "\t=================================================="  << endl;
   cout << "\t|         |   25 Red   |   26 Blk   |   27 Red   | " << endl;
   cout << "\t|   3rd   |--------------------------------------| " << endl;
   cout << "\t|         |   28 Blk   |   29 Blk   |   30 Red   | " << endl;
   cout << "\t|   12    |--------------------------------------| " << endl;
   cout << "\t|         |   31 Blk   |   32 Red   |   33 Blk   | " << endl;
   cout << "\t|  (41)   |--------------------------------------| " << endl;
   cout << "\t|         |   34 Red   |   35 Blk   |   36 Red   | " << endl;
   cout << "\t=================================================="  << endl;
   cout << "\t|---------| Row 1 (42) | Row 2 (43) | Row 3 (44) | " << endl;
   cout << "\t|------------------------------------------------| " << endl;
   cout << "\t|        Red (45)        |        Blk (46)       | " << endl; 
   cout << "\t|------------------------------------------------| " << endl;
   cout << "\t|        Even (47)       |        Odd (48)       | " << endl; 
   cout << "\t|------------------------------------------------| " << endl;
   cout << "\t|       1 - 18 (49)      |      19 - 36  (50)    | " << endl; 
   cout << "\t=================================================="  << endl;
   cout << endl << endl ;
}
