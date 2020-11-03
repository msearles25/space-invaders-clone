#include <assert.h>
#include "BitmapStore.h"

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(const std::string& filename)
{
	// Get a reference to m_Texture using the m_s_instance
	auto& bitmapsMap{ m_s_Instance->m_BitmapMap };
	// auto is equivalent to map<std::string, sf::Texture>

	// Create an iterator to hold a key-value pair and search for the required
	// key-value pair using the name that was passed in
	auto keyValuePair{ bitmapsMap.find(filename) };
	// auto is equivalent to map<std::string, sf::Texture>::iterator

	// No match found, so we'll save it in the map
	if (keyValuePair == bitmapsMap.end())
	{
		// Create a new key-value pair using the file name 
		auto& texture{ bitmapsMap[filename] };
		// Load the texture from the file in the usual way
		texture.loadFromFile(filename);
	}
}