# Exemplos de Código - Cadeias de Caracteres (Strings)

Este diretório contém todos os exemplos de código-fonte apresentados no **Capítulo 05 (Cadeias de Caracteres / Strings)** das notas de aula da disciplina de Programação Estruturada (MCTA028-15).

---

## Estrutura do Projeto

```
.
├── Makefile
├── README.md
├── .gitignore
├── .devcontainer/   # Configuração de ambiente para Dev Container / GitHub Codespaces
├── src/             # Códigos-fonte (.c) dos exemplos e algoritmos
└── build/           # Executáveis compilados (ignorado pelo git)
```

---

## Como Compilar e Executar

### 1. Compilar todos os programas válidos

Para compilar toda a coleção de programas de uma só vez:

```bash
make
```

Os binários correspondentes serão gerados no diretório `build/`.

### 2. Executar a suíte de testes rápidos

Para compilar e disparar a execução de todos os programas não interativos:

```bash
make test
```

### 3. Diagnóstico de estouro de buffer com AddressSanitizer (ASan)

O exemplo `src/14_estouro_buffer_asan.c` demonstra uma tentativa de cópia que ultrapassa o tamanho do buffer. Para compilar com as flags `-fsanitize=address,undefined` e inspecionar o relatório emitido pelo ASan:

```bash
make asan-14
```

### 4. Demonstração de violação de acesso em memória (.rodata / SIGSEGV)

O exemplo `src/04_modificacao_literal.c` ilustra a tentativa ilegal de alterar um literal de string alocado na seção somente-leitura (`.rodata`):

```bash
make segfault-04
```

### 5. Limpar os arquivos compilados

```bash
make clean
```

---

## Descrição dos Códigos em `src/`

### Exemplos Conceituais do Capítulo

- `01_char_vs_inteiros.c`: Interoperabilidade e aritmética com o tipo `char` (tabela ASCII).
- `02_declaracao_strings.c`: Sintaxe de declaração, regra de capacidade $N+1$, inicialização parcial e concatenação estática.
- `03_string_fundamentos.c`: Inspeção byte a byte do layout de memória de arranjos de strings na pilha.
- `03b_string_interning.c`: Unificação de literais (*string interning*) e comparação de ponteiros em `.rodata` vs. Pilha.
- `04_modificacao_literal.c`: Mutabilidade de arranjo na pilha vs. violação de escrita em literais constantes (`SIGSEGV`).
- `05_strings_saida.c`: Exibição de strings na saída padrão contrastando as rotinas `puts` e `fputs`.
- `06_ler_linha_robusta.c`: Entrada segura de linhas completas com `fgets`, remoção do `\n` e descarte de excedentes de fluxo.
- `07_strlen_implementacao.c`: Implementação idiomática de medição de comprimento (`strlen`) com índices e ponteiros.
- `08_strcmp_exemplos.c`: Comparação lexicográfica com `strcmp` e validação de prefixos com `strncmp`.
- `09_snprintf_seguro.c`: Composição, cópia, concatenação e diagnóstico de truncamento de strings com `snprintf`.
- `10_strings_busca.c`: Localização de caracteres e subcadeias com `strchr`, `strrchr` e `strstr`.
- `11_strtok_exemplo.c`: Particionamento destrutivo de texto e tokenização via `strtok`.
- `12_arranjos_de_strings.c`: Matriz bidimensional (`char[3][15]`) vs. arranjo de ponteiros para literais (`const char *[3]`).
- `13_cli_utilitario.c`: Processamento de argumentos de linha de comando (`argc`/`argv`) e conversão robusta com `strtol`.
- `14_estouro_buffer_asan.c`: Demonstração didática de *buffer overflow* interceptado pelo AddressSanitizer.

### Algoritmos Fundamentais sobre Strings

- `24_algoritmo_prefixo_sufixo.c`: Funções idiomáticas `comeca_com` e `termina_com` para validação de prefixos e sufixos.
- `25_algoritmo_texto_para_inteiro.c`: Conversão de texto para inteiro (*parsing*) por acumulação decimal com validação de dígitos e sinal.
- `26_algoritmo_inteiro_para_texto.c`: Serialização de inteiros para texto por extração reversa de restos e inversão modular *in-place*.
- `27_algoritmo_meu_strstr.c`: Algoritmo ingênuo de busca de subcadeia por janela deslizante (*sliding window*).
- `28_algoritmo_distancia_hamming.c`: Métrica de distância de Hamming para sequências textuais e alinhamento de fitas de DNA.

### Soluções dos Exercícios Propostos

- `15_exercicio_inversao_ponteiros.c`: Inversão *in-place* com dois ponteiros convergentes.
- `16_exercicio_meu_strcmp.c`: Implementação de `meu_strcmp` com conversão estrita para `unsigned char` conforme a norma ISO C.
- `17_exercicio_copia_concatenacao.c`: Rotinas defensivas `copiar_seguro` e `concatenar_seguro` com limite estrito de capacidade.
- `18_exercicio_palindromo.c`: Validação de palíndromos insensível a caixa e pontuação em tempo $O(N)$.
- `19_exercicio_compactar_espacos.c`: Compactação *in-place* de múltiplos espaços com varredura linear.
- `20_exercicio_utilitario_wc.c`: Utilitário de contagem de linhas, palavras e bytes via máquina de estados.
- `21_exercicio_cifra_cesar.c`: Cifrador de César na linha de comando (`-k <deslocamento>`) com normalização cíclica em $[0, 25]$.
- `22_exercicio_parser_url.c`: Parser de parâmetros de consulta Web (*query string*) com `strtok` e `strchr`.
- `23_exercicio_validar_acesso.c`: Autenticação segura de senha prevenindo estouro de buffer.
