#include "Game.h"
#include <iostream>

// Initialize static member
Mix_Chunk *Game::keyPickupSound = NULL;
Mix_Music *Game::forestmusic = NULL;
Mix_Chunk *Game::lifelost = NULL;
Mix_Chunk *Game::winsound = NULL;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		// Initialize SDL_mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			std::cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << "\n";
			return false;
		}
		// Allocate 10 channels for mixing
		Mix_AllocateChannels(10);

		// Load the sound effect
		keyPickupSound = Mix_LoadWAV("Key Sound Effect.wav");
		if (keyPickupSound == NULL)
		{
			std::cout << "Failed to load key pickup sound! SDL_mixer Error: " << Mix_GetError() << "\n";
			return false;
		}

		forestmusic = Mix_LoadMUS("Medieval Music.mp3");
		if (forestmusic == NULL)
		{
			std::cout << "Failed to load forest music! SDL_mixer Error: " << Mix_GetError() << "\n";
			return false;
		}
		Mix_PlayMusic(forestmusic, -1);
		lifelost = Mix_LoadWAV("life lost sound.wav");
		if (lifelost == NULL)
		{
			std::cout << "Failed to load life lost sound! SDL_mixer Error: " << Mix_GetError() << "\n";
			return false;
		}

		winsound = Mix_LoadWAV("Win sound effect.wav");
		if (winsound == NULL)
		{
			std::cout << "Failed to load win sound! SDL_mixer Error: " << Mix_GetError() << "\n";
			return false;
		}

		// Set volume to half of maximum
		Mix_VolumeMusic(MIX_MAX_VOLUME / 2);

		std::cout << "SDL Init Success \n";

		Window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (Window != 0)
		{
			std::cout << "Window Init Success \n";

			Renderer = SDL_CreateRenderer(Window, -1, 0);
			if (Renderer != 0)
			{
				std::cout << "Renderer Init Success \n";

				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "Renderer Init Failed \n";
				return false;
			}
		}
		else
		{
			std::cout << "Window Init Failed \n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL Init Failed \n";
		return false;
	}
	std::cout << "Init Success\n";

	Running = true;

	if (!TheTextureManager::instance()->load_img("menubutton.png", "menubuttons", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("gameover.png", "gameover", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("win.png", "win", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("background_new.png", "back", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("walk 1.png", "w1", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("tileset.png", "tileset", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("enemy_walk.png", "enemy_walk", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("bullets.png", "bullet", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("hearts.png", "hearts", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("enemy_bullet.png", "e_bullet", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("menu.png", "menu_back", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("key.png", "key", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("keys.png", "keys", Renderer))
	{
		return false;
	}
	if (!TheTextureManager::instance()->load_img("black.png", "black", Renderer))
	{
		return false;
	}

	menu_bck = new menu();
	menu_bck->load(0, 0, 1366, 768, "menu_back");
	btn = new buttons();
	btn->load(200, 200, 195, 96, "menubuttons");
	exitbtn = new buttons();
	exitbtn->load(200, 300, 196, 92, "menubuttons", 0, 96);
	exitbg = new gamewin();
	exitbg->load(0, 0, 1366, 768, "menu_back");
	winning = new gamewin();
	winning->load(435, 240, 428, 338, "win");
	exitbg2 = new gamelose();
	exitbg2->load(0, 0, 1366, 768, "menu_back");
	lose = new gamelose();
	lose->load(380, 130, 623, 580, "gameover");
	
	return true;
}

void Game::render()
{
	SDL_RenderClear(Renderer);
	if (gameObject::state == 0)
	{
		for (int i = 0; i < gameObject::menu_objects.size(); i++)
		{
			gameObject::menu_objects[i]->draw(Renderer);
		}
	}
	else if (gameObject::state == 1)
	{
		back1->draw(Renderer);
		for (int i = 0; i < gameObject::player_objs.size(); i++)
		{
			gameObject::player_objs[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::objects.size(); i++)
		{
			gameObject::objects[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::enemy_objs.size(); i++)
		{
			gameObject::enemy_objs[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::foreground_objs.size(); i++)
		{
			gameObject::foreground_objs[i]->draw(Renderer);
		}
		for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
		{
			gameObject::Collectible_objects[i]->draw(Renderer);
		}
		// std::cout << gameObject::Collectible_objects.size() << "\n";
		// std::cout << gameObject::keys << "\n";
	}
	else if (gameObject::state == 2)
	{
		for (int i = 0; i < gameObject::lose_state_objs.size(); i++)
		{
			gameObject::lose_state_objs[i]->draw(Renderer);
		}
	}
	else if (gameObject::state == 3){
		for( int i{}; i < gameObject::win_state_objs.size(); i++){
			gameObject::win_state_objs[i]->draw(Renderer);
		}
	}
	SDL_RenderPresent(Renderer);
}

void Game::update()
{
	if (gameObject::state == 0)
	{
		for (int i = 0; i < gameObject::menu_objects.size(); i++)
		{
			gameObject::menu_objects[i]->update();
		}
	}
	else if (gameObject::state == 1)
	{
		if (gameObject::life <= 0)
		{
			gameObject::state = 2;
			gameObject::life = 3;
		}
		back1->update();
		for (int i = 0; i < gameObject::player_objs.size(); i++)
		{
			gameObject::player_objs[i]->update();
		}
		for (int i = 0; i < gameObject::objects.size(); i++)
		{
			gameObject::objects[i]->update();
		}
		for (int i = 0; i < gameObject::enemy_objs.size(); i++)
		{
			gameObject::enemy_objs[i]->update();
		}
		for (int i = 0; i < gameObject::foreground_objs.size(); i++)
		{
			gameObject::foreground_objs[i]->update();
		}
		for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
		{
			gameObject::Collectible_objects[i]->update();
		}
	}
	else if (gameObject::state == 2)
	{
		for (int i = 0; i < gameObject::player_objs.size(); i++)
		{
			delete gameObject::player_objs[i];
		}
		for (int i = 0; i < gameObject::objects.size(); i++)
		{
			delete gameObject::objects[i];
		}
		for (int i = 0; i < gameObject::enemy_objs.size(); i++)
		{
			delete gameObject::enemy_objs[i];
		}
		for (int i = 0; i < gameObject::foreground_objs.size(); i++)
		{
			delete gameObject::foreground_objs[i];
		}
		for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
		{
			delete gameObject::Collectible_objects[i];
		}
		gameObject::player_objs.clear();
		gameObject::objects.clear();
		gameObject::enemy_objs.clear();
		gameObject::foreground_objs.clear();
		gameObject::Collectible_objects.clear();

		for (int i = 0; i < gameObject::lose_state_objs.size(); i++)
		{
			gameObject::lose_state_objs[i]->update();
		}
	}
	else if (gameObject::state == 3)
	{
		for (int i = 0; i < gameObject::player_objs.size(); i++)
		{
			delete gameObject::player_objs[i];
		}
		for (int i = 0; i < gameObject::objects.size(); i++)
		{
			delete gameObject::objects[i];
		}
		for (int i = 0; i < gameObject::enemy_objs.size(); i++)
		{
			delete gameObject::enemy_objs[i];
		}
		for (int i = 0; i < gameObject::foreground_objs.size(); i++)
		{
			delete gameObject::foreground_objs[i];
		}
		for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
		{
			delete gameObject::Collectible_objects[i];
		}
		gameObject::player_objs.clear();
		gameObject::objects.clear();
		gameObject::enemy_objs.clear();
		gameObject::foreground_objs.clear();
		gameObject::Collectible_objects.clear();
		// game win objects update here
		for (int i = 0; i < gameObject::win_state_objs.size(); i++)
		{
			gameObject::win_state_objs[i]->update();
		}
	}
}
void Game::clean()
{
	std::cout << "cleaning game\n";

	for (int i = 0; i < gameObject::player_objs.size(); i++)
	{
		delete gameObject::player_objs[i];
	}
	for (int i = 0; i < gameObject::objects.size(); i++)
	{
		delete gameObject::objects[i];
	}
	for (int i = 0; i < gameObject::enemy_objs.size(); i++)
	{
		delete gameObject::enemy_objs[i];
	}
	for (int i = 0; i < gameObject::foreground_objs.size(); i++)
	{
		delete gameObject::foreground_objs[i];
	}
	for (int i = 0; i < gameObject::Collectible_objects.size(); i++)
	{
		delete gameObject::Collectible_objects[i];
	}
	for (int i = 0; i < gameObject::menu_objects.size(); i++)
	{
		delete gameObject::menu_objects[i];
	}
	for (int i = 0; i < gameObject::win_state_objs.size(); i++)
	{
		delete gameObject::win_state_objs[i];
	}
	for (int i = 0; i < gameObject::lose_state_objs.size(); i++)
	{
		delete gameObject::lose_state_objs[i];
	}
	gameObject::player_objs.clear();
	gameObject::objects.clear();
	gameObject::enemy_objs.clear();
	gameObject::foreground_objs.clear();
	gameObject::Collectible_objects.clear();
	gameObject::menu_objects.clear();
	gameObject::win_state_objs.clear();
	gameObject::lose_state_objs.clear();

	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}

void Game::handleEvents()
{

	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Running = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				Running = false;
				break;
			case SDLK_w:
				std::cout<<*char2<<"\n";
				break;
			case SDLK_p:
				gameObject::state = 3;
				break;
			case SDLK_RETURN:

				if (gameObject::state == 0)
				{
					play_init();
					gameObject::state = 1;
				}
				else if (gameObject::state == 1)
					gameObject::state = 2;
				else if (gameObject::state == 2)
					gameObject::state = 0;
				else if (gameObject::state == 3)
					gameObject::state = 0;
				// std::cout << gameObject::state << "\n";
				break;
			default:
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN: // Handle mouse button down events
			int x, y;
			SDL_GetMouseState(&x, &y);
			// for (auto &button : menu_objects)
			// {
				if (btn->isClicked(x, y))
				{
				std::cout<<x<<" "<<y<<"\n";
				if (gameObject::state == 0)
				{
					play_init();
					gameObject::state = 1;
				}
				}
				else if (exitbtn->isClicked(x, y))
				{
				std::cout<<x<<" "<<y<<"\n";
				if (gameObject::state == 0)
				{
					Running = false;
				}
				}
			// }
			break;
		default:
			break;
		}
	}
	TheInputHandler::Instance()->update();
}

Game *Game::instance()
{
	if (g_instance == nullptr)
	{
		g_instance = new Game();
		return g_instance;
	}
	return g_instance;
}

void Game::reset_game()
{
	delete Game::g_instance;
	Game::g_instance = nullptr;
	// Game::g_instance = new Game();
}

void Game::play_init()
{
	gameObject::life = 3;
	gameObject::keys = 0;
	gameObject::move_x = 30;
	gameObject::move_y = 198;

	char2 = new Character();
	back1 = new static_Objs();
	life = new lives();
	key_collected = new keys();
	key1 = new Collectibles();
	key2 = new Collectibles();
	key3 = new Collectibles();

	barrier = new Static_tree();
	barrier2 = new Static_tree();
	barrier3 = new Static_tree();
	barrier4 = new Static_tree();
	barrier5 = new Static_tree();
	barrier6 = new Static_tree();
	barrier7 = new Static_tree();
	barrier8 = new Static_tree();
	barrier9 = new Static_tree();
	barrier10 = new Static_tree();
	barrier11 = new Static_tree();
	barrier12 = new Static_tree();
	barrier13 = new Static_tree();
	barrier14 = new Static_tree();
	barrier15 = new Static_tree();
	barrier16 = new Static_tree();
	barrier17 = new Static_tree();
	barrier18 = new Static_tree();
	barrier19 = new Static_tree();
	barrier20 = new Static_tree();
	barrier21 = new Static_tree();
	barrier22 = new Static_tree();
	barrier23 = new Static_tree();
	barrier24 = new Static_tree();
	barrier25 = new Static_tree();

	win = new Collectibles();

	enemy1 = new Enemy_troll2();
	enemy2 = new Enemy_troll2();
	enemy3 = new Enemy_troll2();
	enemy4 = new Enemy_troll2();
	enemy5 = new Enemy_troll2();
	enemy6 = new Enemy_troll2();
	enemy7 = new Enemy_troll2();
	enemy8 = new Enemy_troll();
	enemy9 = new Enemy_troll();
	enemy10 = new Enemy_troll();
	enemy11 = new Enemy_troll();
	enemy12 = new Enemy_troll();
	enemy13 = new Enemy_troll();
	enemy14 = new Enemy_troll();
	enemy15 = new Enemy_troll();
	enemy16 = new Enemy_troll2();
	enemy17 = new Enemy_troll2();
	enemy18 = new Enemy_troll2();
	enemy19 = new Enemy_troll2();
	enemy20 = new Enemy_troll();
	enemy21 = new Enemy_troll();

	char2->load(30, 198, 32, 32, "w1");
	back1->load(0, 0, 2732, 1536, "back", 0, 0, true);
	life->load(0, 0, 105, 34, "hearts");
	key_collected->load(0, 768 - 25, 75, 25, "keys");
	key1->load(23, 1482, 25, 26, "key");
	key2->load(1044, 1120, 25, 26, "key");
	key3->load(2688, 1498, 25, 26, "key");

	barrier->load(272, 170, 10, 822, "");
	barrier2->load(0, 146, 368, 26, "");
	barrier3->load(0, 233, 200, 10, "");
	barrier4->load(191, 233, 24, 760, "");
	barrier5->load(115, 982, 98, 21, "");
	barrier6->load(126, 999, 21, 74, "");
	barrier7->load(143, 1053, 73, 163, "");
	barrier8->load(0, 1192, 143, 21, "");
	barrier9->load(268, 982, 88, 17, "");
	barrier10->load(329, 999, 22, 54, "");
	barrier11->load(257, 1053, 86, 169, "");
	barrier12->load(340, 1213, 640, 95, "");
	barrier13->load(340, 1364, 646, 200, "");
	barrier14->load(966, 1192, 678, 40, "");
	barrier15->load(966, 1513, 663, 23, "");
	barrier16->load(1593, 1140, 567, 184, "");
	barrier17->load(1593, 1364, 567, 172, "");
	barrier18->load(1596, 876, 808, 289, "");
	barrier19->load(2152, 495, 580, 337, "");
	barrier20->load(2444, 810, 288, 361, "");
	barrier21->load(1365, 263, 807, 570, "");
	barrier22->load(898, 480, 68, 763, "");
	barrier23->load(898, 165, 413, 334, "");
	barrier24->load(1260, 0, 893, 208, "");
	barrier25->load(2152, 0, 580, 36, "");

	win->load(2447, 32, 20, 20, "");

	enemy1->load(1085, 1368, 48, 48, "enemy_walk");
	enemy2->load(1205, 1368, 48, 48, "enemy_walk");
	enemy3->load(1366, 1368, 48, 48, "enemy_walk");
	enemy4->load(1490, 1368, 48, 48, "enemy_walk");
	enemy5->load(42, 1368, 48, 48, "enemy_walk");
	enemy6->load(2684, 1368, 48, 48, "enemy_walk");
	enemy7->load(2201, 1368, 48, 48, "enemy_walk");
	enemy8->load(2426, 1500, 48, 48, "enemy_walk");
	enemy9->load(191, 1239, 48, 48, "enemy_walk");
	enemy10->load(2426, 1239, 48, 48, "enemy_walk");
	enemy11->load(1366, 1137, 48, 48, "enemy_walk");
	enemy12->load(1366, 1014, 48, 48, "enemy_walk");
	enemy13->load(1163, 540, 48, 48, "enemy_walk");
	enemy14->load(1163, 660, 48, 48, "enemy_walk");
	enemy15->load(1163, 768, 48, 48, "enemy_walk");
	enemy16->load(1000, 918, 48, 48, "enemy_walk");
	enemy17->load(1100, 918, 48, 48, "enemy_walk");
	enemy18->load(2200, 230, 48, 48, "enemy_walk");
	enemy19->load(2300, 230, 48, 48, "enemy_walk");
	enemy20->load(2260, 50, 48, 48, "enemy_walk");
	enemy21->load(2260, 421, 48, 48, "enemy_walk");
}

Game *Game::g_instance = nullptr;