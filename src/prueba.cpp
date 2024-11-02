#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>
#include <cmath> // para funciones matemáticas

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
  std::string reset_position;
  int frame = 0;
  int x = 15; // Posición inicial en x
  int y = 0;  // Posición inicial en y (arriba de la pantalla)

  const int centerX = 250; // Centro del lienzo en x
  const int centerY = 250; // Centro del lienzo en y

  // Colores
    //Color backgroundColor = Color::DarkSeaGreen1; // Color de fondo
    Color circleColor = Color::Yellow; // Color del círculo
    Color ojoColor = Color::Yellow; // Color de los ojos
    Color smileColor = Color::Red; // Color de la sonrisa

  while (true)
  {
    Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

    auto can = Canvas(500, 500);

    // Movimiento de descenso inicial

    // Ajusta el valor para controlar la duración del descenso
    if (frame < 50)
    {
      // Incrementa y para hacer que el círculo baje
      y = frame;
    }
    else if (frame < 100) // Ajusta el valor para controlar la duración de la curva
    {

      // Restar el tiempo de descenso
      int local_frame = frame - 50;
      // Avanza hacia la derecha
      x = 15 + local_frame;
      // Cálculo de la parábola para la curva
      y = 50 - pow(local_frame - 25, 2) / 25;
    }
    else if (frame < 150)
    {

      int local_frame = frame - 100;          // Restar el tiempo de la primera curva
      x = 65 + local_frame;                   // Regresar hacia la izquierda
      y = 25 + pow(local_frame - 25, 2) / 25; // Cálculo de la parábola para la segunda curva
    }
    else if (frame < 200)
    {
      // Movimiento hacia el centro

      // Desplaza x hacia el centro
      x += (centerX - x) / 10;
      // Desplaza y hacia el centro
      y += (centerY - y) / 10;
    }
    else
    {
      // Reinicia el ciclo después de llegar al centro
      frame = 0;
      // Reinicia la posición x
      x = 15;
      // Reinicia la posición y
      y = 0;
    }

    // Dibujar el círculo en la posición actual
    can.DrawPointCircle(x, y, 15, circleColor); //Cabeza
    // Ojo derecho
    can.DrawPointLine(x-5, y-5, x-7, y-7, circleColor);
    can.DrawPointLine(x-5, y-5, x-7, y-3, circleColor);
    // Ojo izquierdo
    can.DrawPointLine(x+5, y-5, x+7, y-7, circleColor);
    can.DrawPointLine(x+5, y-5, x+7, y-3, circleColor);

    //can.DrawPointLine(x, y+5,5,5);
    can.DrawPointLine(x-5, y+5, x+5, y+5, ojoColor);
    can.DrawPoint(x-5, y+6,true, ojoColor);
    can.DrawPoint(x-4, y+7,true, ojoColor);
    can.DrawPoint(x-3, y+8,true, ojoColor);
    can.DrawPoint(x-2, y+9,true, ojoColor);
    can.DrawPoint(x-1, y+9,true, ojoColor);
    can.DrawPoint(x, y+9,true, ojoColor);
    can.DrawPoint(x+1, y+9,true, ojoColor);
    can.DrawPoint(x+2, y+9,true, ojoColor);
    can.DrawPoint(x+3, y+8,true, ojoColor);
    can.DrawPoint(x+4, y+7,true, ojoColor);
    can.DrawPoint(x+5, y+6,true, ojoColor);

    // can.DrawPointCircle(frame, 15, 15);
    /*can.DrawBlockCircle(15, 15, 15);
    can.DrawBlockCircleFilled(10, 8, 1);
    can.DrawBlockCircleFilled(20, 8, 1);
    can.DrawBlockEllipseFilled(15, 20, 2, 2);*/

    // Configuración de pantalla y renderización
    Element lienzo = bgcolor(Color::Aquamarine1, canvas(&can));
    Render(pantalla, lienzo);

    std::cout << reset_position;
    pantalla.Print();
    reset_position = pantalla.ResetPosition(true);

    this_thread::sleep_for(0.03s);
    frame++;
  }

  /*while (true)
  {

    Element personaje = spinner(2, frame);
    Element lienzo = bgcolor(Color::CadetBlueBis, border(vbox(ColorSupport, personaje, canvas(&can))));
    Render(pantalla, lienzo);
    std::cout << reset_position;
    pantalla.Print();
    reset_position = pantalla.ResetPosition(true);
    this_thread::sleep_for(0.1s);
    frame++;
  }*/

  return 0;
}