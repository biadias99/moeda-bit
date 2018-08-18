// usuário: admin
// senha: alg321
//Bianca Dias Barbosa e Henrique Marciano da Silva - BSI 2018
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define N 11

void hideCursor();
void showCursor();
void gotoxy (int x, int y);
void sair ();
float convertToFloat(char bitS[], float bitF);
int verifyBit(char bitS[]);
void bitCount(float num, float dec, float notas[], float moedas[]);
void calculaNotasEMoedas();
void sobre();
void ajuda();
void menu ();
void moldura();
void menuBoasVindas();
void login();

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
    int aux = 5;
    int tecla;
    
    hideCursor();
    
    printf("\n");
    
	if (num != 0){
        rest = num;
        int i;
        for(i = 0; i < 7; i++){
	        div = rest/notas[i];
	        parte_int = div;
	        rest -= parte_int * notas[i];
	        gotoxy(10,aux);printf("%d nota(s) de %.2f Bits\n", parte_int, notas[i]);
	        aux++;
        }
    }
    if (dec != 0){
        rest = dec;
        int i;
        for(i = 0; i < 4; i++){
	        div = rest/moedas[i];
	        parte_int = div;
	        rest -= parte_int * moedas[i];
	        gotoxy(10,aux);printf("%d moeda(s) de %.2f CentBits\n", parte_int, moedas[i]/100);
	        aux++;
        }
    }
    
	gotoxy(40,20);printf("<ESC> Voltar ao menu principal.");

    do{
    	tecla = getch();
	}while(tecla != 27);
	menu();
}

void calculaNotasEMoedas(){
	system("cls");
	showCursor();
	char t1[50];
	char *t2;
    float num, dec, notas[7] = {100, 50, 20, 10, 5, 2, 1}, moedas[4] = { 50, 25, 10, 1};
	int cont;
	moldura();
	gotoxy(50,2);printf("CALCULO DE NOTAS E MOEDAS BIT");

	do{
        gotoxy(10,4);printf("Por favor, insira a quantia de bits que deseja sacar (precisao de duas casas): ");
        fflush(stdin);
        scanf("%s", &t1);
        cont = verifyBit(t1);
        if(cont == 0){
        	system("cls");
        	moldura();
        	gotoxy(50,2);printf("CALCULO DE NOTAS E MOEDAS BIT");
            gotoxy(40,20);printf("Por favor, utilize ponto no lugar da virgula.\n");
        }else{
            gotoxy(40,20);printf("                                              ");	
		}
	} while(cont > 2 || cont == 0);
	
	t2 = strtok(t1, ".");
    t2 = strtok(NULL,".");
    
	num = convertToFloat(t1, num);
	dec = convertToFloat(t2, dec);
	
	bitCount(num, dec, notas, moedas);
}

void sobre(){	
	int tecla = 32;
	system("cls");
	moldura();
	gotoxy(55,2);printf("SOBRE - MOEDA BIT");
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
	gotoxy(55,17);printf("AJUDA - MOEDA BIT");
	gotoxy(10,19);printf("Utilize as setas do seu teclado para mover o quadradinho para cima ou para baixo.");
	gotoxy(10,20);printf("Para escolher uma opcao, aperte ENTER.");
	gotoxy(10,21);printf("Para finalizar o programa, aperte ESC");
	gotoxy(10,23);printf("O sistema calculara para voce a quantidade de notas e moedas que voce deve dar ao seu cliente!");	
	gotoxy(10,24);printf("Alem disso, o sistema possui a opcao de preencher um cheque!");	
}

void menu(){
	system("cls");
	moldura();
	
	int tecla;
	int cont = 0;
	
	hideCursor();

	gotoxy(55,2);printf("MENU PRINCIPAL");
	gotoxy(8,4);printf("%c",254);
	gotoxy(10,4);printf("Determinar notas e moedas");
	gotoxy(10,6);printf("Preencher cheque");
	gotoxy(10,8);printf("Sobre");
	gotoxy(10,15);printf("<ESC> Sair");
	gotoxy(30,15);printf("<SPACE> Ajuda");

   	while(tecla!=27){
   		gotoxy(10,14);tecla = getch();
   		
   		if(tecla == 80 && cont<=2){ // para baixo
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
					calculaNotasEMoedas();
					break;
				case 2:
					//preencheCheque();
					break;
				case 4:
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
	int aux = 1;
	int tent = 0;
	moldura();
	gotoxy(50,10);printf("Bem-vindo ao sistema BitTech");
	gotoxy(45,12);printf("Pressione qualquer tecla para continuar...");
	hideCursor();
	
	if(tecla = getch()){
		login(aux, tent);
	}
}

void login(int verifica, int tentativas){
	char senha[100];
	char senhaOriginal[100];
	
	strcpy(senhaOriginal,"alg321");
	
	char aux;
	int tent = tentativas; // conta a quantidade de tentativas do usuário
	int a = -1;
	int b = 26;
	int verificacao = 1;
	int i = 0;
	
	system("cls");
	moldura();
	showCursor();
	gotoxy(60,3);printf("LOGIN");
	gotoxy(30,6);printf("Nosso sistema eh protegido por senha. Por favor, entre com a senha do admin.");
	gotoxy(20,8);printf("Usuario: admin ");
	gotoxy(20,10);printf("Senha: ");
	if(verifica == 0){
		gotoxy(40,20);printf("Senha incorreta! Por favor, digite novamente.");
		gotoxy(b,10);
	}
	
	if(verifica == 2){
		gotoxy(40,20);printf("Por favor, digite a senha antes de pressionar enter.");
		gotoxy(b,10);	
	}
	fflush(stdin);	
	do{
		aux = getch();
		if(aux > 32){// é caracter que posso escrever, ou seja, não é enter etc
			a++;
			senha[a] = aux;
			b++;
			gotoxy(b,10);printf("*");
		}else{
			if(aux == 8 && a != -1){//backspace - to apagando
				a--;
				senha[a] = '\0';
				b--;
            	printf("%s", "\b \b");
			}
		}		
	}while(aux!=13);
	
	if(strcmp(senha,senhaOriginal) == 0){
		system("cls");
		moldura();
		gotoxy(50,10);printf("Login realizado com sucesso!");
		gotoxy(40,12);printf("Voce esta sendo redirecionado para o sistema...");
		Sleep(2000);
		menu();
	}else{
		if(a != -1){
			if(tent<6 && tent!=3 && tent!=6){
				tent++;
				verificacao=0;
				login(verificacao, tent);
			}else if(tent==3){
				system("cls");
				gotoxy(40,2);printf("Infelizmente, voce errou a senha 3 vezes!");
				gotoxy(40,4);printf("Espere 5 segundos para tentar novamente...");
				printf("\n\n");
				for(i=5;i>0;i--){
					printf("\t\t   %d...",i);
					Sleep(1000);
				}
				tent++;
				verificacao=0;
				login(verificacao,tent);
			}else if(tent==6){
				system("cls");
				gotoxy(40,2);printf("Infelizmente, voce errou a senha 6 vezes!");
				gotoxy(40,4);printf("Por questoes de seguranca, vamos encerrar o programa...");
				printf("\n\n");
				exit(0);
			}
		}else{
			verificacao = 2;
			login(verificacao, tent);
		}
		
	}
}

int main(){
	system("mode con:cols=131 lines=31");
	menuBoasVindas();
}
