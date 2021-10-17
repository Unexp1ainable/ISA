#include "../include/response_answer_auth.h"

ResponseAnswerAuth::ResponseAnswerAuth(const char buffer[BUFFER_LEN]) :
Response(buffer), 
answer(nextToken(buffer)),
token(nextToken(buffer))
{ }
