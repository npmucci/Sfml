#include <SFML/Graphics.hpp>
#include "Personaje.h"

int main()
{
    //Inicialización de la Ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "juego1"); /*800 pixeles de ancho x 600 de alto*/
    // Crear y configurar la textura y el sprite
    window.setFramerateLimit(60);
    
    Personaje zombie; // creamos el objeto de tipo personaje

    
    // Game Loop
        while (window.isOpen()) // Mientras la ventana está abierta, se ejecuta el código que está adentro
        {
            // ReadInput Actualiza los estados de los periféricos de entrada (mouse, teclado, etc.)
            sf::Event event;
            while (window.pollEvent(event)) /* pollEvent son las colas de los mensaje que se le Mandan a la ventana para indicarle que evento está pasando ( hacer click, mover mpuse, etc.)*/
            {
                // se leen las colas de mensajes
                if (event.type == sf::Event::Closed)
                    window.close(); // Cierra la ventana para terminar el juego
            }

            // Se leen los comandos CMD  - Se arma el joystick

         

           // Update – Actualiza los Estados del Juego
            zombie.update();


            window.clear(); // Limpia la ventana

            // Draw – Dibujar
            window.draw(zombie); // le decimos a la ventana que dibuje nuestro personaje que ahora es drawable o dibujable

            // Display - Flip
            window.display(); // Muestra el contenido en pantalla

        }
    return 0;
}
