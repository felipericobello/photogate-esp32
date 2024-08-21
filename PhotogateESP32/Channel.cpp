#import "Channel.h"

Channel::Channel(int index, int pin) : _channelIndex(index), _pin(pin), _refLevel(2048), _up(true), _down(false)
{

}