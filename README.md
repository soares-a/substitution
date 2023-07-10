# Substituição
Este é um programa em C chamado substitution que permite criptografar mensagens usando uma cifra de substituição. A cifra de substituição é uma técnica de criptografia na qual cada letra do alfabeto é substituída por outra letra, determinada por uma chave fornecida pelo usuário.

## Funcionamento do programa
Ao executar o programa, o usuário deve fornecer um único argumento de linha de comando, que será a chave para a cifra de substituição. A chave deve ser uma sequência de 26 caracteres alfabéticos, podendo ser em maiúsculas ou minúsculas. O programa irá ignorar a diferenciação de maiúsculas e minúsculas na chave.

Após receber a chave, o programa solicitará ao usuário um texto simples para criptografar. O texto pode conter letras maiúsculas, minúsculas e outros caracteres que não serão alterados. O programa irá gerar o texto cifrado, substituindo cada letra do texto simples pela letra correspondente da chave. A criptografia preservará o caso das letras: letras maiúsculas permanecerão maiúsculas e letras minúsculas permanecerão minúsculas.

## Exemplo de uso
Aqui estão alguns exemplos de como o programa pode ser executado:


`$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ`


`$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp`

Caso o usuário não forneça um argumento de linha de comando, forneça uma chave inválida ou forneça múltiplos argumentos, o programa exibirá mensagens de erro apropriadas e retornará com um valor de erro.

## Como compilar e executar
Para compilar o programa, utilize o comando:


`$ gcc -o substitution substitution.c -lcs50`

Em seguida, execute o programa informando a chave desejada:

`$ ./substitution chave`

Certifique-se de que o arquivo `substitution.c` e a biblioteca `cs50.h` estejam no mesmo diretório.

## Observações
O programa utiliza a biblioteca `cs50.h` para obter a entrada do usuário de forma conveniente. Certifique-se de ter essa biblioteca instalada e disponível em seu sistema.

Durante a execução do programa, ele irá exibir algumas mensagens para guiar o usuário, como "plaintext:" e "ciphertext:". Essas mensagens serão exibidas no terminal.

## Limitações
Este programa possui as seguintes limitações:

A chave deve conter exatamente 26 caracteres alfabéticos, sem repetições.
Caracteres não alfabéticos (como espaços, vírgulas, pontuação, etc.) não são alterados pela cifra de substituição.
O programa não lida com a decodificação de textos cifrados. Ele é projetado apenas para criptografar textos usando a cifra de substituição.
Boas práticas de uso
Ao usar o programa, certifique-se de seguir as boas práticas de segurança:

Mantenha a chave em segredo, pois é o componente principal para descriptografar o texto.
Não utilize chaves óbvias, como sequências alfabéticas.
Utilize chaves complexas e difíceis de serem adivinhadas por terceiros.

## Referências
Biblioteca CS50: https://cs50.harvard.edu/x/2023/library/

Curso CS50 - Introdução à Ciência da Computação: https://cs50.harvard.edu/x/2023/

Este programa foi desenvolvido como parte do curso CS50 - Introdução à Ciência da Computação da Universidade Harvard.
