//
// Created by seedsone on 18-8-23.
//

#include "url.hpp"

http::url::url(string _url)
            : url_string(_url),
              scheme(string()),
              has_parse(false),
              domain(string()),
              path(string()),
              params(vector<string>())
{

}
/** ******************************************
 * 解析url，生成scheme,domain,path,params
 * @return http::url
 * ********************************************
 * */
http::url http::url::parse()
{
    has_parse = true;
    std::size_t pos = 0;
    pos = url_string.find(":");
    scheme.assign(url_string.substr(0, pos - 1));
    std::size_t pos_delimiter = 0;
    pos_delimiter = url_string.find("/");
    domain.assign(url_string.substr(pos, pos_delimiter));
    std::size_t pos_sigh = 0;
    pos_sigh = url_string.find("?");
    path.assign(url_string.substr(pos_delimiter, pos_sigh));
    
    string raw_params(url_string.substr(pos_sigh, url_string.length()));
    std::size_t params_length = raw_params.length();
    std::size_t params_inc = 0;
    for(std::size_t inc = 0; inc < params_length; )
    {
        if('&' == raw_params.at(inc))
        {
            params.push_back(raw_params.substr(params_inc,inc));
            params_inc = inc;
        }
        ++inc;
    }
    return *this;
}

/** *****************
 * 返回scheme
 * @return string
 * **/
string http::url::get_scheme()
{
    return scheme;
}

/** *****************
 * 返回domain
 * @return string
 * **/
string http::url::get_domain()
{
    return domain;
}

/** *****************
 * 返回path
 * @return string
 * **/
string http::url::get_path()
{
    return path;
}

/** *****************
 * 返回params
 * @return string
 * **/
vector<string> http::url::get_params()
{
    return params;
}
/** ********************
 * 验证url是否合法
 * @return bool
 * **/
bool http::url::valid_url(string _url)
{
    return false;
}
