# List all .tex files
TEX_FILES := $(wildcard *.tex)

# Generate corresponding .dvi files
DVI_FILES := $(TEX_FILES:.tex=.dvi)

# Generate corresponding .pdf files
PDF_FILES := $(TEX_FILES:.tex=.pdf)

# Generate corresponding .png files
PNG_FILES := $(PDF_FILES:.pdf=.png)

# Generate corresponding .svg files
SVG_FILES := $(DVI_FILES:.dvi=.svg)

# Generate corresponding .png files
WEBP_FILES := $(SVG_FILES:.svg=.webp)

# Default target
all: $(SVG_FILES) $(PNG_FILES)

# Rule to convert .tex to .pdf
%.pdf: %.tex
	pdflatex $<

# Rule to convert .pdf to .png
%.png: %.pdf
	convert -density 300 $< -quality 90 -trim $@

# Rule to convert .tex to .dvi
%.dvi: %.tex
	latex $<

# Rule to convert .dvi to .svg
%.svg: %.dvi
	dvisvgm $<

# Clean up auxiliary files
clean:
	rm -f *.aux *.log *.out *.pdf *.webp *.svg *.dvi

.PHONY: all clean