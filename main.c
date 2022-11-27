#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct cliente{
    char nome[100];
    int idade;
    } t_cliente;

typedef struct livro{
    char autor[100];
    char titulo[100];
    char editora[100];
    int ano;
    int id_livro;
    } t_livro;
    
t_cliente clientes[100];
t_livro livros[100];
int contadorID = 0;

void cadastrarCliente(){
    int respostaCliente = 0;
    int posicao = 0;
    
    do {
        printf("Insira em qual posi��o voc� quer salvar os dados do cliente: [ENTRE 0 E 99] ");
        scanf("%d", &posicao);
        if(posicao >= 0 && posicao <= 99){
        printf("Digite o nome do novo cliente: ");
        scanf("%s", &clientes[posicao].nome);
        printf("Digite a idade do novo cliente: ");
        scanf("%d", &clientes[posicao].idade);
        printf("<<Deseja cadastrar outro cliente?>>\n\n(1) - Sim\n(2) - N�o\n");
        scanf("%d", &respostaCliente);    
        } else {
            printf("<<Digite uma posi��o v�lida!!!>>\n");
            cadastrarCliente();
        }
        
    } while (respostaCliente == 1);{
        menu();
    }
}

void adicionarLivro(){
    int respostaAcervo;
    int i = 0;
    int posicaoLivro = 0;
    
    do{
    	printf("Insira em qual posi��o do acervo voc� quer salvar o livro: [ENTRE 0 E 99] ");
    	scanf("%d", &posicaoLivro);
    	if(posicaoLivro >= 0 && posicaoLivro <= 99){
        	printf("Digite o titulo do livro a ser cadastrado: ");
        	scanf("%s", &livros[posicaoLivro].titulo);
        	printf("Digite o autor do livro a ser cadastrado: ");
        	scanf("%s", &livros[posicaoLivro].autor);
        	printf("Digite o ano de lan�amento do livro a ser cadastrado: ");
        	scanf("%d", &livros[posicaoLivro].ano);
        	printf("<<Gostaria de adicionar mais um livro?>>\n\n(1) - Sim\n(2) - N�o\n");
        	scanf("%d", &respostaAcervo);   
    	} else {
        	printf("\n<<Digite uma posi��o v�lida!!!>>\n");
        	adicionarLivro();
    	}
    }while(respostaAcervo == 1);
	{
    	menu();
    }
}

void exibirLivros(){
    int i = 0;
    printf("\n\nLivros da biblioteca:\n\n");
    for(i = 0; i < 100; i++){
        printf("|T�tulo: %s /// Autor: %s /// Ano de lan�amento: %d /// ID: %d|\n", livros[i].titulo, livros[i].autor, livros[i].ano, i);
    }
    menu();
}

void editarLivro(){
     int idEditado;
     int escolha;
     int j = 0;
     
     printf("Quais dos livros abaixo voc� deseja editar? [INFORME O ID]\n");
     for(j = 0; j < 100; j++){
        printf("|T�tulo: %s - ID: %d|\n", livros[j].titulo, j);
    }
     scanf("%d", &idEditado);
     if (idEditado >= 0 && idEditado <= 99){
        printf("Qual das seguintes caracter�sticas voc� deseja editar?\n(1) -T�tulo\n(2) - Autor\n(3) - Data de lan�amento\n");
        scanf("%d", &escolha);
    
        if(escolha == 1){
            printf("Insira o novo t�tulo: ");
            scanf("%s", &livros[idEditado].titulo);
        } 
        else if (escolha == 2){
            printf("Insira o novo autor: ");
            scanf("%s", &livros[idEditado].autor);
        }
        else if (escolha == 3){
            printf("Insira a nova data de lan�amento: ");
            scanf("%d", &livros[idEditado].ano);
        } else {
            printf("\n<<Insira uma op��o v�lida!!!>>\n");
            editarLivro();
        }
    } else {
        printf("\n<<Digite uma posi��o v�lida!!!>>\n");
        editarLivro();
    }
    
    menu();  
}

void exibirClientes(){
    int i = 0;
    printf("\n\nClientes da biblioteca:\n\n");
    for(i = 0; i < 100; i++){
        printf("|Nome: %s - Idade: %d|\n", clientes[i].nome, clientes[i].idade);
    }
    menu();
}

int menu(){
    int op;
    
    printf("\t\t\t\tBIBLIOTECA DO LEONARDO\t\t\t\t");
    printf("\n\t--------------------Voc� quer realizar qual dessas a��es?--------------------\t\n\n(1) - Adicionar livro\n(2) - Editar livro\n(3) - Remover livro\n(4) - Exibir acervo\n(5) - Cadastrar novo cliente\n(6) - Exibir clientes\n");
    scanf("%d", &op);

    switch(op){
        case 1: {
            adicionarLivro();
            break;
            }
        case 2: {
             editarLivro();
             break;
        }
        case 3: {
             removerLivro();
             break;
        }
        case 4: {
            exibirLivros();
            break;
        }
        case 5: {
            cadastrarCliente();
            break;
        }
        case 6: {
            exibirClientes();
            break;
        }
        default:{
            printf("<<Selecione uma op��o v�lida!!!>>\n");
            menu();
            break;
        }
    }
}

void removerLivro(){
    int idRemovido;
    int i;
    int j = 0;
    
     printf("Quais dos livros abaixo voc� deseja remover? [INFORME O ID]\n\n");
     for(j = 0; j < 100; j++){
        printf("|T�tulo: %s - ID: %d|\n", livros[j].titulo, j);
    }
     scanf("%d", &idRemovido);
    
    for(i = idRemovido; i < 100; i++){
        livros[i] = livros[i + 1];
    }
    
    menu();  
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
    
    menu();
    
    return 0;
}

