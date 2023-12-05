#include "object.hpp"
#include <iostream>

Object::Object(const Texture& texture) : x(0), y(0), texture(texture) {}

Object::Object(const Texture& texture, int x, int y) : x(x), y(y), texture(texture) {}

int Object::getX() {
	return x;
}

int Object::getY() {
	return y;
}

int Object::getWidth() {
	return texture.getWidth();
}

int Object::getHeight() {
	return texture.getHeight();
}

void Object::setOffset(int x, int y) {
	this->x = x;
	this->y = y;
}

void Object::render(Engine* engine) {
	engine->textureFill(x, y, texture);
}