#pragma once
#ifndef BITMAP_STORE_H
#define BITMAP_STORE_H

#include <map>
#include <SFML/Graphics.hpp>

class BitmapStore
{
private:
	std::map<std::string, sf::Texture> m_BitmapMap;
	static BitmapStore* m_s_Instance;
public:
	BitmapStore();
	static sf::Texture& getBitmap(const std::string& filename);
	static void addBitmap(const std::string& filename);
};

#endif // !BITMAP_STORE_H