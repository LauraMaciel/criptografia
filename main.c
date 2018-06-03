#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "encriptografia.h"

int main(void){

int p,q,n,tot,e,d,tamanho,k,div_p,div_q;
unsigned long long s[1000],c[1000];
char texto[1000];
p=0;
q=0;
n=0;
tot=0;
e=0;
d=0;
tamanho=0;
k=0;

printf("Digite a mensagem: ");
gets(texto);
printf("Digite p e q (p e q devem ser numeros primos): ");
scanf("%d %d", &p, &q);

quebra_mensagem(texto,s,&n,p,q,&tamanho);

printf("Sua mensagem apos ser quebrada e:\n");

    for(k=0;k<tamanho;k++){
        printf("%d ", s[k]);
    }

printf("\nO tamanho da sua mensagem e:\n");
printf("%d", tamanho);
printf("\nO 'n' e:\n");
printf("%d", n);

calcula_totiene(p,q,&tot);

printf("\nO tot(n) e:\n");
printf("%d\n", tot);

define_e(tot,&e);

printf("O 'e' e:\n");
printf("%d", e);

calcula_d(tot,e,&d);

printf("\nO 'd' e:\n");
printf("%d", d);

faz_cifragem(n,s,c,e,tamanho);
printf("\nMensagem cifrada:\n");
for(k=0;k<tamanho;k++)
{
    printf("%llu ", c[k]);
}

faz_decifragem(n,s,c,d,tamanho,texto);
printf("\nMensagem decifrada:\n");
for(k=0;k<tamanho;k++)
{
    printf("%llu ", s[k]);
}
printf("\n");
for(k=0;k<tamanho;k++)
{
    printf("%c", texto[k]);
}
 return 0;
}


