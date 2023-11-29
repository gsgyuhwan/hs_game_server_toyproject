#include "pch.h"

class GameServerTest : public testing::Test {
protected:
	void SetUp() override {
		server_thread_ = std::thread([this]() {
			boost::asio::io_context io_context;
			game_server_ = std::make_unique<GameServer>(io_context, 8888);
			io_context.run();
			});
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}
	void TearDown() override {
		game_server_.reset();
		server_thread_.join();
	}
	std::thread server_thread_;
	std::unique_ptr<GameServer> game_server_;
};

TEST_F(GameServerTest, GetDefaultAttackTest) {

	EXPECT_EQ(0, GameServer::GetDefaultAttack(0));
}

TEST_F(GameServerTest, GetDefaultHealthOrDurabilityTest) {

	EXPECT_EQ(0, GameServer::GetDefaultHealthOrDurability(0));
}

TEST_F(GameServerTest, GetDeathrattleTest) {

	EXPECT_FALSE(GameServer::GetDeathrattle(0).has_value());
}

TEST_F(GameServerTest, GetDefaultCostTest) {

	EXPECT_EQ(0, GameServer::GetDefaultCost(0));
}

TEST_F(GameServerTest, InstantiateCardTest) {

	CardInstance card{};
	CardInstance ret = GameServer::InstantiateCard(0);
	EXPECT_EQ(card, ret);
}