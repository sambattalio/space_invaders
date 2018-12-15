// invader.cpp
// Sam Battalio
// Lab 01
// Implementation of Invader enemy

#include "gfx2.h"
#include "invader.h"
#include <iostream>

Invader::Invader(int x, int y,int numMoves) {
	this->x = x;
	this->y = y;
	this->across = numMoves - 1;
	this->moveCount = 0;
	this->dir = 1;
	moveTimer = 0;
	animTimer = 0;
}

Invader::~Invader() {

}

void Invader::draw() {
	//gfx_color(R,G,B);
	if (animTimer % 2) {
		// Draw invader at point
		// Top row
		gfx_fill_rectangle(x+2*size,y,size,size);
		gfx_fill_rectangle(x+8*size,y,size,size);
		// second row
		gfx_fill_rectangle(x+3*size,y+size,size,size);
		gfx_fill_rectangle(x+7*size,y+size,size,size);
		// third row
		gfx_fill_rectangle(x+2*size,y+2*size,size*7,size);
		// fourth row
		gfx_fill_rectangle(x+size,y+3*size,2*size,size);
		gfx_fill_rectangle(x+4*size,y+3*size,3*size,size);
		gfx_fill_rectangle(x+8*size,y+3*size,2*size,size);
		// fifth row
		gfx_fill_rectangle(x,y+4*size,11*size,size);
		// sixth row
		gfx_fill_rectangle(x,y+5*size,size,size);
		gfx_fill_rectangle(x+2*size,y+5*size,size*7,size);
		gfx_fill_rectangle(x+10*size,y+5*size,size,size);
		// seventh row
		gfx_fill_rectangle(x,y+6*size,size,size);
		gfx_fill_rectangle(x+size*2,y+6*size,size,size);
		gfx_fill_rectangle(x+size*8,y+6*size,size,size);
		gfx_fill_rectangle(x+10*size,y+6*size,size,size);
		// eighth row
		gfx_fill_rectangle(x+3*size,y+7*size,size*2,size);
		gfx_fill_rectangle(x+6*size,y+7*size,size*2,size);
	} else {
  	//Top row
		gfx_fill_rectangle(x+2*size,y,size,size);
		gfx_fill_rectangle(x+8*size,y,size,size);
		// second row
		gfx_fill_rectangle(x+3*size,y+size,size,size);
		gfx_fill_rectangle(x+7*size,y+size,size,size);
		gfx_fill_rectangle(x,y+size,size,size);
		gfx_fill_rectangle(x+10*size,y+size,size,size);
		// third row
		gfx_fill_rectangle(x+2*size,y+2*size,size*7,size);
  	gfx_fill_rectangle(x,y+2*size,size,size);
		gfx_fill_rectangle(x+10*size,y+2*size,size,size);
		// fourth row
		gfx_fill_rectangle(x,y+3*size,3*size,size);
		gfx_fill_rectangle(x+4*size,y+3*size,3*size,size);
		gfx_fill_rectangle(x+8*size,y+3*size,3*size,size);
		// fifth row
		gfx_fill_rectangle(x,y+4*size,11*size,size);
		// sixth row
		gfx_fill_rectangle(x+size,y+5*size,9*size,size);
		// seventh row
		gfx_fill_rectangle(x+2*size,y+6*size,size,size);
		gfx_fill_rectangle(x+size*8,y+6*size,size,size);
		// eighth row
		gfx_fill_rectangle(x+size,y+7*size,size,size);
		gfx_fill_rectangle(x+9*size,y+7*size,size,size);
	}
}

void Invader::move() {
	//x+= width * dir;
	moveTimer = 30;
	moveCount++;
	if(moveCount > across) {
		dir *= -1;
		moveCount = 0;
		y += height + 5; 
		animTimer++;
	}else {
		x += width * dir;
		animTimer++;
	}
}

bool Invader::checkCollision(Laser &laser) {
	if (laser.getX() > x && laser.getX() < (x + width) && laser.getY() > y && laser.getY() < y + height) {
		laser.setDead();
		return true;
	}
	return false;	
}

int Invader::getX() {
	return x;
}	
int Invader::getY() {
	return y;
}
