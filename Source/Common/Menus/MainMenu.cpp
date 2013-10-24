//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the Main menu screen.
//


#include "MainMenu.h"
#include "../../Common/Constants/Constants.h";
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"



MainMenu::MainMenu() :
    m_SinglePlayer(NULL),
	m_TwoPlayers(NULL),
	m_Credits(NULL),
	m_Exit(NULL),
    m_BackGround1(NULL),
	m_MainMenu(NULL),
	m_Select(0)
{
    m_SinglePlayer = new UIButton(MAIN_MENU_SINGLE_PLAYER);
	m_TwoPlayers = new UIButton(MAIN_MENU_TWO_PLAYERS);
	m_Credits = new UIButton(MAIN_MENU_CREDITS);
	m_Exit = new UIButton(MAIN_MENU_EXIT);
	m_Select = 1;

    m_BackGround1 = new OpenGLTexture(SPLASH_BACKGROUND1);
    m_MainMenu = new OpenGLTexture(MAIN_MENU_LOGO);

	m_SinglePlayer->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.3);
	m_SinglePlayer->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.3);
	m_SinglePlayer->setListener(this);

    m_TwoPlayers->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.5);
	m_TwoPlayers->setListener(this);

    m_Credits->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.7);
	m_Credits->setListener(this);

    m_Exit->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.9);
	m_Exit->setListener(this);
}

MainMenu::~MainMenu()
{
	if(m_SinglePlayer != NULL)
	{
		delete m_SinglePlayer;
		m_SinglePlayer = NULL;
	}

	if(m_TwoPlayers != NULL)
	{
		delete m_TwoPlayers;
		m_TwoPlayers = NULL;
	}

	if(m_Credits != NULL)
	{
		delete m_Credits;
		m_Credits = NULL;
	}

	if(m_Exit != NULL)
	{
		delete m_Exit;
		m_Exit = NULL;
	}

	if(m_BackGround1 != NULL)
	{
		delete m_BackGround1;
		m_BackGround1 = NULL;
	}

	if(m_MainMenu != NULL)
	{
		delete m_MainMenu;
		m_MainMenu= NULL;
	}

}

const char* MainMenu::getName()
{

	return MAIN_MENU_SCREEN_NAME;
}

void MainMenu::update(double delta)
{

}

void MainMenu::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BackGround1, (getWidth() - m_BackGround1->getSourceWidth()) / 2.0f, (getHeight() - m_BackGround1->getSourceHeight()) / 2.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_MainMenu, 140, 15);
	m_SinglePlayer->paint();
	m_TwoPlayers->paint();
	m_Credits->paint();
	m_Exit->paint();
}

void MainMenu::keyUpEvent(int keyCode)
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
		    m_SinglePlayer->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.3);
			m_TwoPlayers->setIsSelected(false);
		    m_Credits->setIsSelected(false);
			m_Exit->setIsSelected(false);
			break;
		}
		case 2:
		{
			m_TwoPlayers->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.5);
			m_SinglePlayer->setIsSelected(false);
		    m_Credits->setIsSelected(false);
			m_Exit->setIsSelected(false);
			break;
		}
		case 3:
		{
			m_Credits->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.7);
		    m_SinglePlayer->setIsSelected(false);
		    m_TwoPlayers->setIsSelected(false);
			m_Exit->setIsSelected(false);
			break;
		}
		case 4:
		{
		    m_Exit->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.9);
			m_SinglePlayer->setIsSelected(false);
		    m_TwoPlayers->setIsSelected(false);
			m_Credits->setIsSelected(false);
			break;
		}


	}

	if(keyCode == KEYCODE_SPACE)
	{
        if(m_SinglePlayer->getIsSelected() == true)
	    {
		    ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
		    GAME_SETTINGS_PLAYERS_AMOUNT = 1;
		    ScreenManager::getInstance()->changeOnePlayers();
	    }

        if(m_TwoPlayers->getIsSelected() == true)
	    {
		    ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
		    GAME_SETTINGS_PLAYERS_AMOUNT = 2;
		    ScreenManager::getInstance()->changeTwoPlayers();
	    }

        if(m_Credits->getIsSelected() == true)
	    {
		    ScreenManager::getInstance()->switchScreen(CREDIT_SCREEN_NAME);
	    }

        if(m_Exit->getIsSelected() == true)
	    {
		    std::exit(0);
	    }	
    }

}

void MainMenu::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_SinglePlayer->mouseMovementEvent(positionX, positionY);
    m_TwoPlayers->mouseMovementEvent(positionX, positionY);
    m_Credits->mouseMovementEvent(positionX, positionY);
    m_Exit->mouseMovementEvent(positionX, positionY);
}

void MainMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
	if(m_SinglePlayer->getIsSelected() == true)
	{
	    m_SinglePlayer->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_TwoPlayers->getIsSelected() == true)
	{
	    m_TwoPlayers->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_Credits->getIsSelected() == true)
	{
	    m_Credits->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_Exit->getIsSelected() == true)
	{
	    m_Exit->mouseLeftClickUpEvent(positionX, positionY);
	}

}

void MainMenu::buttonAction(UIButton * button) 
{
	if(button == m_SinglePlayer)
	{
        ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
		GAME_SETTINGS_PLAYERS_AMOUNT = 1;
		ScreenManager::getInstance()->changeOnePlayers();
	}

	if(button == m_TwoPlayers)
	{
	    ScreenManager::getInstance()->switchScreen(GAME_SETTINGS_SCREEN_NAME);
		GAME_SETTINGS_PLAYERS_AMOUNT = 2;
		ScreenManager::getInstance()->changeTwoPlayers();
	}

	if(button == m_Credits)
	{
	    ScreenManager::getInstance()->switchScreen(CREDIT_SCREEN_NAME);
	}

	if(button == m_Exit)
	{
	    std::exit(0);
	}

}