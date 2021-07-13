#include <iostream>
#include <Windows.h>
#include "../include/song.h"

#pragma comment(lib, "Winmm.lib")

using namespace std;

int main() {

	cout << "Bienvenue sur le Blind Test !" << endl;

	int n;

	Song song("files/Jingle1.mp3");
	song.open().wait(true);

	cout << "Press 1 to start playing.\n";
	cin >> n;

	if (n == 1) {
		cout << "Playing...\n";
		song.play();
	}

	song.close();

	return 0;
}