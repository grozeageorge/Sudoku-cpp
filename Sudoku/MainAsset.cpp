#include "MainAsset.h"

engine::MainAsset::MainAsset()
{

}

void engine::MainAsset::addTexture(int id, const std::string& filePath, bool wantRepeated )
{
	auto texture = std::make_unique<sf::Texture>(); //adaugam textura cu make unique
	if (texture->loadFromFile(filePath)) //functie pentru a incarca textura ... functie bool care returneaza daca s-a incarcat cu succes sau nu
	{
		texture->setRepeated(wantRepeated); //functie care determina refolosirea texturii
		m_textures[id] = std::move(texture); //retinem textura in map -> muta unique ptr in map pe id-ul id
	}
}
void engine::MainAsset::addFont(int id, const std::string& filePath)
{
	auto font = std::make_unique<sf::Font>(); //adaugam un font cu make unique
	if (font->loadFromFile(filePath)) //incarca fontul
	{
		m_fonts[id] = std::move(font); //adauga fontul in map
	}
}

const sf::Texture& engine::MainAsset::getTexture(int id) const
{
	return *(m_textures.at(id).get()); // * pt derefence pointer ca sa returnam obiectul in sine, nu unique ptr
}

const sf::Font& engine::MainAsset::getFont(int id) const
{
	return *(m_fonts.at(id).get());
}