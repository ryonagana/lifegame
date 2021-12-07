#ifndef CALLBACK_CPP
#define CALLBACK_CPP

#include <iostream>

class myButtonCallBack{
public:
	myButtonCallBack(){}
	virtual ~myButtonCallBack(){}
	virtual void FuncCallBack(bool) = 0;
	virtual void resetAll(bool) = 0;
	virtual void restoreScreenBackup(bool) = 0;
	virtual void loadFunPatterns(bool) = 0;
	virtual void saveFile(bool) = 0;
	virtual void loadFile(bool) = 0;
	virtual void NextSpeed(bool) = 0;
	virtual void PrevSpeed(bool) = 0;
};

#endif
