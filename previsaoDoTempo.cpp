#include <iostream>

using namespace std;



int main()
{
    string diasSemana[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo"};
    float diasChuva[7];

    float qtdMaxChuva, qtdMinChuva, somaChuva = 0, mediaChuva;
    int diaMax = 0, diaMin = 0;
    
    for (int i = 0; i < 7; i++){
        cout << "Insira quantos mililitros choveu no dia da semana " << diasSemana[i] << ": ";
        cin >> diasChuva[i];
    }
    
    qtdMaxChuva = diasChuva[0];
    qtdMinChuva = diasChuva[0];
    
    for (int i = 0; i < 7; i++){
        somaChuva += diasChuva[i];
        
        if(diasChuva[i] > qtdMaxChuva){
            qtdMaxChuva = diasChuva[i];
            diaMax = i;
        }
        
        
        if (diasChuva[i] < qtdMinChuva){
            qtdMinChuva = diasChuva[i];
            diaMin =  i;
        }
    }
    
    mediaChuva = somaChuva / 7;
    
    cout << "\nO dia que mais choveu foi " << diasSemana[diaMax] << ", com um total de " << qtdMaxChuva << "mm.";
    cout << "\nO dia que menos choveu foi " << diasSemana[diaMin] << ", com um total de " << qtdMinChuva << "mm.";
    cout << "\nO total de chuva da semana foi de"  << somaChuva << "mm.";
    cout << "\nA média de chuva na semana foi de " << mediaChuva << "mm.";
    
    
    return 0;
}
