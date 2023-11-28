#pragma once
#include <boost/asio.hpp>
#include <array>
#include "Move.h"
#include "BoardState.h"
#include "Match.h"

#define BUF_SIZE 1024

class Session
{
public:
    Session(boost::asio::ip::tcp::socket socket);
    Move GetMove() const;
    void SendBoardState(BoardState boardstate);
    void ReadMove();

private:
    boost::asio::ip::tcp::socket socket_;
    Move read_move;
    std::array<char, BUF_SIZE> buf_;
    std::shared_ptr<Match> match_;
};