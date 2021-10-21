#pragma once

#include "response_base.h"
#include <iostream>

class ResponseListItem
{
public:
    ResponseListItem(int id_, string sender_, string subject_);
    const int id;
    const string sender;
    const string subject;
};
ostream &operator<<(ostream &s, ResponseListItem &item);


class ResponseList : public Response
{
public:
    ResponseList() = default;
    ResponseList(const char buffer[BUFFER_LEN]);
    const vector<ResponseListItem> items() const { return _items; };
    virtual const string message() const override;

private:
    string nextListItem(const char* buffer);
    const char* _lastItem = nullptr;
    vector<ResponseListItem> _items;
};
