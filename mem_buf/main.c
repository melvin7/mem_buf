//
//  main.c
//
//  Created by xichen on 2013-1-8.
//  Copyright (c) 2013 ccteam. All rights reserved.
//

#include <stdio.h>
#include "mem_mgr.h"

int main (int argc, const char * argv[])
{
    char *ret;
    MEM_MGR *mem_mgr = mem_mgr_alloc(1024);
    if(!mem_mgr)
	return -1;

    ret = (char *)mem_mgr_alloc_buf(mem_mgr, 128);
    if(ret)
    {
        memcpy(ret, "hello123", 9);
        printf("%s\n", ret);
    }
    
    ret = (char *)mem_mgr_alloc_buf(mem_mgr, 128);
    if(ret)
    {
        memcpy(ret, "will tell me", 13);
        printf("%s\n", ret);
    }
    
    ret = (char *)mem_mgr_alloc_buf(mem_mgr, 128);
    if(ret)
    {
        memcpy(ret, "i\nam", 5);
        printf("%s\n", ret);
    }
    
    mem_mgr_free(mem_mgr);
    
    return 0;
}

