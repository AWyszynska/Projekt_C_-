#include "mousehoverdisplay.h"
#include <iostream>

MouseHoverDisplay::MouseHoverDisplay(sf::RenderWindow& window, const std::vector<char>& signs, bool limitedDisplay)
    : window(window), signs(signs), limitedDisplay(limitedDisplay)  {
    loadImages();
}

void MouseHoverDisplay::loadImages() {
    sf::Texture texture;
        if (!texture.loadFromFile("tablicazdj/przenicatablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['P'] = texture;
    }
        if (!texture.loadFromFile("tablicazdj/marchewkanasionotablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['M'] = texture;
    }
    if (!texture.loadFromFile("tablicazdj/truskawkanasiono_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['T'] = texture;
    }
        if (!texture.loadFromFile("tablicazdj/marchewka_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['C'] = texture;
    }
        if (!texture.loadFromFile("tablicazdj/truskawka_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['S'] = texture;
    }
            if (!texture.loadFromFile("tablicazdj/jablkonasiono_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['J'] = texture;
    }
            if (!texture.loadFromFile("tablicazdj/gruszkanasiono_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['G'] = texture;
    }
            if (!texture.loadFromFile("tablicazdj/sliwkanasiono_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['Z'] = texture;
    }
                if (!texture.loadFromFile("tablicazdj/jablko_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['A'] = texture;
    }
                if (!texture.loadFromFile("tablicazdj/gruszka_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['E'] = texture;
    }
    if (!texture.loadFromFile("tablicazdj/sliwka_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['F'] = texture;
    }
    if (!texture.loadFromFile("tablicazdj/sztabka_miedzi_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['I'] = texture;
    }
    if (!texture.loadFromFile("tablicazdj/sztabka_srebra_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['R'] = texture;
    }
     if (!texture.loadFromFile("tablicazdj/sztabka_zlota_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['L'] = texture;
    }
    if (!texture.loadFromFile("tablicazdj/diament_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['D'] = texture;
    }
        if (!texture.loadFromFile("tablicazdj/jajko_swini_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['W'] = texture;
    }
        if (!texture.loadFromFile("tablicazdj/jajko_krowy_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['K'] = texture;
    }
        if (!texture.loadFromFile("tablicazdj/jajko_kury_tablica.png")) {
        std::cerr << "Błąd ładowania obrazu" << std::endl;
    } else {
        images['U'] = texture;
    }
}

void MouseHoverDisplay::displayImageOnHover(const sf::Vector2i& mousePosition) {
    int position = 270;
    const int interval = 150;
    const int maxXCoordinate = 800;
    const int minYCoordinate = 600; 

    sf::Texture* selectedTexture = nullptr;
    sf::Vector2f selectedPosition;

    int numIterations = limitedDisplay ? std::min(static_cast<int>(signs.size()), 4) : signs.size();
    for (int i = 0; i < numIterations; ++i) {
        if (images.find(signs[i]) != images.end()) {
            sf::Sprite sprite(images[signs[i]]);
            sprite.setPosition(position, 700);

            if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
                selectedTexture = &images[signs[i]];
                selectedPosition = sprite.getPosition();
            }

            position += interval;
        }
    }

    if (selectedTexture && mousePosition.x <= maxXCoordinate && mousePosition.y >= minYCoordinate) {
        displayLargeImage(selectedPosition, *selectedTexture);
    } else {
        hideLargeImage();
    }
}





void MouseHoverDisplay::displayLargeImage(const sf::Vector2f& position, const sf::Texture& texture) {
    largeSprite.setTexture(texture);
    largeSprite.setPosition(position.x +50, position.y );
    largeSprite.setScale(0.2f, 0.2f);
    window.draw(largeSprite);
}
void MouseHoverDisplay::hideLargeImage() {

    largeSprite.setTexture(sf::Texture());
}