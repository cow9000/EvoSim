//
//  PlayState.cpp
//  EvoSim
//
//  Created by Vawdrey, Derek on 1/26/18.
//  Copyright © 2018 Vawdrey, Derek. All rights reserved.
//

#include "Headers/SplashState.hpp"
#include "Headers/StateManager.hpp"
#include <iostream>

SplashState::SplashState(StateManager* stateManager){
	this->stateManager = stateManager;
	this->wait = true;
	this->timePassed = 0;

	logoTexture.loadFromFile("Assets/Logo.png");
}

SplashState::~SplashState(){
    
}

void SplashState::processState(sf::Event &event){
    if(event.type == sf::Event::MouseButtonPressed){
    	stateManager->setCurrentState(States::implementedStates::MAINMENU);
    }
}

void SplashState::updateState(){
    //If timePassed is creater than 255 + 60
	if(timePassed >= 255){
		stateManager->setCurrentState(States::implementedStates::MAINMENU);
	}

	if(splashClock.getElapsedTime().asSeconds() > 1 && wait){
		wait = false;
		splashClock.restart();
	}

}

void SplashState::renderState(sf::RenderTarget &renderWindow){

	//Draw logo
	sf::Sprite logo(logoTexture);
	logo.setOrigin(logo.getLocalBounds().width/2,logo.getLocalBounds().height/2);
	logo.setPosition(renderWindow.getSize().x/2,renderWindow.getSize().y/2);
	renderWindow.draw(logo);

	if(wait == false){
		sf::RectangleShape splashColor;
		splashColor.setSize(sf::Vector2f(renderWindow.getSize().x, renderWindow.getSize().y));

		timePassed = splashClock.getElapsedTime().asSeconds() * 350;

		sf::Color splashFade(0,0,0,timePassed);


		if(timePassed >= 255){
			splashFade.a = 255;
		}

		splashColor.setFillColor(splashFade);
		splashColor.setPosition(0,0);
		renderWindow.draw(splashColor);
	}
    
}
