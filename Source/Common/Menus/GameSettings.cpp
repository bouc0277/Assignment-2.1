//
// Student:	        Eric Bouchard
// Creation Date:   october 12, 2013
// Course number:   GAM1514
// Professor:       Bradley Flood
// Purpose:         This class manages the game settings screen.
//


#include "GameSettings.h"
#include "../../Common/Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../OpenGL/OpenGL.h"



GameSettings::GameSettings() :
    m_ScoreLimit(NULL),
	m_TimeLimit(NULL),
	m_Difficulty(NULL),
	m_Controls(NULL),
	m_StartGame(NULL),
    m_BackGround1(NULL),
	m_Numbers(NULL),
	m_ScoreInfoNumbers(NULL),
	m_DifficultyArray(NULL),
	m_ControlsArray1(NULL),
	m_ControlsArray2(NULL),
	m_GameSettings(NULL),
	m_Select(0),
	m_GoBack(NULL),
	m_ScoreLimitSelect(9),
	m_DiffucultySelect(0),
	m_TimeLimitSelect(1)
{



    m_ScoreLimit = new UIButton(GAME_SETTINGS_SCORE_LIMIT);
	m_TimeLimit = new UIButton(GAME_SETTINGS_TIME_LIMIT);
	m_Difficulty = new UIButton(GAME_SETTINGS_DIFFICULTY);


	m_Controls = new UIButton(GAME_SETTINGS_CONTROLS);


	m_StartGame = new UIButton(GAME_SETTINGS_START_GAME);
	m_GoBack = new UIButton("BackButton");

	m_Select = 1;
	m_ScoreLimitSelect = 9;
	m_TimeLimitSelect = 5;
	m_DiffucultySelect = 3;
	

    m_BackGround1 = new OpenGLTexture(SPLASH_BACKGROUND1);
    m_GameSettings = new OpenGLTexture("Game_Settings");


	
	m_ScoreLimit->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.3);
	//m_ScoreLimit->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.3);
	m_ScoreLimit->setListener(this);

    m_TimeLimit->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.45);
	m_TimeLimit->setListener(this);

    m_Difficulty->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.6);
	m_Difficulty->setListener(this);

    m_Controls->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.75);
	m_Controls->setListener(this);
	
    m_StartGame->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.9);
	m_StartGame->setListener(this);

	m_GoBack->setCenterPosition(getWidth() / 2.0f - 450, getHeight() * 0.1);
	m_GoBack->setListener(this);


	m_ScoreInfoNumbers = new OpenGLTexture *[GAME_SCORE_INFO_NUMBER_OF_NUMBERS];
    for(int i = 0; i < GAME_SCORE_INFO_NUMBER_OF_NUMBERS; i++)
    {
        m_ScoreInfoNumbers[i] = new OpenGLTexture(GAME_SCORE_INFO_NUMBERS[i]);
    }

	m_DifficultyArray = new OpenGLTexture *[3];
    for(int i = 0; i < 3; i++)
    {
        m_DifficultyArray[i] = new OpenGLTexture(GAME_DIFFICULTY_ARRAY[i]);
    }

	m_ControlsArray1 = new OpenGLTexture *[2];
    for(int i = 0; i < 2; i++)
    {
        m_ControlsArray1[i] = new OpenGLTexture(GAME_CONTROLS_SETTINGS1[i]);
    }

	m_ControlsArray2 = new OpenGLTexture *[2];
    for(int i = 0; i < 2; i++)
    {
        m_ControlsArray2[i] = new OpenGLTexture(GAME_CONTROLS_SETTINGS1[i]);
    }

}

