#include<iostream>
#include<locale.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int main (){
    setlocale(LC_ALL,"Portuguese");
    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinha��o! *" << endl;
    cout << "***************************************" << endl;

    cout << "Escolha o seu n�vel de dificuldade: " << endl;
    cout << "Facil (F), M�dio (M) OU Dif�cil (D)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_tentativas;

    if(dificuldade == 'F'){
        numero_tentativas = 15;
    }
    else if(dificuldade == 'M') {
        numero_tentativas = 10;
    }
    else {
        numero_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    bool errou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_tentativas; tentativas++){
        int chute;
        cout << "Tentiva " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute �: " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parab�ns! Voc� acertou o n�mero secreto!" << endl;
            errou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute foi maior que o n�mero secreto" << endl;
        }
        else{
            cout << "Seu chute foi menor que o n�mero secreto" << endl;
        }
    }
    cout << "FIM DE JOGO!" << endl;
    if(errou){
        cout << "Voc� perdeu! Tente novamente!" << endl;
    }
    else{
            cout << "Voc� aceertou o n�mero secreto em " << tentativas << " tentativas." << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontua��o foi de " << pontos << " pontos." << endl;
    }

}

