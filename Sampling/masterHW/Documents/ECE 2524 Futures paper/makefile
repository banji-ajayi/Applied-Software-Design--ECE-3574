#Thomas Elliott
#Future's Paper makefile

all: html pdf

html: future.txt
	pandoc -s $< -o future.html 

pdf: future.txt
	pandoc $< -o future.pdf

preview:
	$$EDITOR future.txt

clean:
	rm -f future.html
	rm -f future.pdf
