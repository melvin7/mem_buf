//
//  mem_mgr.c
//  mem_mgr
//
//  Created by xichen on 13-1-8.
//  Copyright (c) 2013 ccteam. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "mem_mgr.h"

// free a buffer from the memory manager
// but, it does nothing
static void	    mem_mgr_free_buf(
								 MEM_MGR *mem_mgr, 
								 void *buf
								 );

MEM_MGR	* mem_mgr_alloc( size_t size )
{
    void *buf;
    MEM_MGR *mem_mgr = (MEM_MGR *)malloc(sizeof(MEM_MGR));
    if(!mem_mgr)
		goto error_alloc_mem_mgr;
	
    buf = malloc(size);	// alloc the true buffer owned by the mem mgr
    if(!buf)
		goto error_malloc_buf;
    mem_mgr->buf = mem_mgr->used_pointer = mem_mgr->free_pointer = buf;
    mem_mgr->size = size;
    mem_mgr->used_size = 0;

    return mem_mgr;
error_malloc_buf:
    free(mem_mgr);
error_alloc_mem_mgr:
    return NULL;
}

void mem_mgr_free( MEM_MGR *mem_mgr )
{
    free(mem_mgr->buf);
    free(mem_mgr);
}

void * mem_mgr_alloc_buf( MEM_MGR *mem_mgr, size_t size )
{
    void *  ret;
    if(mem_mgr->size - mem_mgr->used_size < size)
		return NULL;

    ret = mem_mgr->free_pointer;
    mem_mgr->free_pointer += size;
    mem_mgr->used_size += size;
    return ret;
}

// maybe ,you don't understand why this does nothing;
// the reason is that: the mem mgr doesn't release the buffer
static void mem_mgr_free_buf( MEM_MGR *mem_mgr, void *buf )
{
	
}






