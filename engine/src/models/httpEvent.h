#include <iostream>
#include <string>
#include <string_view>
#include <cstdint>
#include <vector>


class httpRequestEvent {

public:

    httpRequestEvent(std::string ip_addr, std::string http_method, std::string uri, std::string host,
                         std::string user_agent, std::string accept, std::string content_type,
                         size_t content_length = 0, std::string body = {}, std::vector<u_int64_t> timestamp)

                :   ip_addr(std::move(ip_addr)),
                    http_method(std::move(http_method)),
                    uri(std::move(uri)),
                    host(std::move(host)),
                    user_agent(std::move(user_agent)),
                    accept(std::move(accept)),
                    content_type(std::move(content_type)),
                    content_length(content_length),
                    body(std::move(body)),
                    timestamp(std::move(timestamp))
                    {}

    ~httpRequestEvent() = default;

    std::string getAddr() const {
        return ip_addr;
    }

    std::string getHttpMethod() const {
        return http_method;
    }

    std::string getUri() const {
        return uri;
    }
    
    std::string getHost() const {
        return host;
    }

    std::string getUserAgent() const {
        return user_agent;
    }

    std::string getAccept() const {
        return accept;
    }

    std::string getContentType() const {
        return content_type;
    }

    size_t getLength() const {
        return content_length;
    }

    std::string getBody() const {
        return body;
    }

    std::vector<u_int64_t> getTime() const {
        return timestamp;
    }

    //Оптимизировать геттеры от копирования

    private:
    
    std::string ip_addr;
    std::string http_method;
    std::string uri;
    std::string host;

    std::string user_agent;
    std::string accept;
    std::string content_type;
    size_t content_length;
    std::string body;
    uint64_t timestamp;



};

class httpResponseEvent {


    public:

    httpResponseEvent(std::string status , std::string server, std::string content_type, std::string content_length, std::string body, std::vector<u_int64_t> timestamp)
    :   status(std::move(status)), server(std::move(server)), content_type(std::move(content_type)), 
        content_length(std::move(content_length)), body(std::move(body)), timestamp(std::move(timestamp))
    {}

    ~httpResponseEvent() = default;

    std::string getStatus() const {
        return status;
    }

    std::string getServer() const {
        return server;
    }

    std::string getContentType() const {
        return content_type;
    }

    std::string getContentLength() const {
        return content_length;
    }
    
    std::string getBody() const {
        return body;
    }

    std::vector<u_int64_t> getTime() const {
        return timestamp;
    } 

    private:
    
    std::string status;
    std::string server;
    std::string content_type;
    std::string content_length;
    std::string body;
    uint64_t timestamp;

};


