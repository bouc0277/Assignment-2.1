//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the Main menu screen.
//

#ifndef __GAM_1514_OSX_Game__Main__Menu__
#define __GAM_1514_OSX_Game__Main__Menu__

#include "../../Common/Screen Manager/Screen.h"

#include "../UI/UIButton.h"

class MainMenu : public Screen, public UIButtonListener
{
public:
	MainMenu();
	~MainMenu();

	const char* getName();

    void update(double delta);
    void paint();

	void keyUpEvent(int keyCode);

	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	void buttonAction(UIButton * button) ;

private:
    UIButton * m_SinglePlayer;
	UIButton * m_TwoPlayers;
	UIButton * m_Credits;
    UIButton * m_Exit;
    OpenGLTexture* m_BackGround1;
	OpenGLTexture* m_MainMenu;
	int m_Select;
};


#endif