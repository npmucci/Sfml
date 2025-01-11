#include <SFML/Graphics.hpp>

int main()
{
    //Inicialización de la Ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "juego1"); /*800 pixeles de ancho x 600 de alto*/
    // Crear y configurar la textura y el sprite
    sf::Texture personaje_texture; // se crea un Objeto de tipo Texture
    if (!personaje_texture.loadFromFile("zombie.png"))
        return -1; // Error al cargar la imagen

    sf::Sprite personaje; // se crea un objeto de tipo Sprite
    personaje.setTexture(personaje_texture); // se carga la textura al sprite

    
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

            //mover personaje
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                personaje.move(0, -.5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                personaje.move(-.5, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                personaje.move(0, .5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                personaje.move(.5, 0);
            }

            // Limitar movimiento para que no se salga de la ventana
            if (personaje.getPosition().x < 0) { // Límite izquierdo
                personaje.setPosition(0, personaje.getPosition().y); // Coloca al personaje en el borde izquierdo (x = 0)
            }

            if (personaje.getPosition().x > 800) { // Límite derecho
                personaje.setPosition(800, personaje.getPosition().y); // Coloca al personaje en el borde derecho (x = 800)
            }

            if (personaje.getPosition().y < 0) { // Límite superior
                personaje.setPosition(personaje.getPosition().x, 0); // Coloca al personaje en el borde superior (y = 0)
            }

            if (personaje.getPosition().y > 600) { // Límite inferior
                personaje.setPosition(personaje.getPosition().x, 600); // Coloca al personaje en el borde inferior (y = 600)
            }



           // Update – Actualiza los Estados del Juego
            window.clear(); // Limpia la ventana

            // Draw – Dibujar
            window.draw(personaje); // le decimos a la ventana que dibuje nuestro personaje

            // Display - Flip
            window.display(); // Muestra el contenido en pantalla

        }
    return 0;
}
