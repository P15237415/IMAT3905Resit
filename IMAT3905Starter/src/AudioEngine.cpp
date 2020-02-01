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

void AudioEngine::createSound3D(SoundHandle* pppSound)
{
	FMOD_VECTOR position = { 3.0f, 4.0f, 2.0f };
	FMOD_VECTOR velocity = { 1.0f, 0.0f, 0.0f };
	m_pChannel->set3DAttributes(&position, &velocity);

	FMOD_VECTOR velocity;
	velocity.x = (position.x - lastPosition.x) * elapsed;
	velocity.y = (position.y - lastPosition.y) * elapsed;
	velocity.z = (position.z - lastPosition.z) * elapsed;

	FMOD_VECTOR direction = { 1.0f, 2.0f, 3.0f };
	m_pChannel->set3DConeOrientation(&direction);
	m_pChannel->set3DConeSettings(30.0f, 60.0f, 0.5f);

	m_pChannel->set3DMinMaxDistance(1.0f, 10000.0f);

	FMOD_VECTOR pos = { 3.0f, 4.0f, 2.0f };
	FMOD_VECTOR vel = { 1.0f, 0.0f, 0.0f };
	FMOD_VECTOR forward = { 1.0f, 0.0f, 0.0f };
	FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
	m_pSystem->set3DListenerAttributes(0, &pos, &vel, &forward, &up);

	result = m_pSystem->createSound(" ", FMOD_3D, 0, pppSound);
}

void AudioEngine::createReverb()
{
	FMOD_VECTOR position = { 10.0f, 0.0f, 0.0f };
	m_pReverb->set3DAttributes(&position, 10.0f, 20.0f);

	FMOD_REVERB_PROPERTIES properties = FMOD_PRESET_OFF;
	m_pSystem->setReverbProperties(&properties);

	result = m_pSystem->createReverb3D(&m_pReverb);
}

void AudioEngine::releaseReverb()
{
	m_pReverb->release();
}

void AudioEngine::update()
{
	m_pSystem->update();
}


