#pragma once
#include <string>
#include "GameObjectBluprint.h"

class BlueprintObjectParser
{
private:
	std::string extractStringBetweenTags(
		std::string stringToSearch, std::string startTag, std::string endTag);
public:
	void parseNextObjectForBlueprint(std::ifstream& reader, GameObjectBluprint& bp);
};