#include "stdafx.h"
#include "dateserver.h"

using boost::asio::ip::tcp;

class tcp_connection
	: public boost::enable_shared_from_this<tcp_connection>
{

private: 
	tcp::socket socket_;
	std::string message_;

	tcp_connection(boost::asio::io_service& io_service); 

	void handle_write(const boost::system::error_code&,
		size_t);

public:
	typedef boost::shared_ptr<tcp_connection> pointer;

	void handle_read(const boost::system::error_code& error,
		size_t bytes_transferred);

	static pointer create(boost::asio::io_service& io_service);
	tcp::socket& socket();
	void start();

};