#!/usr/bin/env python

## playbacktest.py
##
## This is an example of a simple sound playback script.
##
## The script opens an ALSA pcm for sound playback. Set
## various attributes of the device. It then reads data
## from stdin and writes it to the device.
##
## To test it out do the following:
## python recordtest.py out.raw # talk to the microphone
## python playbacktest.py out.raw


# Footnote: I'd normally use print instead of sys.std(out|err).write,
# but we're in the middle of the conversion between python 2 and 3
# and this code runs on both versions without conversion

import sys
import time
import getopt
import alsaaudio
import serial


def init_sound():
    card = 'default'
    # Open the device in playback mode. 
    out = alsaaudio.PCM(alsaaudio.PCM_PLAYBACK, card=card)
    # Set attributes: Mono, 44100 Hz, 16 bit little endian frames
    out.setchannels(1)
    out.setrate(44100)
    out.setformat(alsaaudio.PCM_FORMAT_S16_LE)
    # The period size controls the internal number of frames per period.
    # The significance of this parameter is documented in the ALSA api.
    out.setperiodsize(320)
    return out 

def play_file(name, out):
    # Read data from stdin
    f = open(name, 'rb')
    data = f.read(640)
    
    while data:
        out.write(data)
        data = f.read(320)
            
        
def init_arduino():
    return serial.Serial('/dev/ttyACM0', 9600)
   

son = init_sound()
ar = serial.Serial('/dev/ttyACM1', 9600)

tdv = 1
while True:
   D_V = int(ar.readline())
   if D_V != tdv:
    if D_V == 1:
     play_file('dram/PERC1.WAV',son)
    elif D_V == 2:
     play_file('dram/PERC2.WAV',son)
    elif D_V == 3:
     play_file('dram/PERC3.WAV',son)
    elif D_V == 4:
     play_file('dram/PERC4.WAV',son)
    elif D_V == 5:
     play_file('dram/PERC5.WAV',son)
    elif D_V == 6:
     play_file('dram/PERC6.WAV',son)
    elif D_V == 7:
     play_file('dram/PERC7.WAV',son)
    elif D_V == 8: 
     play_file('dram/SNARE1.WAV',son)
    elif D_V == 9: 
     play_file('dram/SNARE2.WAV',son)
    elif D_V == 10: 
     play_file('dram/SNARE3.WAV',son)
    else:
     play_file('dram/CLAVE.WAV',son)
   print D_V, '\n'
   tdv = D_V