#pragma once
#include<string>
#include<unordered_map>
#include<vector>

class Graphic;
class Menu;

class Resources {

public:

	
	Resources();

	int Frame_gh_1=0;
	int Frame_gh_2=0;
	//���[�h�����n���h�����i�[����vector
	std::vector<int> ghAll;
	//�`��ʒu�ƃn���h�����܂Ƃ߂��I�u�W�F�N�g���i�[����vector
	std::vector<Graphic*> gObject;

	

	//��x�ǂݍ���gh��ۑ�����map
	std::unordered_map<std::string, int> ghmap;

	//gh��URL��map
	std::unordered_map<int, std::string> URLmap;

	int LoadGraphEx(std::string gh);

	std::string GetURL(int gh);

	void Update();
	void draw();

private:
	
	//�摜�̓ǂݍ���
	void LoadResources();
	//gh����Graphic�N���X�𐶐�����
	void CreateGraphicObject();
	
	

};