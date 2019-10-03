#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;



struct sv
{
	int id;
	string name;
};

struct mh
{
	int id;
	string name;
};

struct sv_mh
{
	int id_sv, id_mh;
};

struct kq
{
	int id_mh, id_color;
};


sv get_sv(string in)
{
	sv x;

	return x;
}
mh get_mh(string in)
{

}
sv_mh get_sv_mh(string in)
{

}
void read_file(string path, int mode)
{
	string in;
	fstream input;
	input.open(path, ios::out);
	if (!input.is_open())
	{
		getline(input, in);
		switch (mode)
		{
		case 1:
		{

			break;
		}
		case 2:
		{

			break;
		}
		case 3:
		{

			break;
		}
		}
	}
	input.close();
}
void write_file();

void LapLich();



