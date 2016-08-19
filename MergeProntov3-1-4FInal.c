/**Estrutura de dados em C. ENC 2016/1
Gabriel Velho Ghellere 14202480
Luan Lorenzo dos Santos Borges 15104328
Pedro Dias Mendonça 13104556
ALGORITMO DE ORDENAÇÃO POR SELECAO data de entrega 25/06/2016**/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct cel_
{
    int conteudo;
    struct cel_ *seg;
    struct cel_ *ant;
};
typedef struct cel_ celula;

int tamanho;

/******FUNÇOES******/
celula *CriaCelula (int x);
celula *Intercala (celula *lst, celula *parte2);
celula *MergeSort (celula *head);
void InsereLista (celula **lst, int x);
void ImprimeLista (celula *lst);
celula *divide (celula *lst);
void Desaloca (celula *lst);

int main () {
    int n = 6400;/**Defina aqui o tamanho da lista**/
    int i;
    double cpu_time_used;
    clock_t start, end;

    srand(time(NULL));
    celula *lst = NULL;

    tamanho = sizeof(celula)*n;

    for (i = 0; i < n; i++)
        InsereLista(&lst, rand() % 9999);

    printf("Antes de Ordenar\n");
    ImprimeLista(lst);
    printf("\n\n\n");


    start = clock();
    MergeSort(lst);
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

celula *CriaCelula (int x) {
    celula *nova;
    nova = (celula*)malloc(sizeof(celula));
    nova->conteudo = x;
    nova->seg = NULL;
    nova->ant = NULL;
    return nova;
}

celula *Intercala (celula *lst, celula *parte2) {

    if (lst == NULL) {/**Base Recursao**/
       Desaloca(lst);
        return parte2;
    }

    if (parte2 == NULL) {/**Base2 recursao**/
        Desaloca(parte2);
        return lst;
    }

    if (lst->conteudo < parte2->conteudo) {
        lst->seg = Intercala(lst->seg,parte2);
        lst->seg->ant = lst;
        lst->ant = NULL;
        return lst;
        Desaloca(parte2);
    }
    else {
        parte2->seg = Intercala(lst,parte2->seg);
        parte2->seg->ant = parte2;
        parte2->ant = NULL;
        return parte2;
        Desaloca(lst);
    }
}


celula *MergeSort(celula *lst) {
    celula *lista2;
    if (lst->seg == NULL) {
        return lst;
    }
    else {
        lista2 = divide(lst);
        lst = MergeSort(lst);
        lista2 = MergeSort(lista2);
        return Intercala(lst,lista2);
    }
}


void InsereLista(celula **lst, int x) {
    celula *nova = CriaCelula(x);
    if ((*lst) == NULL)/*****Lista Vazia*****/
        (*lst) = nova;
    else {
        nova->seg = *lst;
        (*lst)->ant = nova;
        (*lst) = nova;
    }
}

void ImprimeLista(celula *lst) {
    celula *p = lst;
    while (p != NULL) {
        printf("%d ",p->conteudo);
        p = p->seg;
    }
}

celula *divide(celula *lst) {
    celula *p1 = lst;
    celula *p2 = lst;
    celula *parte2;

    while (p1->seg != NULL && p1->seg->seg != NULL) {
        p1 = p1->seg->seg;
        p2 = p2->seg;
    }
    parte2 = p2->seg;
    p2->seg = NULL;
    return parte2;
}

void Desaloca(celula *lst) {
    celula *p;

    p = lst;

    if(p != NULL)
        Desaloca(p->seg);
    free(p);
}





