#include <stdio.h>
#include <windows.h>
struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
};

int main() {
SetConsoleOutputCP(CP_UTF8);	
    FILE *arq;
    struct Funcionario f[10];
    int total = 0;
    float soma = 0;
    char linha[100];

    arq = fopen("funcionarios.csv", "r");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    fgets(linha, 100, arq);

    while (fgets(linha, 100, arq) != NULL) {
        sscanf(linha, "%[^,],%[^,],%f",
               f[total].nome,
               f[total].cargo,
               &f[total].salario);

        soma = soma + f[total].salario;
        total = total + 1;
    }

    fclose(arq);

    for (int i = 0; i < total; i++) {
        printf("Nome: %s\n", f[i].nome);
        printf("Cargo: %s\n", f[i].cargo);
        printf("Salario: %.2f\n\n", f[i].salario);
    }

    printf("Total: %d\n", total);
    printf("Media: %.2f\n", soma / total);

    return 0;
}