#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_key(string key);
string encrypt_text(string text, string key);

int main(int argc, string argv[])
{
    // Verificar se foi fornecido exatamente um argumento de linha de comando
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Verificar se a chave fornecida é válida
    if (!validate_key(key))
    {
        printf("Key must contain 26 characters, with no repeating characters.\n");
        return 1;
    }

    // Solicitar o texto simples ao usuário
    string plaintext = get_string("plaintext: ");

    // Criptografar o texto
    string ciphertext = encrypt_text(plaintext, key);

    // Imprimir o texto cifrado
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Validar se a chave fornecida é válida
bool validate_key(string key)
{
    int len = strlen(key);

    // Verificar se a chave possui 26 caracteres
    if (len != 26)
    {
        return false;
    }

    bool used[26] = { false };

    // Verificar se a chave contém apenas caracteres alfabéticos e sem repetições
    for (int i = 0; i < len; i++)
    {
        // Verificar se o caractere é uma letra
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Converter o caractere para minúsculo
        char c = tolower(key[i]);

        // Verificar se o caractere já foi usado na chave
        if (used[c - 'a'])
        {
            return false;
        }

        used[c - 'a'] = true;
    }

    return true;
}

// Criptografar o texto utilizando a chave fornecida
string encrypt_text(string text, string key)
{
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        char c = text[i];

        // Verificar se o caractere é uma letra alfabética
        if (isalpha(c))
        {
            // Converter o caractere para minúsculo
            char lowercase = tolower(c);

            // Obter o índice da letra na chave
            int index = lowercase - 'a';

            // Verificar se o caractere original é maiúsculo
            if (isupper(c))
            {
                // Substituir o caractere pelo caractere correspondente na chave em maiúsculo
                text[i] = toupper(key[index]);
            }
            else
            {
                // Substituir o caractere pelo caractere correspondente na chave em minúsculo
                text[i] = tolower(key[index]);
            }
        }
    }

    return text;
}
