//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the game over screen.
//


#ifndef __GAM_1514_OSX_Game__Over__
#define __GAM_1514_OSX_Game__Over__

#include "../../Common/Screen Manager/Screen.h"

#include "../UI/UIButton.h"

class GameOver : public Screen, public UIButtonListener
{
public:
	GameOver();
	~GameOver();

	const char* getName();

    void update(double delta);
    void paint();

	void keyUpEvent(int keyCode);

	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	void buttonAction(UIButton * button) ;

private:
	UIButton * m_PressSpace;
    UIButton * m_PlayAgain;
    OpenGLTexture* m_BackGround1;
	OpenGLTexture* m_Ice_Hockey_Logo;
	int m_Select;
};


#endif