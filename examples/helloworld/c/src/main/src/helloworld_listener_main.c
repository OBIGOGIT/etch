/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */


// This file automatically generated by:
//   Apache Etch 1.1.0-incubating (LOCAL-0) / c 1.1.0-incubating (LOCAL-0)
//   Fri Aug 28 15:58:20 CEST 2009
// This file is automatically created and should not be edited!
/*
 * helloworld_listener_main.c
 */
 
#include "helloworld_listener_main.h"
#include "etch_objecttypes.h"
#include "etch_runtime.h"
#include "etch_arrayval.h"
#include "etch_nativearray.h"
#include "etch_binary_tdo.h"
#include "etch_general.h"


/**
 * new_helloworld_server
 * create an individual client's helloworld_server implementation.
 * this is java binding's newhelloworldServer().
 * this is called back from helper.new_helper_accepted_server() (java's newServer).
 * @param p parameter bundle. caller retains. 
 * @return the i_helloworld_server, whose thisx is the helloworld_server_impl.
 */
static void* helloworld_server_create(void* factoryData, void* sessionData)
{
    etch_session* session = (etch_session*)sessionData;
    helloworld_remote_client* client  = (helloworld_remote_client*) session->client;

    helloworld_server_impl* newserver = new_helloworld_server_impl(client);

    return newserver->helloworld_server_base;
}

etch_status_t helloworld_listener_start(i_sessionlistener** pplistener, wchar_t* uri, int waitupms)
{
    etch_status_t etch_status = ETCH_SUCCESS;
    
    etch_status = helloworld_helper_listener_create(pplistener, uri, NULL, helloworld_server_create);
    if(etch_status == ETCH_SUCCESS) 
    {
        etch_status = helloworld_helper_listener_start_wait(*pplistener, waitupms);
    }

    return etch_status;
}

etch_status_t helloworld_listener_stop(i_sessionlistener* plistener, int waitupms)
{
    etch_status_t etch_status = ETCH_SUCCESS;
    
    etch_status = helloworld_helper_listener_stop_wait(plistener, waitupms);
    if(etch_status == ETCH_SUCCESS) 
    {
        helloworld_helper_listener_destroy(plistener);
    }

    return etch_status;
}


#ifndef NO_ETCH_SERVER_MAIN

/**
 * main()
 */
int main(int argc, char* argv[])
{
	etch_status_t etch_status = ETCH_SUCCESS;
    i_sessionlistener* listener = NULL;
    int waitupms = 4000;
    
    wchar_t* uri = L"tcp://127.0.0.1:4001?TcpListener.backlog=100";

    etch_config_t* config = NULL;
    etch_config_create(&config);
	
    etch_status = etch_runtime_initialize(config);
    if(etch_status != ETCH_SUCCESS) {
        // error
        return 1;
    }

    etch_status = helloworld_listener_start(&listener, uri, waitupms);
    if(etch_status != ETCH_SUCCESS) {
        // error
    }

    // wait for keypress

    waitkey();

    etch_status = helloworld_listener_stop(listener, waitupms);
    if(etch_status != ETCH_SUCCESS) {
        // error
    }

    etch_status = etch_runtime_shutdown();
    if(etch_status != ETCH_SUCCESS) {
        // error
        return 1;
    }
	etch_config_destroy(config);
	
    return 0;
}

#endif /* NO_ETCH_SERVER_MAIN */
