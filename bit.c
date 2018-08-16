//Bianca Dias Barbosa e Henrique Marciano da Silva - BSI 2018
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 11
float convertToFloat(char bitS[], float bitF){
    bitF = atof(bitS);
    return bitF;
}

int verifyBit(char bitS[]){
    int cont = 0;
    for(int i = 0; i < strlen(bitS); i++){
        if(bitS[i] == ',')
            return 0;
        if(bitS[i] == '.'){
            for(int j = i+1; j < strlen(bitS);j++){
                if(bitS[j] != '\0')
                    cont++;
            }
            return cont;
        }
    }
    return 1;
}

void bitCount(float bitF, float money[]){
    double div, rest = bitF;
    rest = ceil(rest*1000)/1000.0;
    printf("bitF = %lf", rest);
    int i,intDiv;
    printf("\n");
    for(i = 0; i < 11; i++){
        div = rest/money[i];
        intDiv = (int)div;
        rest -= intDiv * money[i];
        printf("intDiv = %d\n",intDiv);
        if(intDiv > 0 && i <= 5)
            printf("%d nota(s) de %.2f Bits\n", intDiv, money[i]);
        else if(intDiv > 0 && i > 5)
            printf("%d moeda(s) de %.2f CentBits\n", intDiv, money[i]);
    }
}

int main(){
	char bitS[50];
	float bitF, money[N] = {100,50,20,10,5,2,1,0.5,0.25,0.1,0.01};
	int cont;
	do{
        printf("\nPor favor, insira a quantia de bits que deseja sacar (precisao de duas casas): ");
        scanf("%s", &bitS);
        cont = verifyBit(bitS);
        if(cont == 0){
            system("cls");
            printf("\nPor favor, utilize ponto no lugar da virgula.\n");
        }

	} while(cont > 2 || cont == 0);
	bitF = convertToFloat(bitS, bitF);
	//printf("%f",bitF);  //-- CORRIGIR AS CASAS DECIMAIS DO FLOAT.
	bitCount(bitF, money);
}
