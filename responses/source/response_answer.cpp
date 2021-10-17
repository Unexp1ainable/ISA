#include "../include/response_answer.h"

ResponseAnswer::ResponseAnswer(const char buffer[BUFFER_LEN]) : 
Response(buffer), 
answer(nextToken(buffer))
{ }
