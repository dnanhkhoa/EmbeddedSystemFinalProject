#ifndef _AUDIO_SAMPLE_H
#define _AUDIO_SAMPLE_H

/* This is an audio file stored in the Flash memory as a constant table of 16-bit data.
 * The audio format should be WAV (raw / PCM) 16-bits, Stereo (sampling rate may be modified)
 */
extern const uint16_t AUDIO_SAMPLE[];
/* Audio file size and start address are defined here since the audio file is 
 * stored in Flash memory as a constant table of 16-bit data
 */
#define AUDIO_FILE_SIZE         990000
#define AUDIO_START_ADDRESS     58 /* Offset relative to audio file header size */

#endif
