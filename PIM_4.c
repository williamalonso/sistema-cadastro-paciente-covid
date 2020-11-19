#include<stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu() {

    int x;

    printf("Bem-vindo(a) ao Menu!\n");
    printf("Selecione uma opcao abaixo\n");
    printf("1 - Fazer login\n");
    printf("2 - Sair\n");
    scanf("%d", &x);

    switch(x) {
        case 1:
            system("cls");
            login();
            break;
        case 2:
            printf("Saindo do sistema!\n");
            return 0;
    }

}

void menu_funcionario() {
    
    int x;

    printf("Login feito com sucesso!\n");
    printf("Selecione uma opcao abaixo\n");
    printf("1 - Cadastrar Paciente\n");
    printf("2 - Fazer Logout\n");
    printf("3 - Sair do Sistema\n");
    scanf("%d", &x);

    switch(x) {
        case 1:
            system("cls");
            dados_pessoais_paciente();
            break;
        case 2:
            system("cls");
            menu();
            break;
        case 3:
            printf("Saindo do sistema!\n");
            return 0;
    }

}

void login() {

    char login[50], senha[50];
    int verifica_senha = 0, x, y;

    printf("Ola, para acessar o sistema digite sua conta logo abaixo!\n"); fflush(stdin);

    while( verifica_senha == 0 ) {

        printf("Login: ");
        gets(login);

        printf("Senha: ");
        gets(senha);

        x = strcmp(senha, "senha"); //compara o que foi digitado na 'senha' com a string "senha". Retorna 0 se a comparação for igual
        y = strcmp(login, "funcionario"); //compara o que foi digitado no 'login' com a string "funcionario". Retorna 0 se a comparação for igual

        if(x == 0 && y == 0) {
            system("cls");
            menu_funcionario();
            verifica_senha = 1;
        } else {
            printf("Conta errada, tente novamente\n");
            printf("\n");
        }

    }

}

