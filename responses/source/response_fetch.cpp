#include "../include/response_fetch.h"

ResponseFetch::ResponseFetch(const char buffer[BUFFER_LEN]) : 
Response(buffer),
sender(nextToken(buffer)),
subject(nextToken(buffer)),
message(nextToken(buffer))
{ }
