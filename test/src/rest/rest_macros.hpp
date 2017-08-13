#pragma once

#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Infos.hpp>

#define INITIALIZE() cURLpp::initialize();

#define TERMINATE() cURLpp::terminate();

#define GET(url, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

#define PUT(url, in, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt(new curlpp::options::CustomRequest("PUT"));\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    request.setOpt(new curlpp::options::PostFields(in));\
    request.setOpt(new curlpp::options::PostFieldSize(in.length()));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

#define POST(url, in, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    request.setOpt(new curlpp::options::PostFields(in));\
    request.setOpt(new curlpp::options::PostFieldSize(in.length()));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}

#define DELETE(url, api_key, out, code)\
{\
    curlpp::Cleanup cleanup;\
    curlpp::Easy request;\
    request.setOpt(new curlpp::options::CustomRequest("DELETE"));\
    request.setOpt<curlpp::options::Url>(url);\
    std::list<std::string> header;\
    header.push_back("Content-Type: application/json");\
    header.push_back("api_key: " + api_key);\
    request.setOpt(new curlpp::options::HttpHeader(header));\
    std::ostringstream os;\
    curlpp::options::WriteStream ws(&os);\
    request.setOpt(ws);\
    request.perform();\
    out.assign(os.str());\
    code = curlpp::infos::ResponseCode::get(request);\
}
