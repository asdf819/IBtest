#include"StdAfx.h"
#include"IBGateway.h"
int main()
{
	EventEngine eventengine;
	//����gateway
	IBGateway ibgateway(&eventengine);

	ibgateway.connect();

	system("pause");

	ibgateway.close();
	return 0;
}