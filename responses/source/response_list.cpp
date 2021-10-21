#include "../include/response_list.h"
#include <sstream>

ResponseListItem::ResponseListItem(int id_, string sender_, string subject_)
    : id(id_),
      sender(sender_),
      subject(subject_)
{
}

ostream &operator<<(ostream &s, ResponseListItem item)
{
    s << item.id << ":\n";
    s << "  From: " << item.sender << "\n";
    s << "  Subject: " << item.subject << "\n";
    return s;
}

ResponseList::ResponseList(const char buffer[BUFFER_LEN]) : Response(buffer)
{
    if (retcode != ResponseCode::OK)
        return;

    string b(buffer);

    auto token = nextListItem(buffer);
    while (token != "")
    {
        int id;
        from_chars(token.begin().base(), token.end().base(), id);
        auto t = nextToken(token.c_str(), 0);
        string sender = t.first;
        string subject = nextToken(token.c_str(), t.second + 1).first;

        _items.push_back(ResponseListItem(id, sender, subject));
        token = nextListItem(buffer);
    }
}

string ResponseList::nextListItem(const char *buffer)
{
    auto startIt = _lastItem ? _lastItem : buffer + 5;
    auto endIt = buffer + strlen(buffer);

    auto start = std::find(startIt, endIt, '(');
    if (start == endIt)
        return "";
    auto end = std::find(start + 1, endIt, ')');
    if (start == endIt)
        return "";

    _lastItem = end + 1;
    return string(start + 1, end);
}

const string ResponseList::message() const
{
    stringstream out;
    if (retcode == ResponseCode::OK)
    {
        out << "SUCCESS:\n";
        for (const auto &item : _items)
        {
            out << item;
        }
    }
    else
    {
        out << "ERROR: ";
        out << _errMessage;
    }
    return out.str();
}
