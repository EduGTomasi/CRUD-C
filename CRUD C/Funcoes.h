#define TAMANHO 20 //constante que define tamanho max da lista de games
#define VERSAO 1.4 //constante para versão atual do SCG
#include <string.h> //bibliotecas necessarias para as funções
#include <stdlib.h>
#include "Structs.h" //chamando meu arquivo de structs

struct Game jogos[TAMANHO]; //variavel global jogos

int contadorGames = 0; //variavel global contador

//funcao utilizada para ler Strings com espaço em C
void leString(char stringLiga[], int max) {
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);
        if ((letra == '\n') && (i == 0)) {
            i = i - 1;
            continue;
        }
        if (letra == '\n') break;
        stringLiga[i] = letra;
    }
    stringLiga[i] = '\0';
}

//Create C
void anexarDados(){ //dados presentes no sistema assim q ele é iniciado
    printf("Anexando Dados Base Do SCG...\n"); //mensagem bonitinha para display
    printf("Danos Anexados com Sucesso!\n");
    
    strcpy(jogos[0].nome, "God of War I"); //jogos com nome, ano e prateleira
    strcpy(jogos[0].ano, "2005");
    jogos[0].prat = 001;
    jogos[0].ativo = 1; //se ativo = 1, o jogo aparece, se ativo = 0, ele não aparece
    
    strcpy(jogos[1].nome, "God of War II");
    strcpy(jogos[1].ano, "2007");
    jogos[1].prat = 001;
    jogos[1].ativo = 1;
    
    strcpy(jogos[2].nome, "God of War III");
    strcpy(jogos[2].ano, "2010");
    jogos[2].prat = 001;
    jogos[2].ativo = 1;
    
    strcpy(jogos[3].nome, "God of War Ascension");
    strcpy(jogos[3].ano, "2013");
    jogos[3].prat = 001;
    jogos[3].ativo = 1;
    
    strcpy(jogos[4].nome, "God of War");
    strcpy(jogos[4].ano, "2018");
    jogos[4].prat = 001;
    jogos[4].ativo = 1;
    
    strcpy(jogos[5].nome, "God of War Ragnarok");
    strcpy(jogos[5].ano, "2022");
    jogos[5].prat = 001;
    jogos[5].ativo = 1;
    
    contadorGames = 6; //marcando quantos games temos inicialmente na lista de informações iniciais
}

//Create C
void cadastrarGames(){ //função para adicionar novos jogos no sistema
    
    printf("\nDigite o nome do game: \n");
    leString(jogos[contadorGames].nome, 50);
    
    printf("\nDigite o ano de lançamento do game: \n");
    leString(jogos[contadorGames].ano, 12);
    
    printf("\nDigite o número da prateleira aonde será guardado: \n");
    fflush(stdin);
    scanf("%d", &jogos[contadorGames].prat);
    
    printf("\nEnviando seu game para o banco de dados do SCG...\n");  //mensagem bonitinha para display
    printf("O SCG recebeu seu game com sucesso!\n");

    jogos[contadorGames].ativo = 1; //todo game registrado sera ativo = 1, para aparecer na lista
    contadorGames++; //contador aumenta a cada game cadastrado
}

//Retrieve R
void listarGames(){ //função para listar todos os games no sistema
    if(contadorGames == 0){
        printf("\nNenhum Game Registrado Até Então \n"); //caso não tenhamos game
    } else {
        printf("\n                     GAMES NO SISTEMA:               \n"); //caso tenhamos pelo menos 1 game
        printf("\n-------------------------------------------------------------");
        printf("\n Etiqueta \t Prateleira \t Ano \t Nome"); 
        printf("\n-------------------------------------------------------------"); //desenhos do display
        for(int i = 0; i < contadorGames; i++){
            if(jogos[i].ativo == 0) {
                printf("\n                     GAME INDISPONIVEL               "); //se ativo = 0, jogo indisponivel
            } else {
                printf("\n %d \t\t %d \t\t %s \t %s", i+1, jogos[i].prat, jogos[i].ano, jogos[i].nome); //se ativo = 1, monta-se o display
            }
            printf("\n-------------------------------------------------------------");
        }
        printf("\n                TOTAL DE GAMES NO SISTEMA: %d               ", contadorGames); //exibe o valor do contador de games
        printf("\n-------------------------------------------------------------\n");
    }
    
}

