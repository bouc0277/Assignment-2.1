//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the game settings screen.
//


#ifndef __GAM_1514_OSX_Game__Game__Settings__
#define __GAM_1514_OSX_Game__Game__Settings__

#include "../../Common/Screen Manager/Screen.h"

#include "../UI/UIButton.h"

class GameSettings: public Screen, public UIButtonListener
{
public:
	GameSettings();
	~GameSettings();

	const char* getName();

    void update(double delta);
    void paint();

	void keyUpEvent(int keyCode);

	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);
	void twoPlayersChange();
	void onePlayersChange();

	short getTimeLimitSelect();

protected:
	void buttonAction(UIButton * button) ;

private:
    UIButton * m_ScoreLimit;
	UIButton * m_TimeLimit;
	UIButton * m_Difficulty;
    UIButton * m_Controls;
    UIButton * m_StartGame;
	UIButton * m_GoBack;
    OpenGLTexture* m_BackGround1;
	OpenGLTexture* m_GameSettings;
	OpenGLTexture* m_Numbers;
	OpenGLTexture** m_ScoreInfoNumbers;
	OpenGLTexture** m_DifficultyArray;
	OpenGLTexture** m_ControlsArray1;
	OpenGLTexture** m_ControlsArray2;
	OpenGLTexture* score;



	int m_Select;
	short m_ScoreLimitSelect;
	short m_DiffucultySelect;
	short m_TimeLimitSelect;
};


#endif