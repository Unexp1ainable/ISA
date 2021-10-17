#pragma once

#include "response_base.h"


class ResponseList : public Response
{
    class Item;

public:
    ResponseList(const char buffer[BUFFER_LEN]);
    const vector<Item> items() const { return _items; };

private:
    vector<Item> _items;
};

class ResponseList::Item
{
public:
    Item(int id, string sender, string subject);
    const int id;
    const string sender;
    const string subject;
};
