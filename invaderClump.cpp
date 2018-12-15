// invaderClump.cpp
// Sam Battalio
// Lab 01
// Implementation for invaderClump
// holds all invaders

#include <vector>
#include <ctime>
#include <cstdlib>
#include "invaderClump.h"
using namespace std;

// constructor with numAcross invaderas across and numDown down
InvaderClump::InvaderClump(int numAcross,int numDown) {
	srand(time(NULL)); // seed random
	for(int i = 0; i < numAcross; i++){
		for(int j = 0; j < numDown; j++){
			invaders.push_back(Invader(i*(Invader::width+5),
																 j*(Invader::height+5) + Invader::height,numAcross));

		}
	}
}

// deconstructor
InvaderClump::~InvaderClump() {  }

// update all invaders and return if one died
bool InvaderClump::update(Laser& ulaser) {
	bool erased = 0;
	for(auto it = invaders.begin(); it != invaders.end(); it++) {
		if(!ulaser.isDead()) // check if theres a laser
			if(it->checkCollision(ulaser)) {// see if it collides with invader
				it = invaders.erase(it);  // destroy invader
				erased = 1;
				if(it == invaders.end()) break; // check to make sure didnt go past end condition
			}
		if(!(it->moveTimer % 30)) it->move(); // move if timer is zero
		it->moveTimer--; // decrement timer
	}
	laser.update();
	return erased;
}

// draw all invaders
void InvaderClump::draw() {
	for(auto it = invaders.begin(); it != invaders.end(); it++) {
		it->draw();
	}
	laser.draw();
}

// set a invader to shoot if can
void InvaderClump::shoot() {
	if(laser.isDead()) {
		int index = rand() % invaders.size();
		laser = Laser(invaders.at(index).getX() + Invader::width / 2,invaders.at(index).getY(),-1);
	}
}

// return laser
Laser& InvaderClump::getLaser() {
	return laser;
}

// return if invader hit bottom of screen
bool InvaderClump::hitBottom(int playerY) {
	for (Invader invader: invaders) {
		if(invader.getY() + Invader::height >= playerY)
			return true;
	}
	return false;
}

// return if all invaders dead
bool InvaderClump::dead() {
	if(invaders.size() == 0) return true;
	return false;
}
