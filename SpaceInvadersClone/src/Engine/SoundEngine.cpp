#include <assert.h>
#include "SoundEngine.h"

SoundEngine* SoundEngine::m_s_Instance = nullptr;

SoundEngine::SoundEngine()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;

	// Load the sound into the buffers
	m_ShootBuffer.loadFromFile("Content/sound/shoot.ogg");
	m_PlayingExplodeBuffer.loadFromFile("Content/sound/playerexplode.ogg");
	m_InvaderExplodeBuffer.loadFromFile("Content/sound/invaderexplode.ogg");
	m_ClickBuffer.loadFromFile("Content/sound/click.ogg");

	// Associate the sounds with the buffers
	m_ShootSound.setBuffer(m_ShootBuffer);
	m_PlayerExplodeSound.setBuffer(m_PlayingExplodeBuffer);
	m_InvaderExplodeSound.setBuffer(m_InvaderExplodeBuffer);
	m_ClickSound.setBuffer(m_ClickBuffer);
}

void SoundEngine::playShoot()
{
	m_s_Instance->m_ShootSound.play();
}

void SoundEngine::playPlayerExplode()
{
	m_s_Instance->m_PlayerExplodeSound.play();
}

void SoundEngine::playInvaderExplode()
{
	m_s_Instance->m_InvaderExplodeSound.play();
}