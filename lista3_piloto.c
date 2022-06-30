/* Beatriz Rodrigues Monteiro
	UC20100019*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PILOTOS 400
#define MAX_CIRCUITO 1000
#define MAX_VOLTA 1000

typedef struct Piloto{
	char nome[120], sexo[20], pais[100];
	int codigo, idade;
} Piloto;

typedef struct Circuito{
	char nome[120], pais[100];
	int codigo, piloto, tamanho, tempoMinuto, tempoSegundo, tempoMilisegundo;
} Circuito;

typedef struct MelhorVolta{
	char equipe[100];
	int pilotoCodigo, circuitoCodigo, dia, mes, ano, minuto, segundo, milisegundo;
} MelhorVolta;

int verificarCodigoPiloto(Piloto*codigoPiloto);
char*verificarNomePiloto(Piloto*nomePiloto);
char*verificarSexoPiloto(Piloto*sexoPiloto);
char*verificarPaisPiloto(Piloto*paisPiloto);
int verificarIdadePiloto(Piloto*idadePiloto);

int verificarCodigoC(Circuito*codigoCircuito);
char*verificarNomeCircuito(Circuito*nomeCircuito);
char*verificarPaisCircuito(Circuito*paisCircuito);
int verificarTamanho(Circuito*tamanhoCircuito);
int verificarMinuto(Circuito*minutoCircuito);
int verificarSegundo(Circuito*segundoCircuito);
int verificarMilisegundo(Circuito*milisegundoCircuito);
int verificarCodigo(Circuito*codigoTeste);

int identificarCodigoPiloto(MelhorVolta*identificaPiloto);
int identificarCodigoCircuito(MelhorVolta*identificaCircuito);
char*verificarEquipePiloto(MelhorVolta*equipePiloto);
int identificarMinuto(MelhorVolta*minutoCircuito);
int identificarSegundo(MelhorVolta*segundoCircuito);
int identificarMilisegundo(MelhorVolta*milisegundoCircuito);
int identificarDia(MelhorVolta*diaCircuito);
int identificarMes(MelhorVolta*mesCircuito);
int identificarAno(MelhorVolta*anoCircuito);


int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int i = 0, j = 0, k = 0, tam = 0, testeC = 0, testeP = 0;
	int opcaoMenu = 0, contadorPiloto = 0, contadorCircuito = 0, contadorMelhor = 0;
	int circuitoProcurado = 0, pesquisaCodigo = 0, codigoProcurado = 0, minutoProcurado = 0, segundoProcurado = 0, milisegundoProcurado = 0;
	char pilotoProcurado[100];
	
	Piloto piloto[MAX_PILOTOS];
	Circuito circuito[MAX_CIRCUITO];
	MelhorVolta volta[MAX_VOLTA];
	
	do{
		printf("-----------------------------\n");
		printf("           MENU              \n");
		printf("-----------------------------\n\n");
		printf("1- CADASTRAR PILOTO\n");
		printf("2- CADASTRAR CIRCUITO\n");
		printf("3- CADASTRAR MELHOR VOLTA \n");
		printf("4- CONSULTA GERAL\n");
		printf("5- CONSULTA POR PILOTO\n");
		printf("6- CONSULTA POR CIRCUITO\n");
		printf("7- CONSULTA POR MELHOR VOLTA\n");
		printf("8- SAIR\n\n");
		
		printf("INFORME OPÇÃO DESEJADA: ");
		scanf("%d", &opcaoMenu);
		fflush(stdin);
		system("cls");
		
		switch(opcaoMenu){
			case 1:
				piloto[i].codigo = verificarCodigoPiloto(piloto);
				strcpy(piloto[i].nome, verificarNomePiloto(piloto));
				strcpy(piloto[i].sexo, verificarSexoPiloto(piloto));
				strcpy(piloto[i].pais, verificarPaisPiloto(piloto));
				piloto[i].idade = verificarIdadePiloto(piloto);
				i++;
				contadorPiloto++;
				
				system("pause");
				system("cls");
				break;
				
			case 2:
				circuito[j].codigo = verificarCodigoC(circuito);
				strcpy(circuito[j].nome, verificarNomeCircuito(circuito));
				strcpy(circuito[j].pais, verificarPaisCircuito(circuito));
				circuito[j].tamanho = verificarTamanho(circuito);
				circuito[j].tempoMinuto = verificarMinuto(circuito);
				circuito[j].tempoSegundo = verificarSegundo(circuito);
				circuito[j].tempoMilisegundo = verificarMilisegundo(circuito);
				circuito[j].piloto = verificarCodigo(circuito);
				printf("CÓDIGO DO CIRCUITO É: %d\n", circuito[j].codigo);
				j++;
				contadorCircuito++;
				
				system("pause");
				system("cls");
				break;
				
			case 3:
				volta[k].pilotoCodigo = identificarCodigoPiloto(volta);
				volta[k].circuitoCodigo = identificarCodigoCircuito(volta);
				strcpy(volta[k].equipe, verificarEquipePiloto(volta));
				volta[k].minuto = identificarMinuto(volta);
				volta[k].segundo = identificarSegundo(volta);
				volta[k].milisegundo = identificarMilisegundo(volta);
				volta[k].dia = identificarDia(volta);
				volta[k].mes = identificarMes(volta);
				volta[k].ano = identificarAno(volta);
				k++;
				contadorMelhor++;
				
				system("pause");
				system("cls");
				break;
				
			case 4:	
				printf("POSSUI CÓDIGO DO PILOTO (1- SIM | 2 - NAO): ");
				scanf("%d", &pesquisaCodigo);
				fflush(stdin);
				
				if(pesquisaCodigo == 1){
					printf("INFORME CÓDIGO DO PILOTO QUE DESEJA PROCURAR: ");
					scanf("%d", &codigoProcurado);
					fflush(stdin);
						
					for(i = 0; i < contadorPiloto; i++){
						if(piloto[i].codigo == codigoProcurado){
							printf("\nCÓDIGO DO PILOTO: %d\n", piloto[i].codigo);
							printf("NOME DO PILOTO: %s\n", piloto[i].nome);
							printf("SEXO DO PILOTO: %s\n", piloto[i].sexo);
							printf("PAÍS DO PILOTO: %s\n", piloto[i].pais);
							printf("IDADE DO PILOTO: %d\n\n", piloto[i].idade);
						}	
					}
				}
				else if (pesquisaCodigo == 2){ 
					for(i = 0; i < contadorPiloto; i++){
						printf("CÓDIGO DO PILOTO: %d\n", piloto[i].codigo);
						printf("NOME DO PILOTO: %s\n", piloto[i].nome);
						printf("SEXO DO PILOTO: %s\n", piloto[i].sexo);
						printf("PAÍS DO PILOTO: %s\n", piloto[i].pais);
						printf("IDADE DO PILOTO: %d\n\n", piloto[i].idade);
					}
					
					for(j = 0; j < contadorCircuito; j++){
						printf("CÓDIGO DO CIRCUITO: %d\n", circuito[j].codigo);
						printf("NOME DO CIRCUITO: %s\n", circuito[j].nome);
						printf("PAÍS DO CIRCUITO: %s\n", circuito[j].pais);
						printf("TAMANHO DO CIRCUITO: %dkm\n", circuito[j].tamanho);
						printf("MENOR TEMPO: %d MINUTOS, %d SEGUNDOS E %d MILISEGUNDOS\n", circuito[j].tempoMinuto, circuito[j].tempoSegundo, circuito[j].tempoMilisegundo);
						printf("CÓDIGO DO PILOTO COM MENOR TEMPO: %d\n\n", circuito[j].piloto);
					}
					
					for(k = 0; k < contadorMelhor; k++){
						printf("CÓDIGO DO CIRCUITO: %d\n", volta[k].circuitoCodigo);
						printf("CÓDIGO DO PILOTO COM MENOR TEMPO: %d\n", volta[k].pilotoCodigo);
						printf("EQUIPE DO PILOTO COM MENOR TEMPO: %s\n", volta[k].equipe);
						printf("DATA DO CIRCUITO: %d do %d de %d\n", volta[k].dia, volta[k].mes, volta[k].ano);
						printf("MENOR TEMPO: %d MINUTOS, %d SEGUNDOS E %d MILISEGUNDOS\n\n", volta[k].minuto, volta[k].segundo, volta[k].milisegundo);
					}
				}
				
				system("pause");
				system("cls");
				break;
				
			case 5:
				do{
					printf("INFORME NOME DO PILOTO QUE DESEJA PROCURAR: ");
					scanf("%s", &pilotoProcurado);
					fflush(stdin);
						
					tam = strlen(pilotoProcurado);
						
					for(i = 0; i < tam; i++){
						if(strcmp(piloto[i].nome, pilotoProcurado) == 0){
							printf("\nCÓDIGO DO PILOTO: %d\n", piloto[i].codigo);
							printf("NOME DO PILOTO: %s\n", piloto[i].nome);
							printf("SEXO DO PILOTO: %s\n", piloto[i].sexo);
							printf("PAÍS DO PILOTO: %s\n", piloto[i].pais);
							printf("IDADE DO PILOTO: %d\n\n", piloto[i].idade);	
							testeP++;
							break;
						}	
						else{
							printf("Piloto não encontrado\n");
						}
					}
				} while(testeP == 0);
				
				system("pause");
				system("cls");
				break;
			case 6:
				do{
					printf("INFORME CIRCUITO QUE DESEJA PROCURAR: ");
					scanf("%d", &circuitoProcurado);
					fflush(stdin);
						
					for(j = 0; j < contadorCircuito; j++){
						if(circuito[j].codigo == circuitoProcurado){
							printf("CÓDIGO DO CIRCUITO: %d\n", circuito[j].codigo);
							printf("NOME DO CIRCUITO: %s\n", circuito[j].nome);
							printf("PAÍS DO CIRCUITO: %s\n", circuito[j].pais);
							printf("TAMANHO DO CIRCUITO: %dkm\n", circuito[j].tamanho);
							printf("MENOR TEMPO: %d MINUTOS, %d SEGUNDOS E %d MILISEGUNDOS\n", circuito[j].tempoMinuto, circuito[j].tempoSegundo, circuito[j].tempoMilisegundo);
							printf("CÓDIGO DO PILOTO COM MENOR TEMPO: %d\n\n", circuito[j].piloto);
							testeC++;
						}
						else{
							printf("Circuito não encontrado\n");
						}
					}
				} while(testeC == 0);
				
				system("pause");
				system("cls");
				break;
				
			case 7:
				printf("INFORME MINUTO QUE DESEJA PESQUISAR: ");
				scanf("%d", &minutoProcurado);
				fflush(stdin);
				
				for(k = 0; k < contadorMelhor; k++){
					if(volta[k].minuto == minutoProcurado || volta[k].minuto > minutoProcurado){
						printf("INFORME SEGUNDO QUE DESEJA PESQUISAR: ");
						scanf("%d", &segundoProcurado);
						fflush(stdin);
						
						if(volta[k].segundo == segundoProcurado || volta[k].segundo > segundoProcurado){
							printf("INFORME MILISEGUNDO QUE DESEJA PESQUISAR: ");
							scanf("%d", &milisegundoProcurado);
							fflush(stdin);
							
							if(volta[k].milisegundo == milisegundoProcurado || volta[k].milisegundo > milisegundoProcurado){
								printf("\n\nCÓDIGO DO CIRCUITO: %d\n", volta[k].circuitoCodigo);
								printf("CÓDIGO DO PILOTO COM MENOR TEMPO: %d\n", volta[k].pilotoCodigo);
								printf("EQUIPE DO PILOTO COM MENOR TEMPO: %s\n", volta[k].equipe);
								printf("DATA DO CIRCUITO: %d do %d de %d\n", volta[k].dia, volta[k].mes, volta[k].ano);
								printf("MENOR TEMPO: %d MINUTOS, %d SEGUNDOS E %d MILISEGUNDOS\n\n", volta[k].minuto, volta[k].segundo, volta[k].milisegundo);
							}
							else{
									printf("Não possui piloto com tempo menor ao pesquisado.\n\n");
							}
						}
						else{
							printf("Não possui piloto com tempo menor ao pesquisado.\n\n");
						}
						
					}
					else{
						printf("Não possui piloto com tempo menor ao pesquisado.\n\n");
					}
				}
				
				system("pause");
				system("cls");
				break;
				
			case 8:
				printf("------------------------------------------\n\n");	
				printf("          AGRADECEMOS SUA VISITA.         \n");
				printf("------------------------------------------");	
				exit(0);
				break;
				
			default:
				printf("Opção inválida\n");
				system("pause");
				system("cls");
				break;
		}
		
	} while(opcaoMenu > 0 || opcaoMenu < 9);
	
	
	return 0;
}

char*verificarNomePiloto(Piloto*nomePiloto){
	char nomeP[120];
	int i = 0;
	
	do{
		printf("INFORME NOME DO PILOTO: ");
		scanf("%s", &nomeP);
		fflush(stdin);
		
		if (strlen(nomeP) < 2){
	        printf ("\nNome inválido por ser muito curto.\n");
	    }
    } while (strlen(nomeP) < 2);
	
	strcpy(nomePiloto[i].nome, nomeP);
	return nomePiloto[i].nome;
}

char*verificarSexoPiloto(Piloto*sexoPiloto){
	char sexoP[20];
	char sexoPredefinido[2][20] = {"F", "M"};
	int i = 0, teste = 0;
	
	do{
		printf("INFORME SEXO DO PILOTO (F- FEMININO | M- MASCULINO): ");
		scanf("%s", &sexoP);
		fflush(stdin);
		
		for(i = 0; i < 2; i++){
				if(strcmp(sexoP, sexoPredefinido[i]) == 0){
					strcpy(sexoPiloto[i].sexo, sexoP);
					return sexoPiloto[i].sexo;
				}
		}
	
		teste++;
		printf("Sexo inválido.\n\n");
	} while(teste > 0);
}

char*verificarPaisPiloto(Piloto*paisPiloto){
	int i = 0, teste = 0;
	char paisPredefinido[11][20] = {"Alemanha", "Australia", "Belgica", "Brasil", "Canada", "Espanha", "Franca", "Hungria", "Italia", "Japao", "Mexico", "Reino Unido"};
	char paisP[100];
	
	do{
		printf("INFORME PAÍS DO PILOTO: \n\n");
		printf("Países disponíveis: \n");
		for(i = 0; i < 11; i++){
			printf("%s -- ", paisPredefinido[i]);
		}
		printf("\n");
		scanf("%s", &paisP);
		fflush(stdin);
		
		for(i = 0; i < 11; i++){
			if(strcmp(paisP, paisPredefinido[i]) == 0){
				strcpy(paisPiloto[i].pais, paisP);
				return paisPiloto[i].pais;
			}
		}
	
		teste++;
		printf("País inválido.\n\n");
	} while(teste > 0);
}

int verificarIdadePiloto(Piloto*idadePiloto){
	int idadeP = 0;
		
	do{
		printf("INFORME IDADE DO PILOTO: ");
		scanf("%d", &idadeP);
		fflush(stdin);
		
		if(idadeP < 0 || idadeP > 110){
			printf("Idade inválida.\n\n");
		}
	
	} while(idadeP < 0 || idadeP > 110);
	
	return idadeP;
}

int verificarCodigoPiloto(Piloto*codigoPiloto){
	int codigoP = 0;
	
	do{
		printf("INFORME CODIGO DO PILOTO: ");
		scanf("%d", &codigoP);
		fflush(stdin);
		
		if(codigoP < 100 || codigoP > 500){
			printf("Código inválido.\n\n");
		}
	
	} while(codigoP < 100 || codigoP > 500);
	
	return codigoP;
}

int verificarCodigoC(Circuito*codigoCircuito){ 
	int codigoC = 0;
	
	codigoC++;
	
	return codigoC;
}

char*verificarNomeCircuito(Circuito*nomeCircuito){
	char nomeC[120];
	int i = 0;
	
	do{
		printf("INFORME NOME DO CIRCUITO: ");
		scanf("%s", &nomeC);
		fflush(stdin);
		
		if (strlen(nomeC) < 2){
	        printf ("\nNome inválido por ser muito curto.\n");
	    }
    } while (strlen(nomeC) < 2);
    
	strcpy(nomeCircuito[i].nome, nomeC);
	return nomeCircuito[i].nome;
}

char*verificarPaisCircuito(Circuito*paisCircuito){
	int i = 0, teste = 0;
	char paisPredefinido[11][20] = {"Alemanha", "Australia", "Belgica", "Brasil", "Canada", "Espanha", "Franca", "Hungria", "Italia", "Japao", "Mexico"};
	char paisC[100];
	
	do{
		printf("INFORME PAÍS DO CIRCUITO: \n\n");
		printf("Países disponíveis: \n");
		for(i = 0; i < 11; i++){
			printf("%s -- ", paisPredefinido[i]);
		}
		printf("\n");
		scanf("%s", &paisC);
		fflush(stdin);
		
		for(i = 0; i < 11; i++){
			if(strcmp(paisC, paisPredefinido[i]) == 0){
				strcpy(paisCircuito[i].pais, paisC);
				return paisCircuito[i].pais;
			}
		}
		
		teste++;	
		printf("País inválido.\n\n");	
	} while(teste > 0);
}

int verificarTamanho(Circuito*tamanhoCircuito){
	int tamanhoC = 0;
		
	do{
		printf("INFORME TAMANHO DO CIRCUITO: ");
		scanf("%d", &tamanhoC);
		fflush(stdin);
		
		if(tamanhoC < 0){
			printf("Tamanho inválido.\n\n");
		}
	
	} while(tamanhoC < 0);
	
	return tamanhoC;
}

int verificarCodigo(Circuito*codigoTeste){
	int codigo = 0;
		
	printf("INFORME CÓDIGO DO PILOTO COM O MENOR TEMPO: ");
	scanf("%d", &codigo);
	fflush(stdin);
	
	return codigo;
}

int verificarMinuto(Circuito*minutoCircuito){
	int minuto = 0;

	printf("INFORME MENOR TEMPO EM MINUTOS: ");
	scanf("%d", &minuto);
	fflush(stdin);

	return minuto;
}

int verificarSegundo(Circuito*segundoCircuito){
	int segundo = 0;

	printf("INFORME MENOR TEMPO EM SEGUNDOS: ");
	scanf("%d", &segundo);
	fflush(stdin);

	return segundo;
}

int verificarMilisegundo(Circuito*milisegundoCircuito){
	int milisegundo = 0;

	printf("INFORME MENOR TEMPO EM MILISEGUNDOS: ");
	scanf("%d", &milisegundo);
	fflush(stdin);

	return milisegundo;
}

int identificarCodigoPiloto(MelhorVolta*identificaPiloto){
	int codigo = 0;

	printf("INFORME CÓDIGO DO PILOTO: ");
	scanf("%d", &codigo);
	fflush(stdin);

	return codigo;
}

int identificarCodigoCircuito(MelhorVolta*identificaCircuito){
	int codigo = 0;

	printf("INFORME CÓDIGO DO CIRCUITO: ");
	scanf("%d", &codigo);
	fflush(stdin);

	return codigo;
}

char*verificarEquipePiloto(MelhorVolta*equipePiloto){
	char equipeP[100];
	int i = 0;
	
	do{
		printf("INFORME EQUIPE DO PILOTO: ");
		scanf("%s", &equipeP);
		fflush(stdin);
		
		if (strlen(equipeP) < 2)
	            printf ("\nNome inválido por ser muito curto.\n");
    } while (strlen(equipeP) < 2);
    
	strcpy(equipePiloto[i].equipe, equipeP);
	return equipePiloto[i].equipe;
}

int identificarDia(MelhorVolta*diaCircuito){
	int dia = 0;

	do{
		printf("INFORME DIA DO CIRCUITO: ");
		scanf("%d", &dia);
		fflush(stdin);
		
		if(dia < 0){
				printf("Data inválida.\n\n");
		}
	} while(dia < 0);

	return dia;
}

int identificarMes(MelhorVolta*mesCircuito){
	int mes = 0;

	do{
		printf("INFORME MÊS DO CIRCUITO: ");
		scanf("%d", &mes);
		fflush(stdin);
	
		if(mes < 0){
				printf("Data inválida.\n\n");
		}
	} while(mes < 0);
	
	return mes;
}

int identificarAno(MelhorVolta*anoCircuito){
	int ano = 0;

	do{
		printf("INFORME ANO DO CIRCUITO: ");
		scanf("%d", &ano);
		fflush(stdin);
	
		if(ano < 0){
				printf("Data inválida.\n\n");
		}
	} while(ano < 0);
	
	return ano;
}

int identificarMinuto(MelhorVolta*minutoCircuito){
	int minuto = 0;

	printf("INFORME MENOR TEMPO EM MINUTOS: ");
	scanf("%d", &minuto);
	fflush(stdin);

	return minuto;
}

int identificarSegundo(MelhorVolta*segundoCircuito){
	int segundo = 0;

	printf("INFORME MENOR TEMPO EM SEGUNDOS: ");
	scanf("%d", &segundo);
	fflush(stdin);

	return segundo;
}

int identificarMilisegundo(MelhorVolta*milisegundoCircuito){
	int milisegundo = 0;

	printf("INFORME MENOR TEMPO EM MILISEGUNDOS: ");
	scanf("%d", &milisegundo);
	fflush(stdin);

	return milisegundo;
}
