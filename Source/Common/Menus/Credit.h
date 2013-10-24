//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the credits screen.
//

#ifndef __GAM_1514_OSX_Game__Credit
#define __GAM_1514_OSX_Game__Credit

#include "../../Common/Screen Manager/Screen.h"

#include "../UI/UIButton.h"

class Credit : public Screen, public UIButtonListener
{
public:
	Credit();
	~Credit();

	const char* getName();

    void update(double delta);
    void paint();

	void keyUpEvent(int keyCode);

	void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
	void mouseLeftClickUpEvent(float positionX, float positionY);

protected:
	void buttonAction(UIButton * button) ;

private:
    UIButton * m_PressButton;
    OpenGLTexture* m_BackGround2;
	int m_Select;
};


#endif