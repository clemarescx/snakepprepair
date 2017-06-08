/*
 * @file: GameManager.h
 * @author: Stig M. Halvorsen <halsti@nith.no>
 * @version: 1.0.0 <11.02.2013>
 *
 * @description: A singleton class to control all gameplay.
 */

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../snake/Snake.h"
#include "../sdl/SDLPng.h"
#include "../sdl/SDLSound.h"
#include "../sdl/SDLManager.h"
#include "../sdl/SDLBmp.h"
#include "InputManager.h"
#include "../resourceManagement/Timer.h"
#include "../renderers/SnakeRenderer.h"
#include "../Direction.h"
#include "RendererManager.h"
#include "../sdl/SDLMusic.h"
#include "../board/grid/Vector2D.h"
#include "../sdl/SDLMusic.h"
#include "../sdl/SDLSound.h"


class GameManager {
public:
    /* Meyer's singleton style instance call */
    static GameManager &Instance() {
        static GameManager g;
        return g;
    }

    /* Kicks off/is the the gameloop */
    void play();

private:

    GameManager();                                // Hidden constructor
    GameManager(const GameManager &);            // Hidden copy constructor
    GameManager &operator=(const GameManager &); // Hidden assign operator
    void updateDirection(Direction &currentDirection, Direction &nextDirection);

    void init();

    void loadAssets();


    bool running = true;
    unsigned int m_window; // pointer to main window
    float m_lastRender; // Time in seconds since last render
    float m_lastMove; // Time in seconds since last position update

    Direction direction = Specs.SNAKE_HEAD_STARTDIR;
    const int board_columns = Specs.BOARD_COLUMNS;
    const int board_rows = Specs.BOARD_ROWS;
    const int node_diameter = Specs.NODE_DIAMETER_PX;
    float move_update_rate = Specs.MAX_MOVE_INTERVAL;
    float min_move_interval = Specs.MIN_MOVE_INTERVAL;

    float apple_spawn_time_delta = 0.f + Specs.MIN_APPLE_RESPAWN_TIME;
    int score = 0;
    int scoreDelta = 0;
    float m_time_delta = 0.f;

    float teleporter_spawn_time_delta = 0.f + Specs.MIN_TELEPORTER_RESPAWN_TIME;
    float teleporter_spawn_time = 0;

    float apple_spawn_time = 0;
    Vector2D velocityVec{0, 0};

    vector<Node> obstaclesVector{};
    //shared_ptr<GameBoard> gameboard;
    vector<Node> teleporterVector{};
    shared_ptr<Snake> snake_new;
    Node appleNode{};

    std::shared_ptr<SDLMusic> gameMusic;
    std::shared_ptr<SDLSound> appleSound;
    std::shared_ptr<SDLSound> bonusSound;
    std::shared_ptr<SDLSound> gruntSound;

    Vector2D getVelocityVector(Direction direction);

    bool isOutOfBounds(const Node &node) const;

    void update_game_state();

    bool isObstacle(const Node &node) const;

    bool isTeleporter(const Node &node) const;
    bool teleportersInstantiated = false;
    bool teleporterInUse = false;
    void instantiateTeleporters();
    void respawnTeleporter();

    bool isApple(const Node &nextPos) const;

    void getValidPosition(Node &obj);

    Node getRandomNode();

    bool isEmptyNode(const Node &node) const;

    bool isSnake(const Node &node) const;

    Node getSnakeHeadNextPos(Node &head, Vector2D &velocity);

    bool isTooCloseToSnake(const Node &node) const;


    void respawnApple();

    bool snakeCrashesWith(Node &node);

    void increaseSpeed(float &currentInterval);

	RendererManager rendererManager{};
	void InitRendererManager();
};

#endif