/**
 * Test: Passed
 */
#include "stdint.h"
#include "stm32f4_discovery_audio_codec.h"
#include "my_init.h"
#include "my_audio.h"

/**
 * Initializes the wave player
 */
void audio_init (uint32_t AudioFreq)
{
    uint8_t volume = 80;

    /* Initialize I2S interface */
    EVAL_AUDIO_SetAudioInterface(AUDIO_INTERFACE_I2S);

    /* Initialize the Audio codec and all related peripherals (I2S, I2C, IOExpander, IOs...) */
    EVAL_AUDIO_Init(OUTPUT_DEVICE_AUTO, volume, AudioFreq);  
}

/**
 * Deinitializes the wave player
 */
void audio_deinit (void) {
    EVAL_AUDIO_DeInit();
}

/**
 * Play wave file from internal Flash
 */
void audio_play (uint16_t* pBuffer, uint32_t FullSize, uint32_t StartAdd)
{
    EVAL_AUDIO_Play((uint16_t*)pBuffer, (FullSize - StartAdd));
}

/**
 * Pause or Resume a played wave
 */
void audio_pause_resume (uint8_t state)
{
    EVAL_AUDIO_PauseResume(state);
}

/**
 * Stop playing wave
 */
void audio_stop (void)
{
    EVAL_AUDIO_Stop(CODEC_PDWN_SW);
}

/**
 * Configure the volune
 */
void audio_volume_adjust (uint8_t volume)
{
    EVAL_AUDIO_VolumeCtl(volume);
}

/**
 * Calculates the remaining file size and new position of the pointer.
 */
void EVAL_AUDIO_TransferComplete_CallBack (uint32_t pBuffer, uint32_t Size)
{
    EVAL_AUDIO_Stop(CODEC_PDWN_HW);
    
    // Init other devices
    device_init();
}

/**
 * Get next data sample callback
 */
uint16_t EVAL_AUDIO_GetSampleCallBack (void)
{
    return 0;
}

/**
 * Basic management of the timeout situation.
 */
uint32_t Codec_TIMEOUT_UserCallback (void)
{
    return 0;
}
