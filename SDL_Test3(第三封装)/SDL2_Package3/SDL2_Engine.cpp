#include "SDL2_Engine.h"
#include <SDL2/SDL_ttf.h>

using namespace WaterBox;
SDL2_Engine *SDL2_Engine::mEngine = nullptr;

SDL2_Engine *SDL2_Engine::get()
{
	if (mEngine == nullptr)
	{
		mEngine = new SDL2_Engine();
	}
	return mEngine;
}

void SDL2_Engine::StartEngine()
{
	mWindow = new SDL2_Window();
	SDL2_Renderer::setWindow(mWindow->getWindow());
	SDL2_Gui::get();
	SDL2_Renderer::get();
	while (true)
	{
		SDL2_Gui::get()->clear();
		mSceneManager->getScene()->init();
		while (true)
		{
			SDL_RenderClear(SDL2_Renderer::get()->getRenderer());
			mSceneManager->getScene()->update();
			SDL2_Gui::get()->update(nullptr);
			SDL_RenderPresent(SDL2_Renderer::get()->getRenderer());
		}
	}
}

SDL_Renderer * WaterBox::SDL2_Engine::getRenderer()
{
	SDL_Renderer *rend = SDL2_Renderer::get()->getRenderer();
	return rend;
}

SDL2_Engine::SDL2_Engine()
{
	//mPackage = new SDL2_Package();
	mSceneManager = new SDL2_SceneManager();
	TTF_Init();
	SDL2_FontSystem::get()->createFont("Data/Font/font.ttf", "SystemFont", 20);
}
