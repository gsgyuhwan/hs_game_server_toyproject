#pragma once
#include "AliasedTypes.h"

class DatabaseManager 
{
public:
	static DatabaseManager& Instance() {
		return instance_;
	}

	DeckList GetPlayersDeck(UserID userid);


private:
	static DatabaseManager instance_;

};
DatabaseManager DatabaseManager::instance_;