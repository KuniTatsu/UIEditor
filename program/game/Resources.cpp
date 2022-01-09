#include"Resources.h"
#include"DxLib.h"
#include"MenuWindow.h"
#include "../support/Support.h"
#include"EditorManager.h"
#include"Graphic.h"

extern EditorManager* eManager;

Resources::Resources()
{
	resourcesFrame = new Menu(0, 0, 300, 768, "graphics/WindowBase_02.png");
	black = GetColor(0, 0, 0);
	LoadResources();
}
int Resources::LoadGraphEx(std::string gh)
{

	auto it = ghmap.find(gh);
	if (it != ghmap.end()) {
		return ghmap[gh];
	}

	else {
		int loadgh = LoadGraph(gh.c_str());
		ghmap.insert(std::make_pair(gh, loadgh));
	}


	return ghmap[gh];
}

void Resources::Update()
{
	
	
}

void Resources::LoadResources()
{
	Frame_gh_1 = LoadGraphEx("graphics/WindowBase_01.png");
	Frame_gh_2 = LoadGraphEx("graphics/WindowBase_02.png");
	ghAll.emplace_back(Frame_gh_1);
	ghAll.emplace_back(Frame_gh_2);
	CreateGraphicObject();
}

void Resources::CreateGraphicObject()
{
	int x = 50;
	int y = 50;
	for (auto gh : ghAll) {
		Graphic* g = new Graphic(t2k::Vector3(x, y, 0), gh,48,48);
		gObject.emplace_back(g);
		y += 60;
	}
}

void Resources::draw()
{
	//フォルダを開くボタン
	DrawBox(900, 0, 1000, 100, -1, true);
	
	if (eManager->CheckMousePointToRect(eManager->mouseX, eManager->mouseY, resourcesFrame->menu_x, 
		resourcesFrame->menu_width, resourcesFrame->menu_y, resourcesFrame->menu_height)) {

		resourcesFrame->Menu_Draw();
		for (auto g : gObject) {
			DrawRotaGraph(g->pos.x, g->pos.y, 1, 0, g->gh, true);
		}
	}
	else {
		DrawBox(0, 0, 200, 50, -1, true);
		DrawStringEx(0, 25, black, "resources");
	}

}


