#pragma once
#include <SFML/Audio.hpp>

class Sound
{
private:
	sf::Sound click;
	sf::Sound escape;
	sf::Sound shot;
	sf::Sound explosion;
	sf::SoundBuffer bufferExplosion;
	sf::SoundBuffer bufferClick;
	sf::SoundBuffer bufferEscape;
	sf::SoundBuffer bufferShot;
	sf::Music soundtrack;

	std::string soundtrackPath;
	std::string clickPath;
	std::string escapePath;
	std::string shotPath;
	std::string explosionPath;
	bool playing; //true if the sound is playing ( or volume level > 0 )
	int soundtrackVol; //soundtrack volume level
	int soundVol; //sound volume level

	Sound();
public:
	static Sound & instance()
	{
		static Sound a;
		return a;
	}

	~Sound() {};
	void playButtonSound();
	void stopButtonSound();
	void playSoundtrack();
	void pauseSoundtrack();
	void stopSoundtrack();
	void muteSoundtrack();
	bool isPlaying();
	void playShotSound();
	void playEscapeSound();
	void playExplosionSound();
};
