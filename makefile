bin/programa: src/main.cpp include/*.hpp
	g++ src/main.cpp -Iinclude -o bin/programa

bin/animacion: src/animacion.cpp include/*.hpp
	g++ src/animacion.cpp -Include -o bin/animcaion

ejecutar: bin/programa
	./bin/programa

ejecutar2: bin/animacion
	./bin/animacion

Clean: bin/programa
	rm bin/programa