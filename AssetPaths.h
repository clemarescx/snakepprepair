//
// Created by thomas on 04.06.17.
//

#ifndef SNAKE_PLUSPLUS_ASSETPATHS_H
#define SNAKE_PLUSPLUS_ASSETPATHS_H

#include <string>
using namespace std;

static const struct images {
	images() {}

	const string snakeHead = "Assets/gfx/SnakeHead.png";
	const string snakeBody = "Assets/gfx/SnakeBody.png";
	const string snakeTail = "Assets/gfx/SnakeTail.png";
	const string apple = "Assets/gfx/Apple.png";
	const string obstacle = "Assets/gfx/Obstacle.png";
	const string wormhole = "Assets/gfx/Hole.png";
	const string background = "Assets/gfx/SnakeBoard.png";
} images;

static const struct audio {
	audio() {}

	const string level = "Assets/sfx/musicLoop.wav";
	const string crunch = "Assets/sfx/eating.wav";
	const string grunt = "Assets/sfx/grunt.wav";
	const string wormhole = "Assets/sfx/bonus.wav";
} audio;

#endif //SNAKE_PLUSPLUS_ASSETPATHS_H