//Utilize U
void pesquisarGames(){ //função para executar pesquisa de um nome exato no sistema
    
    char nome[100];
    int encontrado = 0;
    
    printf("Digite o nome do game que deseja pesquisar: "); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s':\n", nome);
    printf("\n--------------------------------------------------------"); //texto bonitinho com display mostrando os resultados
    printf("\n Etiqueta \t Prateleira \t Ano \t Nome");
    printf("\n--------------------------------------------------------");
    
    for(int i = 0; i < contadorGames; i++){                                 //strcasecmp serve para não levar em conta maisculas e minusculas
        if(jogos[i].ativo == 1 && strcasecmp(jogos[i].nome, nome) == 0) { // se ativo = 0, jogo indisponivel, se ativo = 1, monta-se o display
            printf("\n %d \t\t %d \t\t %s \t %s", i, jogos[i].prat, jogos[i].ano, jogos[i].nome);
            encontrado = 1; //marcador de jogos encontrados
        }
    }
    
    if(!encontrado){
        printf("\nNenhum jogo encontrado com o nome '%s'.\n", nome); //se não houver incremento em encontrado, a pesquisa não encontrou nada
    }
    printf("\n--------------------------------------------------------\n");


}

//Utilize U
int editarGames(){ //função para editar os valores individuais de cada game
    
    char nome[100];
    int encontrado = 0;
    
    printf("\nDigite a seguir o nome do jogo que deseja editar: \n"); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s':\n",nome);
    printf("\n--------------------------------------------------------");
    printf("\n Etiqueta \t Prateleira \t Ano \t Nome");
    printf("\n--------------------------------------------------------");
    
    for(int i = 0; i < contadorGames; i++){
        if(jogos[i].ativo == 1 && strcasecmp(jogos[i].nome, nome) == 0){ //exatamente o mesmo sistema de pesquisa
            printf("\n %d \t\t %d \t\t %s \t %s", i + 1 , jogos[i].prat, jogos[i].ano, jogos[i].nome);
            encontrado = 1;
            printf("\n--------------------------------------------------------\n");
            
            printf("\nDigite um novo nome para este jogo: ");//ao achar o game, o usuario pode alterar suas informações
            scanf(" %[^\n]%*c", jogos[i].nome);
            printf("\nDigite o novo ano para este jogo: ");
            scanf("%s", jogos[i].ano);
            printf("\nDigite a nova prateleira para este jogo: ");
            scanf("%d", &jogos[i].prat);
            printf("\nEnviando seu game para o banco de dados do SCG...\n");  //mensagem bonitinha para display
            printf("O SCG recebeu seu game com sucesso!\n");
            return 0 ;
        }
        
    }
    if(!encontrado){
            printf("\nNenhum jogo com este nome encontrado!!!");
        }
        printf("\n--------------------------------------------------------");

}

//Delete D
void excluirGames(){ // função para excluir games do sistema
   
    char nome[100];
    int encontrado = 0;
    
    printf("\nDigite o nome do game que deseja excluir: "); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s': \n", nome);
    printf("\n--------------------------------------------------------");
    printf("\n Etiqueta \t Prateleira \t Ano \t Nome");
    printf("\n--------------------------------------------------------");
    
    for(int i = 0; i < contadorGames; i++){
        if(jogos[i].ativo == 1 && strcasecmp(jogos[i].nome, nome) == 0) { //exatamente o mesmo sistema de pesquisa, porém caso encontre o game, ele tera seu ativo = 0
            printf("\n--------------------Jogo excluido-----------------------");
            jogos[i].ativo = 0;
            encontrado = 1;
        }
    }
    if(!encontrado){
        printf("\nNenhum jogo foi encontrado com este nome");
    } 
    printf("\n--------------------------------------------------------\n");
}

int menu(){ //função com o display do menu, que aparece assim que executamos o código
    int opcao;
    
    printf("\nBem-vindo, o que deseja fazer?: \n");
    printf("1 - Cadastrar Games\n");
    printf("2 - Listar Games\n");
    printf("3 - Pesquisar Games\n"); 
    printf("4 - Editar Games\n"); 
    printf("5 - Excluir Games\n");
    printf("0 - Sair do sistema\n");
    printf("Favor Insira um Número --> ");
    scanf("%d", &opcao);
    
    return opcao;
}