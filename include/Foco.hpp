#include <stdexcept>

class Foco

{
private:
    bool encendido;
    int numero;

public:
    // Constructor de elemento foco sin parametros iniciales
    Foco()
    {
        this->numero = 0;
        this->encendido = false;
    }

    // Constructor de elemento foco con parametros iniciales
    Foco(int numero)
    {

        this->encendido = false;
        if (numero > 100 || numero < 0)
        {
            throw new std::runtime_error("Numero fuera de rango.");
        }
        else
        {
            this->numero = numero;
        }
    }

    ~Foco() {}

    void Incrementar(int numero)
    {
        this->numero += numero;
    }

    void Disminuir(int numero)
    {
        this->numero -= numero;
    }

    // Este metodo da el valor de verdadero al objeto de la lista (Encendido)
    void Encender()
    {
        this->encendido = true;
    }

    // Este metodo da el valor de falso al objeto de la lista (Apagado)
    void Apagar()
    {
        this->encendido = false;
    }

    // Este metodo imprime el valor de la variable encendido (sea apagado o encendido)
    char Imprimir()
    {
        if (this->encendido)
        {
            return '*';
        }
        else
        {
            return 'o';
        }
    }
};