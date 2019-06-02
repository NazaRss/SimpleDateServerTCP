// task_test2_for_boost.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
#include "dateserver.h"

int main()
{
	using namespace std;

	cout << "Hello, poprobyute podklychutsa po telnet 127.0.0.1 13, spasibo! \n";

  try
  {
    boost::asio::io_service io_service;
    tcp_server server(io_service);
    io_service.run();
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << std::endl;
  }

  return 0;
}