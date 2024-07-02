#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct base {
    char nome[50];
    int data_nascimento;
    char numero[11];
    char insta[50];
    char facebook[50];
    char email[50];
};

struct base* aloca_vetor(int tamanho) {
    struct base *aux;
    aux = (struct base *) malloc(tamanho * sizeof(struct base));
    if(aux == NULL){
        printf("ERROR 01");
        exit(1);
    }
    return aux;
}
int tamanho = 0;

int ordena_alfa(const void *a, const void *b){
    return strcmp(((struct base *)a)->nome, ((struct base *)b)->nome);;
}
void removeprimeiro(struct base **contatos, int *tamanho) {

    struct base *temp = malloc((*tamanho - 1) * sizeof(struct base));

    for (int i = 1; i < *tamanho; ++i) {
        strcpy(temp[i - 1].nome, (*contatos)[i].nome);
        strcpy(temp[i - 1].email, (*contatos)[i].email);
        strcpy(temp[i - 1].numero, (*contatos)[i].numero);
        strcpy(temp[i - 1].insta, (*contatos)[i].insta);
        strcpy(temp[i - 1].facebook, (*contatos)[i].facebook);
        temp[i - 1].data_nascimento = (*contatos)[i].data_nascimento;

    }

    free(*contatos);

    *contatos = malloc((*tamanho - 1) * sizeof(struct base));

    for (int i = 0; i < *tamanho - 1; ++i) {
        (*contatos)[i] = temp[i];
    }

    *tamanho = *tamanho - 1;

    free(temp);
}

void remove_ultimo(struct base **contatos, int *tamanho) {

    struct base *temp = malloc((*tamanho - 1) * sizeof(struct base));

    for (int i = 0; i < *tamanho - 1; ++i) {
        strcpy(temp[i].nome, (*contatos)[i].nome);
        strcpy(temp[i].email, (*contatos)[i].email);
        strcpy(temp[i].numero, (*contatos)[i].numero);
        strcpy(temp[i].insta, (*contatos)[i].insta);
        strcpy(temp[i].facebook, (*contatos)[i].facebook);
        temp[i].data_nascimento = (*contatos)[i].data_nascimento;

    }

    free(*contatos);

    *contatos = malloc((*tamanho - 1) * sizeof(struct base));

    for (int i = 0; i < *tamanho - 1; ++i) {
        (*contatos)[i] = temp[i];
    }

    *tamanho = *tamanho - 1;

    free(temp);
}

void remove_posicao(struct base **contatos, int *tamanho, int posicao){

    struct base *temp = malloc((*tamanho - 1) * sizeof(struct base));

        for (int i = 0, j = 0; i < *tamanho; ++i) {
            if (i + 1 != posicao) {
                strcpy(temp[j].nome, (*contatos)[i].nome);
                strcpy(temp[j].email, (*contatos)[i].email);
                strcpy(temp[j].numero, (*contatos)[i].numero);
                strcpy(temp[j].insta, (*contatos)[i].insta);
                strcpy(temp[j].facebook, (*contatos)[i].facebook);
                temp[j].data_nascimento = (*contatos)[i].data_nascimento;
                j++;
            }
        }

    free(*contatos);
    *contatos = malloc((*tamanho - 1) * sizeof(struct base));
    for (int i = 0; i < *tamanho - 1; ++i) {
        (*contatos)[i] = temp[i];
    }
    *tamanho = *tamanho - 1;

    free(temp);
}