GameSettings::~GameSettings()
{

	if(m_ScoreLimit != NULL)
	{
		delete m_ScoreLimit;
		m_ScoreLimit = NULL;
	}

	if(m_TimeLimit != NULL)
	{
		delete m_TimeLimit;
		m_TimeLimit = NULL;
	}

	if(m_Difficulty != NULL)
	{
		delete m_Difficulty;
		m_Difficulty = NULL;
	}

	if(m_Controls != NULL)
	{
		delete m_Controls;
		m_Controls = NULL;
	}

	if(m_StartGame != NULL)
	{
		delete m_StartGame;
		m_StartGame = NULL;
	}

	if(m_GoBack != NULL)
	{
		delete m_GoBack;
		m_GoBack = NULL;
	}

	if(m_BackGround1 != NULL)
	{
		delete m_BackGround1;
		m_BackGround1 = NULL;
	}

	if(m_Numbers != NULL)
	{
		delete m_Numbers;
		m_Numbers = NULL;
	}

	if(m_GameSettings != NULL)
	{
		delete m_GameSettings;
		m_GameSettings= NULL;
	}

	if(m_ScoreInfoNumbers != NULL)
    {
        for(int i = 0; i < GAME_SCORE_INFO_NUMBER_OF_NUMBERS; i++)
        {
            delete m_ScoreInfoNumbers[i];
            m_ScoreInfoNumbers[i] = NULL;
        }

        
        delete[] m_ScoreInfoNumbers;
        m_ScoreInfoNumbers = NULL;
    }

	if(m_DifficultyArray != NULL)
    {
        for(int i = 0; i < 3; i++)
        {
            delete m_DifficultyArray[i];
            m_DifficultyArray[i] = NULL;
        }

        
        delete[] m_DifficultyArray;
        m_DifficultyArray = NULL;

    }

	if(m_ControlsArray1 != NULL)
    {
        for(int i = 0; i < 2; i++)
        {
            delete m_ControlsArray1[i];
            m_ControlsArray1[i] = NULL;
        }

        
        delete[] m_ControlsArray1;
        m_ControlsArray1 = NULL;

    }

	if(m_ControlsArray2 != NULL)
    {
        for(int i = 0; i < 2; i++)
        {
            delete m_ControlsArray2[i];
            m_ControlsArray2[i] = NULL;
        }

        
        delete[] m_ControlsArray2;
        m_ControlsArray2 = NULL;

    }

}

const char* GameSettings::getName()
{

	return GAME_SETTINGS_SCREEN_NAME;
}

void GameSettings::update(double delta)
{
	if(GAME_MAX_SCORE <=9 && GAME_MAX_SCORE !=-1)
	{
		GAME_MAX_SCORE_INFINITY = GAME_MAX_SCORE; 
	}
	else if(GAME_MAX_SCORE == -1)
	{
		GAME_MAX_SCORE_INFINITY = 10; 
	}

	if(m_TimeLimitSelect <=9 && GAME_MAX_SCORE !=-1)
	{
		GAME_MAX_SCORE_INFINITY = GAME_MAX_SCORE; 
	}
	else if(GAME_MAX_SCORE == -1)
	{
		GAME_MAX_SCORE_INFINITY = 10; 
	}
}

void GameSettings::paint()
{
	OpenGLRenderer::getInstance()->drawTexture(m_BackGround1, (getWidth() - m_BackGround1->getSourceWidth()) / 2.0f, (getHeight() - m_BackGround1->getSourceHeight()) / 2.0f);
	OpenGLRenderer::getInstance()->drawTexture(m_GameSettings, 250, 75);
	OpenGLRenderer::getInstance()->drawTexture(m_Numbers, 800, 200);



	OpenGLTexture* score = m_ScoreInfoNumbers[GAME_MAX_SCORE_INFINITY];
    score->setAlpha(0.5);
    OpenGLRenderer::getInstance()->drawTexture(score, 725, 200);

	m_TimeLimitSelect = ((GAME_TIME_LIMIT_CONST/60)/60);

	OpenGLTexture* time = m_ScoreInfoNumbers[m_TimeLimitSelect];
    score->setAlpha(0.5);
    OpenGLRenderer::getInstance()->drawTexture(time, 725, 300);

	if(GAME_SETTINGS_PLAYERS_AMOUNT ==1)
	{
		OpenGLTexture* Diff = m_DifficultyArray[m_DiffucultySelect-1];
		score->setAlpha(0.5);
		OpenGLRenderer::getInstance()->drawTexture(Diff, 725, 400);
	}

    if(GAME_SETTINGS_PLAYERS_AMOUNT ==2)
	{
		OpenGLTexture* cont2 = m_ControlsArray2[GAME_CONTROLER_CONFIG2];
		score->setAlpha(0.5);
		OpenGLRenderer::getInstance()->drawTexture(cont2, 725, 400);
	}

	OpenGLTexture* cont1 = m_ControlsArray1[GAME_CONTROLER_CONFIG1];
    score->setAlpha(0.5);
    OpenGLRenderer::getInstance()->drawTexture(cont1, 725, 500);

	m_ScoreLimit->paint();
	m_TimeLimit->paint();
	m_Difficulty->paint();
	m_Controls->paint();
	m_StartGame->paint();
	m_GoBack->paint();
}

