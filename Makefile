# Variáveis
CC = gcc
CFLAGS = -Wall -pthread
OBJDIR = obj
SRCDIR = src
BINDIR = bin
TARGET = $(BINDIR)/main

# Lista de arquivos fonte
SRCS = $(wildcard $(SRCDIR)/**/*.c)
# Lista de objetos
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Regras
all: $(TARGET)

# Regra para criar o executável final
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo "Compilação completa: $(TARGET)"

# Regra para compilar os arquivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)  # Cria a pasta para os arquivos objeto, se necessário
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar objetos e binários
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Limpeza completa"

# Remover apenas os binários
cleanbin:
	rm -rf $(BINDIR)
	@echo "Limpeza de binários completa"

# Remover apenas objetos
cleanobj:
	rm -rf $(OBJDIR)
	@echo "Limpeza de objetos completa"