int main() {
    struct base *contatos = aloca_vetor(tamanho);
    int opcao;
    int i = 1;
    do {
        printf("Escolha uma opcao: \n");
        printf("1.INSERIR CONTATO\n");
        printf("2.ALTERAR CONTATO\n");
        printf("3.EXCLUIR CONTATO\n");
        printf("4.PESQUISAR CONTATO\n");
        printf("5.LISTAR CONTATO\n");
        printf("0.SAIR\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("INSERIR NOVO CONTATO: \n");
            tamanho++;


            struct base *novo_contato = aloca_vetor(tamanho);


            printf("Nome: ");
            getchar();
            fgets(novo_contato[tamanho - 1].nome, 50, stdin);

            printf("Insta: ");
            fgets(novo_contato[tamanho - 1].insta, 50, stdin);

            printf("Numero: ");
            fgets(novo_contato[tamanho - 1].numero, 50, stdin);

            printf("Data de nascimento:");
            scanf("%d", &novo_contato[tamanho - 1].data_nascimento);

            printf("Email: ");
            getchar();
            fgets(novo_contato[tamanho - 1].email, 50, stdin);

            printf("Facebook: ");
            fgets(novo_contato[tamanho - 1].facebook, 50, stdin);


            contatos = realloc(contatos, tamanho * sizeof(struct base));
            contatos[tamanho - 1] = novo_contato[tamanho - 1];
            free(novo_contato);

        }

         else if (opcao == 2) {
            printf("ALTERAR CONTATO: \n");

            int id;
            if(tamanho > 0){
                for (int i = 0; i < tamanho; ++i) {
                    printf("- %d. %s ",i+1,contatos[i].nome);
                }
                printf("Qual contato deseja alterar ?: ");
                scanf("%d",&id);

                if(id >= 1 && id <= tamanho){
                    for (int j = 0; j < tamanho; ++j) {
                        if(j == id-1) {
                            remove_posicao(&contatos,&tamanho,id);
                            tamanho++;

                            struct base *novo_contato = aloca_vetor(tamanho);


                            printf("Nome: ");
                            getchar();
                            fgets(novo_contato[tamanho - 1].nome, 50, stdin);

                            printf("Insta: ");
                            fgets(novo_contato[tamanho - 1].insta, 50, stdin);

                            printf("Numero: ");
                            fgets(novo_contato[tamanho - 1].numero, 50, stdin);

                            printf("Data de nascimento:");
                            scanf("%d", &novo_contato[tamanho - 1].data_nascimento);

                            printf("Email: ");
                            getchar();
                            fgets(novo_contato[tamanho - 1].email, 50, stdin);

                            printf("Facebook: ");
                            fgets(novo_contato[tamanho - 1].facebook, 50, stdin);



                            contatos = realloc(contatos, tamanho * sizeof(struct base));
                            contatos[tamanho - 1] = novo_contato[tamanho - 1];
                            free(novo_contato);

                        }

                    }
                } else{
                    printf("| ESSE ID NAO EXISTE, Tente outro |\n");
                }

            }else{
                printf("| Lista de contatos esta vazia |\n");
            }

        } else if (opcao == 3) {
            printf("EXCLUIR CONTATO: \n");
            int id;
            if(tamanho > 0){
                for (int i = 0; i < tamanho; ++i) {
                    printf("- %d. %s ",i+1,contatos[i].nome);
                }

                printf("Qual contato deseja excluir ?");
                scanf("%d",&id);

                if(id <= tamanho && id >= 1){

                    if(id == 1){

                        removeprimeiro(&contatos, &tamanho);

                    }else if(id == tamanho){

                        remove_ultimo(&contatos, &tamanho);

                    } else{
                        remove_posicao(&contatos,&tamanho,id);
                    }
                } else{
                    printf("| ESSE ID NAO EXISTE, Tente outro |\n");
                }


            } else{
                printf("| Lista de contatos esta vazia |\n");
            }

        } else if (opcao == 4) {
            printf("PESQUISAR CONTATOS EXISTENTES: \n");

            int id;
            if(tamanho > 0){
            for (int i = 0; i < tamanho; ++i) {
                printf("- %d. %s ",i+1,contatos[i].nome);
            }
                printf("\n digite algo: ");
                scanf("%d",&id);
                if(id >= 1 && id <= tamanho){
                for (int j = 0; j < tamanho; ++j) {
                    if(j == id-1) {

                        printf("Nome: %s \n", contatos[j].nome);
                        printf("Insta: %s \n",contatos[j].insta);
                        printf("Numero: %s \n", contatos[j].numero);
                        printf("Email: %s \n",contatos[j].email);
                        printf("Data de nascimento: %d \n", contatos[j].data_nascimento);
                        printf("facebook: %s \n",contatos[j].facebook);
                        printf("\n");
                        break;
                    }

                }
                } else{
                    printf("| ESSE ID NAO EXISTE, Tente outro |\n");
                }
            }else{
                printf("| Lista de contatos esta vazia |\n");
            }
        } else if (opcao == 5) {
           if(tamanho > 0){
               printf(" LISTAR CONTATOS:  \n");

               qsort(contatos,tamanho,sizeof(struct base),ordena_alfa);

               for (int i = 0; i < tamanho; i++) {
                   printf("Nome: %s \n", contatos[i].nome);
                   printf("Insta: %s \n",contatos[i].insta);
                   printf("Numero: %s \n", contatos[i].numero);
                   printf("Email: %s \n",contatos[i].email);
                   printf("Data de nascimento: %d \n", contatos[i].data_nascimento);
                   printf("facebook: %s \n",contatos[i].facebook);
                   printf("\n");
               }
           } else{
               printf("| A lista de contatos esta vazia |\n");
           }
        } else if (opcao == 0) {
            printf("SAIR: \n");
            free(contatos);
        } else {
            printf("| OPÇAO INVALIDA!!(TENTE NOVAMENTE): |\n");
        }

    }while (opcao != 0);

    return 0;
 }
