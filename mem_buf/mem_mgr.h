//
//  mem_mgr.h
//  mem_mgr
//
//  Created by xichen on 13-1-8.
//  Copyright (c) 2013 ccteam. All rights reserved.
//

#ifndef mem_mgr_H
#define mem_mgr_H

#define	    DEFAULT_BUF_SIZE	(4 * 1024)

// a linear and simple memory buffer struct
// which contains the memory buffer's pointer, size and free buffer pointer , used buffer pointer and userd size
typedef struct  
{
    char *  buf;            // the pointer of the memory buffer
    size_t    size;         // the size of the memory buffer

    char *  free_pointer;   // the free buffer pointer
    char *  used_pointer;   // the used buffer pointer(it always equals to buf)
    size_t    used_size;    // the used size of the buffer, which starts from the used_buffer
}MEM_MGR;

// alloc the memory manager
MEM_MGR	*   mem_mgr_alloc(size_t size); 

// alloc a buffer from the memory manager
void *	    mem_mgr_alloc_buf(MEM_MGR *mem_mgr, size_t size);

// maybe, you don't understand why mem_mgr_free_buf doesn't exist;
// the reason is that: the mem mgr never releases any buffer;
// you can use mem_mgr_free to free the mem mgr, then do mem_mgr_alloc and alloc buf again

// free the memory manager
void	    mem_mgr_free(MEM_MGR *mem_mgr);


#endif
