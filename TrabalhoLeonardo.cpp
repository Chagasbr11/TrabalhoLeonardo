#include <stdio.h>
#include <string.h>

/*As definições abaixo criam constantes para o número máximo de alunos e o número máximo de notas dos
alunos, sendo 4 notas para cada aluno*/
#define MAX_ALUNOS 30
#define NOTAS 4


/*Estrutura que armazena o nome do aluno, as suas notas e a média indivual de cada aluno*/
typedef struct {
    char nome[50];
    float notas[NOTAS];
    float media;
} Aluno;


/*função que calcula a média individual de cada aluno, ela percorre cada nota, somando ao total, e no final
ela retorna o resultado dividido pela quantidade, para calcular a média do aluno*/
float calcular_media(float notas[], int tamanho) {
    float soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    return soma / tamanho;/*retorna a média do aluno*/
}


/*função que percorre todas a notas e armazena dentro da variável "maior", a maior nota encontrada*/
float maior_nota_turma(Aluno alunos[], int qtd_alunos) {
    float maior = alunos[0].notas[0];
    for (int i = 0; i < qtd_alunos; i++) {
        for (int j = 0; j < NOTAS; j++) {/*estruta de repetição onde ele verifica, se a nota na posição que está é maior que a variável, ela substitui a váriável, e assim, sucessivamente, a próxima nota, se for menor, descarta, se for maior, substitui na variável*/
            if (alunos[i].notas[j] > maior) {
                maior = alunos[i].notas[j];
            }
        }
    }
    return maior;/*retorna a maior nota encontrada*/
}


/*Funciona similar a anterior "maior nota", porém, agora ela verifica qual a menor nota dentre elas*/
float menor_nota_turma(Aluno alunos[], int qtd_alunos) {
    float menor = alunos[0].notas[0];
    for (int i = 0; i < qtd_alunos; i++) {
        for (int j = 0; j < NOTAS; j++) {/*estrutura de repetição que funiona exatamente quanto a anterior, porém, agora ela verifica se é menor para depois armazenar na variável*/
            if (alunos[i].notas[j] < menor) {
                menor = alunos[i].notas[j];
            }
        }
    }
    return menor;/*retorna a menor nota encontrada*/
}


/*função que percorre a média individual da turma para calular a média geral*/
float media_geral_turma(Aluno alunos[], int qtd_alunos) {
    float soma_medias = 0.0;
    for (int i = 0; i < qtd_alunos; i++) {
        soma_medias += alunos[i].media;
    }
    return soma_medias / qtd_alunos;/*após somar todas as médias individuais, ela retorna dividindo pela quantodade de alunos pertencentes  classe, retornando assim, a médiada turma*/
}


/*Função que calcula quantos alunos estão abaixo da média estipulada pelo usuário do programa*/
int alunos_abaixo_minimo(Aluno alunos[], int qtd_alunos, float pontuacao_minima) {
    int abaixo_minimo = 0;
    for (int i = 0; i < qtd_alunos; i++) {
        if (alunos[i].media < pontuacao_minima) {
            abaixo_minimo++;
        }
    }
    return abaixo_minimo;/*retorna a quantidade de alunos que estão abaixo da média*/
}


/*exibe o relatório de alunos que estão acima e abaixo da média*/
void exibir_relatorio(Aluno alunos[], int qtd_alunos, float media_geral) {
    printf("\nAlunos acima da media geral:\n");
    for (int i = 0; i < qtd_alunos; i++) {/*estrutura de repetição que percorre os alunos verificando, se a média daqule aluno, for maior que a média geral, ele mostra o aluno acima da média*/
        if (alunos[i].media > media_geral) {
            printf(" - %s (Media: %.2f)\n", alunos[i].nome, alunos[i].media);
        }
    }

    printf("\nAlunos abaixo da media geral:\n");
    for (int i = 0; i < qtd_alunos; i++) {
        if (alunos[i].media <= media_geral) {/*estrutra de repetição que funciona como a anterior, porém, agora verifica se a média do aluno é menor que a média geral, para poder exibir os alunos abaixo da média*/
            printf(" - %s (Media: %.2f)\n", alunos[i].nome, alunos[i].media);
        }
    }
}


/*Função principal, responsável pela interação com o usuário e pela execução das funções acimas*/
int main() {
    int qtd_alunos;
    float pontuacao_minima;
    Aluno alunos[MAX_ALUNOS];

    printf("Informe a quantidade de alunos (maximo de 30): ");
    scanf("%d", &qtd_alunos);
    if (qtd_alunos > MAX_ALUNOS) {
        printf("Quantidade de alunos excede o limite permitido.\n");
        return 1;
    }/*essa primeira parte solicita o número de alunos valida se está dentro da quantidade estipulada para cada classe*/

    for (int i = 0; i < qtd_alunos; i++) {
        printf("\nInforme o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Informe as 4 notas do aluno %s:\n", alunos[i].nome);
        for (int j = 0; j < NOTAS; j++) {
            printf(" - Nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }
        alunos[i].media = calcular_media(alunos[i].notas, NOTAS);
    }/*essa estrutura de repetição, lê os nomes e notas de cada aluno e calcula a média individual com a função "calcular_media"*/

    float maior_nota = maior_nota_turma(alunos, qtd_alunos);
    float menor_nota = menor_nota_turma(alunos, qtd_alunos);

    float media_geral = media_geral_turma(alunos, qtd_alunos);

    printf("\nInforme a pontuacao minima exigida: ");
    scanf("%f", &pontuacao_minima);
    int abaixo_minimo = alunos_abaixo_minimo(alunos, qtd_alunos, pontuacao_minima);
    /*essa outra parte calcula a maior nota, menor nota, média geral e quantidade de alunos abaixo da pontuação mínima, usando as funções já programadas anteriormente*/

    printf("\n\n=== RELATORIO FINAL ===\n\n");
    printf("Maior nota da turma: %.2f\n", maior_nota);
    printf("Menor nota da turma: %.2f\n", menor_nota);
    printf("Media geral da turma: %.2f\n", media_geral);
    printf("Alunos abaixo da pontuacao minima exigida (%.2f): %d\n", pontuacao_minima, abaixo_minimo);

    exibir_relatorio(alunos, qtd_alunos, media_geral);

    return 0;
}/*o restante do código, exibe as informações gerais da turma e chama a função "exibir_relatorio" para mostrar os alunos acima e abaixo da média geral*/
