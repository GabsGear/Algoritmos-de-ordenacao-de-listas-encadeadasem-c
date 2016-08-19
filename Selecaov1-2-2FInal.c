/**Estrutura de dados em C. ENC 2016/1
Gabriel Velho Ghellere 14202480
Luan Lorenzo dos Santos Borges 15104328
Pedro Dias Mendonça 13104556
ALGORITMO DE ORDENAÇÃO POR SELECAO data de entrega 25/06/2016**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cel_ {
    int conteudo;
    struct cel_ *seg;
    struct cel_ *ant;
};
typedef struct cel_ celula;

int tamanho;

/**FUNÇOES**/
celula *InserirLista (celula *lst, int n);
void ImprimeLista (celula *lst);
void OrdenacaoSelecao (celula *lst);

int main() {
    celula *lst;
    celula *fim;
    celula *p;
    celula c, r;
    clock_t start, end;
    double cpu_time_used;
    int i, n = 100; /**Defina aqui o tamanho da lista**/

    lst = &c;
    fim = &r;
    lst->seg = fim;
    lst->ant = NULL;
    fim->seg = NULL;
    p = lst;
    srand(time(NULL));

    tamanho += sizeof(celula)*n;

    /**Inserindo elementos na lista**/
    for(i = 1; i <= n; i++)
        p = InserirLista(p, rand()%9999);

    printf("Antes de Ordenar\n");
    ImprimeLista(lst);
    printf("\n\n\n");

    start = clock();
    OrdenacaoSelecao(lst);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


    printf("\n Lista Ordenada \n");
    ImprimeLista(lst);
    printf("\nEspaco usado : %d", tamanho);
    printf("\n tempo de execução %.7f", cpu_time_used);
    printf("\n");
    return 0;
}

celula *InserirLista (celula *p, int x) {
    celula * nova;
    nova = (celula*)malloc(sizeof(celula));
    nova->conteudo = x;
    nova->seg = p->seg;
    nova->ant = p;
    p->seg->ant = nova;
    p->seg = nova;
    return p;
}

void ImprimeLista (celula *lst) {
    celula *p = lst->seg;
    while (p->seg != NULL){
        printf("%d ", p->conteudo);
        p = p->seg;
    }
}

void OrdenacaoSelecao (celula *lst) {
    celula *pmin;
    celula *p = lst->seg;
    celula *q;
    int aux;

    tamanho += sizeof(aux);

    while(p->seg->seg != NULL) {
        pmin = p;
        q = p->seg;
        while(q->seg != NULL){
            if(pmin->conteudo > q->conteudo)
                pmin = q;
            q = q->seg;
        }
        aux = p->conteudo;
        p->conteudo = pmin->conteudo;
        pmin->conteudo = aux;
        p = p->seg;
    }
}
