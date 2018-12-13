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

tests: testLC testAB testC

testLC: $(SRCTESTS)/testListeChainee.o $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testListeChainee $^ $(LDFLAGS) -lListeChainee -lcunit
testAB: $(SRCTESTS)/testArbreB.o $(LIBDIR)/libArbreB.a
		$(CC) -o $(TESTDIR)/testArbreB $^ $(LDFLAGS) -lArbreB -lcunit
testC: $(SRCTESTS)/testCase.o $(LIBDIR)/libCase.a
		$(CC) -o $(TESTDIR)/testCase $^ $(LDFLAGS) -lCase -lcunit
testE: $(SRCTESTS)/testEnsemble.o $(LIBDIR)/libEnsemble.a $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testEnsemble $^ $(LDFLAGS) -lEnsemble -lListeChainee -lcunit
testD: $(SRCTESTS)/testDictionnaire.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libEnsemble.a $(LIBDIR)/libArbreB.a $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testDictionnaire $^ $(LDFLAGS) -lDictionnaire -lArbreB -lEnsemble -lListeChainee -lcunit

$(LIBDIR)/libListeChainee.a : $(SRCDIR)/ListeChainee.o
	$(AR) -r $@ $^

$(LIBDIR)/libArbreB.a : $(SRCDIR)/ArbreB.o
	$(AR) -r $@ $^

$(LIBDIR)/libCase.a : $(SRCDIR)/Case.o
	$(AR) -r $@ $^

$(LIBDIR)/libDictionnaire.a : $(SRCDIR)/Dictionnaire.o
	$(AR) -r $@ $^

$(LIBDIR)/libEnsemble.a : $(SRCDIR)/Ensemble.o
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
