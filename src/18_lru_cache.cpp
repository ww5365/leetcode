/*
 * 18_lru_cache.cpp
 *
 *  Created on: Jun 26, 2018
 *      Author: wangwei69
 */

#include "test_main.h"
#include <list>
#include <map>
#include <iostream>

template<typename K, typename V>
class LRU{

    //可以使用模板类中类型，来定义新的数据类型；要开眼；
    using key_tractor_type = std::list<K>;
    using key_to_value_type = std::map<K, std::pair<V, typename key_tractor_type::iterator>>;

private:

    size_t _capcity; //cache容量
    key_to_value_type _key_value_map;
    key_tractor_type _key_tractor_list;

public:

    LRU() : _capcity(100){
        //默认构造函数
    }
    LRU(size_t cap) : _capcity(cap){

    }

    ~LRU(){
        //析构方式，合适吗？
        if (!_key_value_map.empty())
            _key_value_map.clear();
        if (!_key_tractor_list.empty())
            _key_tractor_list.clear();
    }


    /*
     * 获取cache中key对应的value；
     * 命中：  更新tactor,把最新被访问的节点放在list的头部；返回true；
     * 不命中： 返回false；
     */

    bool get(K key, V &val){

        typename key_to_value_type::iterator it = _key_value_map.find(key);

        if (it != _key_value_map.end()){
            val = it->second.first;
            _key_tractor_list.splice(_key_tractor_list.begin(), _key_tractor_list, it->second.second);
            return true;
        }
        return false;
    }

    /*
     * cache中添加数据；
     * 超过capcity的情况下，需要删除cache块；腾出空间来；
     */

    bool set(const K &key, const V &val){

        auto it = _key_value_map.find(key);

        if (it != _key_value_map.end()){//已经存在key
            it->second.first = val;//更新val值
            _key_tractor_list.splice(_key_tractor_list.begin(), _key_tractor_list, (it->second).second);//更新链表
            return true;
        }else{
            if (_key_value_map.size() >= _capcity){
                K del_key = _key_tractor_list.back();
                _key_value_map.erase(del_key);
                _key_tractor_list.pop_back();//删除最后一个元素

                std::cout << "need del key!" <<std::endl;
            }
            //插入头部list，插入元素到map

           typename key_tractor_type::iterator it_new =
                     _key_tractor_list.insert(_key_tractor_list.begin(), key);//list的插入操作

           _key_value_map.insert(std::make_pair(key, std::make_pair(val, it_new)));//map(元素都是pair)插入操作

           return true;
        }
    }

    /*
     * 获取cache块的key链的首尾迭代器(地址)；
     */

    bool get_key_list(typename key_tractor_type::iterator &head,
                      typename key_tractor_type::iterator &end)
    {
        if (!_key_tractor_list.empty()){
            head = _key_tractor_list.begin();
            end = _key_tractor_list.end();
            return true;
        }
        return false;
    }

};


void lru_cache_test(){

    LRU<std::string, uint32_t> lru(3); //cache的容量为3

    lru.set("wang", 10);
    lru.set("wei", 11);
    lru.set("ni", 12);
    lru.set("hao", 13);

    uint32_t val;
    if (lru.get("wei", val)){
        std::cout << "get the key wei val:" << val << std::endl;
    }else{
        std::cout << "not get the key wei val:" << std::endl;
    }

    if (lru.get("wang", val)){
        std::cout << "get the key wang val:" << val << std::endl;
    }else{
        std::cout << "not get the key wang val:" << std::endl;
    }

    std::list<std::string>::iterator key_head;
    std::list<std::string>::iterator key_end;
    if (lru.get_key_list(key_head, key_end)){
        for (;key_head != key_end; key_head ++){
            std::cout << "key:  " << *(key_head) << std::endl;
        }
    }

    if (lru.get_key_list(key_head, key_end)){
        for (;key_head != key_end; key_head ++){
            std::cout << "key:  " << *(key_head) << std::endl;
        }
    }

}

