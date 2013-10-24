//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the Splash screen.
//

#ifndef __GAM_1514_OSX_Game__Splash__
#define __GAM_1514_OSX_Game__Splash__

#include "../../Common/Screen Manager/Screen.h"

#include "../UI/UIButton.h"

class Splash : public Screen, public UIButtonListener
{
public:
	Splash();
	~Splash();

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
    OpenGLTexture* m_BackGround1;
	OpenGLTexture* m_Ice_Hockey_Logo;
};


#endif