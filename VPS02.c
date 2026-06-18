#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    FILE *arquivo;
    struct Funcionario f[100];
    int total = 0;
    float somaSalarios = 0;

    arquivo = fopen("funcionarios.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[150];

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%[^,],%[^,],%f",
               f[total].nome,
               f[total].cargo,
               &f[total].salario);

        somaSalarios += f[total].salario;
        total++;
    }

    fclose(arquivo);

    printf("\n--- RELATORIO DE FUNCIONARIOS ---\n\n");

    for (int i = 0; i < total; i++) {
        printf("Nome: %s\n", f[i].nome);
        printf("Cargo: %s\n", f[i].cargo);
        printf("Salario: R$ %.2f\n\n", f[i].salario);
    }

    float media = somaSalarios / total;

    printf("Total de funcionarios: %d\n", total);
    printf("Salario medio: R$ %.2f\n", media);

    printf("\n--------------------------------\n");

    return 0;
}