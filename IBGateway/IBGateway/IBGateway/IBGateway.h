#ifndef IBGATEWAY_H
#define IBGATEWAY_H
#include"IBAPISPI.h"
class IBAPISPI;
class IBGateway //����Ҫ�̳�jsgateway
{
public:
	IBGateway();
	~IBGateway();

private:
	IBAPISPI *m_ibapispi=nullptr;
};
#endif