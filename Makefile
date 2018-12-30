SRCDIR=src
SRCTESTS=src/tests
LIBDIR=lib
INCLUDEDIR=include
BINDIR=bin
TESTDIR=tests
DOCDIR=doc
DOCHTML=doc/html
DOCPDF=doc/pdf
RAPPORT=doc/rapport
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=gnu99  -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR)

all : $(BINDIR)/ruzzleSolver $(BINDIR)/transcoder tests

$(BINDIR)/ruzzleSolver :

$(BINDIR)/transcoder : $(SRCDIR)/transcoder.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libTools.a $(LIBDIR)/libArbreBinaire.a $(LIBDIR)/libEnsemble.a $(LIBDIR)/libListeChainee.a
	$(CC) -o $(BINDIR)/transcoder $^ $(LDFLAGS) -lDictionnaire -lArbreBinaire -lEnsemble -lListeChainee -lTools

doc : $(DOCDIR)/doc.html $(DOCDIR)/doc.pdf $(DOCDIR)/rapport.pdf

$(DOCDIR)/doc.html: $(DOCHTML)/index.html
	-@ln -s ./html/index.html $(DOCDIR)/doc.html

$(DOCDIR)/doc.pdf: $(DOCPDF)/refman.pdf
	-@ln -s ./pdf/refman.pdf $(DOCDIR)/doc.pdf

$(DOCDIR)/rapport.pdf: $(RAPPORT)/CRProjet.pdf
	-@ln -s ./rapport/CRProjet.pdf $(DOCDIR)/rapport.pdf

$(DOCHTML)/index.html: $(shell ls $(SRCDIR)/*.c) $(shell ls $(INCLUDEDIR)/*.h)
	doxygen

$(DOCPDF)/refman.pdf: $(shell ls $(SRCDIR)/*.c) $(shell ls $(INCLUDEDIR)/*.h)
	doxygen
	cd $(DOCPDF); make

$(RAPPORT)/CRProjet.pdf: $(shell find $(RAPPORT) -name '*.tex') $(shell find $(RAPPORT) -name '*.sty') $(shell find $(RAPPORT) -name '*.svg')
	cd $(RAPPORT); make

tests: $(TESTDIR)/testListeChainee $(TESTDIR)/testArbreBinaire $(TESTDIR)/testCase $(TESTDIR)/testEnsemble $(TESTDIR)/testDictionnaire $(TESTDIR)/testCasesContigues $(TESTDIR)/testMot

$(TESTDIR)/testListeChainee: $(SRCTESTS)/testListeChainee.o $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testListeChainee $^ $(LDFLAGS) -lListeChainee -lcunit
$(TESTDIR)/testArbreBinaire: $(SRCTESTS)/testArbreBinaire.o $(LIBDIR)/libArbreBinaire.a
		$(CC) -o $(TESTDIR)/testArbreBinaire $^ $(LDFLAGS) -lArbreBinaire -lcunit
$(TESTDIR)/testCase: $(SRCTESTS)/testCase.o $(LIBDIR)/libCase.a
		$(CC) -o $(TESTDIR)/testCase $^ $(LDFLAGS) -lCase -lcunit
$(TESTDIR)/testEnsemble: $(SRCTESTS)/testEnsemble.o $(LIBDIR)/libEnsemble.a $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testEnsemble $^ $(LDFLAGS) -lEnsemble -lListeChainee -lcunit
$(TESTDIR)/testDictionnaire: $(SRCTESTS)/testDictionnaire.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libEnsemble.a $(LIBDIR)/libArbreBinaire.a $(LIBDIR)/libListeChainee.a $(LIBDIR)/libTools.a
		$(CC) -o $(TESTDIR)/testDictionnaire $^ $(LDFLAGS) -lDictionnaire -lArbreBinaire -lEnsemble -lTools -lListeChainee -lcunit
$(TESTDIR)/testCasesContigues: $(SRCTESTS)/testCasesContigues.o $(LIBDIR)/libCase.a
		$(CC) -o $(TESTDIR)/testCasesContigues $^ $(LDFLAGS) -lCase -lListeChainee -lcunit
$(TESTDIR)/testMot: $(SRCTESTS)/testMot.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libListeChainee.a $(LIBDIR)/libArbreBinaire.a $(LIBDIR)/libEnsemble.a
		$(CC) -o $(TESTDIR)/testMot $^ $(LDFLAGS) -lDictionnaire -lListeChainee -lArbreBinaire -lEnsemble -lcunit
testPerf: $(SRCTESTS)/testPerformance.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libEnsemble.a $(LIBDIR)/libArbreBinaire.a $(LIBDIR)/libListeChainee.a
		$(CC) -o $(TESTDIR)/testPerformance $^ $(LDFLAGS) -lDictionnaire -lArbreBinaire -lEnsemble -lListeChainee

$(LIBDIR)/libTools.a : $(SRCDIR)/tools.o
	$(AR) -r $@ $^

$(LIBDIR)/libListeChainee.a : $(SRCDIR)/ListeChainee.o
	$(AR) -r $@ $^

$(LIBDIR)/libArbreBinaire.a : $(SRCDIR)/ArbreBinaire.o
	$(AR) -r $@ $^

$(LIBDIR)/libEnsemble.a : $(SRCDIR)/Ensemble.o
		$(AR) -r $@ $^

$(LIBDIR)/libCase.a : $(SRCDIR)/Case.o $(SRCDIR)/CasesContigues.o
	$(AR) -r $@ $^

$(LIBDIR)/libDictionnaire.a : $(SRCDIR)/Dictionnaire.o $(SRCDIR)/Mot.o
	$(AR) -r $@ $^

$(LIBDIR)/libMot.a : $(SRCDIR)/Mot.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(SRCTESTS)/%.o : $(SRCTESTS)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(TESTDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(DOCHTML)/*
	rm -rf $(DOCPDF)/*
	find . -name '*.o' -delete
	find . -name '*.pdf' -delete
	find . -name '*.html' -delete
	find . -name '*.log' -delete
	find . -name '*.aux' -delete
	find . -name '*.dat' -delete
	find . -name '*.gch' -delete
