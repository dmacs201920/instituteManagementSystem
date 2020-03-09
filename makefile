fout :func.o fmain.o
	gcc -g -o fout func.o fmain.o
func.o:func.c fheader.h
	gcc -c -g func.c
fmain.o:fmain.c fheader.h
	gcc -c -g fmain.c


