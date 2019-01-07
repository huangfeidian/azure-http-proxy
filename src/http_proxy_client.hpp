﻿/*
 *    http_proxy_client.hpp:
 *
 *    Copyright (C) 2013-2015 limhiaoing <blog.poxiao.me> All Rights Reserved.
 *
 */

#ifndef AZURE_HTTP_PROXY_CLIENT_HPP
#define AZURE_HTTP_PROXY_CLIENT_HPP

#ifdef ASIO_STANDALONE
#include <asio.hpp>
using error_code = asio::error_code;

#else
#include <boost/asio.hpp>
namespace asio = boost::asio;
using error_code = boost::system::error_code;
#endif

#include <spdlog/spdlog.h>

namespace azure_proxy
{

	class http_proxy_client
	{
		asio::io_service& io_service;
		asio::ip::tcp::acceptor acceptor;
		std::shared_ptr<spdlog::logger> logger;
	public:

		http_proxy_client(asio::io_service& io_service);

		void run();
	private:
		void start_accept();
	};

} // namespace azure_proxy

#endif
