#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"

class GameObject;
class OpenGLTexture;

class Game : public Screen, public InputListener
{
public:
    Game();
    ~Game();
    
    //Game lifecycle methods
    void update(double delta);
    void paint();
    void reset();
    
    //Game Over method, call this when to end the game
    void gameOver();
    void leftGoal();
    void rightGoal();
    
    //Screen name, must be implemented, it's a pure
    //virtual method in the Screen class
    const char* getName();
    
    //Screen event method, inherited from the screen class
    void screenWillAppear();
    
    //GameObject Methods
    void addGameObject(GameObject* gameObject);
    GameObject* getGameObjectByType(const char* type);
    
	void mouseMovementEvent(float aDeltaX, float aDeltaY, float aPositionX, float aPositionY);
private:
    //Key Events
    void keyUpEvent(int keyCode);
    void keyDownEvent(int keyCode);
    
    //Method to reset the ball, called after a goal is scored. The
    //parameter determines which direction the ball will go in
    //after a goal is scored.
    void resetBall(bool leftGoal);
    
    //Conveniance method used to paint the score info, drawn after
    //a goal is scored to update the user on the current score
    void paintScoreInfo(float alpha);
  
    void paintGameOverInfo(float alpha);

    //Vector to hold the GameObjects
    std::vector<GameObject*> m_GameObjects;
    
    //Texture's used for the score info
    OpenGLTexture* m_AlgonquinLogo;
    OpenGLTexture* m_ScoreInfoBackground;
    OpenGLTexture* m_ScoreInfoGoal;
    OpenGLTexture* m_ScoreInfoLeft;
    OpenGLTexture* m_ScoreInfoRight;
	OpenGLTexture* m_GameOverTexture;
    OpenGLTexture** m_ScoreInfoNumbers;
 	OpenGLTexture** m_TimeInfo1;
 	OpenGLTexture** m_TimeInfo2;
 	OpenGLTexture** m_TimeInfo3;

    //Score Info variables
    double m_ScoreInfoTimer;
    float m_ScoreInfoAlpha;
    
    //Score variables
    short m_LeftGoalsScored;
    short m_RightGoalsScored;

	short m_TimeLimit;
	char m_TimeLimitStrAt1;
	short m_TimeLimitStrAt2;
	short m_TimeLimitStrAt3;
	bool m_GameOver;
};

#endif