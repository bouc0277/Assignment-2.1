#include "GameConstants.h"


//Game Constants
const char* GAME_SCREEN_NAME = "Game";
const double GAME_OVER_TIMER = 2.0;
const double GAME_SCORE_INFO_TIMER = 2.0;
const double GAME_SCORE_INFO_FADE_OUT_TIME = 0.5;
short GAME_MAX_SCORE = 9;
short GAME_MAX_SCORE_INFINITY = 9;
short GAME_TIME_LIMIT = 18000;
short GAME_TIME_LIMIT_CONST = 18000;
//Ball Constants
const float GAME_BALL_RADIUS_PERCENTAGE = 0.012f;
float GAME_BALL_DEFAULT_SPEED = 450.0f;
const float GAME_BALL_SPEED_INCREMENT = 50.0f;
const char* GAME_BALL_TYPE = "Ball";

//Paddle Constants
const float GAME_PADDLE_WIDTH_PERCENTAGE = 0.025f;
const float GAME_PADDLE_HEIGHT_PERCENTAGE = 0.2f;
const float GAME_LEFT_PADDLE_X_PERCENTAGE = 0.05f;
const float GAME_RIGHT_PADDLE_X_PERCENTAGE = 0.95f;
const float GAME_PADDLE_Y_PERCENTAGE = 0.5f;
float GAME_PADDLE_ACCELERATION = 75.0f;
float GAME_PADDLE_MAX_SPEED = 300.0f;
const char* GAME_PADDLE_TYPE = "Paddle";
short GAME_CONTROLER_CONFIG1 = 0;
short GAME_CONTROLER_CONFIG2 = 0;