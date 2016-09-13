#define NUM_SOURCES 23 //quantidade de sons
#include <AL/al.h>
#include <AL/alut.h>
ALfloat listenerPos[]={0,0,4};
ALfloat listenerVel[]={0,0,0};
ALfloat listenerOri[]={0,0,1,0,1,0};
ALuint ALbuffer[NUM_SOURCES];
ALuint ALsource[NUM_SOURCES];
ALboolean al_bool;
ALsizei ALsize,ALfreq;
ALenum ALformat;
ALvoid *ALdata;

int currentFileLoading=0;

void ALinit(){//inicia o som
	alListenerfv(AL_POSITION,listenerPos);
	alListenerfv(AL_VELOCITY,listenerVel);
	alListenerfv(AL_ORIENTATION,listenerOri);
alGetError();
	alGenSources(1,&ALsource[currentFileLoading]);
}

void loadSound(char* path,float vol,ALboolean loop){//CARREGA O SOM
	alGenBuffers(1, &ALbuffer[currentFileLoading]);
		alutLoadWAVFile((ALbyte*)path,&ALformat,&ALdata,&ALsize,&ALfreq,&al_bool);
	alBufferData(ALbuffer[currentFileLoading],ALformat,ALdata,ALsize,ALfreq);
	alutUnloadWAV(ALformat,ALdata,ALsize,ALfreq);
	//alGetError();
	alGenSources(1,&ALsource[currentFileLoading]);
	//Sif(alGetError()!=AL_NO_ERROR) exit(0);
	alSourcef(ALsource[currentFileLoading],AL_PITCH,1.0f);
	alSourcef(ALsource[currentFileLoading],AL_GAIN,vol); //volume
	alSourcef(ALsource[currentFileLoading],AL_POSITION,listenerPos[0]);
	alSourcef(ALsource[currentFileLoading],AL_VELOCITY,listenerVel[0]);
	alSourcef(ALsource[currentFileLoading],AL_BUFFER,ALbuffer[currentFileLoading]);
	alSourcef(ALsource[currentFileLoading],AL_LOOPING,loop);//AL_BOOL
	if(currentFileLoading<NUM_SOURCES-1)
		currentFileLoading++;
}

void stopAllSounds(int n){
	for(int i=0;i<NUM_SOURCES;i++)
		if(i!=4&&i!=n) //sons q n param
			alSourceStop(ALsource[i]);
}

/*apaga aq bernard
loadSound("Sounds/Weapons/shot.wav",1.3,AL_FALSE); toca e para         //21
  loadSound("Sounds/parabains.wav",1.3,AL_TRUE);   loop           //22
//alSourcePlay(source[0]); TOCA MSUICA
//alSourcePause(source[0]); pausa MSUICA
//alSourceStop(source[0]); para MSUICA



ALint state;
    alGetSourcei(ALsource[n],AL_SOURCE_STATE,&state);
      if(AL_PLAYING != state)
        alSourcePlay(ALsource[3]);





*/ 	
