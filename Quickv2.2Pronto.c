/**Estrutura de dados em C. ENC 2016/1
Gabriel Velho Ghellere 14202480
Luan Lorenzo dos Santos Borges 15104328
Pedro Dias Mendonça 13104556
ALGORITMO DE ORDENAÇÃO POR SELECAO data de entrega 25/06/2016**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cel_{
    int conteudo;
    struct cel_ *seg;
    struct cel_ *ant;
};
typedef struct cel_ celula;

int tamanho;

void QuickSort(celula *p, celula *r);
celula *Separa(celula *p, celula *r);
celula *inserirLista(celula * lst, int n);
void ImprimeLista(celula * lst);

int main(){
    celula *lst;
    celula *fim;
    celula *p;
    celula c, r;
    clock_t start, end;
    double cpu_time_used;

    int i, n=4200000;

    lst = &c;
    fim = &r;
    lst->seg = fim;
    lst->ant = NULL;
    fim->seg = NULL;
    fim->ant = lst;
    p=lst;

    tamanho += sizeof(celula)*n;

    srand(time(NULL));
    for(i=1; i<=n; i++)
        p = inserirLista(p, rand()%9999);

    printf("Antes de Ordenar\n");
    ImprimeLista(lst);
    printf("\n\n\n");

    start = clock();
    QuickSort(lst->seg, fim->ant);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Lista Ordenada \n");
    ImprimeLista(lst);
    printf("\nEspaco usado : %d", tamanho);
    printf("\n tempo de execução %.7f", cpu_time_used);
    printf("\n");
    return 0;
}


void QuickSort(celula *p, celula *r) {
    celula *j = malloc(sizeof(celula));
    if((r != NULL)&&(p!=r)&&(p != r->seg)) {
        j = Separa(p, r);
        QuickSort(p, j->ant);
        QuickSort(j->seg, r);
    }
}

celula *Separa(celula *p, celula *r){
    int aux, x  = r->conteudo;
    celula *i = p->ant;
    celula *k;

    tamanho += sizeof(aux) + sizeof(aux);

    for (k = p; k != r; k = k->seg)
    {
        if (k->conteudo <= x)
        {
            i = i->seg;
            aux = i->conteudo;
            i->conteudo = k->conteudo;
            k->conteudo = aux;
        }
    }
    i = i->seg;
    aux = i->conteudo;
    i->conteudo = r->conteudo;
    r->conteudo = aux;

    return i;
}
celula * inserirLista(celula * p, int x){
    celula * nova;
    nova=(celula*)malloc(sizeof(celula));
    nova->conteudo = x;
    nova->seg=p->seg;
    nova->ant=p;
    p->seg->ant=nova;
    p->seg =nova;
    return p;
}
void ImprimeLista(celula * lst){
    celula * p = lst->seg;
    while (p->seg != NULL){
        printf("%d ", p->conteudo);
        p=p->seg;
    }
}

