 #include <iostream>
 #include <ctime>
 #include <cstdlib>
 
 using namespace std;
 
 char tabuleiro[3][3] = {};
 void criaTabuleiro();
 void exibeTabuleiro();
 void escolheJogador();
 void trocaJogador();
 void jogo();
 void sistemaDePontos(char jogadorAtual);
 void placar();
 bool verificaVencedor(char jogadorAtual);
 
 int tamanhoTabuleiro = 3, pontosJogadorX = 0, pontosJogadorO = 0;
 bool querJogar;
 char jogadorAtual;
 
 int main()
 {  
    do {
    criaTabuleiro();
    escolheJogador();
    exibeTabuleiro();
    jogo();
    
    
    cout << "\n\nVocê gostaria de jogar novamente? Digite 1 para 'sim' ou qualquer tecla para 'não'.";
    cin >> querJogar;
    } while (querJogar == 1);
    
    cout << "\nObrigada por jogar o Jogo da Velha!";
    
     return 0;
 }
 
 
 void criaTabuleiro(){
    
    // Preenche, inicialmente, o tabuleiro com espaços 
    for(int i = 0; i < tamanhoTabuleiro; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
 
    
    // Enumerando colunas
        cout << "    ";
        for(int j = 0; j < tamanhoTabuleiro; j++){
            cout << j << "  ";
        }
     cout << endl;
    
    
    // Enumerando linhas
    for(int i = 0; i < tamanhoTabuleiro; i++){
        cout << i + 1 << "  ";
        for(int j = 0; j < tamanhoTabuleiro; j++){
             cout << "|" << tabuleiro[i][j] << "|";
        }
        cout << endl;
    }
 }
 
void escolheJogador(){
    cout << "Você gostaria de iniciar com X ou O? ";
    cin >> jogadorAtual;
    jogadorAtual = toupper(jogadorAtual);
    
    while (jogadorAtual != 'X' && jogadorAtual != 'O'){
        cout << "Ops... Tente de novo: ";
        cin >> jogadorAtual;
        jogadorAtual = toupper(jogadorAtual);
    }
}



void trocaJogador(){
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}


void exibeTabuleiro() {
    cout << "\n    ";
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        cout << i + 1 << "  ";
    }
    cout << endl;

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            if (tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O') {
                cout << "|" << tabuleiro[i][j] << "|";
            } else {
                cout << "| |";
            }
        }
        cout << endl;
    }
}

 void jogo(){
    int linha, coluna, numeroDeJogadas = 0;
    bool vencedor = false;
    
    // Laço para que o usuário escolha uma posição
    do {
    cout << "\nVez do jogador " << jogadorAtual << ": " << endl;
    
    cout << "\nDigite a linha que você deseja marcar de 1 a " << tamanhoTabuleiro << endl;
    cin >> linha;
    
    while (linha < 1 || linha > tamanhoTabuleiro){
        cout << "Tente de novo: \n";
        cin >> linha;
    }
    linha--;
    
    cout << "Escolha uma coluna para marcar de 1 até " << tamanhoTabuleiro << endl;
    cin >> coluna;
    
     while (coluna < 1 || coluna > tamanhoTabuleiro){
        cout << "Tente de novo: " << endl;
        cin >> coluna;
    }
    coluna--;
    
    
    // Verifica se posição está ocupada
    if (tabuleiro[linha][coluna] != ' ') {
        cout << "Essa posição já está ocupada. Tente de novo. " << endl;
        continue;
    }
    
    tabuleiro[linha][coluna] = jogadorAtual;
    numeroDeJogadas++;
    exibeTabuleiro();
    
    vencedor = verificaVencedor(jogadorAtual);
    
        if (vencedor){
            cout << "Parabéns! O jogador " << jogadorAtual << " venceu!";
            sistemaDePontos(jogadorAtual);
        } else{
            trocaJogador();
        }
    

    } while (numeroDeJogadas < 9 && !vencedor);
    
    if (!vencedor){
        cout << "\nDeu velha! Ninguém pontuou!" << endl;
        placar();
    }
    
}

bool verificaVencedor(char jogadorAtual){
    // Verifica linhas
    for(int i = 0; i < tamanhoTabuleiro; i++){
       if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual){
           return true;
       }
    }
    
    // Verifica colunas
    for(int j = 0; j < tamanhoTabuleiro; j++){
       if (tabuleiro[0][j] == jogadorAtual && tabuleiro[1][j] == jogadorAtual && tabuleiro[2][j] == jogadorAtual){
           return true;
       }
    }
    
    // Verifica diagonal principal
    if (tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual){
        return true;
    }
    
    // Verifica diagonal secundária
    if (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual){
        return true;
    }
    
    return false;
}

void sistemaDePontos(char jogadorAtual){
    if (jogadorAtual == 'X'){
        pontosJogadorX++;
    } else{
        pontosJogadorO++;
    }
    
    placar();
}

void placar(){
    cout << "\nPlacar: " << pontosJogadorX << " (Jogador X) vs " << pontosJogadorO << "(Jogador O)" << endl;
    cout << endl;
}
    
