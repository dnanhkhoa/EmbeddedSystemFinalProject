/**
 * Test: Passed
 */
#ifndef _MY_AUDIO_H
#define _MY_AUDIO_H

/*-------------------------------- Prototype --------------------------------*/
void audio_init(uint32_t AudioFreq);
void audio_deinit(void);
void audio_play(uint16_t* pBuffer, uint32_t FullSize, uint32_t StartAdd);
void audio_pause_resume(uint8_t state);
void audio_stop(void);
void audio_volume_adjust(uint8_t volume);

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size);
uint16_t EVAL_AUDIO_GetSampleCallBack(void);
uint32_t Codec_TIMEOUT_UserCallback(void);

#endif
