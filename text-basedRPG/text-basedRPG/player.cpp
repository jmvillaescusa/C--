#include "player.h"

Player::Player() {
	name = "";
	vitality = 25;
	strength = 10;
	defence = 5;
	speed = 30;
	luck = 5;
} Player::~Player() {};

//Fighting Commands
void Player::Attack() {
	std::cout << "a";
}
void Player::Defend() {
	std::cout << "d";
}
void Player::UsePotion() {
	std::cout << "U";
}
void Player::Flee() {
	std::cout << "F";
}

//Movement
void Player::MoveUp() { };
void Player::MoveLeft() { };
void Player::MoveDown() { };
void Player::MoveRight() { };

//Inventory Maanagement
void Player::PickUp() { };
void Player::ViewInventory() { };
void Player::Usepotion(char temp) { };
void Player::RemoveItem() { };

//View Commands
void Player::Help() {
	std::cout << "'w' - move up\n";
	std::cout << "'a' - move left\n";
	std::cout << "'s' - move down\n";
	std::cout << "'d' - move right\n";
	std::cout << "'p' - pick up an item\n";
	std::cout << "'i' - view inventory\n";
	std::cout << "'u' - use a potion\n";
	std::cout << "'r' - remove an item\n\n";
};