#pragma once
#include"../library/t2klib.h"

class Graphic {

public:

	Graphic(t2k::Vector3 Pos,int Gh,int Width,int Height);
	t2k::Vector3 pos = {};
	int gh=0;

	int width = 0;
	int height = 0;



};