#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define pi 3.141592
//fun��o de titulo
void stitulo (char sym,char sym2,int contador,char* tittle){
	int I;
	for(I=1;I<=contador;I++)
	 printf("%c",sym);
	 printf("\n\t\t\t|%s|\n",tittle);
	 for(I=1;I<=contador;I++)	
	 printf("%c",sym2);
	 ;}	 
//fun��es de nutri;	 
float calhomem(float peso, float altura, int idade) {
    return 66 + (13.75 * peso) + (5 * altura) - (6.75 * idade);
}

float calmulher(float peso, float altura, int idade) {
    return 655 + (9.56 * peso) + (1.85 * altura) - (4.68 * idade);
}

float CGE(float tmb, float FA) {
    return tmb * FA;
}

void calcularGordura() {
   
    system("cls");
    stitulo('=','=',80,"C�LCULO DO PERCENTUAL DE GORDURA");
    float tric, sub, peit, aux, abdo, supra, coxa;
    char nome[40];
    int idade;
    printf("\nDigite seu nome: ");
    scanf("%s", nome);
    fflush(stdin);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    fflush(stdin);
    printf("Digite a medida do Tr�ceps (em mm): ");
    scanf("%f", &tric);
    fflush(stdin);
    printf("Digite a medida do Subescapular (em mm): ");
    scanf("%f", &sub);
    fflush(stdin);
    printf("Digite a medida do Peitoral (em mm): ");
    scanf("%f", &peit);
    fflush(stdin);
    printf("Digite a medida do Axilar M�dia (em mm): ");
    scanf("%f", &aux);
    fflush(stdin);
    printf("Digite a medida do Abdominal (em mm): ");
    scanf("%f", &abdo);
    fflush(stdin);
    printf("Digite a medida do Suprail�aca (em mm): ");
    scanf("%f", &supra);
    fflush(stdin);
    printf("Digite a medida do Coxa (em mm): ");
    scanf("%f", &coxa);
    fflush(stdin);
    float dobras = tric + sub + peit + aux + abdo + supra + coxa;
    float DC = 1.112 - (0.00043499 * dobras) + (0.00000055 * (dobras * dobras)) - (0.00028826 * idade);
    float PG = (495 / DC) - 450;
    
    system("cls");
    stitulo('=','=',80,"RESULTADO DO PERCENTUAL DE GORDURA");
    printf("\nNome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    printf("Percentual de gordura: %.2f%%\n", PG);
    system("pause");
}

void calcularIMC() {
    system("cls");
    stitulo('=','=',80,"C�LCULO DO �NDICE DE MASSA CORPORAL (IMC)");
    float peso, altura;
    printf("\nDigite o peso (em kg): ");
    scanf("%f", &peso);
    fflush(stdin);
    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);
    fflush(stdin);
    
    float IMC = peso / (altura * altura);
    
    system("cls");
    stitulo('=','=',80,"RESULTADO DO �NDICE DE MASSA CORPORAL (IMC)");
    printf("\nPeso: %.2f kg\n", peso);
    printf("Altura: %.2f metros\n", altura);
    printf("IMC: %.2f\n", IMC);
    puts("================================================================================");
    printf("Classifica��o:\n");
    if (IMC < 18.5) {
        printf("Abaixo do peso\n");
    } else if (IMC <= 24.9) {
        printf("Peso normal\n");
    } else if (IMC <= 29.9) {
        printf("Sobrepeso\n");
    } else if (IMC <= 34.9) {
        printf("Obesidade grau 1\n");
    } else if (IMC <= 39.9) {
        printf("Obesidade grau 2\n");
    } else {
        printf("Obesidade grau 3\n");
    }
    system("pause");
}

