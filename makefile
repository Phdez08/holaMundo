bin/programa: src/main.cpp include/*.hpp
	g++ src/main.cpp -Iinclude -o bin/programa

bin/animacion: src/animacion.cpp include/*.hpp
	g++ src/animacion.cpp -Include -o bin/animacion -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

bin/prueba: src/prueba.cpp include/*.hpp
	g++ src/prueba.cpp -Include -o bin/prueba -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

ejecutar: bin/programa
	./bin/programa

ejecutar2: bin/animacion
	./bin/animacion

ejecutar3: bin/prueba
	./bin/prueba

Clean: bin/programa
	rm bin/programa