void dados_pessoais_paciente() {
    
    int k, i, dia_nascimento, mes_nascimento, ano_nascimento, idade, dia_diagnostico, mes_diagnostico, ano_diagnostico;
    long int telefone;
    char nome[100], CPF[100], rua[100], numero[100], bairro[100], cidade[100], estado[100], cep[100], email[100], comorbidade[100];
    
    fflush(stdin);
    printf("Digite o numero de pacientes que deseja cadastrar: ");
    scanf("%d", &k);

    for(i = 1; i <= k; i++) {
        
        fflush(stdin);
        printf("Digite o NOME do paciente: "); gets(nome); fflush(stdin);
        printf("Digite o CPF do paciente (somente numeros sem pontos): "); gets(CPF); fflush(stdin);
        printf("Digite o TELEFONE do paciente (somente numeros sem tracos): "); scanf("%d", &telefone); fflush(stdin);
        printf("Digite a RUA do paciente: "); gets(rua); fflush(stdin);
        printf("Digite o NUMERO da RUA do paciente: "); gets(numero); fflush(stdin);
        printf("Digite o BAIRRO do paciente: "); gets(bairro); fflush(stdin);
        printf("Digite a CIDADE do paciente: "); gets(cidade); fflush(stdin);
        printf("Digite o ESTADO do paciente: "); gets(estado); fflush(stdin);
        printf("Digite o CEP do paciente (somente numeros sem tracos): "); gets(cep); fflush(stdin);
        printf("Digite o DIA de NASCIMENTO do paciente: "); scanf("%d", &dia_nascimento); fflush(stdin);
        printf("Digite o MES de NASCIMENTO do paciente: "); scanf("%d", &mes_nascimento); fflush(stdin);
        printf("Digite o ANO de NASCIMENTO do paciente: "); scanf("%d", &ano_nascimento); fflush(stdin);
        printf("Digite o EMAIL do paciente: "); gets(email); fflush(stdin);
        printf("Digite o DIA do DIAGNOSTICO do paciente: "); scanf("%d", &dia_diagnostico); fflush(stdin);
        printf("Digite o MES do DIAGNOSTICO do paciente: "); scanf("%d", &mes_diagnostico); fflush(stdin);
        printf("Digite o ANO do DIAGNOSTICO do paciente: "); scanf("%d", &ano_diagnostico); fflush(stdin);
        printf("Digite a COMORBIDADE do paciente (diabetes, obesidade, hipertensao, tuberculose, outros. SE NÃO POSSUIR DEIXE VAZIO): "); gets(comorbidade); fflush(stdin);


        idade = 2020 - ano_nascimento; //calcula idade
        
        if( idade > 65 && comorbidade!=NULL ) { // se pertencer ao grupo de risco
            
            FILE *arq;
            char filename[100];
            sprintf(filename, "Paciente_%d_Grupo_Risco.txt", i); /* Paciente_1_Grupo_Risco.txt; Paciente_2_Grupo_Risco.txt; ... */
            arq = fopen(filename, "w"); // Cria um arquivo texto para gravação
            
            if( arq == NULL ) { // Se não conseguiu criar o arquivo 'Dados_Paciente.txt'
                printf("Problemas na CRIACAO do arquivo\n");
                return;
            }
            
            fprintf(arq, "CEP: %s\n", cep); // salva o cep no arquivo
            fprintf(arq, "IDADE: %d\n", idade); // salva a idade no arquivo

            fclose(arq);

        } else { // caso não seja do grupo de risco

            FILE *arq;
            char filename[100];
            sprintf(filename, "Dados_Paciente_%d.txt", i); /* Dados_Paciente_1.txt; Dados_Paciente_2.txt; ... */
            arq = fopen(filename, "w"); // Cria um arquivo texto para gravação
            
            if( arq == NULL ) { // Se não conseguiu criar o arquivo 'Dados_Paciente.txt'
                printf("Problemas na CRIACAO do arquivo\n");
                return;
            }
            
            fprintf(arq, "NOME: %s\n", nome); // salva o nome no arquivo
            fprintf(arq, "CPF: %s\n", CPF); // salva o CPF no arquivo
            fprintf(arq, "TELEFONE: %d\n", telefone); // salva o telefone no arquivo
            fprintf(arq, "RUA: %s\n", rua); // salva a rua no arquivo
            fprintf(arq, "NUMERO da RUA: %s\n", numero); // salva o numero da rua no arquivo
            fprintf(arq, "BAIRRO: %s\n", bairro); // salva o bairro no arquivo
            fprintf(arq, "CIDADE: %s\n", cidade); // salva a cidade no arquivo
            fprintf(arq, "ESTADO: %s\n", estado); // salva o estado no arquivo
            fprintf(arq, "CEP: %s\n", cep); // salva o cep no arquivo
            fprintf(arq, "DIA de NASCIMENTO: %d\n", dia_nascimento); // salva o dia de nascimento no arquivo
            fprintf(arq, "MES de NASCIMENTO: %d\n", mes_nascimento); // salva o mes de nascimento no arquivo
            fprintf(arq, "ANO de NASCIMENTO: %d\n", ano_nascimento); // salva o ano de nascimento no arquivo
            fprintf(arq, "EMAIL: %s\n", email); // salva o email no arquivo
            fprintf(arq, "DIA do DIAGNOSTICO: %d\n", dia_diagnostico); // salva o dia do diagnostico no arquivo
            fprintf(arq, "MES do DIAGNOSTICO: %d\n", mes_diagnostico); // salva o mes do diagnostico no arquivo
            fprintf(arq, "ANO do DIAGNOSTICO: %d\n", ano_diagnostico); // salva o ano do diagnostico no arquivo
            fprintf(arq, "COMORBIDADE: %s\n", comorbidade); // salva a comorbidade no arquivo

            fclose(arq); // fecha o arquivo

        }
        
        printf("\n");
        printf("Paciente cadastrado com sucesso!\n");
        printf("\n");

    }

}

int main(void){

    menu();

    return 0;
}
