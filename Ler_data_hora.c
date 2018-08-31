#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------ defines -----------
#define MAX_DIA	2
#define MAX_MES 2
#define MAX_ANO 4

#define MAX_HORA 2
#define MAX_MINUTOS 2
#define MAX_SEGUNDOS 2
//--------------------------

/*
	Exercício: Crie uma função para ler uma data e hora do usuário no seguinte formato: 
	
	    dd/mm/yyyy 00:00:00
	
	- Faça todas as validações em relação ao **formato**
	- Não se preocupe com anos bissextos, segundos excedentes, etc
	- Use structs
	- Use array se achar necessário


*/
// ----------- Struct ---------------------
typedef struct{
	char dia[MAX_DIA];
	char mes[MAX_MES];
	char ano[MAX_ANO]; 
}Data;

typedef struct{
	char hora[MAX_HORA];
	char minutos[MAX_MINUTOS];
	char segundos[MAX_SEGUNDOS];
}Hora;

//------------ Prototipos -----------------
void lerDataHora(Data *data, Hora *hora);
Data lerData(void);
Hora lerHora(void);

char leValidaCaracter(char *mnsgTitulo,char *msgErro, char *opcao);

void printaData(Data data);
void printaHora(Hora hora);
void printarDataHora(Data data, Hora hora);

Hora inicializaHora(void);
Data inicializaData(void);
void inicializaDataHora(Data *data, Hora *hora);
//-----------------------------------------
int main(int argc, char *argv[]) {
	Data data;
	Hora hora;
	
	inicializaDataHora(&data,&hora);
	lerDataHora(&data, &hora);
	printarDataHora(data,hora);
	
	return 0;
}

void inicializaDataHora(Data *data, Hora *hora){
	*data = inicializaData();
	*hora = inicializaHora();
}

Data inicializaData(void){
	Data data;
	int i;
	for(i = 0; i < MAX_DIA; i++){
		data.dia[i] = '0';
	}
		for(i = 0; i < MAX_MES; i++){
		data.mes[i] = '0';
	}
		for(i = 0; i < MAX_ANO; i++){
		data.ano[i] = '0';
	}
	
}
Hora inicializaHora(void){
	Hora hora;
	int i;
	for(i = 0; i < MAX_HORA; i++){
		hora.hora[i] = '0';
	}
	for(i = 0; i < MAX_MINUTOS; i++){
		hora.minutos[i] = '0';
	}
	for(i = 0; i < MAX_SEGUNDOS; i++){
		hora.segundos[i] = '0';
	}
	
}
void printarDataHora(Data data, Hora hora){
	system("cls");
	printf("\n");
	printaData(data);
	printf(" ");
	printaHora(hora);
	printf("\n");	
	
}
void printaData(Data data){
	int i;
	for(i = 0; i < MAX_DIA; i++){
		printf("%c",data.dia[i]);
	}
	printf("/");
	for(i = 0; i < MAX_MES; i++){
		printf("%c",data.mes[i]);
	}
	printf("/");
	for(i = 0; i < MAX_ANO; i++){
		printf("%c",data.ano[i]);
	}
}
void printaHora(Hora hora){

	int i;
	for(i = 0; i < MAX_HORA; i++){
		printf("%c",hora.hora[i]);		
	}
	printf(":");
	for(i = 0; i < MAX_MINUTOS; i++){
		printf("%c",hora.minutos[i]);
	}
	printf(":");
	for(i = 0; i < MAX_SEGUNDOS; i++){
		printf("%c",hora.segundos[i]);
	}
}
void lerDataHora(Data *data, Hora *hora){
	printf("Digite a Data\n");
	*data = lerData();
	printf("\nDigite a Hora\n ");
	*hora = lerHora();
	
}
Data lerData(void){
	Data data;
	int i = 0;
	do{
		data.dia[i] = leValidaCaracter("","Dia invalido","0123456789");
		i++;
	}while(i < MAX_DIA);
	printf("/");
	i = 0;
	do{
		data.mes[i] = leValidaCaracter("","mes invalido","0123456789");
		i++;
	}while(i < MAX_MES);
	printf("/");
	i = 0;
	do{
		data.ano[i] = leValidaCaracter("","Ano invalido","0123456789");
		i++;
	}while(i < MAX_ANO);
	return data;
}

Hora lerHora(void){
	Hora hora;
	int i = 0;
	do{
		hora.hora[i] = leValidaCaracter("","Hora invalido","0123456789");
		i++;
	}while(i < MAX_HORA);
	printf(":");
	i = 0;
	do{
		hora.minutos[i] = leValidaCaracter("","Minutos invalido","0123456789");
		i++;
	}while(i < MAX_MINUTOS);
	printf(":");
	i = 0;
	do{
		hora.segundos[i] = leValidaCaracter("","Segundos invalido","0123456789");
		i++;
	}while(i < MAX_SEGUNDOS);
	return hora;
}

char leValidaCaracter(char *mnsgTitulo,char *msgErro, char *opcao){
	char caracterler;
	do{
		
		printf(mnsgTitulo);
		caracterler = toupper(getche());
		if(strchr(opcao, caracterler) == 0){
			printf(msgErro);
			printf(" Aperte enter...");
			getch();	
		}
	}while(strchr(opcao, caracterler) == 0);
	return caracterler;
}