void calcularGastoEnergetico() {
    system("cls");
    stitulo('=','=',80,"C�LCULO DO GASTO ENERG�TICO DI�RIO");
    int genero;
    float peso, altura;
    int idade;
    float FA;
    float tmb, GE;
    
    printf("\nInforme o g�nero (0 para homem, 1 para mulher): ");
    scanf("%d", &genero);
    fflush(stdin);
    printf("Informe o peso em kg: ");
    scanf("%f", &peso);
    fflush(stdin);
    printf("Informe a altura em cm: ");
    scanf("%f", &altura);
    fflush(stdin);
    printf("Informe a idade em anos: ");
    scanf("%d", &idade);
    fflush(stdin);
    printf("Informe o fator de atividade f�sica:\n");
    printf("1 - Sedent�rio (pouco ou nenhum exerc�cio)\n");
    printf("2 - Levemente ativo (exerc�cio leve 1-3 dias por semana)\n");
    printf("3 - Moderadamente ativo (exerc�cio moderado 3-5 dias por semana)\n");
    printf("4 - Muito ativo (exerc�cio intenso 6-7 dias por semana)\n");
    printf("5 - Extremamente ativo (exerc�cio intenso diariamente ou atividade f�sica extenuante 2x/dia)\n");
    printf("\nOp��o: ");
    scanf("%f", &FA);
    fflush(stdin);
    
    switch ((int)FA) {
        case 1:
            FA = 1.2;
            break;
        case 2:
            FA = 1.375;
            break;
        case 3:
            FA = 1.55;
            break;
        case 4:
            FA = 1.725;
            break;
        case 5:
            FA = 1.9;
            break;
        default:
            printf("\nOp��o inv�lida. O fator de atividade f�sica ser� considerado como 1.0 (sedent�rio).\n");
            FA = 1.0;
            break;
    }
    
    if (genero == 0) {
        tmb = calhomem(peso, altura, idade);
    } else {
        tmb = calmulher(peso, altura, idade);
    }
    
    GE = CGE(tmb, FA);
    
    system("cls");
    printf("==========================================================\n");
    printf("G�nero: %s\n", genero == 0 ? "Masculino" : "Feminino");
    printf("Peso: %.2f kg\n", peso);
    printf("Altura: %.2f cm\n", altura);
    printf("Idade: %d anos\n", idade);
    printf("Fator de atividade f�sica: %.2f\n", FA);
    printf("Gasto energ�tico basal: %.2f calorias\n", tmb);
    printf("Gasto energ�tico total: %.2f calorias\n", GE);
    printf("==========================================================\n");
    system("pause");
}
int main(){
    system("color 3E");
	int opcao;
	float AT,p,raio,D,d,B,B2,H,a,b,c,medida,conv;
	setlocale(LC_ALL, "portuguese");
	do
	{stitulo('=','=',80,"M E N U  P R I N C I P A L");
		printf("\n\t\t\t  ESCOLHA A OPCAO DESEJADA\n");
			puts("\n\t 1 - Calcular �rea de Figuras Planas");
	      	puts("\t 2 - Calcular Volume de S�lidos Geom�tricos"); 
	      	puts("\t 3 - Convers�o de Medidas");
	      	puts("\t 4 - C�lculos Nutricionais");
	      	puts("\t 5 - Sair");
	    printf("\n\t op��o: ");		scanf("%d",&opcao);		fflush(stdin);
		
		switch(opcao){
			case 1:{//sub1
				do{system("cls");
					stitulo('=','=',80,"CALCULE AREAS DE FIGURAS PLANAS");
						puts("\n\t 1 - C�rculo");
						puts("\n\t 2 - Losango");
						puts("\n\t 3 - Paralelogramo");
						puts("\n\t 4 - Trap�zio");
						puts("\n\t 5 - Tri�ngulo");
						puts("\n\t 6 - Digite 0 para sair");
					printf("\t op��o: ");
					scanf("%d",&opcao);
					fflush(stdin);
					
				switch(opcao){
					case 1:{system("cls");
						stitulo('=','=',80,"01 - C�LCULO DA �REA DO C�RCULO");
						printf("\ninforme o raio do c�rculo: ");	scanf("%f",&raio);	fflush(stdin);
						printf("A �rea desse c�rculo �: %.4f\n",pi*(raio*raio));
						system("pause");
						break;}
					case 2:{system("cls");
						stitulo('=','=',80,"01 - C�LCULO DA �REA DO LOSANGO");
						printf("\nInforme a Diagonal maior:");	scanf("%f",&D);		fflush(stdin);
						printf("Informe a Diagonal menor:");	scanf("%f",&d);		fflush(stdin);
						printf("A �rea do Losango �: %.4f\n",(D*d)/2);
						system("pause");
						break;}
					case 3:{system("cls");
						stitulo('=','=',80,"03 - C�LCULO DA �REA DO PARALELOGRAMO");
						printf("\nInforme a base:");	scanf("%f",&B);		fflush(stdin);
						printf("Informe a altura:");	scanf("%f",&H);		fflush(stdin);
						printf("A �rea do Paralelogramo �: %.4f\n",(B*H));
						system("pause");
						break;}
					case 4:{system("cls");
						stitulo('=','=',80,"04 - C�LCULO DA �REA DO TRAP�ZIO");
						printf("\nInforme a base maior:");		scanf("%f",&B);		fflush(stdin);
						printf("Informe a base menor:");		scanf("%f",&B2);	fflush(stdin);
						printf("Informe a altura:");			scanf("%f",&H);		fflush(stdin);
						printf("A �rea do Paralelogramo �: %.4f\n",(((B+B2)*H)/2));
						system("pause");
						break;}
					case 5:{system("cls");
						stitulo('=','=',80,"05 - C�LCULO DA �REA DO TRI�NGULO");
						printf("\nPara evitar resultados invalidos, n�o atribua valores negativos aos lados.\n");
						printf("Observe tamb�m, se os valores atribuidos respeitam a lei da desigualdade tri�ngular\n");
						printf("a soma de quaisquer dois lados do tri�ngulo deve ser maior que o terceiro lado\n");
						system("pause");
						printf("\nInforme o 1.o lado do tri�ngulo:");		scanf("%f",&a);		fflush(stdin);
						printf("\nInforme o 2.o lado do tri�ngulo:");		scanf("%f",&b);		fflush(stdin);
						printf("\nInforme o 3.o lado do tri�ngulo:");		scanf("%f",&c);		fflush(stdin);
						p=(a+b+c)/2;
						AT=sqrt(p*(p-a)*(p-b)*(p-c));
						printf("A �rea do tri�ngulo �:%f\n",AT);
						system("pause");
						break;}
					case 0:{break;}
					default:puts("Op��o inv�lida. Digite novamente.\n");		system("pause");}
				
				}while(opcao!=0);
				break;
			}
			case 2:{//sub2
				do{
				system("cls");
						stitulo('=','=',80,"C�LCULE O VOLUME DE SOLIDOS GEOM�TRICOS");
						puts("\n\t 1 - Esfera");
						puts("\n\t 2 - Cone C�rcular");
						puts("\n\t 3 - Cilindro");
						puts("\n\t 4 - Paralelep�pedo");
						puts("\n\t 5 - Digite 0 para sair");
					printf("\n\t opcao: ");
					scanf("%d",&opcao);
					fflush(stdin);
				switch(opcao){
					case 1:{system("cls");
						stitulo('=','=',80,"01 - C�LCULO DO VOLUME DE UMA ESFERA");
						printf("\ninforme o raio da esfera: ");		scanf("%f",&raio);		fflush(stdin);
						printf("O volume dessa esfera �: %.4f\n",((4*pi)*(raio*raio*raio)/3));					
						system("pause");
						break;}
					case 2:{system("cls");
						stitulo('=','=',80,"02 - C�LCULO DO VOLUME DE UM CONE C�RCULAR");
						printf("\ninforme o raio da base: ");	scanf("%f",&raio);		fflush(stdin);
						printf("informe a altura do cone: ");	scanf("%f",&H);			fflush(stdin);
						printf("\nO volume desse cone circular �: %.4f\n",(pi*(raio*raio)*H)/3);
						system("pause");
						break;}
					case 3:{system("cls");
						stitulo('=','=',80,"03 - C�LCULO DO VOLUME DE UM CILINDRO");
						printf("\ninforme o raio da base: ");	scanf("%f",&raio);		fflush(stdin);
						printf("informe a altura do cone: ");	scanf("%f",&H);			fflush(stdin);
						printf("O volume desse cilindro �: %.4f\n",(pi*(raio*raio)*H));
						system("pause");
						break;}
					case 4:{system("cls");
						stitulo('=','=',80,"04 - C�LCULO DO VOLUME DE PARALELEPIPEDO");
						printf("\ninforme o comprimento: ");	scanf("%f",&a);		fflush(stdin);
						printf("informe a largura: ");			scanf("%f",&b);		fflush(stdin);
						printf("informe a altura: ");			scanf("%f",&H);		fflush(stdin);
						printf("O volume desse paralelepipedo �: %.4f\n",(a*b*H));
						system("pause");
						break;}
					case 0:{break;}
					default:{puts("Op��o inv�lida. Digite novamente.\n");system("pause");}
				}
				}while(opcao!=0);
				break;
			}
			case 3:{//sub3
				do{
				system("cls");
					stitulo('=','=',80,"CONVERSOR DE MEDIDAS");
						puts("\n\t 1 - Metros para Jardas\t\t\t\t\t\t 5 - Litros para Gal�es");	
						puts("\n\t 2 - Jardas para Metros\t\t\t\t\t\t 6 - Gal�es para Litros");
						puts("\n\t 3 - Cent�metros c�bicos para polegadas c�bicas\t\t\t 7 - Quilograma para Libras");
						puts("\n\t 4 - Polegadas c�bicas para Cent�metros c�bicos\t\t\t 8 - Libras para Quilogramas");
						puts("\n\t\t\t\t\t 9 - Digite 0 para sair");
					printf("\n\t op��o: ");
					scanf("%d",&opcao);
					fflush(stdin);
				switch(opcao){
					case 1:{system("cls");
						stitulo('=','=',80,"01 - CONVERTER METROS PARA JARDAS");
						printf("\nInforme o valor em metros a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/0.9144;
						printf("\n%.2f metros � igual a %.4f jardas\n",medida,conv);
						system("pause");
						break;}
					case 2:{system("cls");
						stitulo('=','=',80,"02 - CONVERTER JARDAS PARA METROS");
						printf("\nInforme o valor em jardas a serem convertidas:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*0.9144;
						printf("\n%.2f jardas � igual a %.4f metros\n",medida,conv);
						system("pause");
						break;}
					case 3:{system("cls");
						stitulo('=','=',80,"03 - CONVERTER Cent.� PARA POLEGADAS�");
						printf("\nInforme o valor em centimetros� a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/16.387;
						printf("\n%.2f cent.� � igual a %.3f pol.�\n",medida,conv);
						system("pause");
						break;}
					case 4:{system("cls");
						stitulo('=','=',80,"04 - CONVERTER POLEGADAS� PARA CM�");
						printf("\nInforme o valor em polegadas� a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*16.387;
						printf("\n%.2f pol.� � igual a %.3f cent.�\n",medida,conv);
						system("pause");
						break;}
					case 5:{system("cls");
						stitulo('=','=',80,"05 - CONVERTER LITROS PARA GAL�ES");
						printf("\nInforme o valor em litros a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*0.2642;
						printf("\n%.2f litros � igual a %.4f gal�es\n",medida,conv);
						system("pause");
						break;}
					case 6:{system("cls");
						stitulo('=','=',80,"06 - CONVERTER GAL�ES PARA LITROS");
						printf("\nInforme o valor em gal�es a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/0.2642;
						printf("\n%.2f gal�es � igual a %.4f litros\n",medida,conv);
						system("pause");
						break;}
					case 7:{system("cls");
						stitulo('=','=',80,"07 - CONVERTER QUILOGRAMAS PARA LIBRAS");
						printf("\nInforme o valor em libras a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*2.2046;
						printf("\n%.2f kg. � igual a %.4f lb.\n",medida,conv);
						system("pause");
						break;}
					case 8:{system("cls");
						stitulo('=','=',80,"08 - CONVERTER LIBRAS PARA QUILOGRAMAS");
						printf("\nInforme o valor em quilos a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/2.2046;
						printf("\n%.2f lb. � igual a %.4f kg.\n",medida,conv);
						system("pause");
						break;}
					case 0:{break;}
					
					default:{puts("Op��o inv�lida. Digite novamente.\n");system("pause");}		
				}
				}while(opcao!=0);
				break;}
			case 4:{//sub4
				do {
				system("cls");
					stitulo('=','=',80,"C�LCULOS NUTRICIONAIS");
						puts("\n\t 1 - C�lculo da gordura corporal");
						puts("\n\t 2 - C�lculo do gasto energ�tico di�rio");
						puts("\n\t 3 - C�lculo do �ndice de Massa Corporal (IMC))");
						puts("\n\t 0 - Sair");
					printf("\n\t op��o: ");
					scanf("%d",&opcao);
					fflush(stdin);			
        switch (opcao) {
            case 1:
                calcularGordura();
                break;
            case 2:
                calcularGastoEnergetico();
                break;
            case 3:
                calcularIMC();
                break;
            case 0:
                printf("\nSaindo do programa.\n");
                break;
            default:{puts("Op��o inv�lida. Digite novamente.");system("pause");}
        }
    } while (opcao != 0);
			}
			case 5:{//fechar o programa
				break;
			}
			default:{puts("Op��o inv�lida. Digite novamente.\n");system("pause");}}
	
		system("cls");	
	}
	while(opcao!=5);
}	
