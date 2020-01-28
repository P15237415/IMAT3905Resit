#include "AudioEngine.h"

AudioEngine::AudioEngine()
{
}

void AudioEngine::initialize()
{
	result = FMOD::System_Create(&m_pSystem);
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s/n", result, FMOD_ErrorString(result));
		exit(-1);
	}

	result = m_pSystem->init(512, FMOD_INIT_NORMAL, extradriverdata);
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
}

void AudioEngine::createSound(SoundHandle* ppSound, const char* pFile)
{
	result = m_pSystem->createSound(pFile, FMOD_DEFAULT, 0, ppSound);
}

void AudioEngine::playSound(SoundHandle pSound, bool bLoop)
{
	if (!bLoop)
	{
		pSound->setMode(FMOD_LOOP_OFF);
	}
	else
	{
		pSound->setMode(FMOD_LOOP_NORMAL);
		pSound->setLoopCount(-1);
	}
	result = m_pSystem->playSound(pSound, 0, false, &m_pChannel);
}

void AudioEngine::releaseSound(SoundHandle pSound)
{
	pSound->release();
}

void AudioEngine::update()
{
	m_pSystem->update();
}


