#include<iostream>
#include<locale.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int main (){
    setlocale(LC_ALL,"Portuguese");
    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinhação! *" << endl;
    cout << "***************************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Facil (F), Médio (M) OU Difícil (D)" << endl;

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
        cout << "O valor do seu chute é: " << chute << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            errou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute foi maior que o número secreto" << endl;
        }
        else{
            cout << "Seu chute foi menor que o número secreto" << endl;
        }
    }
    cout << "FIM DE JOGO!" << endl;
    if(errou){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
            cout << "Você aceertou o número secreto em " << tentativas << " tentativas." << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuação foi de " << pontos << " pontos." << endl;
    }

}

