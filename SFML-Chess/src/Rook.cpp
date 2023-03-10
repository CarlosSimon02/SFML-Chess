#include <Rook.hpp>

Rook::Rook(Side side)
	: Piece(Type::Rook, side,
		{ {-1,0}, {+1,0},{0,+1},{0,-1} }) //straight
{}

std::vector<sf::Vector2i> Rook::createPositionChoices(std::array<std::unique_ptr<Piece>, 64>& piecesBuffer)
{
	std::vector<sf::Vector2i> positionChoicesList;
	positionChoicesList.push_back(getPos());
	for (size_t i = 0; i < getMoveDirections().size(); i++)
	{
		int offset = 1;
		while (getPos().x + getMoveDirections()[i].x * offset >= 0 &&
			getPos().x + getMoveDirections()[i].x * offset < Board::TILESIZE &&
			getPos().y + getMoveDirections()[i].y * offset >= 0 &&
			getPos().y + getMoveDirections()[i].y * offset < Board::TILESIZE)
		{
			positionChoicesList.push_back({ getPos().x + getMoveDirections()[i].x * offset,getPos().y + getMoveDirections()[i].y * offset });
			offset++;
		}
	}
	return positionChoicesList;
}