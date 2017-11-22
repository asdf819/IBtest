#ifndef IBGATEWAY_H
#define IBGATEWAY_H
#include "StdAfx.h"
#include "jsgateway.hpp"
#include "eventengine.h"
#include "IBAPISPI.h"

class IBAPISPI;
class IBGateway:JSGateway //����Ҫ�̳�jsgateway
{
public:
	IBGateway(EventEngine *eventengine);
	~IBGateway();

	void connect();																					//����
	void subscribe(const jsstructs::SubscribeReq& subscribeReq);									//����
	std::string sendOrder(const jsstructs::OrderReq & req);											//����
	void cancelOrder(const jsstructs::CancelOrderReq & req);										//����
	void qryAccount();																				//��ѯ�˻��ʽ�
	void qryPosition();																				//��ѯ�ֲ�
	void close();																					//�Ͽ�API
	void writeLog(const std::string &msg);
	void writeError(const std::string& msg, const int &errorID);
	void removeOrder(const std::string &orderID);                                                   //�Ƴ�order
	void updateOrder(const std::string &orderID, const jsstructs::CancelOrderReq &req);              //����order
	void initQuery();                                                                               //��ʼ����ѯѭ��
	void query();                                                                                   //��ѯ
	jsstructs::CancelOrderReq getOrder(const std::string &orderID);                                 //��ȡorder

	//IBAPI
	void reqHistoryData(const Contract& contract, const std::string& durationStr, const std::string&  barSizeSetting);


	//IBSPI
	void onHistoricalData(std::shared_ptr<Event_Bar>e);
private:



	IBAPISPI *m_ibapispi=nullptr;
};
#endif