void GameSettings::keyUpEvent(int keyCode)
{

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
				m_Select +=1;
				break;
			}

		    case 5:
			{
				break;
			}
		}
		
	}

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
		    case 5:
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
		    m_ScoreLimit->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.3);
			m_TimeLimit->setIsSelected(false);
		    m_Difficulty->setIsSelected(false);
			m_Controls->setIsSelected(false);
            m_StartGame->setIsSelected(false);
			break;
		}
		case 2:
		{
			m_TimeLimit->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.45);
		    m_ScoreLimit->setIsSelected(false);
		    m_Difficulty->setIsSelected(false);
			m_Controls->setIsSelected(false);
			m_StartGame->setIsSelected(false);
			break;
		}
		case 3:
		{
			m_Difficulty->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.6);
		    m_ScoreLimit->setIsSelected(false);
		    m_TimeLimit->setIsSelected(false);
			m_Controls->setIsSelected(false);
			m_StartGame->setIsSelected(false);
			break;
		}
		case 4:
		{
		    m_Controls->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.75);
			m_ScoreLimit->setIsSelected(false);
		    m_TimeLimit->setIsSelected(false);
			m_Difficulty->setIsSelected(false);
			m_StartGame->setIsSelected(false);
			break;
		}
		case 5:
		{
		    m_StartGame->mouseMovementEvent(getWidth() / 2.0f, getHeight() * 0.9);
			m_ScoreLimit->setIsSelected(false);
		    m_TimeLimit->setIsSelected(false);
			m_Difficulty->setIsSelected(false);
			m_Controls->setIsSelected(false);
			break;
		}

	}

	if(keyCode == KEYCODE_SPACE)
	{
	    if(m_StartGame->getIsSelected() == true)
	    {
		   ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
		   
	    }
    }

	if(keyCode == KEYCODE_RIGHT_ARROW)
	{
        if(m_ScoreLimit->getIsSelected() == true)
	    {
			if(m_ScoreLimitSelect < 9 && m_ScoreLimitSelect !=-1)
			{
		        m_ScoreLimitSelect +=1;
			    GAME_MAX_SCORE = m_ScoreLimitSelect;
			}
			else if(m_ScoreLimitSelect == 9)
			{
		        m_ScoreLimitSelect =-1;
			    GAME_MAX_SCORE = m_ScoreLimitSelect;
			}
	    }

        if(m_TimeLimit->getIsSelected() == true)
	    {
			if(GAME_TIME_LIMIT < 18000 && GAME_TIME_LIMIT !=-1)
			{
		        GAME_TIME_LIMIT +=3600;
				GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
			}
			else if(GAME_TIME_LIMIT == 18000)
			{
		        GAME_TIME_LIMIT =-1;
                GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
			}			
	    }

		if(m_Difficulty->getIsSelected() == true && GAME_SETTINGS_PLAYERS_AMOUNT == 1)
	    {
		    if(GAME_PADDLE_ACCELERATION < 75)
			{
		        GAME_PADDLE_ACCELERATION += 25.0f;
			    GAME_PADDLE_MAX_SPEED += 100.0f;
				m_DiffucultySelect+=1;
				GAME_BALL_DEFAULT_SPEED+=150;
			}
		}

		if(m_Difficulty->getIsSelected() == true && GAME_SETTINGS_PLAYERS_AMOUNT == 2)
	    {
			if(GAME_CONTROLER_CONFIG2 < 1  && GAME_CONTROLER_CONFIG1 != 1)
			{
		        GAME_CONTROLER_CONFIG2 += 1;
			}
		}

		if(m_Controls->getIsSelected() == true)
	    {
		    if(GAME_CONTROLER_CONFIG1 < 1 && GAME_CONTROLER_CONFIG2 != 1)
			{
		        GAME_CONTROLER_CONFIG1 += 1;
			}
		}
    }

	if(keyCode == KEYCODE_LEFT_ARROW)
	{
        if(m_ScoreLimit->getIsSelected() == true)
	    {
			if(m_ScoreLimitSelect > 1)
			{
		        m_ScoreLimitSelect -=1;
			    GAME_MAX_SCORE = m_ScoreLimitSelect;
			}
	    }

		if(m_ScoreLimit->getIsSelected() == true)
		{
			if(m_ScoreLimitSelect == -1)
			{
				m_ScoreLimitSelect =9;
				GAME_MAX_SCORE = m_ScoreLimitSelect;
			}
		}

		if(m_TimeLimit->getIsSelected() == true)
		{
			if(GAME_TIME_LIMIT > 3600)
			{
				GAME_TIME_LIMIT -=3600;
                GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
			}
		}

		if(m_TimeLimit->getIsSelected() == true)
		{
			if(GAME_TIME_LIMIT == -1)
			{
				GAME_TIME_LIMIT =18000;
                GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
			}
		}

		if(m_Difficulty->getIsSelected() == true && GAME_SETTINGS_PLAYERS_AMOUNT == 1)
		{
			if(GAME_PADDLE_ACCELERATION > 25)
			{
				GAME_PADDLE_ACCELERATION -= 25.0f;
				GAME_PADDLE_MAX_SPEED -= 100.0f;
				m_DiffucultySelect-=1;
				GAME_BALL_DEFAULT_SPEED-=150;
			}
		}

		if(m_Difficulty->getIsSelected() == true && GAME_SETTINGS_PLAYERS_AMOUNT == 2)
		{
			if(GAME_CONTROLER_CONFIG2 > 0)
			{
				GAME_CONTROLER_CONFIG2 -= 1;
			}
		}

		if(m_Controls->getIsSelected() == true)
		{
			if(GAME_CONTROLER_CONFIG1 > 0)
			{
				GAME_CONTROLER_CONFIG1 -= 1;
			}
		}

    }

}

