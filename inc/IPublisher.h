#ifndef H_IPUBLISHER
#define H_IPUBLISHER
#include "IObserver.h"
class IPublisher
{
public:
	virtual void attach(IObserver *) = 0;
	virtual void dettach(IObserver *) = 0;
	virtual void notify() = 0;
	virtual ~IPublisher(){};
	
};
#endif