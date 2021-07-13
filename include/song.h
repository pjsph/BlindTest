#pragma once

#include <string>

/**
* Représente une musique
*/
class Song {
public:
	/**
	* Constructeur
	* 
	* @param path Chemin du fichier mp3
	*/
	Song(std::string path);

	/**
	* Permet d'ouvrir le flux de lecture du fichier, nécessaire avant lecture
	*/
	Song& open();

	/**
	* Permet de lancer la lecture du fichier
	*/
	Song& play();

	/**
	* Permet d'ajouter l'attribut 'wait' lors de la lecture
	* L'attribut 'wait' permet de bloquer le programme lors de la lecture du fichier
	*/
	Song& wait(bool wait);

	/**
	* Permet de fermer le flux de lecture du fichier, nécessaire après lecture
	*/
	void close();

private:
	std::string m_path;
	std::string m_alias;
	bool m_opened = false;
	bool m_wait = false;
};