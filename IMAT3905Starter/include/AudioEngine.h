#pragma once
#include "fmod.hpp"
#include "fmod_errors.h"
#include <stdio.h>
#include <cstdlib>
using namespace std;
typedef FMOD::Sound* SoundHandle;
class AudioEngine
{
public:
	AudioEngine();
	void initialize();
	void createSound(SoundHandle* ppSound, const char* pFile);
	void playSound(SoundHandle pSound, bool bLoop = false);
	void releaseSound(SoundHandle pSound);
	void createSound3D(SoundHandle* pppSound);
	void createReverb();
	void releaseReverb();
	void update();
private:
	FMOD::System *m_pSystem;
	FMOD::Channel *m_pChannel = nullptr;
	FMOD::Reverb3D *m_pReverb;
	FMOD_REVERB_PROPERTIES properties = FMOD_PRESET_CONCERTHALL;
	FMOD_RESULT result;
	unsigned int version;
	bool bLoop = false;
	void *extradriverdata = nullptr;
};

