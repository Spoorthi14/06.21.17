#include "Emitter.h"
#include "Ice.h"
#include <utility>

#ifndef RFRAY_H_
#define RFRAY_H_
class RFRay : public Emitter, public Ice
{
	public:
	RFRay() : _distanceTravelled(0.0), _rfLoss(0.0), _freq(0.0)
	{
		_currentAmplitude = this->_emitterAmplitude;
	};
	void SetFreq(float);
	void Update(float,float,float); //Updates _distanceTravelled and _rfLoss, after changing the position
	//Variables
	std::pair<float,float> _currentPosition; //Current position in (x,z)
	float _currentAngle; //Current angle with respect to horizontal
	float _currentAmplitude; //Amplitude of wave derived from emitter.
	std::pair<float,float> _priorPosition; //Current position in (x,z)
	float _distanceTravelled; //Keeps track of the propagation distance
	float _rfLoss; //Amount of attenuation (apart from distance) accumulated
	float _freq; //Frequency of the ray
	//The path traveled in (x,z) coordinates by the ray, and each pair goes with one time-step.
	std::vector<std::pair<float,float> > _path;
};

#endif
