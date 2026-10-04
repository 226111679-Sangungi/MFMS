CC = gcc
CFLAGS = -Wall -Wextra -std=c99

CORE = main.c validation.c
MODULES = employees.c budget.c suppliers.c assets.c reports.c

mfms: $(CORE) $(MODULES)
	$(CC) $(CFLAGS) $(CORE) $(MODULES) -o mfms

stubs: $(CORE) stubs.c
	$(CC) $(CFLAGS) $(CORE) stubs.c -o mfms

clean:
	rm -f mfms
