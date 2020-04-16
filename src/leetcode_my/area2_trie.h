 /***************************************************************************
  *
  * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
  *
  **************************************************************************/



 /**
  * @file area2_trie.h
  * @author wangwei(com@baidu.com)
  * @date 2018/01/22 19:23:25
  * @brief
  *
  * 国际化新本行政区划数据，建tire树，sug-as自己召回；
  *
  **/
#ifndef  __AREA2_TRIE_H_
#define  __AREA2_TRIE_H_

#include <stdint.h>
#include <stdlib.h>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>


struct DistrictInfo
{
    uint32_t cid;
    uint32_t level;
    std::string level_name;
    DistrictInfo(uint32_t cid_, uint32_t level_, std::string level_name_):
        cid(cid_), level(level_), level_name(level_name_){}

};


class DistrictTrie
{
public:
    struct TrieNode {
        TrieNode(): leaf(false) {}
        std::string name;
        std::vector<DistrictInfo*> datas;
        std::map<uint16_t, TrieNode*> next;
        bool leaf;
    };

public:
    DistrictTrie();
    ~DistrictTrie();

    int Init();
    int Insert(const char *str, DistrictInfo* &district_info);

    //查询
    bool Search(const char *str, std::vector<DistrictInfo*> &res);
    std::vector<DistrictInfo*>* SearchAll(const char *str);

private:
    TrieNode *m_root;
};


#endif
