CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
ASAN_FLAGS = -fsanitize=address,undefined -g
DEBUG_FLAGS = -g
LDLIBS = -lm
SRC_DIR = src
BUILD_DIR = build

# Programas padrao que compilam sem erros nem warnings
SRCS = $(SRC_DIR)/01_char_vs_inteiros.c \
       $(SRC_DIR)/02_declaracao_strings.c \
       $(SRC_DIR)/03_string_fundamentos.c \
       $(SRC_DIR)/03b_string_interning.c \
       $(SRC_DIR)/05_strings_saida.c \
       $(SRC_DIR)/06_ler_linha_robusta.c \
       $(SRC_DIR)/07_strlen_implementacao.c \
       $(SRC_DIR)/08_strcmp_exemplos.c \
       $(SRC_DIR)/09_snprintf_seguro.c \
       $(SRC_DIR)/10_strings_busca.c \
       $(SRC_DIR)/11_strtok_exemplo.c \
       $(SRC_DIR)/12_arranjos_de_strings.c \
       $(SRC_DIR)/13_cli_utilitario.c \
       $(SRC_DIR)/15_exercicio_inversao_ponteiros.c \
       $(SRC_DIR)/16_exercicio_meu_strcmp.c \
       $(SRC_DIR)/17_exercicio_copia_concatenacao.c \
       $(SRC_DIR)/18_exercicio_palindromo.c \
       $(SRC_DIR)/19_exercicio_compactar_espacos.c \
       $(SRC_DIR)/20_exercicio_utilitario_wc.c \
       $(SRC_DIR)/21_exercicio_cifra_cesar.c \
       $(SRC_DIR)/22_exercicio_parser_url.c \
       $(SRC_DIR)/23_exercicio_validar_acesso.c \
       $(SRC_DIR)/24_algoritmo_prefixo_sufixo.c \
       $(SRC_DIR)/25_algoritmo_texto_para_inteiro.c \
       $(SRC_DIR)/26_algoritmo_inteiro_para_texto.c \
       $(SRC_DIR)/27_algoritmo_meu_strstr.c \
       $(SRC_DIR)/28_algoritmo_distancia_hamming.c

BINS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SRCS))
ASAN_BIN_14 = $(BUILD_DIR)/14_estouro_buffer_asan

all: $(BINS) $(BUILD_DIR)/04_modificacao_literal

# Alvo com AddressSanitizer para demonstrar estouro de buffer (exemplo 14)
asan-14: $(ASAN_BIN_14)
	@echo "--- Executando 14_estouro_buffer_asan com AddressSanitizer (espera-se diagnostico do ASan) ---"
	-./$(ASAN_BIN_14)

$(ASAN_BIN_14): $(SRC_DIR)/14_estouro_buffer_asan.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $< -o $@ $(LDLIBS)

# Alvo para demonstrar violacao de acesso em tempo de execucao (SIGSEGV)
$(BUILD_DIR)/04_modificacao_literal: $(SRC_DIR)/04_modificacao_literal.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Wno-discarded-qualifiers $< -o $@ $(LDLIBS)

segfault-04: $(BUILD_DIR)/04_modificacao_literal
	@echo "--- Executando 04_modificacao_literal (espera-se falha de segmentacao) ---"
	-./$(BUILD_DIR)/04_modificacao_literal

$(BUILD_DIR)/%: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

$(BUILD_DIR):
	mkdir -m 755 -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

test: all
	@echo "=== Executando suite de testes rapidos ==="
	@for bin in 01_char_vs_inteiros 02_declaracao_strings 03_string_fundamentos \
	           03b_string_interning 05_strings_saida 07_strlen_implementacao 08_strcmp_exemplos \
	           09_snprintf_seguro 10_strings_busca 11_strtok_exemplo \
	           12_arranjos_de_strings 15_exercicio_inversao_ponteiros \
	           16_exercicio_meu_strcmp 17_exercicio_copia_concatenacao \
	           18_exercicio_palindromo 19_exercicio_compactar_espacos \
	           24_algoritmo_prefixo_sufixo 25_algoritmo_texto_para_inteiro \
	           26_algoritmo_inteiro_para_texto 27_algoritmo_meu_strstr \
	           28_algoritmo_distancia_hamming; do \
		echo "--- Executando $$bin ---"; \
		./$(BUILD_DIR)/$$bin; \
	done
	@echo "=== Testes concluidos com sucesso! ==="

.PHONY: all clean asan-14 segfault-04 test
