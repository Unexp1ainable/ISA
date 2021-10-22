#pragma once

#include "response_base.h"
#include <iostream>

/**
 * @brief Item in the list of the response from the server on the list command
 * 
 */
class ResponseListItem
{
public:
    ResponseListItem(int id_, string sender_, string subject_);
    const int id;
    const string sender;
    const string subject;
};
ostream &operator<<(ostream &s, ResponseListItem &item);

/**
 * @brief Response from the server on the list command
 * 
 */
class ResponseList : public Response
{
public:
    ResponseList() = default;
    ResponseList(const char buffer[BUFFER_LEN]);

    // vector of messages
    const vector<ResponseListItem> items() const { return _items; };
    virtual const string message() const override;

private:
    /**
     * @brief Returns item representing one message from server response
     * 
     * @param buffer Server response
     * @return string Item from list
     */
    string nextListItem(const char* buffer);
    const char* _lastItem = nullptr;

    // vector of messages
    vector<ResponseListItem> _items;
};
