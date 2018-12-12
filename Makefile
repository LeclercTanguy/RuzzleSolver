SRCDIR=src
SRCTESTS=src/tests
LIBDIR=lib
INCLUDEDIR=include
BINDIR=bin
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=gnu99  -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR)
EXEC=ruzzleSolver

tests:
	$(SRCTESTS)/testListeChainee.o $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testListeChainee $^ $(LDFLAGS) -lListeChainee -lcunit
	$(SRCTESTS)/testArbreB.o $(LIBDIR)/libArbreB.a
		$(CC) -o $(TESTDIR)/testArbreB $^ $(LDFLAGS) -lCase -lcunit
$(SRCTESTS)/testCase.o $(LIBDIR)/libCase.a
			$(CC) -o $(TESTDIR)/testCase $^ $(LDFLAGS) -lCase -lcunit

$(LIBDIR)/libListeChainee.a : $(SRCDIR)/ListeChainee.o
	$(AR) -r $@ $^

$(LIBDIR)/libArbreB.a : $(SRCDIR)/ArbreB.o
	$(AR) -r $@ $^

$(LIBDIR)/libCase.a : $(SRCDIR)/Case.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(SRCTESTS)/%.o : $(SRCTESTS)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
