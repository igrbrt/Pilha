/* 
 * File:   main.c
 * Author: igor
 *
 * Created on 20 de Outubro de 2010, 15:02
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */


typedef struct No{
    int info;
    struct No *ant;

}No;

//prototipo das funcoes
void push(No**,No**,int,int);
int pop(No**,No**,int);
int top(No**,No**,int);
int check(No**,No**,int);
void sucess();

int main() {
   No *Topo=(No*)malloc(sizeof(No)); // pilha 1
   Topo = NULL;
   No *Topo2=(No*)malloc(sizeof(No)); // pilha 2
   Topo2 = NULL;
   int op=0,opp,info;
   do{
       __fpurge(stdin);
       op = 0;
       opp = 0;
       printf("\t\t == Pilha ==\n\n(1) - Pilha 1\n(2) - Pilha 2\n--> ");
       scanf("%d",&opp);
       while(opp != 1 && opp!= 2){
           printf("Calma,Usuario amigo!\nApenas 1 ou 2\n");
           __fpurge(stdin);
           scanf("%d",&opp);
       }
       system("clear");
       printf("\t\t == Pilha ==\n\n(1) - Inserir\n(2) - Remover\n(3) - Ver Topo\n(4) - Sair\n--> ");
       scanf("%d",&op);
       switch(op){
           case 1:  puts("\nElemento: "); scanf("%d",&info);
                    push(&Topo,&Topo2,info,opp);
                    sucess();
                    break;
           case 2:  if((check(&Topo,&Topo2,opp)) == 0)
                        break;
                    info = pop(&Topo,&Topo2,opp);
                    printf("\nElemento %d removido da pilha %d \n",info,opp);
                    sleep(1);
                    sucess();
                    break;
           case 3:  if((check(&Topo,&Topo2,opp)) == 0)
                        break;
                    info = top(&Topo,&Topo2,opp);
                    printf("\nTopo da pilha %d: %d\n",opp,info);
                    break;
           case 4:  puts("\nFechando...");
                    break;
           default: puts("\nCalma, Usuario amigo!\n");
       }
       sleep(2);
       system("clear");
   }while(op!=4);
    return (0);
}

void push(No **Topo,No **Topo2,int info,int opp){  //insere
    No *novo = (No*)malloc(sizeof(No)); // no a ser inserido
    novo->info = info;  // recebe informacao
    if(opp == 1){ // inserir na pilha 1
            if(*Topo == NULL ){  // insere primeiro elemento
            *Topo = novo;
            (*Topo)->ant = NULL;
            return;
        }
            else{       // insere do segundo pra frente
            novo->ant = *Topo;
            *Topo = novo;
            return;
        }
    }
    else{  // inserir na pilha 2
        if(*Topo2 == NULL ){
            *Topo2 = novo;
            (*Topo2)->ant = NULL;
            return;
        }
        else{
            novo->ant = *Topo2;
            *Topo2 = novo;
            return;
        }
    }
}

int pop(No **Topo,No** Topo2,int opp){  //remove e retorna o valor removido
    int info;
    No *aux = (No*)malloc(sizeof(No));
    if(opp == 1){       // remover da pilha 1
        aux = *Topo;
        *Topo = (*Topo)->ant;
        info = aux->info;
        free(aux);
        return info;
    }
    else{       // remover pilha 2
        aux = *Topo2;
        *Topo2 = (*Topo2)->ant;
        info = aux->info;
        free(aux);
        return info;
    }
}

int top(No **Topo,No **Topo2,int opp){  // retorna o topo
    if(opp == 1)
        return (*Topo)->info;
    else
        return (*Topo2)->info;
}

int check(No** Topo,No** Topo2,int opp){ //verifica pilha
    if(opp == 1 && *Topo == NULL){
        puts("Pilha 1 Vazia!");
        return 0;
    }
    else if(opp == 2 && *Topo2 == NULL){
            puts("Pilha 2 Vazia!");
            return 0;
        }
    return 1;
}
void sucess(){
    system("clear");
    puts("\n\n\tOperacao Realizada com sucesso !");
    sleep(1);
}