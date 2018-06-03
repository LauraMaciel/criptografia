#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "encriptografia.h"

void quebra_mensagem (char texto[],unsigned long long s[], int *n, int p, int q,int *tamanho)
{
    int i,tam;

    *n=p*q;
    tam=0;
    for(i=0;texto[i]!='\0';i++){
        tam++;
    }
    *tamanho=tam;
    for(i=0;i<tam;i++){
        s[i]=texto[i];
    }
}
void calcula_totiene(int p, int q, int *tot)
{
    *tot=(p-1)*(q-1);
}

int define_primos(int e, int tot)
{
    int i, div,num_divisores_e,num_divisores_tot,j;
    int divisores_e[1000],divisores_tot[1000];

    div=0;

//Definido quais são os divisores de e:
    num_divisores_e=0;
    for(i=e;i>0;i--){
        if(e%i==0){
            divisores_e[num_divisores_e]=i;
            num_divisores_e++;
        }
    }
//Definido quais são os divisores de tot:
    num_divisores_tot=0;
    for(i=tot;i>0;i--){
        if(tot%i==0){
            divisores_tot[num_divisores_tot]=i;
            num_divisores_tot++;
        }
    }
//Comparando os divisoes de tot e e:
    for(i=0;i<num_divisores_e;i++){
        for(j=0;j<num_divisores_tot;j++){
            if(divisores_e[i]==divisores_tot[j])
                div++;
        }
    }
if(div==1){
    return 1;} else {
    return 0;}
}

void define_e(int tot, int *e)
{
    int div,i,primo,aux_e;

    for(i=0;i!=aux_e;i++){
        printf("Digite o 'e': \n");
        scanf("%d", &aux_e);
        primo=define_primos(aux_e,tot);
        if((primo==1)&&(1<aux_e)&&(aux_e<tot)){
            i=aux_e-1;
        }
      }
      *e=aux_e;
}

void calcula_d(int tot, int e, int*d)
{
  int aux_d;

  for(aux_d=1;aux_d<=tot;aux_d++){
    if((e*aux_d)%tot==1)
      *d=aux_d;
  }

}

void faz_cifragem(int n, unsigned long long s[1000], unsigned long long c[1000], int e, int tamanho)
{
  int i,j;
  unsigned long long aux[1000];

  for(i=0;i<tamanho;i++)
    {
    aux[i]=1;
    for(j=0;j<e;j++)
    {
        aux[i]*=s[i];
    }
    c[i]=aux[i]%n;
  }
}

void faz_decifragem(int n, unsigned long long s[1000], unsigned long long c[1000], int d, int tamanho, char texto[1000])
{
  int i,j;
  unsigned long long aux[10];

  for(i=0;i<tamanho;i++)
    {
    aux[i]=1;
    for(j=0;j<d;j++)
    {
        printf("\n%llu *= %llu", aux[i],c[i]);
        aux[i]*=c[i];
        printf(" O aux e :%llu", aux[i]);
    }
    printf("\n%llu = %llu % %d", s[i],aux[i],n);
    s[i]=aux[i]%n;
    printf(" O s e: %llu", s[i]);
  }
}