void GameSettings::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
	m_ScoreLimit->mouseMovementEvent(positionX, positionY);
    m_TimeLimit->mouseMovementEvent(positionX, positionY);
    m_Difficulty->mouseMovementEvent(positionX, positionY);
    m_Controls->mouseMovementEvent(positionX, positionY);
    m_StartGame->mouseMovementEvent(positionX, positionY);
    m_GoBack->mouseMovementEvent(positionX, positionY);
}

void GameSettings::mouseLeftClickUpEvent(float positionX, float positionY)
{
	if(m_ScoreLimit->getIsSelected() == true)
	{
	    m_ScoreLimit->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_TimeLimit->getIsSelected() == true)
	{
	    m_TimeLimit->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_Difficulty->getIsSelected() == true)
	{
	    m_Difficulty->mouseLeftClickUpEvent(positionX, positionY);
	}

    if(m_Controls->getIsSelected() == true)
	{
	    m_Controls->mouseLeftClickUpEvent(positionX, positionY);
	}

	if(m_StartGame->getIsSelected() == true)
	{
	    m_StartGame->mouseLeftClickUpEvent(positionX, positionY);
	}

    if(m_GoBack->getIsSelected() == true)
	{
	    m_GoBack->mouseLeftClickUpEvent(positionX, positionY);
	}

}

