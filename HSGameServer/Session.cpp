#pragma once
#include "Session.h"


Session::Session(boost::asio::ip::tcp::socket socket, std::unordered_set<std::shared_ptr<Match>>& match_set)
    : socket_(std::move(socket)),
    read_move(),
    buf_(),
    match_set_(match_set)
{
    user_id_ = DatabaseManager::Instance().GetUserID(socket.remote_endpoint().address().to_string());
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
                match_set_.erase(match_->shared_from_this());
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
                match_set_.erase(match_->shared_from_this());
            }
        });
}
