// button.cpp
// Sam Battalio
// Lab 01
// button implementation
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "button.h"
#include "gfx2.h"
using namespace std;

// init button
Button::Button(int x, int y, int w, int h, char * text, char * font, int state) {
	this->x = x - w / 2;
	this->y = y - h / 2;
	this->state = state;
	strcpy(this->font,font);
	strcpy(this->text,text);
	text_w = gfx_textpixelwidth(text,font);
	text_h = gfx_textpixelheight(text,font);
	width = w;
	height = h;
}

// deconstructor
Button::~Button() { }

// checm if it was clicekd and return the state
int Button::checkClick(int current, int m_x, int m_y) {
	if(m_x > x && m_x < x + width && m_y > y && m_y < y + height)
		return state;
	return current;
}

// draw button
void Button::draw() {
	gfx_rectangle(x,y,width,height);
	gfx_changefont(font);
	gfx_text(x + width / 2 - text_w / 2, y + height / 2 + text_h / 2, text); 
}
