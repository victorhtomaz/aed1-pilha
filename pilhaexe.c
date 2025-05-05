#include <stdio.h>
#include <stdlib.h>

const int TAMANHO = 5;

typedef struct {
    int indexTopo;
    int tamanhoVetor;
    int vetor[];
} Pilha;

void iniciaPilha(Pilha** p, int tamanho);
void liberarPilha(Pilha* p);
int pegaTopoPilha(Pilha* p);
void empilhar(Pilha* p, int x);
void desempilhar(Pilha* p);
int main(void);

void iniciaPilha(Pilha** p, int tamanho){
    (*p) = malloc(sizeof(Pilha) + tamanho);
    (*p)->indexTopo = -1;
    (*p)->tamanhoVetor = tamanho;
}

void liberarPilha(Pilha* p){
    free(p);
}

int pegaTopoPilha(Pilha* p){
    if (p->indexTopo == -1)
        return -1; //Erro ocorreu
    else
        return p->vetor[p->indexTopo];
}

void desempilhar(Pilha* p){
    int valor;
    if (p->indexTopo > -1)
    {
        valor = p->vetor[p->indexTopo];
        p->indexTopo -= 1;
    }
    else
        return; //Erro ocorreu
}

void empilhar(Pilha* p, int x){
    if (p->indexTopo < p->tamanhoVetor - 1)
    {
        p->indexTopo += 1;
        p->vetor[p->indexTopo] = x;
    }
    else{
        //Erro ocorreu
        return;
    }
}

int main(void){
    Pilha* pilha;
    int tp, i;

    unsigned int a;

    iniciaPilha(&pilha, TAMANHO);

    empilhar(pilha, 2);
    empilhar(pilha, 4);
    empilhar(pilha, 6);
    empilhar(pilha, 8);

    for (i = 0; i < 4; i++)
    {
        tp = pegaTopoPilha(pilha);
        printf("%d\n", tp);
        desempilhar(pilha);
    }

    liberarPilha(pilha);
}