Compilar: src/main.cpp
	g++ src/main.cpp -Iinclude -o bin/programa

Ejecutar: bin/programa
	./bin/programa

Clean: bin/programa
	rm bin/programa