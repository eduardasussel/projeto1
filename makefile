PROG = programa
CC = gcc
CFLAGS = -Wall -g

SRC = main.c \
      arena.c \
	  arquivo.c \
      carregador.c \
	  circulo.c \
      disparador.c \
      esmagado.c \
	  forma.c \
      gerarSvgxt.c \
      gerarTxt.c \
      linha.c \
	  pilha.c \
      retangulo.c \
      texto.c \
      tipos.c \

OBJ = $(SRC:.c=.o)

$(PROG): $(OBJ)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(PROG)

run: $(PROG)
	./$(PROG)

rebuild: clean $(PROG)
