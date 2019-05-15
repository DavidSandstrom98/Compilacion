CFLAGS=-Wall
FUENTES=parser.cpp main.cpp tokens.cpp Codigo.cpp

all: parser prueba

clean:
	rm parser.cpp parser.hpp parser tokens.cpp *~

parser.cpp parser.hpp: parser.y Codigo.hpp Aux.hpp
	bison -d -o $@ $<

tokens.cpp: tokens.l parser.hpp Aux.hpp
	lex -o $@ $<

parser: $(FUENTES) Codigo.hpp Aux.hpp
	g++ $(CFLAGS) -o $@ $(FUENTES) 

prueba:  parser ../Pruebas/prueba1.in ../Pruebas/prueba2.in ../Pruebas/pruebamala1.in ../Pruebas/pruebamala2.in ../Pruebas/pruebaBooleanos.in ../Pruebas/pruebaFor.in
	./parser <../Pruebas/prueba1.in
	./parser <../Pruebas/prueba2.in
	./parser <../Pruebas/pruebamala1.in
	./parser <../Pruebas/pruebamala2.in
	./parser <../Pruebas/pruebaBooleanos.in
	./parser <../Pruebas/pruebaFor.in