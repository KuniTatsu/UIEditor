#include "EditorManager.h"
#include "../support/Support.h"
#include"DxLib.h"
#include"Resources.h"
#include"Graphic.h"

EditorManager::EditorManager()
{
}

void EditorManager::InitManager()
{
	resources = new Resources();
}

bool EditorManager::CheckMousePointToRect(int MouseX, int MouseY, int RectLeftTopX, int RectWidth, int RectTopY, int RectHeight)
{
	if (MouseX >= RectLeftTopX && MouseX <= RectLeftTopX + RectWidth
		&& MouseY >= RectTopY && MouseY <= RectTopY + RectHeight) {
		return true;
	}
	return false;
}

void EditorManager::Update()
{
	main_sequence_.update(deltatime_);
	GetMousePoint(&mouseX, &mouseY);
	resources->Update();
}

void EditorManager::Draw()
{
	drawNowSeqName(nowSeq);
	//DrawBox(0, 0, 200, 200, -1, true);
	resources->draw();

	if (nowSeq == sequence::place) {
		DrawRotaGraph(mouseX, mouseY, 1, 0, nowSelectGraphic->gh, true);
	}
	if (setGraphic.empty())return;
	for (auto set : setGraphic) {
		DrawRotaGraph(set->pos.x, set->pos.y, 1, 0, set->gh, true);
	}
}

bool EditorManager::Seq_main(const float deltatime)
{
	for (auto g : resources->gObject) {
		if (t2k::Input::isMouseTrigger(t2k::Input::MOUSE_RELEASED_LEFT)) {
			if (CheckMousePointToRect(mouseX, mouseY, g->pos.x - (g->width / 2), g->width, g->pos.y - (g->height / 2), g->height)) {
				nowSelectGraphic = g;
				ChangeSequence(sequence::place);
				return true;
			}
		}
	}
	return true;
}

bool EditorManager::Seq_Place(const float deltatime)
{
	//ƒNƒŠƒbƒN‚µ‚½‚ç
	if (t2k::Input::isMouseTrigger(t2k::Input::MOUSE_RELEASED_LEFT)) {

		Graphic* newGraphic = new Graphic(t2k::Vector3(mouseX, mouseY, 0), nowSelectGraphic->gh, nowSelectGraphic->width, nowSelectGraphic->height);

		setGraphic.emplace_back(newGraphic);
		
		ChangeSequence(sequence::main);
		return true;
	}

	if (t2k::Input::isKeyDownTrigger(t2k::Input::KEYBORD_ESCAPE)) {
		ChangeSequence(sequence::main);
		return true;
	}
	return true;
}
void EditorManager::ChangeSequence(sequence seq)
{
	nowSeq = seq;
	if (seq == sequence::main) {
		main_sequence_.change(&EditorManager::Seq_main);
	}
	else if (seq == sequence::place) {
		main_sequence_.change(&EditorManager::Seq_Place);
	}


}

void EditorManager::drawNowSeqName(sequence seq)
{
	if (seq == sequence::main) {
		DrawStringEx(0, 700, -1, "MainSequence");
	}
	else if (seq == sequence::place) {
		DrawStringEx(0, 700, -1, "PlaceSequence");
	}
}
