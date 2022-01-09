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
	//�傫���ύX���̃O���t�B�b�N
	std::vector<Graphic*>editGraphic;

	std::vector<Menu*>editMenu;

	//�ŏI����ʒu�̃O���t�B�b�N
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

	//�����V�[�N�G���X��ݒ�
	t2k::Sequence<EditorManager*> main_sequence_ =
		t2k::Sequence<EditorManager*>(this, &EditorManager::Seq_main);

	//�A�C�e�����g�p����V�[�N�G���X
	bool Seq_main(const float deltatime);

	bool Seq_Place(const float deltatime);

	bool Seq_Edit(const float deltatime);


	//�V�[�N�G���X�̗񋓑�
	enum class sequence {
		main,
		place,
		edit,
	};
	sequence nowSeq = sequence::main;

	void ChangeSequence(sequence seq);
	void drawNowSeqName(sequence seq);


};