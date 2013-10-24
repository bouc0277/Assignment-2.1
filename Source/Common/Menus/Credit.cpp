//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the credits screen.
//


#include "Credit.h"
#include "../../Common/Constants/Constants.h";
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"



Credit::Credit() :
    m_PressButton(NULL),
    m_BackGround2(NULL),
	m_Select(0)

{
    m_PressButton = new UIButton(BACK_BUTTON_SINGLE_PLAYER);
	int m_Select = 1;
    m_BackGround2 = new OpenGLTexture(SPLASH_BACKGROUND2);
	
	
	m_PressButton->setCenterPosition(getWidth() / 2.0f -450, getHeight() * 0.1);
	m_PressButton->setListener(this);


}

Credit::~Credit()
{
	if(m_PressButton != NULL)
	{
		delete m_PressButton;
		m_PressButton = NULL;
	}
	if(m_BackGround2 != NULL)
	{
		delete m_BackGround2;
		m_BackGround2 = NULL;
	}
}

const char* Credit::getName()
{

	return CREDIT_SCREEN_NAME;
}

void Credit::update(double delta)
{

}

void Credit::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BackGround2, (getWidth() - m_BackGround2->getSourceWidth()) / 2.0f, (getHeight() - m_BackGround2->getSourceHeight()) / 2.0f);
	m_PressButton->paint();
}

void Credit::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_SPACE)
	{
        ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
}

void Credit::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_PressButton->mouseMovementEvent(positionX, positionY);
}

void Credit::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_PressButton->mouseLeftClickUpEvent(positionX, positionY);
}

void Credit::buttonAction(UIButton * button) 
{
	if(button == m_PressButton)
	{
	    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}

}