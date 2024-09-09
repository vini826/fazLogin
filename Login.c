#include <stdio.h>  // Biblioteca padrão para entrada e saída
#include <stdlib.h> // Biblioteca padrão do C, usada aqui para funções como exit
#include <string.h> // Biblioteca para manipulação de strings, como strncpy e strtok

// Definindo constantes
#define EMAILS_COUNT 10       // Número máximo de emails que serão armazenados
#define MAX_EMAIL_LENGTH 50   // Tamanho máximo permitido para cada email
#define MAX_CPF_LENGTH 20     // Tamanho máximo permitido para cada CPF

int main()
{
    // Abrindo o arquivo "emailsesenhas.txt" para leitura
    FILE *file = fopen("emailsesenhas.txt", "r");
    
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL)
    {
        // Caso o arquivo não seja aberto, imprime uma mensagem de erro
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Termina o programa com um código de erro
    }

    // Arrays para armazenar os emails e CPFs
    char emails[EMAILS_COUNT][MAX_EMAIL_LENGTH];  // Armazena os emails
    char CPF[EMAILS_COUNT][MAX_CPF_LENGTH];       // Armazena os CPFs
    char line[1000]; // Variável para armazenar a linha inteira do arquivo
    int i = 0;       // Índice para iterar pelos arrays

    // Lê a linha inteira do arquivo
    if (fgets(line, sizeof(line), file))
    {
        // Remove o caractere de nova linha ao final da string, se existir
        line[strcspn(line, "\n")] = '\0';

        // Divide a linha com base nas vírgulas usando strtok
        char *token = strtok(line, ",");

        // Continua a dividir a linha enquanto houver tokens e o limite não for atingido
        while (token != NULL && i < EMAILS_COUNT)
        {
            // O primeiro token é o email
            strncpy(emails[i], token, MAX_EMAIL_LENGTH - 1); // Copia o email para o array
            token = strtok(NULL, ","); // Pega o próximo token, que deve ser o CPF

            // O segundo token é o CPF
            if (token != NULL)
            {
                strncpy(CPF[i], token, MAX_CPF_LENGTH - 1); // Copia o CPF para o array
                token = strtok(NULL, ","); // Pega o próximo token, se existir
            }

            i++; // Incrementa o índice para o próximo email/CPF
        }
    }

    // Fecha o arquivo após a leitura
    fclose(file);

    // Exibe os emails e CPFs armazenados
    printf("Emails e Senhas organizados em arrays:\n");
    for (int j = 0; j < EMAILS_COUNT; j++)
    {
        // Imprime o email e o CPF correspondentes
        printf("Email: %s, CPF: %s\n", emails[j], CPF[j]);
    }

    return 0; // Termina o programa com sucesso
}
