#include <iostream>
#include <Porcentaje.hpp>

int main(){
    Porcentaje foco;
    Porcentaje foco2;
    Porcentaje foco3;
    Porcentaje foco1;


    foco1.Incrementar (10);
    foco1.Incrementar (10);
    foco1.Disminuir (4);

    std::cout
    <<"Foco 1: "
    <<foco1.Imprimir()
    <<std::endl;
  
}