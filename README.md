# Labs C

Este repositório contém testes, curiosidades e pequenas experiências com a linguagem C, desenvolvidas durante meus estudos.

# 🧠 Objetivo

Registrar o aprendizado de forma prática e acessível, facilitando a revisão e servindo como referência para quem também estiver estudando C.

---

# 📂 Exemplos

# `buffer_keyboard.c`

Demonstra como lidar com um erro comum relacionado ao buffer do teclado ao usar `scanf()` com o especificador `%c`.

O problema ocorre porque o caractere de nova linha (`\n`) deixado no buffer após a leitura de outros dados pode ser interpretado como entrada válida para `%c`.  
A solução é adicionar um espaço antes do `%c` na string de formatação:

scanf(" %c", &variavel);

-----------

## Mais arquivos e testes serão adicionados conforme avanço nos estudos.
