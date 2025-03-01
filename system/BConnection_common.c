/**
 * @file BConnection_common.c
 * @author Ambroz Bizjak <ambrop7@gmail.com>
 * 
 * @section LICENSE
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the author nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "BConnection.h"

int BListener_Init (BListener *o, BAddr addr, BReactor *reactor, void *user,
                    BListener_handler handler)
{
    return BListener_InitFrom(o, BLisCon_from_addr(addr), reactor, user, handler);
}

#ifndef BADVPN_USE_WINAPI
int BListener_InitUnix (BListener *o, const char *socket_path, BReactor *reactor, void *user,
                        BListener_handler handler)
{
    return BListener_InitFrom(o, BLisCon_from_unix(socket_path), reactor, user, handler);
}
#endif

int BConnector_Init (BConnector *o, BAddr addr, BReactor *reactor, void *user,
                     BConnector_handler handler, const char *sobindtodevice)
{
    return BConnector_InitFrom(o, BLisCon_from_addr(addr), reactor, user, handler, sobindtodevice);
}

#ifndef BADVPN_USE_WINAPI
int BConnector_InitUnix (BConnector *o, const char *socket_path, BReactor *reactor, void *user,
                         BConnector_handler handler, const char *sobindtodevice)
{
    return BConnector_InitFrom(o, BLisCon_from_unix(socket_path), reactor, user, handler, sobindtodevice);
}
#endif
