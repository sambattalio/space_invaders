// player.cpp
// Sam Battalio
// Lab 01

#include <iostream>
#include "player.h"
using namespace std;

// Init player at width / height
Player::Player(int width, int height){ 
	points[0] = {(short)(width / 2), (short)(height - size)};
	points[1] = {(short)(width / 2 - size / 2), (short)height};
	points[2] = {(short)(width / 2 + size / 2), (short)height};
	s_width = width;
	score = 0;
	lives = 3;
}

// player deconstructor
Player::~Player() { }

// move player / init laser based on input
void Player::move(char input) {
	switch(input) {
		case 'a':
			if(points[1].x > 0) {
				points[0].x -= speed;
				points[1].x -= speed;
				points[2].x -= speed;
			}
			break;
		case 'd':
			if(points[2].x < s_width) {
				points[0].x += speed;
				points[1].x += speed;
				points[2].x += speed;
			}
			break;
		case ' ':
			if(laser.isDead()) {
				laser = Laser(points[0].x - Laser::size / 4,points[0].y,1);
			}
			break;
	}
}

// update laser and check if dead
void Player::update() {
	if(lives <= 0) cout << "GAME OVER" << endl;
	if(laser.isDead()) return;
	laser.update();
}

// draw the number of lives at x y
void Player::drawLives(int x, int y) {
	for (int i = 0; i < lives; i++)
		gfx_fill_circle(x+i*10 + 5,y,5);
}

// check if alive
bool Player::isAlive() {
	return lives > 0;
}

// draw player
void Player::draw() {
	gfx_fill_polygon(points,3);
	laser.draw();
}

// return laser class
Laser& Player::getLaser() {
	return laser;
}

// check if hit by enemy laser
bool Player::checkCollision(Laser &laser) {
	if (laser.getX() > points[1].x && laser.getX() < points[2].x && laser.getY() > points[0].y &&
		  laser.getY() < points[1].y) {
		laser.setDead();
		lives--;
		return true;
	}
	return false;
}

// get top y value
int Player::getTopY() {
	return points[0].y;
}

// inc score
void Player::setScore() {
	score += 100;
}

// return score
int Player::getScore() {
	return score;
}
