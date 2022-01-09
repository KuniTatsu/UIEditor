#include "DxLib.h"
#include "../library/t2klib.h"
#include "../support/Support.h"
#include "game_main.h"
#include <time.h>
#include <list>
#include <map>
#include <algorithm>
#include"EditorManager.h"


bool init = false;
EditorManager* eManager = nullptr;

void gameMain(float deltatime) {

	if (!init) {

		eManager = new EditorManager();
		eManager->InitManager();

		init = true;
	}
	eManager->deltatime_ = deltatime;
	eManager->Update();
	eManager->Draw();



}

