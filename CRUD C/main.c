/******************************************************************************
Sistema de cadastro de Games
SCG possibilita cadastro, listagem, pesquisa, edição e exclusão.
Código separado em 3 arquivos,  main, funções e structs.
CRUD completo.
Create em cadastro e dados iniciais.
Retrieve em listagem.
Utilize em pesquisa e edição.
Delete em deletar.
Alunos Eduardo Gobbi Tomasi e Eduardo Rodrigueri.
*******************************************************************************/
#include <stdio.h>
#include "Funcoes.h" //chamando meu arquivo de funções

void main(){
    
    anexarDados();
    int opcao;
    printf("\nSistema de Cadastro de Games - SCG %.1f\n", VERSAO);
    
    do {
        opcao = menu();
        switch(opcao){ //switch para verificar o número escolhido pelo usuario
            case 1: cadastrarGames();
                    break;
            case 2: listarGames();
                    break;
            case 3: pesquisarGames(); //cada função chamada por 1 número diferente
                    break;
            case 4: editarGames();
                    break;
            case 5: excluirGames();
                    break;
            case 0: printf("\nAgradecemos o Acesso ao SCG! \n\n");
                    break;
            default: printf("\nOpção indisponivel! \n");
        }
    } while(opcao != 0);//quando 0 for escolhido, programa encerra e imprime mensagem da linha 30
}
