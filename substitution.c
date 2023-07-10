#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funções de protótipo
bool validate_key(string key);
string encrypt_text(string text, string key);

int main(int argc, string argv[])
{
    // Verifica se foi fornecido exatamente um argumento na linha de comando
    if (argc != 2)
    {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    string key = argv[1];

    // Verifica se a chave fornecida é válida
    if(!validate_key(key))
    {
        printf("A chave deve conter 26 caracteres, sem repetições.\n");
        return 1;
    }

    // Solicita ao usuário o texto simples
    string plaintext = get_string("Texto simples: ");

    // Criptografa o texto simples
    string ciphertext = encrypt_text(plaintext, key);

    // Imprime o texto cifrado
    printf("Texto cifrado: %s\n", ciphertext);

    return 0;
}

// Valida se a chave fornecida é válida
bool validate_key(string key)
{
    int len = strlen(key);

    // Verifica se a chave contém 26 caracteres
    if (len != 26)
    {
        return false;
    }

    bool used[26] = { false };

    // Verifica se a chave contém apenas caracteres alfabéticos e sem repetições
    for (int i = 0; i < len; i++)
    {

        // Verifica se o caractere é uma letra
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Converte o caractere para maiúsculo
        char uppercase = toupper(key[i]);

        // Verifica se o caractere já foi usado na chave
        if (used[uppercase - 'A'])
        {
            return false;
        }

        used[uppercase - 'A'] = true;
    }
    return true;
}

// Criptografa o texto usando a chave fornecida
string encrypt_text(string text, string key)
{

    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {

        char c = text[i];

        // Verifica se o caractere é uma letra alfabética
        if (isalpha(c))
        {

            // Converte o caractere para maiúsculo
            char uppercase = toupper(c);

            // Obtém o índice da letra na chave
            int index = uppercase - 'A';

            // Verifica se o caractere original é maiúsculo
            if (isupper(c))
            {

                // Substitui o caractere pelo correspondente em maiúsculo da chave
                text[i] = toupper(key[index]);
            }
            else
            {

                // Substitui o caractere pelo correspondente em minúsculo da chave
                text[i] = tolower(key[index]);
            }
        }
    }
    return text;
}
