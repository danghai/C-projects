CC = gcc
FLAG = -o
CFLAG = -c

all: new_intr no_echo	canonical_input getpass noncanonical_input

new_intr: new_intr.c
		$(CC) $(FLAG) new_intr new_intr.c

no_echo: no_echo.c
		$(CC) $(FLAG) no_echo no_echo.c

canonical_input: canonical_input.c
		$(CC) $(FLAG) canonical_input canonical_input.c

nontcanonical_input: noncanonical_input.c
		$(CC) $(FLAG) noncanonical_input noncanonical_input.c

getpass: getpass.c
		$(CC) $(FLAG) getpass getpass.c

clean:
		rm new_intr no_echo	canonical_input getpass noncanonical_input
