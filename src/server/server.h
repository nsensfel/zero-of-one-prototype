#ifndef _ZoO_SERVER_SERVER_H_
#define _ZoO_SERVER_SERVER_H_

#include "../parameters/parameters_types.h"

#include "server_types.h"

int ZoO_server_cleanup_session (const char * session);

int ZoO_server_initialize
(
   struct ZoO_server [const restrict static 1],
   const char * session
);

int ZoO_server_main (const struct ZoO_parameters params);
int ZoO_server_finalize (struct ZoO_server [const restrict static 1]);

void ZoO_server_no_mq_termination (struct ZoO_server [const restrict static 1]);

int ZoO_server_receive_message
(
   struct ZoO_server [const restrict static 1],
   struct ZoO_server_message msg_buffer [const restrict static 1]
);

int ZoO_server_add_worker
(
   struct ZoO_server s [const restrict static 1],
   struct ZoO_server_message msg_buffer [const restrict static 1],
   struct ZoO_worker_parameters worker_params [const restrict static 1]
);

int ZoO_server_finalize_worker
(
   struct ZoO_server [const restrict static 1],
   struct ZoO_server_message msg_buffer [const restrict static 1]
);

#endif