#include "stdafx.h"
#include "dateserver.h"

using boost::asio::ip::tcp;

class tcp_server
{
public:
	tcp_server(boost::asio::io_service& io_service);
		

private:
	tcp::acceptor acceptor_;

	void start_accept();
	void handle_accept(tcp_connection::pointer new_connection,
		const boost::system::error_code& error);	
};