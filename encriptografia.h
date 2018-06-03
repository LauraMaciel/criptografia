#ifndef _encriptografia_h
#define _encriptografia_h

/*
** Cabeçalhos das funções implementadas no módulo encriptografia.c
*/
/*
** Calcula o n e quebra a mensagem
*/
void quebra_mensagem (char texto[],unsigned long long s[], int *n, int p, int q,int *tamanho);
/*
** Calcula o totiene de dois números recebidos
*/
void calcula_totiene(int p, int q, int *tot);
/*
** Escolha do inteiro e, sob as determinadas restrições
*/
int define_primos(int e, int tot);
/*
** Escolha do inteiro e, sob as determinadas restrições
*/
void define_e(int tot, int *e);
/*
** Calcula a chave d
*/
void calcula_d(int tot, int e, int*d);
/*
** Faz a cifragem
*/
void faz_cifragem(int n, unsigned long long s[1000], unsigned long long c[1000], int e, int tamanho);
/*
** Faz a decifragem
*/
void faz_decifragem(int n, unsigned long long s[1000], unsigned long long c[1000], int d, int tamanho, char texto[1000]);
#endif // _encriptografia_h
