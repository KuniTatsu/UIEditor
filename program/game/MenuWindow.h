#pragma once
#include<DxLib.h>
#include<string>

class Menu {
public:

	Menu() {}
	virtual ~Menu() {}
	int menu_x, menu_y, menu_width, menu_height = 0;
	int menu_gh[9] = { 0 };
	bool menu_live;


	//new����Ƃ��ɑ傫����gh��path�������œn����������傫����path�𗼕�excel���炢���肽��
	Menu(int menu_window_x, int menu_window_y, int menu_window_width, int menu_window_height, std::string gh_path);

	void Menu_Draw();
};

class MenuWindow :public Menu {
public:

	typedef struct {
		int x;
		int y;
		std::string name;
		int menu_num;
	}MenuElement_t;

public:

	int SelectNum;				// ���݂̑I��ԍ�
	bool menuInit = false;

	int read_menu_x = 0;
	int read_menu_y = 0;
	int read_menu_element_num_ = 0;

	MenuElement_t* read_menu_element = nullptr;

	//bool menu_layer_flag_0 = false;
	bool secondMenuFlag = false;
	bool manageSelectFlag = true;//Read�֐���SelectNum�𓮂������ǂ��� true�Ȃ瓮����

	MenuWindow(int menu_window_x, int menu_window_y, int menu_window_width, int menu_window_height, std::string gh_path, MenuElement_t* elements, int elements_num);
	~MenuWindow();
	//���j���[���J��
	void Open();

	void Read();

	void All();

private:

	int String_Color_Black = 0;;
	int elements_num_;
	bool m_IsStartOpened;		// ESC�L�[�ŊJ����1�t���[����
	MenuElement_t* MenuElement = nullptr;

};

