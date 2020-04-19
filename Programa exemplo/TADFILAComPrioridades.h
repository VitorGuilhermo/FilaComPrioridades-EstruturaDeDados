#define MAXFILA 10

struct TpElemento{
    char nome[50];
    int Prioridade;
};
struct TpFilaPrioridade{
    int INICIO, FIM, CONT;
    TpElemento FILA[MAXFILA];
};

//Obrigatório SEMPRE
void FPInicializar(TpFilaPrioridade &FP){
    FP.INICIO = 0;
    FP.FIM = -1;
    FP.CONT = 0;
}

void FPInserir(TpFilaPrioridade &FP, TpElemento Elemento){
    TpElemento aux;
    int i;
    FP.FILA[++FP.FIM] = Elemento;
    i = FP.FIM;
    while(i > FP.INICIO && FP.FILA[i].Prioridade < FP.FILA[i-1].Prioridade ){   //enquanto o i(elemento final do vetor) for maior que a posicao inicial (ou seja, vai percorrer todo o vetor) e a prioridade da ultima for maior que a antipenultima, irá acontecer o remanejamento
        aux = FP.FILA[i];
        FP.FILA[i] = FP.FILA[i-1];
        FP.FILA[i-1] = aux;
        i--;
    }
    FP.CONT ++;
}

//Retirar, OBRIGATORIAMENTE o elemento que se encontra no INÍCIO da FILA, independente da Prioridade. E, por fim, deve ser retornado o Elemento, neste caso um TpElemento.
TpElemento FPRetirar(TpFilaPrioridade &FP){
    FP.CONT--;
    return FP.FILA[FP.INICIO++];
}

// Retornar o elemento do INÍCIO
TpElemento FPElementoInicio(TpFilaPrioridade FP){
    return FP.FILA[FP.INICIO];
}
//Retornar o elemento do FIM
TpElemento FPElementoFim(TpFilaPrioridade FP){
    return FP.FILA[FP.FIM];
}
// Verificar se a FILA está Cheia
int FPCheia(int cont){
    return (cont == MAXFILA);
}
//Verificar se a FILA está Vazia
int FPVazia(int cont){
    return cont == 0;
}

// Exibir a FILA com PRIORIDADES
void FPExibir(TpFilaPrioridade FP){
    TpElemento Aux;
    while (!FPVazia(FP.CONT)){
        Aux = FPRetirar(FP);
        printf("Elemento: %c - Prioridade: %d\n", Aux.nome, Aux.Prioridade);
    }
}


//Desenhos
void desenhaCaixa(int x, int caixa){
    int i = x;

    textcolor(9);
    gotoxy(60, i+1);
    printf("=============--    o   ---==========");
    gotoxy(66, i+2);
    printf("-=-=-=-|    / \\    |");
    gotoxy(66, i+3);
    printf("-=-=-=-|___________|");
    gotoxy(60, i+5);
    printf("====================================");
    if(caixa == 1){
        textcolor(10);
        gotoxy(89, i+2);
        printf("OPEN");
    }
    else{
        textcolor(4);
        gotoxy(88, i+2);
        printf("CLOSED");
    }
    textcolor(15);
}

void apagaPessoa(int x, int y){
    int i = x, j = y;
    gotoxy(i, j);
        printf(" ");
        gotoxy(i-1, j+1);
        printf(" ");
        gotoxy(i, j+1);
        printf(" ");
        gotoxy(i+1, j+1);
        printf(" ");
        gotoxy(i-1, j+2);
        printf(" ");
        gotoxy(i+1, j+2);
        printf(" ");
}

void desenhaPessoaAnimacao(int x, int y){
    int i, j = y;
    for(i = x; i<61; i++){
        gotoxy(i, j);
        printf("o");
        gotoxy(i-1, j+1);
        printf("/");
        gotoxy(i, j+1);
        printf("|");
        gotoxy(i+1, j+1);
        printf("\\");
        gotoxy(i-1, j+2);
        if(i % 2 != 0){
            gotoxy(i, j+2);
            printf("|");
        }
        else
            printf("/");
        gotoxy(i+1, j+2);
        if(i % 2 == 0)
            printf("\\");
        else{
            gotoxy(i, j+2);
            printf("|");
        }
        Sleep(150);

        apagaPessoa(i, j);

    }
    gotoxy(i, j);
    printf("o");
    gotoxy(i-1, j+1);
    printf("/");
    gotoxy(i, j+1);
    printf("|");
    gotoxy(i+1, j+1);
    printf("\\");
    gotoxy(i-1, j+2);
    printf("/");
    gotoxy(i+1, j+2);
    printf("\\");
}

void limpaLinha(int x, int y){
    int i;
    for(i=0; i< 40; i++){
        gotoxy(x+i, y);
        printf(" ");
    }
}

void desenhaSaida(int x, int y){
    int i;
    char desenho[][22] = {
                            "      /|",
                            "     / |",
                            "    /  |",
                            "   /   |",
                            "  /    |",
                            " /     |",
                            "/  _   |",
                            "|_| |  |",
                            "___    |",
                            "_|_|   |",
                            "__ .   |",
                            "___    |",
                            "|__|   |",
                            "___    |",
                            "_|_|   |",
                            "      /",
                            "     /",
                            "    /",
                            "   /",
                            "  /",
                            " /",
                            "/"
    };

    textcolor(12);
    for(i=0; i<22; i++){
        gotoxy(x, y+i);
        printf("%s\n", desenho[i]);
    }
    textcolor(15);
}
