#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_RESERVAS 100

typedef struct {
    char nome[50];
    char cpf[12];
    int dia;
    char diaSemana[10];
    int numeroPessoas;
} Reserva;

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;

void fazerReserva();
void listarReservas();
void totalPessoasPorDia();
void limparBuffer();

int main() {
    setlocale(LC_ALL, "");
    int opcao;

    do {
        system("cls");
        printf("==== Sistema de Reservas do Restaurante ====\n");
        printf("1 - Fazer Reserva\n");
        printf("2 - Listar Reservas\n");
        printf("3 - Total de Pessoas Por Dia\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                totalPessoasPorDia();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        system("pause");
    } while (opcao != 4);

    return 0;
}

void fazerReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido! (%d)\n", MAX_RESERVAS);
        return;
    }

    printf("Informe o Nome: ");
    fgets(reservas[totalReservas].nome, 50, stdin);
    reservas[totalReservas].nome[strcspn(reservas[totalReservas].nome, "\n")] = 0;

    printf("Informe o CPF: ");
    fgets(reservas[totalReservas].cpf, 12, stdin);
    reservas[totalReservas].cpf[strcspn(reservas[totalReservas].cpf, "\n")] = 0;

    int opcaoDia;
    do {
        printf("Informe o Dia da Reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
        scanf("%d", &opcaoDia);
        limparBuffer();

        switch (opcaoDia) {
            case 1:
                strcpy(reservas[totalReservas].diaSemana, "Quinta");
                reservas[totalReservas].dia = opcaoDia;
                break;
            case 2:
                strcpy(reservas[totalReservas].diaSemana, "Sexta");
                reservas[totalReservas].dia = opcaoDia;
                break;
            case 3:
                strcpy(reservas[totalReservas].diaSemana, "Sábado");
                reservas[totalReservas].dia = opcaoDia;
                break;
            case 4:
                strcpy(reservas[totalReservas].diaSemana, "Domingo");
                reservas[totalReservas].dia = opcaoDia;
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
                break;
        }
    } while (opcaoDia < 1 || opcaoDia > 4);

    printf("Informe o Número de Pessoas: ");
    scanf("%d", &reservas[totalReservas].numeroPessoas);
    limparBuffer();

    totalReservas++;
    printf("Reserva realizada com sucesso!\n");
}

void listarReservas() {
    if (totalReservas == 0) {
        printf("Não há reservas cadastradas.\n");
        return;
    }
    int i;
	    for (i = 0; i < totalReservas; i++) {
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].dia);
        printf("Dia da Semana: %s\n", reservas[i].diaSemana);
        printf("Número de Pessoas: %d\n", reservas[i].numeroPessoas);
        printf("===============================\n");
    }
}

void totalPessoasPorDia() {
    int dia, totalPessoas = 0;
    printf("Informe o Dia da Reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo): ");
    scanf("%d", &dia);
    limparBuffer();
    int i;
    for (i = 0; i < totalReservas; i++) {
        if (reservas[i].dia == dia) {
            totalPessoas += reservas[i].numeroPessoas;
        }
    }

    printf("Total de Pessoas para o dia %d: %d\n", dia, totalPessoas);
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

