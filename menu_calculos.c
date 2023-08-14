#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define pi 3.141592
//função de titulo
void stitulo (char sym,char sym2,int contador,char* tittle){
	int I;
	for(I=1;I<=contador;I++)
	 printf("%c",sym);
	 printf("\n\t\t\t|%s|\n",tittle);
	 for(I=1;I<=contador;I++)	
	 printf("%c",sym2);
	 ;}	 
//funções de nutri;	 
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
    stitulo('=','=',80,"CÁLCULO DO PERCENTUAL DE GORDURA");
    float tric, sub, peit, aux, abdo, supra, coxa;
    char nome[40];
    int idade;
    printf("\nDigite seu nome: ");
    scanf("%s", nome);
    fflush(stdin);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    fflush(stdin);
    printf("Digite a medida do Tríceps (em mm): ");
    scanf("%f", &tric);
    fflush(stdin);
    printf("Digite a medida do Subescapular (em mm): ");
    scanf("%f", &sub);
    fflush(stdin);
    printf("Digite a medida do Peitoral (em mm): ");
    scanf("%f", &peit);
    fflush(stdin);
    printf("Digite a medida do Axilar Média (em mm): ");
    scanf("%f", &aux);
    fflush(stdin);
    printf("Digite a medida do Abdominal (em mm): ");
    scanf("%f", &abdo);
    fflush(stdin);
    printf("Digite a medida do Suprailíaca (em mm): ");
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
    stitulo('=','=',80,"CÁLCULO DO ÍNDICE DE MASSA CORPORAL (IMC)");
    float peso, altura;
    printf("\nDigite o peso (em kg): ");
    scanf("%f", &peso);
    fflush(stdin);
    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);
    fflush(stdin);
    
    float IMC = peso / (altura * altura);
    
    system("cls");
    stitulo('=','=',80,"RESULTADO DO ÍNDICE DE MASSA CORPORAL (IMC)");
    printf("\nPeso: %.2f kg\n", peso);
    printf("Altura: %.2f metros\n", altura);
    printf("IMC: %.2f\n", IMC);
    puts("================================================================================");
    printf("Classificação:\n");
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
    stitulo('=','=',80,"CÁLCULO DO GASTO ENERGÉTICO DIÁRIO");
    int genero;
    float peso, altura;
    int idade;
    float FA;
    float tmb, GE;
    
    printf("\nInforme o gênero (0 para homem, 1 para mulher): ");
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
    printf("Informe o fator de atividade física:\n");
    printf("1 - Sedentário (pouco ou nenhum exercício)\n");
    printf("2 - Levemente ativo (exercício leve 1-3 dias por semana)\n");
    printf("3 - Moderadamente ativo (exercício moderado 3-5 dias por semana)\n");
    printf("4 - Muito ativo (exercício intenso 6-7 dias por semana)\n");
    printf("5 - Extremamente ativo (exercício intenso diariamente ou atividade física extenuante 2x/dia)\n");
    printf("\nOpção: ");
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
            printf("\nOpção inválida. O fator de atividade física será considerado como 1.0 (sedentário).\n");
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
    printf("Gênero: %s\n", genero == 0 ? "Masculino" : "Feminino");
    printf("Peso: %.2f kg\n", peso);
    printf("Altura: %.2f cm\n", altura);
    printf("Idade: %d anos\n", idade);
    printf("Fator de atividade física: %.2f\n", FA);
    printf("Gasto energético basal: %.2f calorias\n", tmb);
    printf("Gasto energético total: %.2f calorias\n", GE);
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
			puts("\n\t 1 - Calcular Área de Figuras Planas");
	      	puts("\t 2 - Calcular Volume de Sólidos Geométricos"); 
	      	puts("\t 3 - Conversão de Medidas");
	      	puts("\t 4 - Cálculos Nutricionais");
	      	puts("\t 5 - Sair");
	    printf("\n\t opção: ");		scanf("%d",&opcao);		fflush(stdin);
		
		switch(opcao){
			case 1:{//sub1
				do{system("cls");
					stitulo('=','=',80,"CALCULE AREAS DE FIGURAS PLANAS");
						puts("\n\t 1 - Círculo");
						puts("\n\t 2 - Losango");
						puts("\n\t 3 - Paralelogramo");
						puts("\n\t 4 - Trapézio");
						puts("\n\t 5 - Triângulo");
						puts("\n\t 6 - Digite 0 para sair");
					printf("\t opção: ");
					scanf("%d",&opcao);
					fflush(stdin);
					
				switch(opcao){
					case 1:{system("cls");
						stitulo('=','=',80,"01 - CÁLCULO DA ÁREA DO CÍRCULO");
						printf("\ninforme o raio do círculo: ");	scanf("%f",&raio);	fflush(stdin);
						printf("A área desse círculo é: %.4f\n",pi*(raio*raio));
						system("pause");
						break;}
					case 2:{system("cls");
						stitulo('=','=',80,"01 - CÁLCULO DA ÁREA DO LOSANGO");
						printf("\nInforme a Diagonal maior:");	scanf("%f",&D);		fflush(stdin);
						printf("Informe a Diagonal menor:");	scanf("%f",&d);		fflush(stdin);
						printf("A área do Losango é: %.4f\n",(D*d)/2);
						system("pause");
						break;}
					case 3:{system("cls");
						stitulo('=','=',80,"03 - CÁLCULO DA ÁREA DO PARALELOGRAMO");
						printf("\nInforme a base:");	scanf("%f",&B);		fflush(stdin);
						printf("Informe a altura:");	scanf("%f",&H);		fflush(stdin);
						printf("A área do Paralelogramo é: %.4f\n",(B*H));
						system("pause");
						break;}
					case 4:{system("cls");
						stitulo('=','=',80,"04 - CÁLCULO DA ÁREA DO TRAPÉZIO");
						printf("\nInforme a base maior:");		scanf("%f",&B);		fflush(stdin);
						printf("Informe a base menor:");		scanf("%f",&B2);	fflush(stdin);
						printf("Informe a altura:");			scanf("%f",&H);		fflush(stdin);
						printf("A área do Paralelogramo é: %.4f\n",(((B+B2)*H)/2));
						system("pause");
						break;}
					case 5:{system("cls");
						stitulo('=','=',80,"05 - CÁLCULO DA ÁREA DO TRIÂNGULO");
						printf("\nPara evitar resultados invalidos, não atribua valores negativos aos lados.\n");
						printf("Observe também, se os valores atribuidos respeitam a lei da desigualdade triângular\n");
						printf("a soma de quaisquer dois lados do triângulo deve ser maior que o terceiro lado\n");
						system("pause");
						printf("\nInforme o 1.o lado do triângulo:");		scanf("%f",&a);		fflush(stdin);
						printf("\nInforme o 2.o lado do triângulo:");		scanf("%f",&b);		fflush(stdin);
						printf("\nInforme o 3.o lado do triângulo:");		scanf("%f",&c);		fflush(stdin);
						p=(a+b+c)/2;
						AT=sqrt(p*(p-a)*(p-b)*(p-c));
						printf("A área do triângulo é:%f\n",AT);
						system("pause");
						break;}
					case 0:{break;}
					default:puts("Opção inválida. Digite novamente.\n");		system("pause");}
				
				}while(opcao!=0);
				break;
			}
			case 2:{//sub2
				do{
				system("cls");
						stitulo('=','=',80,"CÁLCULE O VOLUME DE SOLIDOS GEOMÉTRICOS");
						puts("\n\t 1 - Esfera");
						puts("\n\t 2 - Cone Círcular");
						puts("\n\t 3 - Cilindro");
						puts("\n\t 4 - Paralelepípedo");
						puts("\n\t 5 - Digite 0 para sair");
					printf("\n\t opcao: ");
					scanf("%d",&opcao);
					fflush(stdin);
				switch(opcao){
					case 1:{system("cls");
						stitulo('=','=',80,"01 - CÁLCULO DO VOLUME DE UMA ESFERA");
						printf("\ninforme o raio da esfera: ");		scanf("%f",&raio);		fflush(stdin);
						printf("O volume dessa esfera é: %.4f\n",((4*pi)*(raio*raio*raio)/3));					
						system("pause");
						break;}
					case 2:{system("cls");
						stitulo('=','=',80,"02 - CÁLCULO DO VOLUME DE UM CONE CÍRCULAR");
						printf("\ninforme o raio da base: ");	scanf("%f",&raio);		fflush(stdin);
						printf("informe a altura do cone: ");	scanf("%f",&H);			fflush(stdin);
						printf("\nO volume desse cone circular é: %.4f\n",(pi*(raio*raio)*H)/3);
						system("pause");
						break;}
					case 3:{system("cls");
						stitulo('=','=',80,"03 - CÁLCULO DO VOLUME DE UM CILINDRO");
						printf("\ninforme o raio da base: ");	scanf("%f",&raio);		fflush(stdin);
						printf("informe a altura do cone: ");	scanf("%f",&H);			fflush(stdin);
						printf("O volume desse cilindro é: %.4f\n",(pi*(raio*raio)*H));
						system("pause");
						break;}
					case 4:{system("cls");
						stitulo('=','=',80,"04 - CÁLCULO DO VOLUME DE PARALELEPIPEDO");
						printf("\ninforme o comprimento: ");	scanf("%f",&a);		fflush(stdin);
						printf("informe a largura: ");			scanf("%f",&b);		fflush(stdin);
						printf("informe a altura: ");			scanf("%f",&H);		fflush(stdin);
						printf("O volume desse paralelepipedo é: %.4f\n",(a*b*H));
						system("pause");
						break;}
					case 0:{break;}
					default:{puts("Opção inválida. Digite novamente.\n");system("pause");}
				}
				}while(opcao!=0);
				break;
			}
			case 3:{//sub3
				do{
				system("cls");
					stitulo('=','=',80,"CONVERSOR DE MEDIDAS");
						puts("\n\t 1 - Metros para Jardas\t\t\t\t\t\t 5 - Litros para Galões");	
						puts("\n\t 2 - Jardas para Metros\t\t\t\t\t\t 6 - Galões para Litros");
						puts("\n\t 3 - Centímetros cúbicos para polegadas cúbicas\t\t\t 7 - Quilograma para Libras");
						puts("\n\t 4 - Polegadas cúbicas para Centímetros cúbicos\t\t\t 8 - Libras para Quilogramas");
						puts("\n\t\t\t\t\t 9 - Digite 0 para sair");
					printf("\n\t opção: ");
					scanf("%d",&opcao);
					fflush(stdin);
				switch(opcao){
					case 1:{system("cls");
						stitulo('=','=',80,"01 - CONVERTER METROS PARA JARDAS");
						printf("\nInforme o valor em metros a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/0.9144;
						printf("\n%.2f metros é igual a %.4f jardas\n",medida,conv);
						system("pause");
						break;}
					case 2:{system("cls");
						stitulo('=','=',80,"02 - CONVERTER JARDAS PARA METROS");
						printf("\nInforme o valor em jardas a serem convertidas:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*0.9144;
						printf("\n%.2f jardas é igual a %.4f metros\n",medida,conv);
						system("pause");
						break;}
					case 3:{system("cls");
						stitulo('=','=',80,"03 - CONVERTER Cent.³ PARA POLEGADAS³");
						printf("\nInforme o valor em centimetros³ a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/16.387;
						printf("\n%.2f cent.³ é igual a %.3f pol.³\n",medida,conv);
						system("pause");
						break;}
					case 4:{system("cls");
						stitulo('=','=',80,"04 - CONVERTER POLEGADAS³ PARA CM³");
						printf("\nInforme o valor em polegadas³ a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*16.387;
						printf("\n%.2f pol.³ é igual a %.3f cent.³\n",medida,conv);
						system("pause");
						break;}
					case 5:{system("cls");
						stitulo('=','=',80,"05 - CONVERTER LITROS PARA GALÕES");
						printf("\nInforme o valor em litros a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*0.2642;
						printf("\n%.2f litros é igual a %.4f galões\n",medida,conv);
						system("pause");
						break;}
					case 6:{system("cls");
						stitulo('=','=',80,"06 - CONVERTER GALÕES PARA LITROS");
						printf("\nInforme o valor em galões a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/0.2642;
						printf("\n%.2f galões é igual a %.4f litros\n",medida,conv);
						system("pause");
						break;}
					case 7:{system("cls");
						stitulo('=','=',80,"07 - CONVERTER QUILOGRAMAS PARA LIBRAS");
						printf("\nInforme o valor em libras a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida*2.2046;
						printf("\n%.2f kg. é igual a %.4f lb.\n",medida,conv);
						system("pause");
						break;}
					case 8:{system("cls");
						stitulo('=','=',80,"08 - CONVERTER LIBRAS PARA QUILOGRAMAS");
						printf("\nInforme o valor em quilos a serem convertidos:");	scanf("%f",&medida);	fflush(stdin);
						conv=medida/2.2046;
						printf("\n%.2f lb. é igual a %.4f kg.\n",medida,conv);
						system("pause");
						break;}
					case 0:{break;}
					
					default:{puts("Opção inválida. Digite novamente.\n");system("pause");}		
				}
				}while(opcao!=0);
				break;}
			case 4:{//sub4
				do {
				system("cls");
					stitulo('=','=',80,"CÁLCULOS NUTRICIONAIS");
						puts("\n\t 1 - Cálculo da gordura corporal");
						puts("\n\t 2 - Cálculo do gasto energético diário");
						puts("\n\t 3 - Cálculo do Índice de Massa Corporal (IMC))");
						puts("\n\t 0 - Sair");
					printf("\n\t opção: ");
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
            default:{puts("Opção inválida. Digite novamente.");system("pause");}
        }
    } while (opcao != 0);
			}
			case 5:{//fechar o programa
				break;
			}
			default:{puts("Opção inválida. Digite novamente.\n");system("pause");}}
	
		system("cls");	
	}
	while(opcao!=5);
}	
