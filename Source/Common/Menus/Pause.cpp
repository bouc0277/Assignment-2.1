//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the Pause screen.
//

#include "Pause.h"
#include "../../Common/Game/Game.h"
#include "../../Common/Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"



Pause::Pause() :
    m_PressSpace(NULL),
    m_Restart(NULL),
    m_BackGround1(NULL),
	m_Ice_Hockey_Logo(NULL),
    m_Select(0),
    m_Resume(NULL),
	m_Settings(NULL)
{
	m_PressSpace = new UIButton(GAME_GAME_MAIN_MENU);
	m_Restart = new UIButton(GAME_RESTART);	
	m_Resume = new UIButton(GAME_RESUME);	
	m_Settings = new UIButton(GAME_GAME_SETTINGS);	

    m_BackGround1 = new OpenGLTexture(GAME_PAUSE_BACKGROUND);
    m_Ice_Hockey_Logo = new OpenGLTexture(GAME_PAUSE_TITLE);

	m_PressSpace->setCenterPosition(getWidth() / 2.0f , getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE-250);
	m_PressSpace->setListener(this);

	m_Restart->setCenterPosition(getWidth() / 2.0f , getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE - 400);
	m_Restart->setListener(this);

	m_Resume->setCenterPosition(getWidth() / 2.0f , getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE - 100);
	m_Resume->setListener(this);

	m_Settings->setCenterPosition(getWidth() / 2.0f , getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE );
	m_Settings->setListener(this);

	m_Select = 1;
}

Pause::~Pause()
{
	if(m_PressSpace != NULL)
	{
		delete m_PressSpace;
		m_PressSpace = NULL;
	}

	if(m_Restart != NULL)
	{
		delete m_Restart;
		m_Restart = NULL;
	}

	if(m_Resume != NULL)
	{
		delete m_Resume;
		m_Resume = NULL;
	}

	if(m_Settings != NULL)
	{
		delete m_Settings;
		m_Settings = NULL;
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

const char* Pause::getName()
{

	return GAME_PAUSE_SCREEN_NAME;
}

void Pause::update(double delta)
{

}

void Pause::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BackGround1, (getWidth() - m_BackGround1->getSourceWidth()) / 2.0f , (getHeight() - m_BackGround1->getSourceHeight()) / 2.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_Ice_Hockey_Logo, 370, 15);
	m_PressSpace->paint();
	m_Restart->paint();
	m_Resume->paint();
	m_Settings->paint();
}

void Pause::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_UP_ARROW)
	{
	    switch(m_Select)
		{
		    case 1:
			{
				break;
			}

		    case 2:
			{
				m_Select -=1;
				break;
			}

		    case 3:
			{
				m_Select -=1;
				break;
			}

		    case 4:
			{
				m_Select -=1;
				break;
			}
		}
	}

	if(keyCode == KEYCODE_DOWN_ARROW)
	{
	    switch(m_Select)
		{
		    case 1:
			{
				m_Select +=1;
				break;
			}

		    case 2:
			{
				m_Select +=1;
				break;
			}
		    case 3:
			{
				m_Select +=1;
				break;
			}
		    case 4:
			{
				break;
			}
		}
	}

	switch(m_Select)
	{
	    case 1:
		{
			m_Restart->mouseMovementEvent(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE-400);
			m_PressSpace->setIsSelected(false);
			m_Resume->setIsSelected(false);
			m_Settings->setIsSelected(false);
			break;
		}
		case 2:
		{
		    m_PressSpace->mouseMovementEvent(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE-250);
			m_Restart->setIsSelected(false);
			m_Resume->setIsSelected(false);
			m_Settings->setIsSelected(false);
			break;
		}
		case 3:
		{
		    m_Resume->mouseMovementEvent(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE - 100);
			m_PressSpace->setIsSelected(false);
			m_Restart->setIsSelected(false);
			m_Settings->setIsSelected(false);
			break;
		}
		case 4:
		{
		    m_Settings->mouseMovementEvent(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE);
			m_Restart->setIsSelected(false);
			m_Resume->setIsSelected(false);
			m_PressSpace->setIsSelected(false);
			break;
		}
	}



	if(keyCode == KEYCODE_SPACE)
	{
        if(m_PressSpace->getIsSelected() == true)
	    {
		    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
            Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	        game->reset();
		}
        if(m_Restart->getIsSelected() == true)
	    {
	        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
            Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	        game->reset();
		}
        if(m_Resume->getIsSelected() == true)
	    {
	        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
		}
        if(m_Settings->getIsSelected() == true)
	    {
	        ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
		}
	}
}



void Pause::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_PressSpace->mouseMovementEvent(positionX, positionY);
	m_Restart->mouseMovementEvent(positionX, positionY);
	m_Resume->mouseMovementEvent(positionX, positionY);
	m_Settings->mouseMovementEvent(positionX, positionY);
}

void Pause::mouseLeftClickUpEvent(float positionX, float positionY)
{
	if(m_PressSpace->getIsSelected() == true)
	{
	    m_PressSpace->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_Restart->getIsSelected() == true)
	{
	    m_Restart->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_Resume->getIsSelected() == true)
	{
	    m_Resume->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_Settings->getIsSelected() == true)
	{
	    m_Settings->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void Pause::buttonAction(UIButton * button) 
{
	if(button == m_PressSpace)
	{
	    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
        Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	    game->reset();
	}

	if(button == m_Restart)
	{
	    ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
        Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	    game->reset();
	}

	if(button == m_Resume)
	{
	    ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	if(button == m_Settings)
	{
    	ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
	}

}
