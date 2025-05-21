#include <iostream>
#include <cstdlib>  
#include <ctime> 

using namespace std;

int main()
{
    int conjNumerosSorteados[6] = {};
    int conjNumerosPalpites[6] = {};
    int numerosSorteados, numeroPalpite;
    bool repete = false, jaEscolhido = false;
    
    srand(time(0));
    
    // Determina um número aleatório
     for(int i = 0; i < 6; i++){
         repete = false;
         numerosSorteados = rand() % 60 + 1;
         
         // Verifica se número sorteado já está armazenado
         for(int j = 0; j < 6; j++){
             if(numerosSorteados == conjNumerosSorteados[j]){
                 repete = true;
                 break;
             }
         }
         
         // Se for repetido, a vez do laço é descartada e recomeça
         if(repete == true){
             i--;
         }
         else{
             conjNumerosSorteados[i] = numerosSorteados;
         }
       
     }
     
     
     
     // O usuário começa a jogar
     cout << "Seja bem vindo à Mega-Sena! Escolha um número de 1 a 60 para começar o seu palpite: " << endl;
     for (int i = 0; i < 6; i++){
    
        cout << "\nDigite o " << i + 1 << "º palpite: ";
        cin >> numeroPalpite;
             
             
        while (numeroPalpite < 1 || numeroPalpite > 60){
            cout << "\nInválido, tente de novo!  ";
            cin >> numeroPalpite;
        }
           
        // Verifica se o palpite do usuário já foi armazenado anteriormente
         jaEscolhido = false;
         for (int j = 0; j < i; j++){
             if (conjNumerosPalpites[j] == numeroPalpite){
                 jaEscolhido = true;
                 cout << "\nOps! Você já digitou esse número... Tente de novo!  ";
                 break;
             } 
             
         }

         // Se sim, a vez do laço é descartada
             if(jaEscolhido == true) {
                i--;  
             } else {
                conjNumerosPalpites[i] = numeroPalpite; 
             }
         
     }

    // Exibe os resultados
        cout << "\nOs números sorteados foram: " << endl;
        for (int i = 0; i < 6; i++){
            cout << conjNumerosSorteados[i] << " ";
        }
        cout << endl;
        
        
        cout << "\nOs seus palpites foram: " << endl;
        for (int j = 0; j < 6; j++){
            cout << conjNumerosPalpites[j] << " ";
        }
        
        
        // Verificando se usuário acertou
        int acertos = 0;
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 6; j++){
                if (conjNumerosSorteados[i] == conjNumerosPalpites[j]){
                    acertos++;
                }
            }
        }
     
        switch (acertos){
            case 4:
            cout << "\n\nParabéns! Você acertou a quadra! Vá até a Lotérica e retire o seu prêmio.";
            break;
            
            case 5: 
            cout << "\n\nParabéns! Você acertou a quina! Vá até a Lotérica e retire o seu prêmio.";
            break;
            
            case 6:
            cout << "\n\nParabéns! Você acertou todos os números! Vá até a Lotérica e retire o seu prêmio.";
            break;
            
            default:
            cout << "\n\nInfelizmente não foi dessa vez... Você obteve um total de " << acertos << " acertos. Continue tentando!";
        }
     
     

    return 0;
}
