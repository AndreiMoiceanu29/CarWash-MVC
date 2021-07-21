#ifndef H_IOBSERVER
#define H_IOBSERVER
class IObserver
{
public:
	virtual void update(int) = 0;
	virtual ~IObserver(){};
	
};
#endif