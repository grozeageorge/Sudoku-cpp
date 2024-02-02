#pragma once

#include <map> //map pt a retine texturile si fonturile folosite
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>


namespace engine
{
	class MainAsset //clasa pt font-uri si texturi
	{
	private:
		std::map<int, std::unique_ptr<sf::Texture>> m_textures; //map va avea un intreg si un pointer unic catre fontul/textura propriu zisa
		std::map<int, std::unique_ptr<sf::Font>> m_fonts;
	public:
		MainAsset();
		~MainAsset() = default;

		void addTexture(int id, const std::string &filePath, bool wantRepeated = false); //functii care vor adauga font/textura noua ... want_repeated pentru a refolosi textura
		void addFont(int id, const std::string &filePath);

		const sf::Texture& getTexture(int id) const; //functi care nu modifica obiectul si returneaza fontul/textura care e constanta
		const sf::Font& getFont(int id) const;
	};
}