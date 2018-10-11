#ifndef MAP_H
#define MAP_H

#include "Continent.h"

#include <string>
#include <vector>

using namespace std;

class Map {

	public:
		vector<Continent> c;
		Map();
		Map(string, string, string, string, string);
		~Map();

		string getAuthor();
		string getImage();
		string getWrap();
		string getScroll();
		string getWarn();
		vector<Continent> getContinents();

		void setAuthor(string);
		void setImage(string);
		void setWrap(string);
		void setScroll(string);
		void setWarn(string);
		void addContinents(Continent);

	private:
		string author;
		string image;
		string wrap;
		string scroll;
		string warn;

};
#endif