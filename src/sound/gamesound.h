#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <string>
#include <iostream>
#include <map>

struct Mix_Chunk;

class GameSound
{
	std::map<std::string, Mix_Chunk*> sfx;
	bool soundsystem_ok;
	
public:
	GameSound();
	~GameSound();
	
	void loadEffect(const std::string& effectName, const std::string& effectFileName);
	void playEffect(const std::string&, float, float);
	void playMusic(const std::string& name);
	void endMusic();
};

#endif

