#pragma once
#include<string>
#include<unordered_map>
#include<vector>

class Graphic;
class Menu;

class Resources {

public:

	Menu* resourcesFrame = nullptr;

	Resources();

	int Frame_gh_1=0;
	int Frame_gh_2=0;
	//���[�h�����n���h�����i�[����vector
	std::vector<int> ghAll;
	//�`��ʒu�ƃn���h�����܂Ƃ߂��I�u�W�F�N�g���i�[����vector
	std::vector<Graphic*> gObject;

	

	//��x�ǂݍ���gh��ۑ�����map
	std::unordered_map<std::string, int> ghmap;

	int LoadGraphEx(std::string gh);
	void Update();
	void draw();

private:
	int black;
	//�摜�̓ǂݍ���
	void LoadResources();
	//gh����Graphic�N���X�𐶐�����
	void CreateGraphicObject();
	
	

};