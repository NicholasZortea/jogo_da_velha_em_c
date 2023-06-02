#include<stdio.h>

void preencheMatrizCom0(int matriz[3][3]){
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void preenchePosicaoEscolhida(int jogador, int matriz[3][3], int x, int y){
    int linha, coluna;
    if(matriz[x][y] != 0){  //posicao vazia portanto jogador pode marcar aqui
        //4 verificar se a posicao ja esta ocupada
        if(jogador == 1){
            do{
                printf("Escolha outra posicao, esta nao eh valida!\n");
                printf("Digite a linha:\n");
                scanf("%d", &linha);
                printf("Digite a coluna: \n");
                scanf("%d", &coluna);
            }
            while(matriz[linha][coluna] !=0);
            matriz[linha][coluna] = 1;
        }else if(jogador ==2){
            do{
                printf("Escolha outra posicao, esta nao eh valida!\n");
                printf("Digite a linha:\n");
                scanf("%d", &linha);
                printf("Digite a coluna: \n");
                scanf("%d", &coluna);
            }while(matriz[linha][coluna] != 0);
            matriz[linha][coluna] = 2;
        }
    }else{
        matriz[x][y] = jogador;
    }
}


int verificaVitoria(int jogador, int matriz[3][3]){
    int contagemPontos = 0, pontosParaVitoria = 3, contaLinhas = 0, contaColunas = 0, condicaoParaEmpate=9;

    //verifica se ganhou linha por linha
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j]==jogador){
                contagemPontos++;
            }
        }
        contaLinhas++;
        //apos percorrer a linha verifica se o jogador ganhou
        if(contagemPontos == pontosParaVitoria){
            printf("Parabens jogador %d, voce ganhou na %d linha!", jogador, contaLinhas);
            printaMatriz(matriz);
            return(jogador);
        }else{
            contagemPontos = 0;
            //caso nao tenha ganhado nessa linha a contagem e zerada para a proxima linha
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[j][i]==jogador){
                contagemPontos++;
            }
        }
        contaColunas++;
        //apos percorrer a coluna verifica se o jogador ganhou
        if(contagemPontos == pontosParaVitoria){
            printf("Parabens jogador %d, voce ganhou %d coluna!", jogador, contaColunas);
            printaMatriz(matriz);
            return(jogador);
        }else{
            contagemPontos = 0;
            //caso nao tenha ganhado nessa coluna a contagem e zerada para a proxima linha
        }
    }

    //percorre a diagonal principal
    for(int i=0,j=0; i<3,j<3; i++,j++){
        if(matriz[i][j] == jogador){
            contagemPontos++;
        }
    }
    if(contagemPontos==pontosParaVitoria){
        printf("Parabens jogador %d, voce ganhou na diagonal principal!", jogador);
        printaMatriz(matriz);
        return jogador;
    }else{
        contagemPontos = 0;
    }

    //percorre a diagonal secundaria
    for(int i=2,j=0; i>=0,j<3; i--,j++){
        if(matriz[i][j] == jogador){
            contagemPontos++;
        }
    }
    if(contagemPontos==pontosParaVitoria){
        printf("Parabens jogador %d, voce ganhou na diagonal secundaria!", jogador);
        printaMatriz(matriz);
        return jogador;
    }

    //verifica se nao deu empate:
    int contNot0 = 0;
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matriz[i][j]!=0){
                contNot0++;
            }
        }
    }
    if(contNot0 == condicaoParaEmpate){
        printf("houve um empate!\n");
        return 3;
    }

    return 0;
}

void printaMatriz(int matriz[3][3]){
    for(int i = 0; i< 3; i++)
    {
        printf("\n\t");
        for(int j = 0; j< 3; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void escolhePosicao(int jogador, int matriz[3][3]){
    int x;
    int y;
    printaMatriz(matriz);
    printf("Digite qual linha deseja marcar jogador %d: \n", jogador);
    scanf("%d", &x);
    printf("Digite qual coluna deseja marcar jogador %d: \n", jogador);
    scanf("%d", &y);
    preenchePosicaoEscolhida(jogador,matriz,x,y);

}

int main()
{
    //1 passo declarar uma matriz
    int matriz[3][3];

    //2 passo preencher com 0 em todas as posicoes da matriz
    preencheMatrizCom0(matriz);

    //3 o jogador 1 escolhe em que posicao vai ser ocupado pelo número "1"

    int jogador1 = 1;
    int jogador2 = 2;

    int x = 0;

    while(x == 0)
    {
        escolhePosicao(jogador1,matriz);
        //5 verificar se o jogador 1 venceu
        int resultado1 = verificaVitoria(jogador1, matriz);
        if( resultado1 == jogador1 || resultado1 == 3)
        {   
            break;
        }

        escolhePosicao(jogador2,matriz);
        int resultado2 = verificaVitoria(jogador2, matriz);
        //5 verificar se o jogador 2 venceu
        if(resultado2 == jogador2 || resultado2 == 3)
        {
            p
            break;
        }
    }

    return 0;
}
