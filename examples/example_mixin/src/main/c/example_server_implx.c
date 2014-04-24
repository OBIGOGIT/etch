
// This file automatically generated by:
//   Apache Etch 1.2.0-incubating (LOCAL-0) / c 1.2.0-incubating (LOCAL-0)
//   Mon Mar 28 14:18:57 CEST 2011
// This file is automatically created and should not be edited!

/*
 * example_server_implx.c 
 * $helper.getImplName functions which would ordinarily not be subject to edit.
 */

#include "example_server_impl.h"
#include "example_remote_client.h"
#include "etch_objecttypes.h"
#include "etch_general.h"
#include "etch_url.h"

int destroy_example_server_impl(void*);

/* - - - - - - - - - - - - - - - - - - - - - - - -   
 *example_server_impl private construction / destruction 
 * - - - - - - - - - - - - - - - - - - - - - - - -    
 */

/**
 * init_example_server_impl()
 * called by example_server_impl constructor to instantiate server implementation object
 * @param client the remote client, not owned.
 * @param usermem_dtor destructor for any custom memory allocations.
 */
example_server_impl* init_example_server_impl(example_remote_client* client, 
    etch_object_destructor usermem_dtor)
{
    example_server_impl* pserver = (example_server_impl*) new_object (sizeof(example_server_impl), 
        ETCHTYPEB_EXESERVERIMPL, get_dynamic_classid_unique(&CLASSID_EXAMPLE_SERVER_IMPL));  
		
    pserver->client  = client;  /* not owned */
    ((etch_object*)pserver)->destroy = destroy_example_server_impl;  /* private destructor */
    pserver->destroyex = usermem_dtor;  /* user memory destructor */

    /* instantiate base */
    pserver->example_server_base = new_example_server_base(pserver, NULL); /* owned */

    pserver->iexample = pserver->example_server_base->iexample;

    pserver->iobjsession = pserver->example_server_base->iobjsession;
    pserver->iobjsession->thisx = pserver;  /* set implementor reference */
    pserver->_session_control = pserver->example_server_base->_session_control;
    pserver->_session_notify  = pserver->example_server_base->_session_notify;
    pserver->_session_query   = pserver->example_server_base->_session_query;

    return pserver;
}

/**
 * destroy_perf_server_impl()
 * perf_server_impl private destructor.
 * calls back to user destructor to effect cleanup of any perf_server_impl 
 * memory which may have been allocated in custom code added by user.
 */
int destroy_example_server_impl (void* data)
{
    example_server_impl* thisx = (example_server_impl*)data;
    if (NULL == thisx) return -1;  

    if (!is_etchobj_static_content(thisx))
    {    
        if(thisx->destroyex)
        {   /* call back to user memory destructor */
            thisx->destroyex(thisx);
        }
        if(thisx->example_server_base)
        {
            destroy_example_server_base(thisx->example_server_base);
        }
    }
            
    return destroy_objectex((etch_object*)thisx);
}
