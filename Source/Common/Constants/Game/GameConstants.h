#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

//Game Constants
extern const char* GAME_SCREEN_NAME;
extern const double GAME_OVER_TIMER;
extern const double GAME_SCORE_INFO_TIMER;
extern const double GAME_SCORE_INFO_FADE_OUT_TIME;
extern short GAME_MAX_SCORE;
extern short GAME_MAX_SCORE_INFINITY;
extern short GAME_TIME_LIMIT;
extern short GAME_TIME_LIMIT_CONST;

//Ball Constants
extern const float GAME_BALL_RADIUS_PERCENTAGE;
extern float GAME_BALL_DEFAULT_SPEED;
extern const float GAME_BALL_SPEED_INCREMENT;
extern const char* GAME_BALL_TYPE;

//Paddle Constants
extern const float GAME_PADDLE_WIDTH_PERCENTAGE;
extern const float GAME_PADDLE_HEIGHT_PERCENTAGE;
extern const float GAME_LEFT_PADDLE_X_PERCENTAGE;
extern const float GAME_RIGHT_PADDLE_X_PERCENTAGE;
extern const float GAME_PADDLE_Y_PERCENTAGE;
extern float GAME_PADDLE_ACCELERATION;
extern float GAME_PADDLE_MAX_SPEED;
extern const char* GAME_PADDLE_TYPE;
extern short GAME_CONTROLER_CONFIG1;
extern short GAME_CONTROLER_CONFIG2;

#endif 