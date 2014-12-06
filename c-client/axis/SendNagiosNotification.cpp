/*
 * This file was auto-generated by the Axis C++ Web Service Generator (WSDL2Ws)
 * This file contains Client Stub implementation for remote web service.
 */

#include "SendNotification.h"

#include <axis/server/AxisWrapperAPI.h>

using namespace std;

 SendNotification::SendNotification(const char* pchEndpointUri, AXIS_PROTOCOL_TYPE eProtocol)
:Stub(pchEndpointUri, eProtocol)
{
	m_pCall->setEndpointURI(pchEndpointUri);
}

SendNotification::SendNotification(xsd__string url)
:Stub(" ", APTHTTP)
{
	m_pCall->setEndpointURI(url);
}

SendNotification::~SendNotification()
{
}

xsd__string SendNotification::sendNotificationToNagios(xsd__string url, 
			xsd__string recipient, 
			xsd__string subject, 
			xsd__string message,
			xsd__string rwfile,
			xsd__boolean isService,
			xsd__string hostName,
			xsd__string objectName)
{
	xsd__string Ret;
	const char* pcCmplxFaultName;
	try
	{
		if (AXIS_SUCCESS != m_pCall->initialize(CPP_RPC_PROVIDER, NORMAL_CHANNEL)) 
			return Ret;
		m_pCall->setEndpointURI(url);
		m_pCall->setTransportProperty(SOAPACTION_HEADER , "");
		m_pCall->setSOAPVersion(SOAP_VER_1_1);
		m_pCall->setOperation("sendNagiosNotification", url);
		applyUserPreferences();
		m_pCall->addParameter((void*)&recipient, "memberName", XSD_STRING);
		m_pCall->addParameter((void*)&subject, "summary", XSD_STRING);
		m_pCall->addParameter((void*)&message, "message", XSD_STRING);
		m_pCall->addParameter((void*)&rwfile, "url", XSD_STRING);
		m_pCall->addParameter((void*)&isService, "isService", XSD_BOOLEAN);
		m_pCall->addParameter((void*)&hostName, "hostName", XSD_STRING);
		m_pCall->addParameter((void*)&objectName, "objectName", XSD_STRING);
		if (AXIS_SUCCESS == m_pCall->invoke())
		{
			if(AXIS_SUCCESS == m_pCall->checkMessage("sendNagiosNotificationResponse", url))
			{
				Ret = m_pCall->getElementAsString("sendNagiosNotificationReturn", 0);
			}
		}
		m_pCall->unInitialize();
		return Ret;
	}
	catch(AxisException& e)
	{
		int iExceptionCode = e.getExceptionCode();
		if(AXISC_NODE_VALUE_MISMATCH_EXCEPTION != iExceptionCode)
		{
			m_pCall->unInitialize();
			throw;
		}
		ISoapFault* pSoapFault = (ISoapFault*) m_pCall->checkFault("Fault",url );
		if(pSoapFault)
		{
			m_pCall->unInitialize();
			throw AxisClientException(pSoapFault);
		}
		else throw;
	}
}

int SendNotification::getFaultDetail(char** ppcDetail)
{
	return m_pCall->getFaultDetail(ppcDetail);
}

int main(int argc, char** argv) {

	SendNotification *sn;
	char *url, *recipient, *subject, *message, *rwfile, *hostName, *objectName;
	xsd__boolean isService;
	xsd__string result;

	if (argc < 8)
	{
		printf ("Usage: SendNagiosNotification url recipient subject message command_file [service|host] hostName objectName\n");
		return 0;
	}
	url = (char *)malloc (strlen(argv[1])+26);
	strcat (url, argv[1]);
	strcat (url, "/SendSOAPNotification.jws");
	recipient = argv[2];
	subject = argv[3];
	message = argv[4];
	rwfile = argv[5];
	if (strcmp(argv[6], "host")) {
		printf ("service is true\n");
		isService = true_;
	} else {
		printf ("service is false\n");
		isService = false_;
	}
	hostName = argv[7];
	objectName = argv[8];
	sn = new SendNotification(url);
	result = sn->sendNotificationToNagios (url, recipient, subject, message, rwfile, isService, hostName, objectName);
	printf ("%s", result);
	
	return 0;
}