//
// Created by seedsone on 18-8-23.
//

#ifndef SERVERFLY_URL_HPP
#define SERVERFLY_URL_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace http
{
    class url : public string
    {
    public:
        url() = default;
    
        url(string _url);

    public:
        url parse(); // 解析url
        string get_scheme();
        string get_domain();
        string get_path();
        vector<string> get_params();

    public:
        static bool valid_url(string _url);
        
    private:
        string url_string; // 保存的原始url
        bool has_parse;    // 是否已经解析
        string scheme;     // 协议模式
        string domain;     // 域名
        string path;       // 路径
        vector<string> params;     // 参数
    };
}


#endif //SERVERFLY_URL_HPP
