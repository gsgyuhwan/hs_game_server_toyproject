#pragma once
#include <boost/asio.hpp>
#include <array>
#include <unordered_set>
#include <cstring>
#include "DatabaseManager.h"
#include "AliasedTypes.h"
#include "Move.h"
#include "BoardState.h"
#include "Match.h"

#define BUF_SIZE 1024

class Session
{
public:
    Session(boost::asio::ip::tcp::socket socket, std::unordered_set<std::shared_ptr<Match>>& match_set);
    Move GetMove() const;
    void SendBoardState(BoardState boardstate);
    void ReadMove();
    UserID GetUserID();
private:
    boost::asio::ip::tcp::socket socket_;
    Move read_move;
    UserID user_id_;
    std::array<char, BUF_SIZE> buf_;
    std::shared_ptr<Match> match_;
    std::unordered_set<std::shared_ptr<Match>>& match_set_;
};