#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main (){
    srand(time(0));
    int satsning = 0;
    int saldo = 0;
    int insattning = 0;
    int OmANV = 0;
    int OmAI = 0;
    int SatsCheck = 0;
    int NyInsattning = 0;
    int tarning1; int tarning2; int tarning3; int tarning4;
    char svar = 'y';
    char svar2 = 'y';
    int AnvHogstaTarn = 0;
    int AIHogstaTarn = 0;

                cout << "Hi! And welcome to this dice game. The computer and you will toss 2 dices each. The one who gets the highest dice wins the round. The series consists of 3 rounds and it's a best of 3 rounds." << endl << endl;

    while(svar == 'y'){ //Kör loopen medans svaret är 'Y'.

        while(insattning >= 5001 || insattning <= 99){ //Loopar om insättningen är större än 5001 eller mindre än 99 annars bryts loopen om programmet går vidare.
                cout << "How much do you want to put in to the bank?" << endl;
                cin >> insattning; //Lagrar insättningen

            if(insattning <= 5000 && insattning >= 100){ //Om insättningen är mindre än 5000 eller 100 så är insättningen saldot.
                saldo = insattning;
                cout << "You account balance is " << saldo << " crowns" << endl;
                }

            else{
                cout << endl << "Invalid deposit" << endl;
                }
            }

        while(satsning != 100 && satsning != 300 && satsning != 500){ //Loopar om satsningen inte är 100, 300 eller 500 annars bryts loopen och programmet går vidare.
                cout << "How much do you want to bet?" << endl;
                cin >> SatsCheck; //Lagrar satsningen

            if(SatsCheck == 100 && saldo >= 100 || SatsCheck == 300 && saldo >= 300  || SatsCheck == 500 && saldo >= 500){ //Om saldo och satsning är 100, 300 eller 500 så kastas tärningarna.
                satsning = SatsCheck; //Lagrar satsningen
                cout << endl << "Let's play!" << endl;
                }

            else{
                cout << endl << "Invalid bet, please make a new deposit" <<  endl; //Om det inte finns tillräckligt med pengar gör en ny insättning.
                cin >> NyInsattning; //Lagrar ny insättning
                saldo = NyInsattning + saldo; //Saldo får ett nytt värde + det gamla värdet från förut.
                cout << endl << "Your account balance is " << saldo << endl;
                }
            }

        while(OmANV < 2 && OmAI < 2){ //Kör loopen medans dator eller användare inte har högre värde än 2. Värdet i det här fallet är omgångarna.

                tarning1 = rand()% 6 + 1;
                tarning2 = rand()% 6 + 1;
                cout << endl << "Your result was " << tarning1 << " and " << tarning2 << endl;

                tarning3 = rand()% 6 + 1;
                tarning4 = rand()% 6 + 1;
                cout << "The computer result was " << tarning3 << " and " << tarning4 << endl << endl;

            if(tarning1 > tarning2){ //Om tärningen 1 är större än tärning 2, så är tärning 1 den högsta tärningen.
                AnvHogstaTarn = tarning1;
                }

            else{
                AnvHogstaTarn = tarning2; //Annars är tärning 2 den största.
                }

            if(tarning3 > tarning4){ //Om tärning 3 är större än tärning 4, är tärning 3 den högsta tärningen.
                AIHogstaTarn = tarning3; //Lagrar tärningsvärde.
                }

            else{
                AIHogstaTarn = tarning4; //Annars är tärning 4 den högsta. Lagrar tärningsvärde.
                }

            if(AnvHogstaTarn > AIHogstaTarn){ //Om spelarens högsta tärning är större än datorns, vinner spelaren.
                OmANV++; //Lagrar omgångar värdet för serien.
                cout << "You won" << endl << "Your highest dice was " << AnvHogstaTarn << endl << endl;
                }

            else if(AnvHogstaTarn < AIHogstaTarn){ //Lagrar värdet för omgångarna i serien.
                OmAI++; //Lagrar omgångar värdet för serien.
                cout << "You lost because you are bad" << endl << "The computers highest dice was " << AIHogstaTarn << endl << endl;
                }

            else{ //Lagrar värdet för omgångarna i serien.
                OmANV++; //Lagrar omgångar värdet för serien.
                cout << "The score was even, you won anyhow" << endl << "Your highest dice was " << AnvHogstaTarn << endl;
                }

            }

            if(OmANV == 2){ //Om användaren har vunnit 2 omgångar vinner han spelet.
                saldo = saldo + satsning; //Lagrar det nya saldot efter resultatet har bestämts.
                cout << "You won " << satsning << endl;
                cout << "Your account balance is " << saldo << endl;
                }

            else{ //Annars förlorar han.
                saldo = saldo - satsning; //Lagrar det nya saldot efter resultatet har bestämts.
                cout << "You lost because you are bad, and you lost " << satsning << endl;
                cout << "Your account balance is " << saldo << endl;
                }

                cout << endl << "Do you want to play again? Type 'Y' for yes and 'N' for no." << endl; //Kan inte lägga dessa inputs och outputs i några statements. Koden Skriver inte ut någonting efter insättning och satsning. Antar att answer inten måste deklareras innan det kan ske en beräkning.
                cin >> svar;

            if(svar == 'n'){ //Stänger av programmet.
                cout << "See ya";
                }

            else if(svar == 'y'){ //Loopar programmet och återställer omgångarna, satsningen och satscheck.
                cout << "Let's play again" << endl;
                system("CLS");
                satsning = 0;
                SatsCheck = 0;
                OmAI = 0;
                OmANV = 0;
                }
        }
}
