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
	//ロードしたハンドルを格納するvector
	std::vector<int> ghAll;
	//描画位置とハンドルをまとめたオブジェクトを格納するvector
	std::vector<Graphic*> gObject;

	

	//一度読み込んだghを保存するmap
	std::unordered_map<std::string, int> ghmap;

	//ghとURLのmap
	std::unordered_map<int, std::string> URLmap;

	int LoadGraphEx(std::string gh);

	std::string GetURL(int gh);

	void Update();
	void draw();

private:
	
	//画像の読み込み
	void LoadResources();
	//ghからGraphicクラスを生成する
	void CreateGraphicObject();
	
	

};