#include "Sound.h"
#include <iostream>

Sound::Sound()
{
	soundtrackPath = "resources/soundtrack.wav";
	clickPath = "resources/button_click.wav";
	shotPath = "resources/shot.wav";
	escapePath = "resources/escape.wav";
	explosionPath = "resources/explosion.wav";



	soundtrackVol = 20;
	soundVol = 15;

	if ( !soundtrack.openFromFile(soundtrackPath) )
		std::cout << "Couldn't open soundtrack file!" << std::endl;

	soundtrack.setLoop(true);
	soundtrack.setVolume(soundtrackVol);

	bufferClick.loadFromFile(clickPath);
	bufferEscape.loadFromFile(escapePath);
	bufferShot.loadFromFile(shotPath);
	bufferExplosion.loadFromFile(explosionPath);

	click.setBuffer(bufferClick);
	escape.setBuffer(bufferEscape);
	shot.setBuffer(bufferShot);
	explosion.setBuffer(bufferExplosion);
	click.setLoop(false);
	escape.setLoop(false);
	shot.setLoop(false);
	explosion.setLoop(false);
	explosion.setVolume(soundVol-10);
	click.setVolume(soundVol);
	escape.setVolume(soundVol);
	shot.setVolume(soundVol);

	playing = false;

	soundtrack.play();
}

void Sound::playButtonSound()
{
	click.play();
}

void Sound::playExplosionSound() { explosion.play(); }

void Sound::stopButtonSound()
{
	click.stop();
}

void Sound::playSoundtrack()
{
	if (soundtrack.getVolume() == 0)
		soundtrack.setVolume(soundtrackVol);

	else
		soundtrack.play();

	playing = true;
}

void Sound::pauseSoundtrack()
{
	soundtrack.pause();
	playing = false;
}

void Sound::stopSoundtrack()
{
	soundtrack.stop();
	playing = false;
}

bool Sound::isPlaying()
{
	return playing;
}

void Sound::muteSoundtrack()
{
	soundtrack.setVolume(0);
	playing = false;
}

void Sound::playShotSound() { shot.play(); }

void Sound::playEscapeSound() { escape.play(); }
