#pragma once
#include"../library/t2klib.h"
#include<vector>

class Resources;
class Graphic;
class Menu;

class EditorManager {


public:

	Resources* resources = nullptr;

	EditorManager();

	float deltatime_;

	void InitManager();

	int mouseX = 0;
	int mouseY = 0;
	Graphic* nowSelectGraphic = nullptr;
	//大きさ変更中のグラフィック
	std::vector<Graphic*>editGraphic;

	std::vector<Menu*>editMenu;

	//最終決定位置のグラフィック
	std::vector<Menu*>setGraphic;


	bool CheckMousePointToRect(int MouseX, int MouseY, int RectLeftTopX, int RectWidth, int RectTopY, int RectHeight);

	void Update();
	void Draw();

private:
	Menu* resourcesFrame = nullptr;
	Graphic* edit = nullptr;
	Menu* makeMenu = nullptr;

	int editWidth = 48;
	int editHeight = 48;

	int black;

	//初期シークエンスを設定
	t2k::Sequence<EditorManager*> main_sequence_ =
		t2k::Sequence<EditorManager*>(this, &EditorManager::Seq_main);

	//アイテムを使用するシークエンス
	bool Seq_main(const float deltatime);

	bool Seq_Place(const float deltatime);

	bool Seq_Edit(const float deltatime);


	//シークエンスの列挙体
	enum class sequence {
		main,
		place,
		edit,
	};
	sequence nowSeq = sequence::main;

	void ChangeSequence(sequence seq);
	void drawNowSeqName(sequence seq);


};