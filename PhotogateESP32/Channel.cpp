#import "Channel.h"

Channel::Channel(int index, int pin) : _channelIndex(index), _pin(pin), _refLevel(REF_LEVEL), _up(true), _down(false)
{
}

unsigned int Channel::Read()
{
  return analogRead(_pin);
}