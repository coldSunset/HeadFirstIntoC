hfcal.o: 
	gcc -I./includes -c hfcal.c -o hfcal.o

elliptical.o:
	gcc -I./includes -c elliptical.c -o elliptical.o

libhfcal.a: 
	ar -rcs ./libs/libhfcal.a hfcal.o
	
elliptical:
	gcc elliptical.o -L./libs -lhfcal -o elliptical 