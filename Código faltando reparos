#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMAILS_COUNT 10
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

int main()
{
// Lendo arquivo
FILE *file = fopen("emailsesenhas.txt", "r");
if (file == NULL)
{
printf("Erro ao abrir o arquivo.\n");
return 1;
}

char emails[EMAILS_COUNT][MAX_EMAIL_LENGTH];
char passwords[EMAILS_COUNT][MAX_PASSWORD_LENGTH];
char line[1000]; // Linha para armazenar todo o conteúdo do arquivo
int i = 0;

// Lendo a linha inteira do arquivo
if (fgets(line, sizeof(line), file))
{
    // Removendo o caractere de nova linha
    line[strcspn(line, "\n")] = '\0';

    // Usando strtok para dividir a linha com base nas vírgulas
    char *token = strtok(line, ",");

    while (token != NULL && i < EMAILS_COUNT)
    {
        // O primeiro token é o e-mail
        strncpy(emails[i], token, MAX_EMAIL_LENGTH - 1);
        token = strtok(NULL, ",");

        // O segundo token é a senha
        if (token != NULL)
        {
            strncpy(passwords[i], token, MAX_PASSWORD_LENGTH - 1);
            token = strtok(NULL, ",");
        }

        i++;
    }
}

fclose(file);

// Exibindo os e-mails e senhas armazenados nos arrays
printf("Emails e Senhas organizados em arrays:\n");
for (int j = 0; j < EMAILS_COUNT; j++)
{
    printf("Email: %s, Senha: %s\n", emails[j], passwords[j]);
}

return 0;
}
