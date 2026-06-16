#include <stdio.h>
#include <windows.h>

struct empresa {
    char produto[50];
    int quantidade;
    char localizacao[50];
    float valorUnitario;
};
void main(){
	SetConsoleOutputCP(CP_UTF8);
	struct empresa produtos[5] = {
		{"Cadeira",50,"Armazém A",150.00},
		{"Mesa",30,"Galpão A",300.00},
		{"Computador",20,"Armazém B",1200.00},
		{"Impressora",10,"Galpão A",500.00},
		{"Monitor",20,"Armazém B",800.00}
	};
	
	FILE *arquivo = fopen("inventario.csv","w");
	if(arquivo == NULL){
		printf("Erro ao gravar arquivo\n");
		return 0;
	}
	fprintf(arquivo,"produto,quantidade,localizacao,valorUnitario\n");
		for(int i = 0; i < 5; i++)
		fprintf(arquivo,"%s, %d, %s\n",produtos[i].produto, produtos[i].quantidade, produtos[i].localizacao, produtos[i].valorUnitario);
	fclose(arquivo);
	printf("Arquivo criado com sucesso.");
	getch();
}
