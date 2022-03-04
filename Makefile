all: parta partb

parta: gensine gendial

partb: dtmf

gensine: main.o gensnd.o
	gcc -o gensine main.o -lm

gendial: main2.o gensnd.o
	gcc -o gendial main2.o -lm

dtmf: main1b.o gensnd.o
	gcc -o dtmf main1b.o gensnd.o -lm

main.o: main.c
	gcc -c main.c

main2.o: main2.c
	gcc -c main2.c

gensnd.o: gensnd.c
	gcc -c gensnd.c

main1b.o: main1b.c
	gcc -c main1b.c

clean:
	rm main.o main2.o main1b.o gensnd.o gensine gendial dtmf
