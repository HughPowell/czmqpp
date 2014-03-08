/*
 * Copyright (c) 2011-2013 libczmq++ developers (see AUTHORS)
 *
 * This file is part of libczmq++.
 *
 * libczmq++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) 
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <czmq++/socket.hpp>

#include <czmq++/assert.hpp>

namespace czmqpp {

socket::socket(context& ctx, int type)
{
    self_ = zsocket_new(ctx.self(), type);
}
socket::~socket()
{
    CZMQPP_ASSERT(self_);
    // context.self will delete the self_ for us.
}

void* socket::self()
{
    return self_;
}

int socket::bind(const std::string& address)
{
    return zsocket_bind(self_, address.c_str());
}
int socket::connect(const std::string& address)
{
    return zsocket_connect(self_, address.c_str());
}

} // namespace czmqpp

