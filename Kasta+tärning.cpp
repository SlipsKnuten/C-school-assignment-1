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

    while(svar == 'y'){ //K�r loopen medans svaret �r 'Y'.

        while(insattning >= 5001 || insattning <= 99){ //Loopar om ins�ttningen �r st�rre �n 5001 eller mindre �n 99 annars bryts loopen om programmet g�r vidare.
                cout << "How much do you want to put in to the bank?" << endl;
                cin >> insattning; //Lagrar ins�ttningen

            if(insattning <= 5000 && insattning >= 100){ //Om ins�ttningen �r mindre �n 5000 eller 100 s� �r ins�ttningen saldot.
                saldo = insattning;
                cout << "You account balance is " << saldo << " crowns" << endl;
                }

            else{
                cout << endl << "Invalid deposit" << endl;
                }
            }

        while(satsning != 100 && satsning != 300 && satsning != 500){ //Loopar om satsningen inte �r 100, 300 eller 500 annars bryts loopen och programmet g�r vidare.
                cout << "How much do you want to bet?" << endl;
                cin >> SatsCheck; //Lagrar satsningen

            if(SatsCheck == 100 && saldo >= 100 || SatsCheck == 300 && saldo >= 300  || SatsCheck == 500 && saldo >= 500){ //Om saldo och satsning �r 100, 300 eller 500 s� kastas t�rningarna.
                satsning = SatsCheck; //Lagrar satsningen
                cout << endl << "Let's play!" << endl;
                }

            else{
                cout << endl << "Invalid bet, please make a new deposit" <<  endl; //Om det inte finns tillr�ckligt med pengar g�r en ny ins�ttning.
                cin >> NyInsattning; //Lagrar ny ins�ttning
                saldo = NyInsattning + saldo; //Saldo f�r ett nytt v�rde + det gamla v�rdet fr�n f�rut.
                cout << endl << "Your account balance is " << saldo << endl;
                }
            }

        while(OmANV < 2 && OmAI < 2){ //K�r loopen medans dator eller anv�ndare inte har h�gre v�rde �n 2. V�rdet i det h�r fallet �r omg�ngarna.

                tarning1 = rand()% 6 + 1;
                tarning2 = rand()% 6 + 1;
                cout << endl << "Your result was " << tarning1 << " and " << tarning2 << endl;

                tarning3 = rand()% 6 + 1;
                tarning4 = rand()% 6 + 1;
                cout << "The computer result was " << tarning3 << " and " << tarning4 << endl << endl;

            if(tarning1 > tarning2){ //Om t�rningen 1 �r st�rre �n t�rning 2, s� �r t�rning 1 den h�gsta t�rningen.
                AnvHogstaTarn = tarning1;
                }

            else{
                AnvHogstaTarn = tarning2; //Annars �r t�rning 2 den st�rsta.
                }

            if(tarning3 > tarning4){ //Om t�rning 3 �r st�rre �n t�rning 4, �r t�rning 3 den h�gsta t�rningen.
                AIHogstaTarn = tarning3; //Lagrar t�rningsv�rde.
                }

            else{
                AIHogstaTarn = tarning4; //Annars �r t�rning 4 den h�gsta. Lagrar t�rningsv�rde.
                }

            if(AnvHogstaTarn > AIHogstaTarn){ //Om spelarens h�gsta t�rning �r st�rre �n datorns, vinner spelaren.
                OmANV++; //Lagrar omg�ngar v�rdet f�r serien.
                cout << "You won" << endl << "Your highest dice was " << AnvHogstaTarn << endl << endl;
                }

            else if(AnvHogstaTarn < AIHogstaTarn){ //Lagrar v�rdet f�r omg�ngarna i serien.
                OmAI++; //Lagrar omg�ngar v�rdet f�r serien.
                cout << "You lost because you are bad" << endl << "The computers highest dice was " << AIHogstaTarn << endl << endl;
                }

            else{ //Lagrar v�rdet f�r omg�ngarna i serien.
                OmANV++; //Lagrar omg�ngar v�rdet f�r serien.
                cout << "The score was even, you won anyhow" << endl << "Your highest dice was " << AnvHogstaTarn << endl;
                }

            }

            if(OmANV == 2){ //Om anv�ndaren har vunnit 2 omg�ngar vinner han spelet.
                saldo = saldo + satsning; //Lagrar det nya saldot efter resultatet har best�mts.
                cout << "You won " << satsning << endl;
                cout << "Your account balance is " << saldo << endl;
                }

            else{ //Annars f�rlorar han.
                saldo = saldo - satsning; //Lagrar det nya saldot efter resultatet har best�mts.
                cout << "You lost because you are bad, and you lost " << satsning << endl;
                cout << "Your account balance is " << saldo << endl;
                }

                cout << endl << "Do you want to play again? Type 'Y' for yes and 'N' for no." << endl; //Kan inte l�gga dessa inputs och outputs i n�gra statements. Koden Skriver inte ut n�gonting efter ins�ttning och satsning. Antar att answer inten m�ste deklareras innan det kan ske en ber�kning.
                cin >> svar;

            if(svar == 'n'){ //St�nger av programmet.
                cout << "See ya";
                }

            else if(svar == 'y'){ //Loopar programmet och �terst�ller omg�ngarna, satsningen och satscheck.
                cout << "Let's play again" << endl;
                system("CLS");
                satsning = 0;
                SatsCheck = 0;
                OmAI = 0;
                OmANV = 0;
                }
        }
}
