// INSTRUCCIONES DEL PRE-PROCESADOR, las instrucciones con simbolo #
#include <iostream>
#include <Foco.hpp>
#include <list>
/*
Se usa el namespace para saber que estamos utlizando esa carpeta.
De donde vamos a usar la libreria standar.
*/
using namespace std;

class SerieNavidad
{
private:
    // Lista de datos de tipo Foco con nombre focos
    std::list<Foco> focos;

public:
    SerieNavidad(int noFocos)
    {
        /*
        Este for crea una lista de # de focos menor al valor que se guarda
        en noFocos.
        */
        for (size_t i = 0; i < noFocos; i++)
        {
            Foco foco;
            this->focos.emplace_back(foco);
        }
    }
    ~SerieNavidad()
    {
    }
    void Encender()
    {

        /*
        Este for funciona para ir recorriendo los elementos de la lista
        y va encendiendo cada uno de los elementos
        */
        for (auto &&f : focos)
        {
            f.Encender();
        }
    }

    void Imprimir()
    {
        for (auto &&focoActual : focos)
        {
            /*
            Recorre la lista dando señal de imprimir el valor que tiene cada elemento (true/false)
            y lo muestra a traves del cout.
            */
            std::cout
                << focoActual.Imprimir()
                << "-";
        }
        std::cout
            << std::endl;
    }
};