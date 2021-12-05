#ifndef CALLBACK_CPP
#define CALLBACK_CPP

#include <iostream>

class myButtonCallBack{
public:
	myButtonCallBack(){}
	virtual ~myButtonCallBack(){}
	virtual void FuncCallBack(bool) = 0;
	virtual void resetAll(bool) = 0;
};

#endif