void GameSettings::buttonAction(UIButton * button) 
{
	if(button == m_ScoreLimit)
	{
		if(m_ScoreLimitSelect < 9 && m_ScoreLimitSelect !=-1)
		{
		    m_ScoreLimitSelect +=1;
			GAME_MAX_SCORE = m_ScoreLimitSelect;
		}
		else if(m_ScoreLimitSelect == 9)
		{
		    m_ScoreLimitSelect =-1;
			GAME_MAX_SCORE = m_ScoreLimitSelect;
		}
		else if(m_ScoreLimitSelect == -1)
		{
		    m_ScoreLimitSelect = 1;
			GAME_MAX_SCORE = m_ScoreLimitSelect;
		}
	}

	if(button == m_TimeLimit)
	{
		if(GAME_TIME_LIMIT < 18000 && GAME_TIME_LIMIT !=-1)
		{
		    GAME_TIME_LIMIT +=3600;
            GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
		}
		else if(GAME_TIME_LIMIT == 18000)
		{
		    GAME_TIME_LIMIT =-1;
            GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
		}	
		else if(GAME_TIME_LIMIT == -1)
		{
		    GAME_TIME_LIMIT =3600;
            GAME_TIME_LIMIT_CONST = GAME_TIME_LIMIT;
		}	
	}

	if(button == m_Difficulty)
	{
	    if(m_Difficulty->getIsSelected() == true && GAME_SETTINGS_PLAYERS_AMOUNT == 1)
	    {
		    if(GAME_PADDLE_ACCELERATION > 25)
			{
		        GAME_PADDLE_ACCELERATION -= 25.0f;
			    GAME_PADDLE_MAX_SPEED -= 100.0f;
				m_DiffucultySelect-=1;
				GAME_BALL_DEFAULT_SPEED-=150;
			}
			else if(GAME_PADDLE_ACCELERATION == 25)
			{
		        GAME_PADDLE_ACCELERATION = 75.0f;
			    GAME_PADDLE_MAX_SPEED = 300.0f;
				m_DiffucultySelect=3;
				GAME_BALL_DEFAULT_SPEED=450;
			}
		}

		if(m_Difficulty->getIsSelected() == true && GAME_SETTINGS_PLAYERS_AMOUNT == 2)
	    {
		    if(GAME_CONTROLER_CONFIG2 == 0 && GAME_CONTROLER_CONFIG1 != 1)
			{
		        GAME_CONTROLER_CONFIG2 += 1;
			}
			else if(GAME_CONTROLER_CONFIG2 == 1 && GAME_CONTROLER_CONFIG1 != 1)
			{
		        GAME_CONTROLER_CONFIG2 = 0;
			}
		}
	}

	if(button == m_Controls)
	{

	    if(m_Controls->getIsSelected() == true)
	    {
		    if(GAME_CONTROLER_CONFIG1 == 0 && GAME_CONTROLER_CONFIG2 != 1)
			{
		        GAME_CONTROLER_CONFIG1 += 1;
			}
			else if(GAME_CONTROLER_CONFIG1 == 1 && GAME_CONTROLER_CONFIG2 != 1)
			{
		        GAME_CONTROLER_CONFIG1 = 0;
			}
		}
	}

    if(button == m_StartGame)
	{
	    ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
	}

	if(button == m_GoBack)
	{
	    ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
	    GAME_SETTINGS_PLAYERS_AMOUNT = 1;
	}
}


void GameSettings::twoPlayersChange()
{
	m_Controls = new UIButton("Controlsp1");
	m_Controls->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.75);
	m_Controls->setListener(this);

	m_Difficulty = new UIButton("Controlsp2");
	m_Difficulty->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.6);
	m_Difficulty->setListener(this);
}

void GameSettings::onePlayersChange()
{
	m_Controls = new UIButton(GAME_SETTINGS_CONTROLS);
	m_Controls->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.75);
	m_Controls->setListener(this);

	m_Difficulty = new UIButton(GAME_SETTINGS_DIFFICULTY);
	m_Difficulty->setCenterPosition(getWidth() / 2.0f, getHeight() * 0.6);
	m_Difficulty->setListener(this);
}

short GameSettings::getTimeLimitSelect()
{

	return m_TimeLimitSelect;
}