#include "stdafx.h"
#include "dateserver.h"

	typedef boost::shared_ptr<tcp_connection> pointer;

	std::string inputString;
    const int max_length = 4;
    char data[10];

	pointer tcp_connection::create(boost::asio::io_service& io_service)
	{
		return pointer(new tcp_connection(io_service));
	}

	tcp::socket& tcp_connection::socket()
	{
		return socket_;
	}

	void tcp_connection::start()
	{
		boost::asio::async_read(socket_,boost::asio::buffer(data, max_length),
			boost::bind(&tcp_connection::handle_read, shared_from_this(),
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
	}

	void tcp_connection::handle_read(const boost::system::error_code& error,
		size_t bytes_transferred)
	{

		std::cout << "Client connected." << std::endl;
		if (!error)
		{
			if (!isalnum(data[2]))
				data[2] = '\0';
			else if (!isalnum(data[3]))
				data[3] = '\0';
			
            inputString = data;

            message_ = TimeZones::getDateAndTime(inputString);

			boost::system::error_code write_error;
			boost::asio::write(socket_, boost::asio::buffer(message_),
				boost::asio::transfer_all(), write_error);
			std::cout << "Write status: " << write_error << std::endl;
        }
		else
		{
            std::cout << "ERROR" << std::endl;
            delete this;
		}
	}

	tcp_connection::tcp_connection(boost::asio::io_service& io_service)
	: socket_(io_service)
	{
	}

	void tcp_connection::handle_write(const boost::system::error_code&,
					  size_t)
	{
	}