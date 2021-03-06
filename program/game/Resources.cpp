#include"Resources.h"
#include"DxLib.h"
#include"MenuWindow.h"
#include "../support/Support.h"
#include"EditorManager.h"
#include"Graphic.h"

extern EditorManager* eManager;

Resources::Resources()
{
	LoadResources();
}
int Resources::LoadGraphEx(std::string gh)
{
	//**int型のghを登録,返す処理
	auto it = ghmap.find(gh);
	if (it != ghmap.end()) {
		return ghmap[gh];
	}

	else {
		int loadgh = LoadGraph(gh.c_str());
		ghmap.insert(std::make_pair(gh, loadgh));

		//**逆検索のmap登録
		URLmap.insert(std::make_pair(loadgh, gh));
		//**
	}
	return ghmap[gh];
	//**

}

std::string Resources::GetURL(int gh)
{
	auto it = URLmap.find(gh);
	if (it != URLmap.end()) {
		return URLmap[gh];
	}
	else {
		return "存在しないよ";
	}
	return "エラーだよ";
}

void Resources::Update()
{
}

void Resources::LoadResources()
{
	//リソース画像は個別に読み込む
	Frame_gh_1 = LoadGraphEx("graphics/WindowBase_01.png");
	Frame_gh_2 = LoadGraphEx("graphics/WindowBase_02.png");
	//必ずghAllvectorに格納する
	ghAll.emplace_back(Frame_gh_1);
	ghAll.emplace_back(Frame_gh_2);
	CreateGraphicObject();
}

void Resources::CreateGraphicObject()
{
	int x = 50;
	int y = 50;
	for (auto gh : ghAll) {
		Graphic* g = new Graphic(t2k::Vector3(x, y, 0), gh, 48, 48);
		gObject.emplace_back(g);
		y += 60;
	}
}

void Resources::draw()
{

}


