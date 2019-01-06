all : analyseDescendante.pdf CRProjet.pdf

CRProjet.pdf :
	pdflatex -shell-escape CRProjet.tex
	pdflatex -shell-escape CRProjet.tex  #seconde compilation pour les références

analyseDescendante.pdf :
	inkscape -f ./analyseDescendante/analyseDescendante.svg -A ./analyseDescendante/analyseDescendante.pdf

clean :
	rm *.aux *.log *.pdf
