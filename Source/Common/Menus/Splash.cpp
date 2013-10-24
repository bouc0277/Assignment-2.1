//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the Splash screen.
//

#include "Splash.h"
#include "../../Common/Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"



Splash::Splash() :
    m_PressSpace(NULL),
    m_BackGround1(NULL),
	m_Ice_Hockey_Logo(NULL)
{
	m_PressSpace = new UIButton(SPLASH_PRESS_SPACE);
		
    m_BackGround1 = new OpenGLTexture(SPLASH_BACKGROUND1);
    m_Ice_Hockey_Logo = new OpenGLTexture(SPLASH_LOGO);

	m_PressSpace->setCenterPosition(getWidth() / 2.0f, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE);
	m_PressSpace->setListener(this);
}

Splash::~Splash()
{
	if(m_PressSpace != NULL)
	{
		delete m_PressSpace;
		m_PressSpace = NULL;
	}
	if(m_BackGround1 != NULL)
	{
		delete m_BackGround1;
		m_BackGround1 = NULL;
	}
	if(m_Ice_Hockey_Logo != NULL)
	{
		delete m_Ice_Hockey_Logo;
		m_Ice_Hockey_Logo = NULL;
	}
}

const char* Splash::getName()
{

	return SPLASH_SCREEN_NAME;
}

void Splash::update(double delta)
{

}

void Splash::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BackGround1, (getWidth() - m_BackGround1->getSourceWidth()) / 2.0f, (getHeight() - m_BackGround1->getSourceHeight()) / 2.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_Ice_Hockey_Logo, 140, 15);
	m_PressSpace->paint();

}

void Splash::keyUpEvent(int keyCode)
{

	if(keyCode == KEYCODE_SPACE)
	{
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}


void Splash::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_PressSpace->mouseMovementEvent(positionX, positionY);
}

void Splash::mouseLeftClickUpEvent(float positionX, float positionY)
{
	m_PressSpace->mouseLeftClickUpEvent(positionX, positionY);
}

void Splash::buttonAction(UIButton * button) 
{
	if(button == m_PressSpace)
	{
	    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
}