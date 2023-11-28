#pragma once
#include "Session.h"
#include <cstring>

Session::Session(boost::asio::ip::tcp::socket socket)
	: socket_(std::move(socket)),
	read_move(),
    buf_()
{
}

Move Session::GetMove() const
{
	return read_move;
}

void Session::SendBoardState(BoardState boardstate)
{
    memcpy(buf_.data(), &boardstate, sizeof(BoardState));

    boost::asio::async_write(socket_,
        boost::asio::buffer(buf_.data(), sizeof(BoardState)),
        [this](boost::system::error_code ec, std::size_t)
        {
            if (!ec)
            {

            }
            else
            {
                GameServer::Instance().EndMatch(match_->shared_from_this());
            }
        });
}

void Session::ReadMove()
{
    boost::asio::async_read(socket_,
        boost::asio::buffer(buf_.data(), sizeof(Move)),
        [this](boost::system::error_code ec, std::size_t)
        {
            if (!ec)
            {
                memcpy(&read_move, buf_.data(), sizeof(BoardState));
                match_->PlayMove(read_move);
            }
            else
            {
                GameServer::Instance().EndMatch(match_->shared_from_this());
            }
        });
}
