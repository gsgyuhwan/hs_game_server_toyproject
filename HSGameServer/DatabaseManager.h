#pragma once
#include <string>
#include "AliasedTypes.h"


class DatabaseManager 
{
public:
	DatabaseManager(const DatabaseManager&) = delete;
	DatabaseManager(DatabaseManager&&) = delete;

	DatabaseManager& operator=(const DatabaseManager&) = delete;
	DatabaseManager& operator=(DatabaseManager&&) = delete;

	static DatabaseManager& Instance() {
		static DatabaseManager instance_;
		return instance_;
	}

	DeckList GetPlayersDeck(UserID userid) {
		DeckList ret{ 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15, };
		return ret;
	}

	UserID GetUserID(std::string address);

private:
	DatabaseManager() {};
	~DatabaseManager() {};

};