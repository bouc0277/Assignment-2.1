//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the game over screen.
//

#include "GameOver.h"
#include "../../Common/Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"
#include "../../Common/Game/Game.h"


GameOver::GameOver() :
    m_PressSpace(NULL),
    m_PlayAgain(NULL),
    m_BackGround1(NULL),
	m_Ice_Hockey_Logo(NULL),
    m_Select(0)
{
	m_PressSpace = new UIButton(BACK_BUTTON_SINGLE_PLAYER);
	m_PlayAgain = new UIButton(GAME_OVER_PLAY_AGAIN);	

    m_BackGround1 = new OpenGLTexture(GAME_OVER_BACKGROUND);
    m_Ice_Hockey_Logo = new OpenGLTexture(GAME_OVER_TITLE);

	m_PressSpace->setCenterPosition(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE-250);
	m_PressSpace->setListener(this);

	m_PlayAgain->setCenterPosition(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE - 400);
	m_PlayAgain->setListener(this);

	m_Select = 1;
}

GameOver::~GameOver()
{
	if(m_PressSpace != NULL)
	{
		delete m_PressSpace;
		m_PressSpace = NULL;
	}

	if(m_PlayAgain != NULL)
	{
		delete m_PlayAgain;
		m_PlayAgain = NULL;
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

const char* GameOver::getName()
{

	return GAME_OVER_SCREEN_NAME;
}

void GameOver::update(double delta)
{

}

void GameOver::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BackGround1, (getWidth() - m_BackGround1->getSourceWidth()) / 2.0f , (getHeight() - m_BackGround1->getSourceHeight()) / 2.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_Ice_Hockey_Logo, 170, 15);
	m_PressSpace->paint();
	m_PlayAgain->paint();
}

void GameOver::keyUpEvent(int keyCode)
{
	if(keyCode == KEYCODE_UP_ARROW)
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
				break;
			}

		    case 2:
			{
				m_Select -=1;
				break;
			}
		}
	}

	switch(m_Select)
	{
	    case 1:
		{
		    m_PressSpace->mouseMovementEvent(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE-250);
			m_PlayAgain->setIsSelected(false);
			break;
		}
		case 2:
		{
		    m_PlayAgain->mouseMovementEvent(getWidth() / 2.0f +230, getHeight() * SPLASH_PRESS_SPACE_Y_PERCENTAGE-400);
			m_PressSpace->setIsSelected(false);
			break;
		}
	}



	if(keyCode == KEYCODE_SPACE)
	{
        if(m_PressSpace->getIsSelected() == true)
	    {
		    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
		}
        if(m_PlayAgain->getIsSelected() == true)
	    {
	        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
            Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	        game->reset();
		}
	}
}



void GameOver::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_PressSpace->mouseMovementEvent(positionX, positionY);
	m_PlayAgain->mouseMovementEvent(positionX, positionY);
}

void GameOver::mouseLeftClickUpEvent(float positionX, float positionY)
{
	if(m_PressSpace->getIsSelected() == true)
	{
	    m_PressSpace->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_PlayAgain->getIsSelected() == true)
	{
	    m_PlayAgain->mouseLeftClickUpEvent(positionX, positionY);
	}
}

void GameOver::buttonAction(UIButton * button) 
{
	if(button == m_PressSpace)
	{
	    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	}
	if(button == m_PlayAgain)
	{
	    ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
        Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
	    game->reset();
	}
}