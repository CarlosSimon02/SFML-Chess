#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <memory>

#include "Board.hpp"
#include "PiecesBuffer.hpp"

class Piece
{
public:
	Piece(const Type& type, const Side& side, const sf::Vector2i& position, const std::vector<sf::Vector2i>& moveDirections);
	void setPos(const sf::Vector2i& boardPos);
	sf::Sprite getSprite() const;
	sf::Vector2i getPos() const;
	virtual std::vector<sf::Vector2i> createPositionChoices(PiecesBuffer& piecesBuffer) = 0;
	std::vector<sf::Vector2i> getMoveDirections() const;
	Side getSide() const;
	Type getType() const;
	void setState(State state);
	State getState() const;

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::Vector2i mPos;
	Type mType;
	Side mSide;
	State mState = State::Static;
	std::vector<sf::Vector2i> mMoveDirections;

};