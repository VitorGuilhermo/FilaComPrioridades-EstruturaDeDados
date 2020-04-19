#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<locale.h>
#include<time.h>
#include "TADFILAComPrioridades.h"

char menu(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t     SIMULACAO FILA SUPERMERCADO        \n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t\t====================================\n");

    return toupper(getch());
}

void perguntaFuncionamentoCaixas(int &c1, int &c2, int &c3, int &c4){
    char op;
    system("cls");
    printf("\n\n\n\n\n\n\t\t\t\t\tCaixa 1 esta em funcionamento? [S/N]  ");
    fflush(stdin);
    scanf("%c", &op);
    if(toupper(op) == 'S')
            c1 = 1;
    printf("\n\t\t\t\t\tCaixa 2 esta em funcionamento? [S/N]  ");
    fflush(stdin);
    scanf("%c", &op);
    if(toupper(op) == 'S')
            c2 = 1;
    printf("\n\t\t\t\t\tCaixa 3 esta em funcionamento? [S/N]  ");
    fflush(stdin);
    scanf("%c", &op);
    if(toupper(op) == 'S')
            c3 = 1;
    printf("\n\t\t\t\t\tCaixa 4 esta em funcionamento? [S/N]  ");
    fflush(stdin);
    scanf("%c", &op);
     if(toupper(op) == 'S')
            c4 = 1;
    system("cls");
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    textcolor(15);

    TpElemento pessoa, processo1, processo2, processo3, processo4;
    TpFilaPrioridade f1, f2, f3, f4;

    char op;
    int c1, c2, c3, c4, ut, caixaSorteado, t1, t2, t3, t4, qtdePessoas=0, flag;
    float tempoMedioAtendimento;

    op = menu();
    while(op == 13){
        FILE *ptr = fopen("Pessoas.txt", "r");
        c1 = c2 = c3 = c4 = t1= t2 = t3 = t4 = flag = qtdePessoas = 0;
        tempoMedioAtendimento = 0;
        ut = 1;

        FPInicializar(f1);
        FPInicializar(f2);
        FPInicializar(f3);
        FPInicializar(f4);

        perguntaFuncionamentoCaixas(c1, c2, c3, c4);

        desenhaCaixa(2, c1);

        desenhaCaixa(9, c2);

        desenhaCaixa(16, c3);

        desenhaCaixa(23, c4);

        desenhaSaida(112, 5);

        while(!feof(ptr) || !FPVazia(f1.CONT) || !FPVazia(f2.CONT) || !FPVazia(f3.CONT) || !FPVazia(f4.CONT)){

            textcolor(2);
            gotoxy(99, 1);
            printf("UT = %d\n", ut);
            gotoxy(99, 2);
            printf("Temp Espera: %.2f\n", tempoMedioAtendimento/qtdePessoas);
            textcolor(15);

            if(ut % 3 == 0 && !feof(ptr)){

                qtdePessoas++;

                do{
                    caixaSorteado = (rand() % 4) + 1;

                    if(c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0){
                        flag = 1;
                        break;
                    }
                }while(caixaSorteado == 1 && c1 == 0 || caixaSorteado == 2 && c2 == 0 || caixaSorteado == 3 && c3 == 0 || caixaSorteado == 4 && c4 == 0);

                if(flag == 1){
                    system("cls");
                    printf("n\n\n\n\n\n\n\t\t\t\tNenhum caixa funcionando. O supermercado esta fechado!\n");
                    Sleep(2000);
                    break;
                }

                fscanf(ptr, "%[^;];%d\n", &pessoa.nome, &pessoa.Prioridade);

                if(caixaSorteado == 1){
                    desenhaPessoaAnimacao(3, 4);
                    FPInserir(f1, pessoa);
                    tempoMedioAtendimento += 5;
                }
                else if(caixaSorteado == 2){
                    desenhaPessoaAnimacao(3, 11);
                    FPInserir(f2, pessoa);
                    tempoMedioAtendimento += 2;
                }
                else if(caixaSorteado == 3){
                    desenhaPessoaAnimacao(3, 18);
                    FPInserir(f3, pessoa);
                    tempoMedioAtendimento += 4;
                }
                else if(caixaSorteado == 4){
                    desenhaPessoaAnimacao(3, 25);
                    FPInserir(f4, pessoa);
                    tempoMedioAtendimento +=7;
                }
            }

            //EXCLUSAO
            if(t1 == 0 && !FPVazia(f1.CONT) && c1 == 1){
                processo1 = FPRetirar(f1);
                t1 = 5;

                limpaLinha(63, 6);
                gotoxy(63, 6);
                printf("\tPessoa em atendimento: %s", processo1.nome);
            }
            if(t2 == 0 && !FPVazia(f2.CONT) && c2 == 1){
                processo2 = FPRetirar(f2);
                t2 = 2;

                limpaLinha(63, 13);
                gotoxy(63, 13);
                printf("\tPessoa em atendimento: %s", processo2.nome);
            }
            if(t3 == 0 && !FPVazia(f3.CONT) && c3 == 1){
                processo3 = FPRetirar(f3);
                t3 = 4;

                limpaLinha(63, 20);
                gotoxy(63, 20);
                printf("\tPessoa em atendimento: %s", processo3.nome);
            }
            if(t4 == 0 && !FPVazia(f4.CONT) && c4 == 1){
                processo4 = FPRetirar(f4);
                t4 = 7;

                limpaLinha(63, 27);
                gotoxy(63, 27);
                printf("\tPessoa em atendimento: %s", processo4.nome);
            }

            if(t1 > 0){
                t1--;
                if(t1 == 0){
                    apagaPessoa(61, 4);
                    printf("\tAtendimento finalizado: %s", processo1.nome);
                }
            }
            if(t2 > 0){
                t2--;
                if(t2 == 0){
                    apagaPessoa(61, 11);
                    printf("\tAtendimento finalizado: %s", processo2.nome);
                }

            }
            if(t3 > 0){
                t3--;
                if(t3 == 0){
                    apagaPessoa(61, 18);
                    printf("\tAtendimento finalizado: %s", processo3.nome);
                }

            }
            if(t4 > 0){
                t4--;
                if(t4 == 0){
                    apagaPessoa(61, 25);
                    printf("\tAtendimento finalizado: %s", processo4.nome);
                }

            }

            Sleep(2000);
            ut++;
        }

        op = menu();

        fclose(ptr);
    }

    return 0;
}
