#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Piece : public sf::Drawable {
private:        
    sf::Sprite sprite;
    int value;

public:
    Piece(sf::Texture &texture, int x, int y, int val) {
        sprite.setTexture(texture);    
        value = val;
        if (value < 0)
            sprite.setTextureRect(sf::IntRect(56 * (abs(value) - 1), 0, 56, 56));
        else
            sprite.setTextureRect(sf::IntRect(56 * (abs(value) - 1), 56, 56, 56));
        sprite.setPosition(x, y);
        sprite.setOrigin(56 / 2, 56 / 2);
    }

    bool ContainPosition(int x, int y) {
        int szX = sprite.getPosition().x;
        int szY = sprite.getPosition().y;
        sf::IntRect rect = sf::IntRect(szX - 28 + 3, szY - 28 + 3, 50, 50);
        return rect.contains(x, y);
    }

    void SetPosition(int x, int y) {
        sprite.setPosition(x, y);
    }

    sf::Vector2f GetPosition() {
        return sprite.getPosition();
    }

    int GetValue() {
        return value;
    }

    virtual void draw(sf::RenderTarget &rt, sf::RenderStates rs) const override {
        rt.draw(sprite, rs);
    }
};

#endif // PIECE_HPP
