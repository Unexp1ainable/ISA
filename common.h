#pragma once

constexpr int BUFFER_LEN = 1024;


enum class Command {
    FETCH,
    LIST,
    LOGOUT,
    LOGIN,
    SEND,
    REGISTER,
    UNKNOWN
};
