// laser.cpp
// Sam Battalio
// Lab 01
// Laser 

#include "laser.h"

// default constructor
Laser::Laser() {
	this->x = -1;
	this->y = -1;
	this->dir = 0;
	dead = true;
}

// init laser at a point and direction
Laser::Laser(int x, int y, int dir) {
	this->x = x;
	this->y = y;
	this->dir = dir;
	dead = false;
}

// deconstructor
Laser::~Laser() { };

// update if not dead
void Laser::update() {
	if(!dead) {
		y -= speed * dir;
		if(y < 0 || y > 500) dead = true;
	}
};

// set dead bool
void Laser::setDead() {
	dead = true;
}

// draw if alive
void Laser::draw() {
	if(!dead) gfx_fill_rectangle(x,y,size / 2, size);
}

// get if dead
bool Laser::isDead() {
	return dead;
}

// get x
int Laser::getX() {
	return x;
}

// get y
int Laser::getY() {
	return y;
}

// get size
int Laser::getSize() {
	return size;
}
