//Bianca Dias Barbosa e Henrique Marciano da Silva - BSI 2018
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#define N 11

void hideCursor();
void showCursor();
void gotoxy (int x, int y);
void sair ();
float convertToFloat(char bitS[], float bitF);
int verifyBit(char bitS[]);
void bitCount(float num, float dec, float notas[], float moedas[]);
void sobre();
void ajuda();
void menu ();
void moldura();
void menuBoasVindas();

void hideCursor(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void showCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x,int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y}); //posiciona cursor na tela
}

void sair(){
	system("cls");
	gotoxy(40,2);printf("Obrigada por utilizar nosso sistema!\n");
	exit(0); // força o fechamento do programa;
}

float convertToFloat(char bitS[], float bitF){
    bitF = atoi(bitS);
    return bitF;
}

int verifyBit(char bitS[]){
    int cont = 0;
    int i, j;
    for(i = 0; i < strlen(bitS); i++){
        if(bitS[i] == ',')
            return 0;
        if(bitS[i] == '.'){
            for(j = i+1; j < strlen(bitS);j++){
                if(bitS[j] != '\0')
                    cont++;
            }
            return cont;
        }
    }
    return 1;
}

void bitCount(float num, float dec, float notas[], float moedas[]){
    float div, rest;
    int parte_int;
    
    if (num != 0){
        rest = num;
        int i;
        for(i = 0; i < 7; i++){
        div = rest/notas[i];
        parte_int = div;
        rest -= parte_int * notas[i];
        printf("%d nota(s) de %.2f Bits\n", parte_int, notas[i]);
        }
    }
    if (dec != 0){
        rest = dec;
        int i;
        for(i = 0; i < 4; i++){
        div = rest/moedas[i];
        parte_int = div;
        rest -= parte_int * moedas[i];
        printf("%d moeda(s) de %.2f CentBits\n", parte_int, moedas[i]/100);
        }
    }
}

void sobre(){	
	int tecla = 32;
	system("cls");
	gotoxy(50,1);printf("SOBRE - MOEDA BIT");
	printf("\n\n\tTrabalho de strings desenvolvido por Bianca Dias e Henrique Marciano\n\t");
	printf("\n\tDisciplina: Algoritmos I\n\t");
	printf("\n\tProfessora: Andrea");
	printf("\n\n\t\t\t\tBSI - 2018");
	printf("\n\n\n\t<ESC> Voltar ao menu principal.");
	
	tecla = getch();
	
	while(tecla!=27){
		tecla = getch();
	}
	
	if(tecla == 27)
		menu();
}

void ajuda(){
	gotoxy(52,17);printf("AJUDA");
	gotoxy(10,19);printf("Utilize as setas do seu teclado para mover o quadradinho para cima ou para baixo.");
	gotoxy(10,20);printf("Para escolher uma opcao, aperte ENTER.");
	gotoxy(10,21);printf("Para finalizar o programa, aperte ESC");
	gotoxy(10,22);printf("Divirta-se e aprenda muita matematica!");	
}

void menu(){
	system("cls");
	int tecla;
	int cont = 0;
	
	hideCursor();

	gotoxy(50,1);printf("MENU PRINCIPAL");
	gotoxy(8,4);printf("%c",254);
	gotoxy(10,4);printf("Operacoes entre matrizes");
	gotoxy(10,6);printf("Verificacao");
	gotoxy(10,8);printf("Determinar matriz transposta");
	gotoxy(10,10);printf("Resolva um sistema linear triangular");
	gotoxy(10,12);printf("Sobre");
	gotoxy(10,15);printf("<ESC> Sair");
	gotoxy(30,15);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();
   		
   		if(tecla == 80 && cont<=6){ // para baixo
   			gotoxy(8,4+cont);printf("  ");
   			cont+=2;
			gotoxy(8,4+cont);printf("%c",254);  
		}
		
		if(tecla == 72 && cont>0){ // para cima
   			gotoxy(8,4+cont);printf("  ");
   			cont-=2;
			gotoxy(8,4+cont);printf("%c",254);  
		}
		
		if(tecla == 13){
			switch(cont){
				case 0: 
					//menuOperacoes(matriz);
					break;
				case 2:
					//menuVerificacao(matriz);
					break;
				case 4:
					//matrizTransposta(matriz);
					break;
				case 6:
					//menuSistemaLinear(matriz);
					break;
				case 8:
					sobre();
					break;
			}
		}
		
		if(tecla==32){
			ajuda();
		}
	}
	
	sair();	
}

void moldura(){ //desenha a moldura 
	int a;
	unsigned char caracter=178;
	int i = 30, j = 130;
	system("cls");
	//parede de cima horizontal
	for(a=0;a<j+1;a++){ 
		gotoxy(a,0);
		printf("%c",caracter);
	}
	
	//parede da direita vertical
	for(a=1;a<i;a++)  
    {
        gotoxy(j,a);
        printf("%c",caracter);
    }
    
    //parede de baixo horizontal
    for(a=j;a>=0;a--)   
    {
        gotoxy(a,i);
        printf("%c",caracter);
    }
    
    //parede da esquerda vertical
    for(a=i;a>0;a--)  
    {
       	gotoxy(0,a);
        printf("%c",caracter);
    }
}

void menuBoasVindas(){
	char tecla;
	moldura();
	gotoxy(50,10);printf("Bem-vindo ao sistema BitTech");
	hideCursor();
	tecla = getch();
}

int main(){
	system("mode con:cols=131 lines=31");
	char t1[50];
	char *t2;
    float num, dec, notas[7] = {100, 50, 20, 10, 5, 2, 1}, moedas[4] = { 50, 25, 10, 1};
	int cont;
	int opc;
	int loginCorreto = 0;
	
	// menuBoasVindas();
		
	do{
        printf("\nPor favor, insira a quantia de bits que deseja sacar (precisao de duas casas): ");
        scanf("%s", &t1);
        cont = verifyBit(t1);
        if(cont == 0){
            system("cls");
            printf("\nPor favor, utilize ponto no lugar da virgula.\n");
        }

	} while(cont > 2 || cont == 0);
	
	t2 = strtok(t1, ".");
    t2 = strtok(NULL,".");
    
	num = convertToFloat(t1, num);
	dec = convertToFloat(t2, dec);
	
	bitCount(num, dec, notas, moedas);
}
