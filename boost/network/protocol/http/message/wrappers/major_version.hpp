#ifndef BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_MAJOR_VERSION_HPP_20101120
#define BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_MAJOR_VERSION_HPP_20101120

// Copyright 2010 Dean Michael Berris. 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/utility/enable_if.hpp>
#include <boost/network/protocol/http/support/is_server.hpp>
#include <boost/cstdint.hpp>

namespace boost { namespace network { namespace http {

    template <class Tag>
    struct basic_request;

    template <class Tag>
    struct major_version_wrapper {
        basic_request<Tag> const & request;
        explicit major_version_wrapper(basic_request<Tag> const & request)
        : request(request) {}
        operator boost::uint8_t () {
            return request.http_version_major;
        }
    };

    template <class Tag>
    inline typename enable_if<is_server<Tag>, major_version_wrapper<Tag> >::type
    major_version(basic_request<Tag> const & request) {
        return major_version_wrapper<Tag>(request);
    }
    
} /* http */
    
} /* network */
    
} /* boost */

#endif /* BOOST_NETWORK_PROTOCOL_HTTP_MESSAGE_WRAPPERS_MAJOR_VERSION_HPP_20101120 */
