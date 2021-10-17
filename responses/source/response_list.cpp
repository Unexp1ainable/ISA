#include "../include/response_list.h"

ResponseList::ResponseList(const char buffer[BUFFER_LEN]) :
Response(buffer)
{
    if (retcode != ResponseCode::OK)
        return;

    string b(buffer);

    while (b.find('(', 5) != string::npos) {
        auto token = nextToken(buffer);
        int id;
        from_chars(token.begin().base(), token.end().base(), id);
        _items.push_back(Item(id ,nextToken(buffer),nextToken(buffer)));
    }
}
