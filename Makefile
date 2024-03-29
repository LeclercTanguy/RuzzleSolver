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

$(BINDIR)/ruzzleSolver : $(SRCDIR)/ruzzleSolver.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libRuzzle.a $(LIBDIR)/libCollections.a $(LIBDIR)/libTools.a
	$(CC) -o $(BINDIR)/ruzzleSolver $^ $(LDFLAGS) -lDictionnaire -lRuzzle -lCollections -lTools

$(BINDIR)/transcoder : $(SRCDIR)/transcoder.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libTools.a $(LIBDIR)/libCollections.a
	$(CC) -o $(BINDIR)/transcoder $^ $(LDFLAGS) -lDictionnaire -lCollections -lTools

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

$(RAPPORT)/CRProjet.pdf: $(shell find $(RAPPORT)/ -name '*.tex') $(shell find $(RAPPORT)/ -name '*.sty') $(shell find $(RAPPORT)/ -name '*.svg')
	cd $(RAPPORT); make

tests: $(TESTDIR)/testListeChainee $(TESTDIR)/testArbreBinaire $(TESTDIR)/testCase $(TESTDIR)/testEnsemble $(TESTDIR)/testDictionnaire $(TESTDIR)/testCasesContigues $(TESTDIR)/testMot $(TESTDIR)/testGrille $(TESTDIR)/testRuzzle $(TESTDIR)/testABR

$(TESTDIR)/testListeChainee: $(SRCTESTS)/testListeChainee.o $(LIBDIR)/libCollections.a
		$(CC) -o $(TESTDIR)/testListeChainee $^ $(LDFLAGS) -lCollections -lcunit

$(TESTDIR)/testArbreBinaire: $(SRCTESTS)/testArbreBinaire.o $(LIBDIR)/libCollections.a
		$(CC) -o $(TESTDIR)/testArbreBinaire $^ $(LDFLAGS) -lCollections -lcunit

$(TESTDIR)/testCase: $(SRCTESTS)/testCase.o $(LIBDIR)/libRuzzle.a
		$(CC) -o $(TESTDIR)/testCase $^ $(LDFLAGS) -lRuzzle -lcunit

$(TESTDIR)/testEnsemble: $(SRCTESTS)/testEnsemble.o $(LIBDIR)/libCollections.a
		$(CC) -o $(TESTDIR)/testEnsemble $^ $(LDFLAGS) -lCollections -lcunit

$(TESTDIR)/testDictionnaire: $(SRCTESTS)/testDictionnaire.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libCollections.a $(LIBDIR)/libTools.a
		$(CC) -o $(TESTDIR)/testDictionnaire $^ $(LDFLAGS) -lDictionnaire -lCollections -lTools -lcunit

$(TESTDIR)/testCasesContigues: $(SRCTESTS)/testCasesContigues.o $(LIBDIR)/libRuzzle.a $(LIBDIR)/libCollections.a
		$(CC) -o $(TESTDIR)/testCasesContigues $^ $(LDFLAGS) -lRuzzle -lCollections -lcunit

$(TESTDIR)/testMot: $(SRCTESTS)/testMot.o $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libCollections.a
		$(CC) -o $(TESTDIR)/testMot $^ $(LDFLAGS) -lDictionnaire -lCollections -lcunit

$(TESTDIR)/testGrille: $(SRCTESTS)/testGrille.o $(LIBDIR)/libRuzzle.a
		$(CC) -o $(TESTDIR)/testGrille $^ $(LDFLAGS) -lRuzzle -lcunit

$(TESTDIR)/testRuzzle: $(SRCTESTS)/testRuzzle.o $(LIBDIR)/libRuzzle.a $(LIBDIR)/libDictionnaire.a $(LIBDIR)/libCollections.a $(LIBDIR)/libTools.a
		$(CC) -o $(TESTDIR)/testRuzzle $^ $(LDFLAGS) -lRuzzle -lDictionnaire -lCollections -lcunit -lTools

$(TESTDIR)/testABR: $(SRCTESTS)/testABR.o $(LIBDIR)/libCollections.a $(LIBDIR)/libTools.a
		$(CC) -o $(TESTDIR)/testABR $^ $(LDFLAGS) -lCollections -lTools -lcunit

# bibliothèques
$(LIBDIR)/libTools.a : $(SRCDIR)/tools.o
	$(AR) -r $@ $^

$(LIBDIR)/libCollections.a : $(SRCDIR)/ListeChainee.o $(SRCDIR)/ArbreBinaire.o $(SRCDIR)/Ensemble.o $(SRCDIR)/ABR.o
	$(AR) -r $@ $^

$(LIBDIR)/libDictionnaire.a : $(SRCDIR)/Dictionnaire.o $(SRCDIR)/Mot.o
	$(AR) -r $@ $^

$(LIBDIR)/libRuzzle.a : $(SRCDIR)/Ruzzle.o $(SRCDIR)/Grille.o $(SRCDIR)/Case.o $(SRCDIR)/CasesContigues.o
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
	rm -rf $(RAPPORT)/_minted-CRProjet
	find . -name '*.o' -delete
	find . -name '*.pdf' -delete
	find . -name '*.html' -delete
	find . -name '*.log' -delete
	find . -name '*.aux' -delete
	find . -name '*.dat' -delete
	find . -name '*.gch' -delete
