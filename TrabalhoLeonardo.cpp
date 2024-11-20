#include <stdio.h>
#include <string.h>

/*As defini��es abaixo criam constantes para o n�mero m�ximo de alunos e o n�mero m�ximo de notas dos
alunos, sendo 4 notas para cada aluno*/
#define MAX_ALUNOS 30
#define NOTAS 4


/*Estrutura que armazena o nome do aluno, as suas notas e a m�dia indivual de cada aluno*/
typedef struct {
    char nome[50];
    float notas[NOTAS];
    float media;
} Aluno;


/*fun��o que calcula a m�dia individual de cada aluno, ela percorre cada nota, somando ao total, e no final
ela retorna o resultado dividido pela quantidade, para calcular a m�dia do aluno*/
float calcular_media(float notas[], int tamanho) {
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    return soma / tamanho;/*retorna a m�dia do aluno*/
}


/*fun��o que percorre todas a notas e armazena dentro da vari�vel "maior", a maior nota encontrada*/
float maior_nota_turma(Aluno alunos[], int qtd_alunos) {
    float maior = alunos[0].notas[0];
    for (int i = 0; i < qtd_alunos; i++) {
        for (int j = 0; j < NOTAS; j++) {/*estruta de repeti��o onde ele verifica, se a nota na posi��o que est� � maior que a vari�vel, ela substitui a v�ri�vel, e assim, sucessivamente, a pr�xima nota, se for menor, descarta, se for maior, substitui na vari�vel*/
            if (alunos[i].notas[j] > maior) {
                maior = alunos[i].notas[j];
            }
        }
    }
    return maior;/*retorna a maior nota encontrada*/
}


/*Funciona similar a anterior "maior nota", por�m, agora ela verifica qual a menor nota dentre elas*/
float menor_nota_turma(Aluno alunos[], int qtd_alunos) {
    float menor = alunos[0].notas[0];
    for (int i = 0; i < qtd_alunos; i++) {
        for (int j = 0; j < NOTAS; j++) {/*estrutura de repeti��o que funiona exatamente quanto a anterior, por�m, agora ela verifica se � menor para depois armazenar na vari�vel*/
            if (alunos[i].notas[j] < menor) {
                menor = alunos[i].notas[j];
            }
        }
    }
    return menor;/*retorna a menor nota encontrada*/
}


/*fun��o que percorre a m�dia individual da turma para calular a m�dia geral*/
float media_geral_turma(Aluno alunos[], int qtd_alunos) {
    float soma_medias = 0.0;
    for (int i = 0; i < qtd_alunos; i++) {
        soma_medias += alunos[i].media;
    }
    return soma_medias / qtd_alunos;/*ap�s somar todas as m�dias individuais, ela retorna dividindo pela quantodade de alunos pertencentes  classe, retornando assim, a m�diada turma*/
}


/*Fun��o que calcula quantos alunos est�o abaixo da m�dia estipulada pelo usu�rio do programa*/
int alunos_abaixo_minimo(Aluno alunos[], int qtd_alunos, float pontuacao_minima) {
    int abaixo_minimo = 0;
    for (int i = 0; i < qtd_alunos; i++) {
        if (alunos[i].media < pontuacao_minima) {
            abaixo_minimo++;
        }
    }
    return abaixo_minimo;/*retorna a quantidade de alunos que est�o abaixo da m�dia*/
}


/*exibe o relat�rio de alunos que est�o acima e abaixo da m�dia*/
void exibir_relatorio(Aluno alunos[], int qtd_alunos, float media_geral) {
    printf("\nAlunos acima da media geral:\n");
    for (int i = 0; i < qtd_alunos; i++) {/*estrutura de repeti��o que percorre os alunos verificando, se a m�dia daqule aluno, for maior que a m�dia geral, ele mostra o aluno acima da m�dia*/
        if (alunos[i].media > media_geral) {
            printf(" - %s (Media: %.2f)\n", alunos[i].nome, alunos[i].media);
        }
    }

    printf("\nAlunos abaixo da media geral:\n");
    for (int i = 0; i < qtd_alunos; i++) {
        if (alunos[i].media <= media_geral) {/*estrutra de repeti��o que funciona como a anterior, por�m, agora verifica se a m�dia do aluno � menor que a m�dia geral, para poder exibir os alunos abaixo da m�dia*/
            printf(" - %s (Media: %.2f)\n", alunos[i].nome, alunos[i].media);
        }
    }
}


/*Fun��o principal, respons�vel pela intera��o com o usu�rio e pela execu��o das fun��es acimas*/
int main() {
    int qtd_alunos;
    float pontuacao_minima;
    Aluno alunos[MAX_ALUNOS];

    printf("Informe a quantidade de alunos (maximo de 30): ");
    scanf("%d", &qtd_alunos);
    if (qtd_alunos > MAX_ALUNOS) {
        printf("Quantidade de alunos excede o limite permitido.\n");
        return 1;
    }/*essa primeira parte solicita o n�mero de alunos valida se est� dentro da quantidade estipulada para cada classe*/

    for (int i = 0; i < qtd_alunos; i++) {
        printf("\nInforme o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Informe as 4 notas do aluno %s:\n", alunos[i].nome);
        for (int j = 0; j < NOTAS; j++) {
            printf(" - Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        alunos[i].media = calcular_media(alunos[i].notas, NOTAS);
    }/*essa estrutura de repeti��o, l� os nomes e notas de cada aluno e calcula a m�dia individual com a fun��o "calcular_media"*/

    float maior_nota = maior_nota_turma(alunos, qtd_alunos);
    float menor_nota = menor_nota_turma(alunos, qtd_alunos);

    float media_geral = media_geral_turma(alunos, qtd_alunos);

    printf("\nInforme a pontuacao minima exigida: ");
    scanf("%f", &pontuacao_minima);
    int abaixo_minimo = alunos_abaixo_minimo(alunos, qtd_alunos, pontuacao_minima);
    /*essa outra parte calcula a maior nota, menor nota, m�dia geral e quantidade de alunos abaixo da pontua��o m�nima, usando as fun��es j� programadas anteriormente*/

    printf("\n\n=== RELATORIO FINAL ===\n\n");
    printf("Maior nota da turma: %.2f\n", maior_nota);
    printf("Menor nota da turma: %.2f\n", menor_nota);
    printf("Media geral da turma: %.2f\n", media_geral);
    printf("Alunos abaixo da pontuacao minima exigida (%.2f): %d\n", pontuacao_minima, abaixo_minimo);

    exibir_relatorio(alunos, qtd_alunos, media_geral);

    return 0;
}/*o restante do c�digo, exibe as informa��es gerais da turma e chama a fun��o "exibir_relatorio" para mostrar os alunos acima e abaixo da m�dia geral*/
