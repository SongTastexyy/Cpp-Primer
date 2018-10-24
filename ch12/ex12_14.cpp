/***************************************************************************
*  @file       The code is for the exercises in C++ Primmer 5th Edition
*  @author     youyu Xu
*  @date       24  10 2018
*
*  @remark
***************************************************************************/
#include <iostream>
#include <memory>
#include <string>
using namespace std;
struct destination
{
	string ip;
	int port;
	destination(string _ip,int _port):ip(_ip),port(_port){}
};

struct connection
{
	string ip;
	int port;
	connection(string _ip,int _port):ip(_ip),port(_port){}
};

connection connect(destination* pDest)
{
	shared_ptr<connection> pCoon(new connection(pDest->ip, pDest->port));
	cout << "creating connection():" << pCoon.use_count() << endl;
	return *pCoon;
}

void disconnect(connection pConn)
{
	std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, end_connection);
	//shared_ptr<connection> p(&conn, [](connection *p) {disconnect(*p); })   //使用lambda代替
	cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
	destination dest("202.118.176.67", 3316);
	f(dest);
	system("pause");
}
