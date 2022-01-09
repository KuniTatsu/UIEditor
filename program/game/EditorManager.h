#pragma once
#include"../library/t2klib.h"
#include<vector>

class Resources;
class Graphic;

class EditorManager {


public:

	Resources* resources = nullptr;

	EditorManager();

	float deltatime_;

	void InitManager();

	int mouseX = 0;
	int mouseY = 0;
	Graphic* nowSelectGraphic = nullptr;
	std::vector<Graphic*>setGraphic;


	bool CheckMousePointToRect(int MouseX, int MouseY, int RectLeftTopX, int RectWidth, int RectTopY, int RectHeight);

	void Update();
	void Draw();

private:

	//�����V�[�N�G���X��ݒ�
	t2k::Sequence<EditorManager*> main_sequence_ =
		t2k::Sequence<EditorManager*>(this, &EditorManager::Seq_main);

	//�A�C�e�����g�p����V�[�N�G���X
	bool Seq_main(const float deltatime);

	bool Seq_Place(const float deltatime);


	//�V�[�N�G���X�̗񋓑�
	enum class sequence {
		main,
		place,
	};
	sequence nowSeq = sequence::main;

	void ChangeSequence(sequence seq);
	void drawNowSeqName(sequence seq);


};